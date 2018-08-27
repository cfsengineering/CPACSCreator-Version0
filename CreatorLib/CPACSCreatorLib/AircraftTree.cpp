/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
//
// Created by makem on 29/04/18.
//

#include "AircraftTree.h"
#include "Helper.h"

#include "CPACSTreeItem.h"
#include "CreatorException.h"

#include <list>
#include <vector>
#include <set>
#include "tixi.h"
#include "CPACSProfilesDB.h"
#include "easylogging++.h"
#include "poly34.h"



Eigen::Matrix4d cpcr::AircraftTree::getGlobalTransformMatrixOfElement( UID elementUID) {

    CPACSTreeItem* element = m_root->getChildByUid(elementUID);
    std::vector<std::pair<CPACSTreeItem*, Eigen::Matrix4d> > chain = getTransformationChainForOneElement(element);
    Eigen::Matrix4d r = Eigen::Matrix4d::Identity();
    // We need to apply the transformation in reverse order
    for(int i = chain.size() - 1; i >= 0; i--){
        r = r *( chain[i].second );
    }


    return r;
}


std::vector<cpcr::UID> cpcr::AircraftTree::getAllElementUIDsUsedInAWing(UID wingUID) {

    std::vector< std::string> elementUIDs ;


    CPACSTreeItem * wing = m_root->getChildByUid(wingUID);
    if(wing->getType() != "wing" ){
        LOG(ERROR) << "The given uid is not a wing uid" ;
    }

    std::vector<CPACSTreeItem *> fromElementsItems =  wing->getChild(UniqueXPath("segments"))->findAllChildrenOfTypeRecursively("fromElementUID");
    std::vector<CPACSTreeItem *> toElementsItems =  wing->getChild(UniqueXPath("segments"))->findAllChildrenOfTypeRecursively("toElementUID");



    // Retrieve the uids
    std::string tempUid = "";
    for(auto e: fromElementsItems ){
        tempUid = modifier.retrieve<std::string>(e->getXPath(), "", true);
        elementUIDs.push_back(tempUid);
    }

    for(auto e: toElementsItems ){
        tempUid = modifier.retrieve<std::string>(e->getXPath(), "", true);
        elementUIDs.push_back(tempUid);
    }

    // make uid unique
    std::sort(elementUIDs.begin(), elementUIDs.end());
    auto last = std::unique(elementUIDs.begin(), elementUIDs.end());
    elementUIDs.erase(last, elementUIDs.end());


    return elementUIDs;

}




Eigen::Vector4d cpcr::AircraftTree::computePositionToHaveSweepAngle(Eigen::Vector4d originP, Eigen::Vector4d toPlaceP,
                                                                    double sweep) {

    double sweepR = DegreeToRadian(sweep);
    double deltaY = toPlaceP[1] - originP[1];
    double hypo = deltaY/ cos(sweepR);   // TODO check the limit case
    double deltaX = sin(sweepR) * hypo;

    Eigen::Vector4d r = toPlaceP ;
    r[0] = originP[0] + deltaX;

    return r;
}



Eigen::Vector4d cpcr::AircraftTree::computePositionToHaveDihedralAngle(Eigen::Vector4d originP, Eigen::Vector4d toPlaceP,
                                                                    double dihedral) {
    // find the requierd Z value for to place

    double dihedralR = DegreeToRadian(dihedral);
    double deltaY = toPlaceP[1] - originP[1];
    double hypo = deltaY/ cos(dihedralR);   // TODO check the limit case
    double deltaZ = sin(dihedralR) * hypo;

    Eigen::Vector4d r = toPlaceP ;
    r[2] = originP[2] + deltaZ;

    return r;
}



cpcr::CPACSTransformation cpcr::AircraftTree::getTransformToPlaceElementByTranslationAt(const UID &elementUID,
                                                                                        const Eigen::Vector4d &wantedOriginP) {

    CPACSTreeItem* element = m_root->getChildByUid(elementUID);
    CPACSTreeItem* wing = element->getParentOfType("wing");


    std::vector<std::pair<CPACSTreeItem*, Eigen::Matrix4d> > Ts = getTransformationChainForOneElement(element);


    // We first isolate the transform of the element (cut off influence of positioning, section and wing transform)

    int numberOfTransformation = Ts.size();
    Eigen::Vector4d P = wantedOriginP;
    Eigen::Matrix4d inverseT;
    for(int i = numberOfTransformation -1; i >=1 ; i-- ){
        inverseT = Ts[i].second.inverse();
        P =  inverseT * P;
    }

    // now we have: P' = wantedT0 *origin

    CPACSTransformation T0 = modifier.getTransformation(Ts[0].first->getXPath());
    Eigen::Matrix4d T0Scaling = T0.getScalingAsMatrix();
    Eigen::Matrix4d T0Rotation = T0.getRotationAsMatrix();
    Eigen::Matrix4d T0Translation = T0.getTranslationAsMatrix();

    // P' =   wT wR wS origin;
    // Assuming we want only change T
    // ->   P' = wT? (wR * wS * origin)
    //      P' = wT? * origin'

    Eigen::Vector4d elementOrigin ;
    elementOrigin << 0,0,0,1;

    elementOrigin = T0Scaling * elementOrigin; // TODO useless?
    elementOrigin = T0Rotation * elementOrigin; // useless

    // P' = wT * origin'

    Point newTranslationT0;

    newTranslationT0.x = P[0] - elementOrigin[0];
    newTranslationT0.y = P[1] - elementOrigin[1];
    newTranslationT0.z = P[2] - elementOrigin[2];

    CPACSTransformation r (T0.getScaling(), T0.getRotation(), newTranslationT0 );

    // check if it is correct
    elementOrigin << 0,0,0,1;
    P = r.getTransformationAsMatrix() * elementOrigin;

    for (int i = 1; i < Ts.size(); i++ ){
        P = Ts[i].second * P;
    }

    if( ! P.isApprox(wantedOriginP, 0.00001) ){
        LOG(ERROR) << "Something go wrong!";
    }

    return r;



}


std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>>
cpcr::AircraftTree::getTransformationChainForOneElement(cpcr::CPACSTreeItem *elementItem) {


    if(elementItem->getType() != "element"){
        std::string msg = "requiered elementItem parameter";
        LOG(ERROR) << msg;
        throw CreatorException(msg);
    }

    // get transformation from the elementItem
    CPACSTreeItem* elementTItem = elementItem->getChild(UniqueXPath("transformation")) ;
    CPACSTransformation elementT  = modifier.getTransformation(elementTItem->getXPath().toString());

    // get the transformation from the section
    CPACSTreeItem* sectionItem = elementItem->getParentOfType("section");
    if(sectionItem == nullptr ){
        throw CreatorException("structure is not respected");
    }
    CPACSTreeItem* sectionTItem = sectionItem->getChild(UniqueXPath("transformation")) ;
    CPACSTransformation sectionT = modifier.getTransformation(sectionTItem->getXPath().toString());

    // get the transformation from the wing
    CPACSTreeItem* wingItem = elementItem->getParentOfType("wing");
    if(wingItem == nullptr ){
        throw CreatorException("structure is not respected");
    }
    CPACSTreeItem* wingTItem = wingItem->getChild(UniqueXPath("transformation")) ;
    CPACSTransformation wingT = modifier.getTransformation(wingTItem->getXPath().toString());


    // get the positioning global translation
    std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d> positioningPair = getGlobalPositioningTranslationForSection( sectionItem->getUid() );


    // now create the all transformation chain

    std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> chain;

    chain.push_back(std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>(elementTItem, elementT.getTransformationAsMatrix()) );
    chain.push_back(std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>(sectionTItem, sectionT.getTransformationAsMatrix()) );
    chain.push_back(positioningPair );
    chain.push_back(std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>(wingTItem, wingT.getTransformationAsMatrix()) );

    return chain;
}



std::pair<cpcr::CPACSTreeItem*,Eigen::Matrix4d> cpcr::AircraftTree::getGlobalPositioningTranslationForSection(cpcr::UID sectionUID) {

    CPACSTreeItem * sectionItem = m_root->getChildByUid(sectionUID);
    CPACSTreeItem * wingItem = sectionItem->getParentOfType("wing");
    CPACSTreeItem * positioningsItem = wingItem->getChild("positionings", false); // We do not enable warnings because this can be a normal case if the positionigs is not present

    if(positioningsItem == nullptr){    // this can happend if no positioning is used in this wing
        return  std::pair<CPACSTreeItem*,Eigen::Matrix4d> (nullptr, Eigen::Matrix4d::Identity() );
    }

    // get all positioning item
    std::vector<CPACSTreeItem*> positionings =  positioningsItem->findAllChildrenOfTypeRecursively("positioning");

    // check if a positioning is used for this section
    // if yes store the value in positioningItem
    // (and create CPACSpositioning object from file)
    bool positioningFound = false;
    CPACSTreeItem* positioningItem = nullptr;
    std::map<CPACSTreeItem* , CPACSPositioning> positioningsObject ;
    CPACSPositioning pTemp;
    for( auto p : positionings){
        pTemp = modifier.getPositioning(p->getXPath() ) ;
        positioningsObject.insert( std::pair<CPACSTreeItem*, CPACSPositioning> ( p, pTemp ) );
        if( pTemp.getToSectionUID() == sectionUID) {
            positioningFound = true;
            positioningItem = p;
        }
    }

    if(positioningFound == false){  // in this case, this section is not influenced by any positioning
        return  std::pair<CPACSTreeItem*,Eigen::Matrix4d> (nullptr, Eigen::Matrix4d::Identity() );
    }

    // Create the dependence queue of this particular positioning
    std::vector<CPACSPositioning*> depedence ;
    CPACSPositioning* original = &(positioningsObject[positioningItem]);
    depedence.push_back(original);

    std::string from = original->getFromSectionUID();
    CPACSTreeItem* next ;
    while( from != "" ){
        next = nullptr;
        for(auto candidat : positioningsObject ){
            if (candidat.second.getToSectionUID() == from ){ // in this case the prvious element depend of this one
                next = candidat.first;
                depedence.push_back(&(positioningsObject[next]));
            }
        }
        // if the last from section was not found -> this mean the from section is not placed or invalid
        // -> we reach the last positioning dependences
        from = "";
        if ( next != nullptr) {
            from = positioningsObject[next].getFromSectionUID(); // eider the from
        }
        // TODO: detection of cycle
    }

    // combine all the dependence to get one  translation
    Eigen::Matrix4d globalTranslation = Eigen::Matrix4d::Identity();
    for ( std::vector<CPACSPositioning*>::reverse_iterator rit = depedence.rbegin(); rit!= depedence.rend(); ++rit){
        globalTranslation =  (*rit)->getPositioningAsMatrix() * globalTranslation ;
    }

    return std::pair<CPACSTreeItem*,Eigen::Matrix4d> (positioningItem, globalTranslation );
}





double cpcr::AircraftTree::getWingSweep(cpcr::UID wingUID, double chordPercent) {

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);


    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wingUID);
    std::map<UID, Eigen::Vector4d> chordPoints = getChordPointsOfElements(wingUID, chordPercent);
    std::map<UID, Eigen::Vector4d> chordPointsM = getChordPointsOfElements(wingUID, 0.5);

    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();

    // We transform all the chord point to work in the wing system !
    for (UID u : elementUIDs ){
        chordPointsM[u] = wingTMI * chordPointsM[u];
        chordPoints[u] = wingTMI * chordPoints[u];
    }

    UID rootUID = getRootOfWing(wing);
    UID extremityUID = getExtremityInY(rootUID, chordPointsM);


    // get the segment from min to max
    Eigen::Vector4d rootToExtremity = chordPoints[extremityUID] - chordPoints[rootUID];

    // compute the angle between the rootToExtremity and the unit y vector
    double dot = rootToExtremity[0] * 0 + rootToExtremity[1] * 1; // with unit vector of y
    double det = rootToExtremity[0] * 1 - rootToExtremity[1] * 0;
    double sweepAngleR = std::atan2(det, dot);

    // transform radian to degree
    double sweepAngle = RadianToDegree(sweepAngleR);

    return sweepAngle;
}



void cpcr::AircraftTree::writeToFile() {
    writeToFile( getFilename());
}


void cpcr::AircraftTree::writeToFile(std::string newFile) {

    closeTiglHandle();

    // TODO : IMPORTANT check if we need to reconstruct the tree!
    modifier.save(newFile);
    this->fileName = newFile;
    // reopen the tigl handler
    openTiglHandle(m_root->getUid());


}

void cpcr::AircraftTree::openTiglHandle(std::string modelUid) {

    if(! modifier.isValid()){
        throw CreatorException("make sure to have a valid tixi handler before to open tigl handler");
    }

    if (tiglOpenCPACSConfiguration(modifier.getTixiHandle(), modelUid.c_str(), tiglHandle) != TIGL_SUCCESS) {
        throw CreatorException("Error reading in cpacs file with TiGL");

    }

}

void cpcr::AircraftTree::closeTiglHandle() {

    TiglBoolean tiglISValid ;
    tiglIsCPACSConfigurationHandleValid(*tiglHandle, &tiglISValid);
    if( tiglISValid == TIGL_TRUE){
        tiglCloseCPACSConfiguration(*tiglHandle);
    }
    *tiglHandle = 0;

}

void cpcr::AircraftTree::build(std::string file, cpcr::UniqueXPath root) {

    closeTiglHandle();
    // construct as a standard CPACSTree
    CPACSTree::build(file, root);

    // check that the root is of the correct type
    if( m_root->getType() != "model"){
        clean();
        throw CreatorException("The given xPath do not lead to a aircraft model!");
    }

    // get the tigl acces
    openTiglHandle(m_root->getUid());

}

cpcr::AircraftTree::AircraftTree(): CPACSTree() {
    tiglHandle = new TiglCPACSConfigurationHandle ;
    *tiglHandle = 0;

}

cpcr::AircraftTree::~AircraftTree(){
    closeTiglHandle();
    delete tiglHandle;
}


void cpcr::AircraftTree::setWingSweepByTranslation(cpcr::UID wingUID, double sweepAngle, double chordPercent) {

    // wing tree item
    CPACSTreeItem * wing = m_root->getChildByUid(wingUID);


    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wingUID);   // element UIDs used in this wing
    std::map<UID, Eigen::Vector4d> chordPoints = getChordPointsOfElements(wingUID, chordPercent);     // get for each element the associated chord Point
    std::map<UID, Eigen::Vector4d> chordPointsM = getChordPointsOfElements(wingUID, 0.5);
    std::map< UID, Eigen::Matrix4d> globalMatrices;
    Eigen::Vector4d neutral, rootO, rootCP, oldTipO, oldTipCP, newTipO, newTipCP ;  // O stay for origin and CP for chord point

    std::map<UID, Eigen::Vector4d> wantedOriginsInWingSys ;


    // get the global affine transform matrix for each element
    Eigen::Matrix4d tempM ;
    for( auto uid : elementUIDs) {
        tempM = getGlobalTransformMatrixOfElement(uid);
        globalMatrices.insert(std::pair<UID, Eigen::Matrix4d>(uid, tempM) );
    }



    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();

    // We transform all the chord point to work in the wing system !
    for (UID u : elementUIDs ){
        chordPointsM[u] = wingTMI * chordPointsM[u];
        chordPoints[u] = wingTMI * chordPoints[u];
    }


    // set root and tip
    UID rootUID = getRootOfWing(wing);
    UID extremityUID = getExtremityInY(rootUID, chordPointsM );
    neutral << 0,0,0,1;
    rootCP = chordPoints[rootUID];
    oldTipCP = chordPoints[extremityUID];
    oldTipO =  wingTMI * globalMatrices[extremityUID] * neutral;

    // set the wanted position for extremity !!
    newTipCP = computePositionToHaveSweepAngle(rootCP, oldTipCP, sweepAngle);
    newTipO = newTipCP + ( oldTipO - oldTipCP); // the new origin can get form the new chord point and the old delta



    // Get the translation to perform the shear on the right axis
    Eigen::Matrix4d translateXaxisToRootCP = Eigen::Matrix4d::Identity();
    translateXaxisToRootCP(0, 1) = -rootCP(1); // we simply substract the y coordinate to shift the point CP on the XZ-plane

    // Shear matrix
    Eigen::Matrix4d shear = Eigen::Matrix4d::Identity();
    Eigen::Vector4d newTipCPb = translateXaxisToRootCP * newTipCP;
    Eigen::Vector4d oldTipCPb = translateXaxisToRootCP * oldTipCP;
    double lambda = (newTipCPb(0) - oldTipCPb(0)) / oldTipCPb(1);   // shear formula
    shear(0, 1) = lambda;


    // Get the wanted origin for each elements using the shearing matrix
    Eigen::Vector4d tempOToCP; // vector from airfoil origin to CP,
                                // since only translation will be performed on the airfoi
                                // will remain unchanged before and after the sweep angle is set
    Eigen::Vector4d tempNewCP;
    for( auto uid: elementUIDs){
        tempOToCP = chordPoints[uid] - ( wingTMI * globalMatrices[uid] * neutral ) ;
        tempNewCP = translateXaxisToRootCP.inverse() *  shear * translateXaxisToRootCP * chordPoints[uid];
        wantedOriginsInWingSys[uid] = tempNewCP - tempOToCP;
    }

    // set all elements
    CPACSTransformation newT;
    Eigen::Matrix4d newM;
    Eigen::Vector4d wantedOriginInG;
    UniqueXPath tempXPath;
    CPACSTreeItem* element;
    for(auto uid: elementUIDs) // the first element (the more closest of the XZ plan) do not move
    {
        newM = globalMatrices[uid];
        wantedOriginInG = wingTM * wantedOriginsInWingSys[uid]; // scaling and rotation set the same
        newM(0,3) = wantedOriginInG(0); // set translation
        newM(1,3) = wantedOriginInG(1);
        newM(2,3) = wantedOriginInG(2);
        element = wing->getChildByUid(uid);
        placeElementMinimalChanges(element, newM);   // here we save the result in memory (not in file)
    }



    // update tigl handle // TODO check if is the correct method to maintain tigl and aircraft sychronous
    closeTiglHandle();
    openTiglHandle(m_root->getUid() );


}








void cpcr::AircraftTree::setWingSweepByShearing(cpcr::UID wingUID, double sweepAngle, double chordPercent) {

    bool enableTest = true; // If true check at the end if all chord are correctly placed

    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wingUID);
    std::map<UID, Eigen::Vector4d> chordPoints = getChordPointsOfElements(wingUID, chordPercent);
    std::map<UID, Eigen::Vector4d> chordPointsM = getChordPointsOfElements(wingUID, 0.5);
    std::map<UID, Eigen::Vector4d> chordPointsLE = getChordPointsOfElements(wingUID, 0);
    std::map<UID, Eigen::Vector4d> chordPointsTE = getChordPointsOfElements(wingUID, 1);

    Eigen::Vector4d neutral, rootCP, oldTipCP, newTipCP;  // O stay for origin, and CP for chord point

    CPACSTreeItem * wing = m_root->getChildByUid(wingUID);

    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();

    // We transform all the chord point to work in the wing system !
    for (UID u : elementUIDs ){
        chordPointsM[u] = wingTMI * chordPointsM[u];
        chordPointsLE[u] = wingTMI * chordPointsLE[u];
        chordPoints[u] = wingTMI * chordPoints[u];
        chordPointsTE[u] = wingTMI * chordPointsTE[u];
    }


    // set root and tip
    UID rootUID = getRootOfWing(wing);
    UID extremityUID = getExtremityInY(rootUID, chordPointsM );

    rootCP = chordPoints[rootUID];
    oldTipCP = chordPoints[extremityUID];

    // set the wanted position for the tip !!
    newTipCP = computePositionToHaveSweepAngle(rootCP, oldTipCP, sweepAngle); // old Tip is use for xand y coordinate


    // Get the translation to perform the shear on the right axis
    Eigen::Matrix4d translateXaxisToRootCP = Eigen::Matrix4d::Identity();
    translateXaxisToRootCP(0, 1) = -rootCP(1); // we simply substract the y coordinate to shift the point CP on the XZ-plane

    // Shear matrix
    Eigen::Matrix4d shear = Eigen::Matrix4d::Identity();
    Eigen::Vector4d newTipCPb = translateXaxisToRootCP * newTipCP;
    Eigen::Vector4d oldTipCPb = translateXaxisToRootCP * oldTipCP;
    double lambda = (newTipCPb(0) - oldTipCPb(0)) / oldTipCPb(1);   // shear formula
    shear(0, 1) = lambda;


    // Prepare sensor and  value that allow the creation of transformation
    // Remark that sensors trick works because, we now that the original p0 lie on the XZ-plane
    Eigen::Vector4d sensor1, sensor2, sensor3, sensor1P, sensor2P, sensor3P , sensorN ;;
    CPACSTreeItem * element;
    std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> tempChain;
    Eigen::Matrix4d allOldExpectE, tempNewElementMatResultat, semiGlobalMatricesInv;
    UniqueXPath tempXPath;
    CPACSTransformation tempNewTransformationE ;

    // For each element find out the good transformation for element to do the shearing
    for (auto uid: elementUIDs) {
        element = m_root->getChildByUid(uid);
        tempChain = getTransformationChainForOneElement(element);
        tempNewElementMatResultat = tempChain[1].second.inverse() * tempChain[2].second.inverse()
                                    * translateXaxisToRootCP.inverse() * shear * translateXaxisToRootCP
                                    * tempChain[2].second * tempChain[1].second * tempChain[0].second  ;

        semiGlobalMatricesInv = (tempChain[2].second * tempChain[1].second  * tempChain[0].second ).inverse();

        sensor1 = semiGlobalMatricesInv * chordPointsLE[uid]; // give the point in the airfoil sys
        sensor2 = semiGlobalMatricesInv * chordPointsTE[uid];
        sensorN << 0,1,0,1 ; // sensor 1 and sensor 2 should be on the XZ-plane, because they are airfoil // todo test?
        sensor3.block<3,1>(0,0) = sensor1.block<3,1>(0,0) +  (sensorN.block<3,1>(0,0)).cross((sensor2-sensor1).block<3,1>(0,0)); // create a vector perpendicular at s1 s2 on the XZ-plane
        sensor3(3) = 1;  // set the augmented component;
        sensor1P = tempNewElementMatResultat * sensor1;
        sensor2P = tempNewElementMatResultat * sensor2;
        sensor3P = tempNewElementMatResultat * sensor3;



        tempNewTransformationE = TransformChord(sensor1, sensor2, sensor3, sensor1P, sensor2P, sensor3P);

        tempXPath = UniqueXPath(element->getXPath());
        tempXPath.addParticleAtEnd("transformation");
        modifier.setTransformation(tempXPath,tempNewTransformationE ); // save the result in memory
    }

    // update tigl handle // TODO check if is the correct method to maintain tigl and aircraft sychronous
    closeTiglHandle();
    openTiglHandle(m_root->getUid());


    // Check results
    if(enableTest){
        std::map<UID, Eigen::Vector4d> newChordPoints = getChordPointsOfElements(wingUID, chordPercent);
        Eigen::Vector4d testResult, testExpected;


        for(auto uid: elementUIDs ){
            element = m_root->getChildByUid(uid);
            testExpected = wingTM * translateXaxisToRootCP.inverse() * shear * translateXaxisToRootCP * chordPoints[uid];
            testResult = newChordPoints[uid];
            if( ! testExpected.isApprox(testResult, 0.0001) ){
                throw CreatorException("SetWingSweep3: not the expected result!");
            }
        }


    }
}

void cpcr::AircraftTree::close() {

    closeTiglHandle();
    clean();
}





std::map<cpcr::UID, Eigen::Vector4d> cpcr::AircraftTree::getChordPointsOfElements(cpcr::UID wingUID, double chordPercent) {

    std::map<cpcr::UID, Eigen::Vector4d>  elementsChordPoints;

    // get all segment Items
    CPACSTreeItem* wingItem = m_root->getChildByUid(wingUID);
    std::vector<CPACSTreeItem *> segmentItems = wingItem->findAllChildrenOfTypeRecursively("segment");


    // prepare loop
    CPACSTreeItem * tempFromItem;
    CPACSTreeItem * tempToItem;

    std::string tempFromUid;
    std::string tempToUid;

    Eigen::Vector4d fromLE;
    double fromLEX; // for tigl
    double fromLEY;
    double fromLEZ;

    Eigen::Vector4d toLE;
    double toLEX;
    double toLEY;
    double toLEZ;

    int wingIdx = wingItem->getTixiIndex();
    int segmentIdx;
    TiglReturnCode returnTigl;

    // Loop over all segment and call tigl to get the chord point
    for(auto s : segmentItems){

        segmentIdx = s->getTixiIndex();

        // get reference element
        tempFromItem = s->getChild("fromElementUID");
        tempToItem = s->getChild("toElementUID");

        // TODO ? check null return

        // retrive uid values
        tempFromUid = modifier.retrieve<std::string>(tempFromItem->getXPath(), "", true);
        tempToUid = modifier.retrieve<std::string>(tempToItem->getXPath(), "", true);

        // get chord points
        returnTigl =  tiglWingGetChordPoint(*tiglHandle, wingIdx, segmentIdx ,0 , chordPercent,&fromLEX, &fromLEY, &fromLEZ );
        if ( returnTigl != TIGL_SUCCESS ){
            DLOG(ERROR) << "SOMETHING GO WORNG WITH TIGL";
        }
        returnTigl =   tiglWingGetChordPoint(*tiglHandle,wingIdx, segmentIdx ,1 , chordPercent, &toLEX, &toLEY, &toLEZ );
        if ( returnTigl != TIGL_SUCCESS ){
            DLOG(ERROR) << "SOMETHING GO WORNG WITH TIGL";
        }

        // create vector point
        fromLE << fromLEX, fromLEY, fromLEZ, 1; // 1 at the end because it's a point and not a vector
        toLE << toLEX, toLEY, toLEZ, 1;

        // Insert in the map. If the element already exist is overwritten, otherwise is created.
        // Remark that the element have the same position whatever in witch segment the element is used
        elementsChordPoints[tempFromUid] = fromLE;
        elementsChordPoints[tempToUid] = toLE;
    }

    return elementsChordPoints;
}





double cpcr::AircraftTree::getWingPlanformAreaByTigl(cpcr::UID wingUid, TiglSymmetryAxis symmetry) {
    // TODO: error handling
    double area = -1;
    CPACSTreeItem* wing = m_root->getChildByUid(wingUid);

    if( symmetry == TIGL_NO_SYMMETRY)    {
        tiglWingGetReferenceArea(*tiglHandle,wing->getTixiIndex(), TIGL_NO_SYMMETRY, &area);
    }
    else if( symmetry == TIGL_X_Y_PLANE) {
        tiglWingGetReferenceArea(*tiglHandle,wing->getTixiIndex(), TIGL_X_Y_PLANE, &area);
    }
    else if( symmetry == TIGL_X_Z_PLANE)    {
        tiglWingGetReferenceArea(*tiglHandle,wing->getTixiIndex(), TIGL_X_Z_PLANE, &area);
    }
    else if (symmetry == TIGL_Y_Z_PLANE){
        tiglWingGetReferenceArea(*tiglHandle,wing->getTixiIndex(), TIGL_Y_Z_PLANE, &area);
    }
    else{
       throw CreatorException("AIRCRAFT: getWingPlanformAreaByTigl: given sysmetry unknown!");
    }
    return area;
}



double cpcr::AircraftTree::getWingDihedral(UID wingUID,  double chordPercent) {

    CPACSTreeItem* wing =  m_root->getChildByUid(wingUID);

    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wingUID);
    std::map<UID, Eigen::Vector4d> chordPoints = getChordPointsOfElements(wingUID, chordPercent);
    std::map<UID, Eigen::Vector4d> chordPointsM = getChordPointsOfElements(wingUID, 0.5);

    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();

    // We transform all the chord point to work in the wing system !
    for (UID u : elementUIDs ){
        chordPointsM[u] = wingTMI * chordPointsM[u];
        chordPoints[u] = wingTMI * chordPoints[u];
    }

    UID rootUID = getRootOfWing(wing);
    UID extremityUID = getExtremityInY(rootUID, chordPointsM);


    // get the segment from min to max
    Eigen::Vector4d rootToExtremity = chordPoints[extremityUID] - chordPoints[rootUID];

    // compute the angle between the projection of minToMax on YZ and the unit y vector [0,1,0]
    // use the fact that the projection give the cos(angle) and sin(angle) -> tan(angle) = sin/cos
    double dihedralAngleR = std::atan2(rootToExtremity[2],rootToExtremity[1] );

    // transform radian to degree
    double dihedralAngle = RadianToDegree(dihedralAngleR);

    return dihedralAngle;

}

double cpcr::AircraftTree::getWingWorldDihedral(cpcr::UID wingUID, double chordPercent) {
    CPACSTreeItem* wing =  m_root->getChildByUid(wingUID);

    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wingUID);
    std::map<UID, Eigen::Vector4d> chordPoints = getChordPointsOfElements(wingUID, chordPercent);
    std::map<UID, Eigen::Vector4d> chordPointsM = getChordPointsOfElements(wingUID, 0.5);


    UID rootUID = getRootOfWing(wing);
    UID extremityUID = getExtremityInY(rootUID, chordPointsM); // relative to world coordinate system


    // get the segment from min to max
    Eigen::Vector4d rootToExtremity = chordPoints[extremityUID] - chordPoints[rootUID];

    // compute the angle between the projection of minToMax on YZ and the unit y vector [0,1,0]
    // use the fact that the projection give the cos(angle) and sin(angle) -> tan(angle) = sin/cos
    double dihedralAngleR = std::atan2(rootToExtremity[2],rootToExtremity[1] );

    // transform radian to degree
    double dihedralAngle = RadianToDegree(dihedralAngleR);

    return dihedralAngle;
}



void cpcr::AircraftTree::setWingDihedral(UID wingUID, double dihedral, double chordPercent) {


    // wing tree item
    CPACSTreeItem * wing = m_root->getChildByUid(wingUID);
    // element UIDs used in this wing
    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wingUID);
    // get for each element the associated chord Point
    std::map<UID, Eigen::Vector4d> chordPoints = getChordPointsOfElements(wingUID, chordPercent );
    // get for each element the middle chord point (used to determine the extremity)
    std::map<UID, Eigen::Vector4d> chordPointsM = getChordPointsOfElements(wingUID, 0.5);

    // wingUID -> globalTransformation map
    std::map< UID, Eigen::Matrix4d> globalMatrices;

    Eigen::Vector4d neutral, rootO, rootCP, oldTipO, oldTipCP, newTipO, newTipCP ;  // O stay for origin and CP for chord point

    std::map<UID, Eigen::Vector4d> wantedOriginsInWingSys ;


    // get the global affine transform matrix for each element
    Eigen::Matrix4d tempM ;
    for( auto uid : elementUIDs) {
        tempM = getGlobalTransformMatrixOfElement(uid);
        globalMatrices.insert(std::pair<UID, Eigen::Matrix4d>(uid, tempM) );
    }

    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();

    // We transform all the chord point to work in the wing system !
    for (UID u : elementUIDs ){
        chordPointsM[u] = wingTMI * chordPointsM[u];
        chordPoints[u] = wingTMI * chordPoints[u];
    }

    UID rootUID = getRootOfWing(wing);
    UID extremityUID = getExtremityInY(rootUID, chordPointsM);


    // set wing origin, extremity  (in the wing coord sys)
    rootCP = chordPoints[rootUID];
    neutral << 0,0,0,1;
    rootO = wingTMI * globalMatrices[rootUID] *neutral;

    oldTipCP = chordPoints[extremityUID];
    oldTipO =  wingTMI * globalMatrices[extremityUID] * neutral;


    // set the wanted position for extremity !!
    newTipCP = computePositionToHaveDihedralAngle(rootCP, oldTipCP, dihedral);
    newTipO = newTipCP + ( oldTipO - oldTipCP); // the new origin can get form the new chord point and the old delta


    // Get the translation to perform the shear on the right axis
    Eigen::Matrix4d translateXaxisToRootCP = Eigen::Matrix4d::Identity();
    translateXaxisToRootCP(0, 1) = -rootCP(1); // we simply substract the y coordinate to shift the point CP on the XZ-plane

    // Shear matrix
    Eigen::Matrix4d shear = Eigen::Matrix4d::Identity();
    Eigen::Vector4d newTipCPb = translateXaxisToRootCP * newTipCP;
    Eigen::Vector4d oldTipCPb = translateXaxisToRootCP * oldTipCP;

    double lambda = (newTipCPb(2) - oldTipCPb(2)) / oldTipCPb(1);   // shear formula
    shear(2, 1) = lambda;



    // Get the wanted origin for each elements using the shearing matrix
    Eigen::Vector4d tempOToCP; // vector from airfoil origin to CP,
    // since only translation will be performed on the airfoi
    // will remain unchanged before and after the sweep angle is set
    Eigen::Vector4d tempNewCP;
    for( auto uid: elementUIDs){
        tempOToCP = chordPoints[uid] - (wingTMI * globalMatrices[uid] * neutral ) ;
        tempNewCP = translateXaxisToRootCP.inverse() *  shear * translateXaxisToRootCP * chordPoints[uid];
        wantedOriginsInWingSys[uid] = tempNewCP - tempOToCP;
    }


    // Set all element
    CPACSTransformation newT;
    Eigen::Matrix4d newM;
    Eigen::Vector4d wantedOriginInG;
    UniqueXPath tempXPath;
    UID tempUid;
    CPACSTreeItem* element;


    for(int i = 1; i < elementUIDs.size(); i++) // the first element (the more closest of the XZ plan) do not move
    {
        tempUid = elementUIDs[i];
        newM = globalMatrices[tempUid];
        wantedOriginInG = wingTM * wantedOriginsInWingSys[tempUid]; // scaling and rotation set the same
        newM(0,3) = wantedOriginInG(0); // set translation
        newM(1,3) = wantedOriginInG(1);
        newM(2,3) = wantedOriginInG(2);
        element = wing->getChildByUid(tempUid);
        placeElementMinimalChanges(element, newM);   // here we save the result in memory (not in file)
    }

    // update tigl handle // TODO check if is the correct method to maintain tigl and aircraft sychronous
    closeTiglHandle();
    openTiglHandle(m_root->getUid() );
}




std::vector<cpcr::UID> cpcr::AircraftTree::getAllAirfoilsUIDInThisWing(cpcr::UID wingUID) {

    std::vector<UID> airfoilsUID;
    std::vector<UID> elementsUID = getAllElementUIDsUsedInAWing(wingUID);


    CPACSTreeItem* element;
    CPACSTreeItem* airfoil;
    UID tempUID;
    for (UID uid : elementsUID){
        element = m_root->getChildByUid(uid);
        airfoil = element->getChild("./airfoilUID");
        tempUID = modifier.retrieve<std::string>(airfoil->getXPath(),"notSet") ;
        if(std::find(airfoilsUID.begin(), airfoilsUID.end(),tempUID) == airfoilsUID.end() ){    // check if uid is already present
            airfoilsUID.push_back(tempUID);
        }

    }

    return airfoilsUID;
}

void cpcr::AircraftTree::setWingAirfoilsFromExternalFile(cpcr::UID wingUID, std::string filename, bool keepChord) {

    CPACSPointsProfile profile = modifier.addWingAirfoil(filename);
    setWingAirfoilsByUID(wingUID, profile.getUID(), keepChord );
}



void cpcr::AircraftTree::setWingAirfoilsByUID(cpcr::UID wingUID, cpcr::UID airfoilUID, bool keepChord) {

    if( !modifier.wingAirfoilExist(airfoilUID)){
        throw CreatorException("The airfoil does not seem to exist.");
    }

    CPACSTreeItem * wing = m_root->getChildByUid(wingUID);

    if(keepChord == true ){
        setWingAirfoilsByUIDKeepChord(wing, airfoilUID);
    }else{
        setWingAirfoilsByUIDBasic(wing, airfoilUID);
    }



}

void cpcr::AircraftTree::setWingAirfoilsByUIDKeepChord(CPACSTreeItem* wing, UID airfoilUID) {


    CPACSPointsProfile profile = modifier.getAirfoil(airfoilUID);
    // wing tree item

    // elements in this wing , also the elements not used in a segment!!!
    std::vector<CPACSTreeItem*> elements = wing->findAllChildrenOfTypeRecursively("element");
    // element Uids used in this wing , only the elements used in a segment!!!
    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wing->getUid());
    // get for each element the associated chord Point
    std::map<UID, Eigen::Vector4d> lEPoints = getChordPointsOfElements(wing->getUid(), 0 );
    // get for each element the associated chord Point
    std::map<UID, Eigen::Vector4d> tEPoints = getChordPointsOfElements(wing->getUid(), 1 );


    // UPDATE THE LINK
    UniqueXPath airfoilPathTemp;
    // update all the elements
    for(CPACSTreeItem * e: elements){
        airfoilPathTemp = e->getXPath();
        airfoilPathTemp.addParticleAtEnd("airfoilUID");
        modifier.setValue(airfoilPathTemp , profile.getUID());
    }

    //UPDATE THE TRANSFORMATION
    // Prepare sensor and  value that allow the creation of transformation
    // Remark that sensors trick works because, we now that the original p0 lie on the XZ-plane
    Eigen::Vector4d  oldBaseLE, oldBaseTE, preSensor3, baseLE, baseTE, sensor3, sensor1P, sensor2P, sensor3P , sensorN ;;
    CPACSTreeItem * element;
    std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> tempChain;
    Eigen::Matrix4d allOldExpectE, globalMatricesInv;
    UniqueXPath tempXPath;
    CPACSTransformation tempNewTransformationE ;

    baseLE.block<3,1>(0,0) = profile.getLeadingEdge();
    baseLE(3) = 1;
    baseTE.block<3,1>(0,0) = profile.getTrailingEdge();
    baseTE(3) = 1;
    sensorN << 0,1,0,1 ; // BaseLE and baseTE  should be on the XZ-plane, because they are airfoil // todo test?
    sensor3.block<3,1>(0,0) = baseLE.block<3,1>(0,0) +  (sensorN.block<3,1>(0,0)).cross((baseTE-baseLE).block<3,1>(0,0)); // create a vector perpendicular at s1 s2 on the XZ-plane
    sensor3(3) = 1;  // set the augmented component;

    // Update the transformation of element such that the new profile is adapted to the old one.
    for (auto uid: elementUIDs) {
        element = m_root->getChildByUid(uid);
        tempChain = getTransformationChainForOneElement(element);
        allOldExpectE = tempChain[3].second * tempChain[2].second * tempChain[1].second;

        sensor1P = allOldExpectE.inverse() * lEPoints[uid];
        sensor2P = allOldExpectE.inverse() * tEPoints[uid];

        globalMatricesInv = getGlobalTransformMatrixOfElement(uid).inverse();
        oldBaseLE = globalMatricesInv * lEPoints[uid];
        oldBaseTE = globalMatricesInv * tEPoints[uid];
        preSensor3.block<3,1>(0,0) = oldBaseLE.block<3,1>(0,0) +  (sensorN.block<3,1>(0,0)).cross((oldBaseTE-oldBaseLE).block<3,1>(0,0)); // create a vector perpendicular at s1 s2 on the XZ-plane
        preSensor3(3) = 1;  // set the augmented component;

        sensor3P = tempChain[0].second * preSensor3;

        tempNewTransformationE = TransformChord(baseLE, baseTE, sensor3, sensor1P, sensor2P, sensor3P);

        tempXPath = UniqueXPath(element->getXPath());
        tempXPath.addParticleAtEnd("transformation");
        modifier.setTransformation(tempXPath,tempNewTransformationE ); // save the result in memory
    }

    // update tigl handle // TODO check if is the correct method to maintain tigl and aircraft sychronous
    closeTiglHandle();
    openTiglHandle(m_root->getUid());

}

void cpcr::AircraftTree::setWingAirfoilsByUIDBasic(CPACSTreeItem* wing, UID airfoilUID) {

    // element in this wing
    std::vector<CPACSTreeItem*> elements = wing->findAllChildrenOfTypeRecursively("element");

    UniqueXPath airfoilPathTemp;
    // update the element
    for(CPACSTreeItem* e : elements){
        airfoilPathTemp = e->getXPath();
        airfoilPathTemp.addParticleAtEnd("airfoilUID");
        modifier.setValue(airfoilPathTemp , airfoilUID);
    }

    closeTiglHandle();
    openTiglHandle(m_root->getUid());
}



//
std::map<cpcr::CPACSTreeItem *, std::vector<cpcr::CPACSTreeItem *> > cpcr::AircraftTree::getWingGraph(
        cpcr::CPACSTreeItem *wing) {

    std::map<CPACSTreeItem *, std::vector<CPACSTreeItem *>> graph;

    std::vector<CPACSTreeItem *> segments = wing->findAllChildrenOfTypeRecursively("segment");

    UID tempFromUID;
    UID tempToUID;
    CPACSTreeItem * tempFrom;
    CPACSTreeItem * tempTo;
    for(CPACSTreeItem* s : segments ){

        tempFromUID = modifier.retrieve<std::string>(s->getChild("fromElementUID")->getXPath(), "", true);
        tempToUID = modifier.retrieve<std::string>(s->getChild("toElementUID")->getXPath(), "", true);
        tempFrom = wing->getChildByUid(tempFromUID);
        tempTo = wing->getChildByUid(tempToUID);
        if(tempFrom == nullptr || tempTo == nullptr){
            throw CreatorException("AircraftTree::getWingGraph: element was not found!");
        }

        if( graph.count(tempFrom) == 0){
            graph[tempFrom] = std::vector<CPACSTreeItem*> ();
            graph[tempFrom].push_back(tempTo);
        } else {
            // check if the element exist
            if (std::find(graph[tempFrom].begin(), graph[tempFrom].end(), tempTo) == graph[tempFrom].end()) {
                graph[tempFrom].push_back(tempTo);
            }
        }
        if( graph.count(tempTo) == 0){
            graph[tempTo] = std::vector<CPACSTreeItem*> ();
            graph[tempTo].push_back(tempFrom);
        } else {
            if (std::find(graph[tempTo].begin(), graph[tempTo].end(), tempFrom) == graph[tempTo].end()) {
                graph[tempTo].push_back(tempFrom);
            }
        }

    }

    return graph;
}








std::vector<cpcr::CPACSTreeItem *>
cpcr::AircraftTree::formatGraph(std::map<CPACSTreeItem *, std::vector<CPACSTreeItem *> > wingGraph) {

    std::vector<CPACSTreeItem *> r; // a order list starting at the root and going to the tip

    CPACSTreeItem* root = nullptr;
    CPACSTreeItem* tip = nullptr;

    for(std::pair<CPACSTreeItem *, std::vector<CPACSTreeItem *>> p : wingGraph ){
        if(p.second.size() == 1){
            if(root == nullptr){
                root = p.first;
            }
            else if( tip == nullptr){
                tip = p.first;
            }
            else{
                throw CreatorException("AircrafTree:formatGraph: none standard detected (multiple ends)");
            }
        } else if( p.second.size() < 1){
            throw CreatorException("AircraftTree:formatGraph: none standard graph detected (unconnected)");
        } else if( p.second.size() > 2){
            throw CreatorException("AircraftTree:formatGraph: none standard graph detected (multiple branches)");
        }
    }

    if( tip == nullptr || root == nullptr) {
        throw CreatorException("AircraftTree::formatGraph: unexpected number of end");
    }

    // now there should be exactly 2 extremities and all others elements have 2 vertices
    // We set the root as the closest extremity of the x axis in the wing coordinates system

    CPACSTreeItem* wing = root->getParentOfType("wing");
    std::map<cpcr::UID, Eigen::Vector4d>  chordPoints = getChordPointsOfElements(wing->getUid(), 0.5);
    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTMI = wingT.getTransformationAsMatrix().inverse();

    Eigen::Vector4d rootP = wingTMI * chordPoints[root->getUid()] ;
    Eigen::Vector4d tipP =  wingTMI * chordPoints[tip->getUid()] ;

    double dRoot = pow(rootP(1),2) + pow(rootP(2),2); // distance in YZ plan
    double dTip = pow(tipP(1),2) + pow(tipP(2),2); // distance in YZ plan

    CPACSTreeItem* temp = nullptr ;
    if ( dRoot > dTip){
        temp = root;
        root = tip;
        tip = temp;
    }


    CPACSTreeItem* current = nullptr;
    CPACSTreeItem* next, *nextA, *nextB;
    std::set<CPACSTreeItem*> usedElements ; // to check previous and cycle

    next = root;
    while( next != nullptr ){

        current = next;
        r.push_back(current);
        usedElements.insert(current);

        if(wingGraph[current].size() == 1  ){
            next = wingGraph[current][0];
            if(usedElements.count(next) != 0){
                next = nullptr; // end case
            }
        }else if( wingGraph[current].size() == 2){

            nextA = wingGraph[current][0];
            nextB = wingGraph[current][1];

            if( usedElements.count(nextA) == 0 ){
                next = nextA;
            }
            else if(usedElements.count(nextB) == 0 ){
                next = nextB;
            }
            else{
                throw CreatorException("AircraftTree::formatGraph: unexpected graph");
            }
        }else {
            throw CreatorException("AircraftTree::formatGraph: unexpected graph");
        }
    }

    return r;
}




bool cpcr::AircraftTree::checkIfAirfoilsAreStandardizedForWing(UID wingUID) {


    CPACSProfilesDB db ;
    db.init(&modifier);

    std::vector<std::string> usedUids = getAllAirfoilsUIDInThisWing(wingUID);

    bool alreadyNormalized = true;
    for( std::string u : usedUids ){
        alreadyNormalized = alreadyNormalized && db.isNormalized[u];
    }

    return alreadyNormalized;
}





void cpcr::AircraftTree::airfoilsStandardizationForWing(UID wingUID) {

    CPACSProfilesDB db ;
    db.init(&modifier);

    std::vector<std::string> usedUids = getAllAirfoilsUIDInThisWing(wingUID);

    db.createAssociateNormalizedProfiles();

    CPACSTreeItem* element;
    for( std::string eUid : getAllElementUIDsUsedInAWing(wingUID) ){
        element = m_root->getChildByUid(eUid);
        std::string airfoilUID = modifier.retrieve<std::string>(element->getXPath().toString() + "/airfoilUID", "", true);

        if(!db.isNormalized[airfoilUID]){

            std::string newAirfoilUid = db.normalizedVersion[airfoilUID];

            std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> chain = getTransformationChainForOneElement(element);
            Eigen::Matrix4d elementM = chain[0].second;
            Eigen::Matrix4d newElementM = elementM * db.normalizationM[airfoilUID].inverse();
            CPACSTransformation newTransformation(newElementM);

            modifier.setValue<std::string>(element->getXPath().toString() + "/airfoilUID", newAirfoilUid);
            modifier.setTransformation(element->getXPath().toString() + "/transformation", newTransformation);

        }
    }

    writeToFile();
    closeTiglHandle();
    openTiglHandle(m_root->getUid());





}



bool cpcr::AircraftTree::checkIfWingTransformationIsStandardizedForWing(UID wingUID) {

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);

    cpcr::CPACSTransformation idealWingT = this->determineWingTransformation(wingUID); // the tree was rebuild -> the item has changed
    cpcr::CPACSTransformation currentWingT = this->modifier.getTransformation(wing->getXPath().toString() + "/transformation");

    bool simmilar = true;
    if( ! (idealWingT.getTranslation().toEigen().isApprox(currentWingT.getTranslation().toEigen(), 0.0001)) ){
        simmilar = false;
    }
    if( !(idealWingT.getRotation() == currentWingT.getRotation()) ){
        simmilar = false;
    }

    if( !(idealWingT.getScaling() == currentWingT.getScaling()) ){
        simmilar = false;
    }
    return simmilar ;
}




void cpcr::AircraftTree::setWingTransformation(UID wingUID,
                                               const cpcr::CPACSTransformation &newT) {

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);

    cpcr::CPACSTransformation oldT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");

    Eigen::Matrix4d oldM = oldT.getTransformationAsMatrix();
    Eigen::Matrix4d newWingM = newT.getTransformationAsMatrix();

    std::vector<UID> elementsUID = getAllElementUIDsUsedInAWing(wing->getUid());
    std::map<UID, Eigen::Matrix4d> globals ;
    std::map<UID, Eigen::Matrix4d> newElementsM ;


    Eigen::Matrix4d newWingMI = newWingM.inverse();

    for(UID uid : elementsUID){
        globals[uid] = getGlobalTransformMatrixOfElement(uid);
        newElementsM[uid] = newWingMI * globals[uid];    // Wnew Wnew^-1 G = G
    }

    modifier.setTransformation(wing->getXPath().toString() + "/transformation", newT);

    // remove all positioning
    modifier.clearPositionings(wing->getXPath().toString() + "/positionings");

    // set all section to identity
    CPACSTransformation identity ;
    identity.setRotation( Point(0,0,0));
    identity.setTranslation( Point(0,0,0));
    identity.setScaling( Point(1,1,1));
    for(CPACSTreeItem * section : wing->findAllChildrenOfTypeRecursively("section")){
        modifier.setTransformation(section->getXPath().toString() + "/transformation", identity);
    }

    // set the new position in element (and wing) only
    CPACSTransformation tempNewE;
    CPACSTreeItem* tempE;
    for(UID uid : elementsUID){
        tempE = wing->getChildByUid(uid);
        CPACSTransformation tempNewE(newElementsM[uid]);
        modifier.setTransformation(tempE->getXPath().toString() + "/transformation", tempNewE);
    }

    writeToFile();
    reBuild();

}

cpcr::CPACSTransformation cpcr::AircraftTree::determineWingTransformation(UID wingUID) {

    CPACSTransformation newTransformation;

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);

    double globalDihedral = getWingWorldDihedral(wing->getUid(), 0);
    if( fabs( globalDihedral )  > 45  ){
        newTransformation.setRotation(Point(90,0,0));
    }

    std::vector<cpcr::CPACSTreeItem *> elementsInGraphOrder = formatGraph( getWingGraph(wing) );
    CPACSTreeItem * root = elementsInGraphOrder[0];
    std::map< UID, Eigen::Vector4d> lEs = getChordPointsOfElements(wing->getUid(), 0);

    newTransformation.setTranslation(Point( lEs[root->getUid()](0)  ,lEs[root->getUid()](1), lEs[root->getUid()](2)) );

    return newTransformation;
}




void cpcr::AircraftTree::oneSectionOneElementStandardizationForWing(UID wingUID) {

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);

    std::vector< CPACSTreeItem *> sections = wing->findAllChildrenOfTypeRecursively("section");


    std::vector< CPACSTreeItem *> elements;
    for(CPACSTreeItem* s : sections){

        elements = s->findAllChildrenOfTypeRecursively("element");
        if (elements.size() == 0 ){

            LOG(WARNING) << "oneSectionOneElementStandardizationForWing: A section with no element was found -> we remove it.";
            tixi::TixiRemoveElement(modifier.getTixiHandle(), s->getXPath().toString() );

        }else{

            for( CPACSTreeItem * e : elements){
                if( e->getTixiIndex() == 1 ){ // we keep the first in the original section

                }else{

                    UID airfoilUID = modifier.retrieve<std::string>(e->getXPath().toString() + "/airfoilUID", "");
                    UID elementUID = e->getUid(); // element uid should stay the same for the segment
                    UID ETransformationUID = e->getChild("transformation")->getUid();
                    std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> chain = getTransformationChainForOneElement(e);

                    // make  section
                    UID newSectionUID = s->getUid() + "_bis" + std::to_string(e->getTixiIndex());
                    newSectionUID = modifier.makeUIDUnique(newSectionUID);
                    UniqueXPath newSectionX = modifier.createEmptySection(wing->getXPath().toString() + "/sections/section", newSectionUID);
                    modifier.setTransformation(newSectionX.toString() +"/transformation" , CPACSTransformation() ); // we set the transform of the section to identity

                    // set element
                    modifier.setUid(newSectionX.toString() + "/elements/element", elementUID);
                    modifier.setValue<std::string>(newSectionX.toString() + "/elements/element/airfoilUID", airfoilUID);
                    CPACSTransformation newE(  chain[2].second * chain[1].second * chain[0].second); // We set the position only in element
                    modifier.setTransformation(newSectionX.toString() + "/elements/element/transformation", newE);
                    if(ETransformationUID != ""){
                        modifier.setUid(newSectionX.toString() + "/elements/element/transformation", ETransformationUID);
                    }else{
                        ETransformationUID = elementUID + "_transformation1";
                        ETransformationUID = modifier.makeUIDUnique(ETransformationUID);
                    }


                    // remove section in the old section
                    tixi::TixiRemoveElement(modifier.getTixiHandle(), e->getXPath().toString());

                }

            }
        }
    }

    // need to be rebuild -> Carefull the treeItem would not be the same anymore!
    this->writeToFile();  // TODO: temp file or in memory build
    this->reBuild();


}

bool cpcr::AircraftTree::checkIfOneSectionOneElementForWing(UID wingUID) {

    bool r = true;
    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);
    std::vector< CPACSTreeItem *> sections = wing->findAllChildrenOfTypeRecursively("section");

    std::vector< CPACSTreeItem *> elements;
    for(CPACSTreeItem* s : sections){

        elements = s->findAllChildrenOfTypeRecursively("element");

        if( elements.size() == 1 ){
            // perfect
        }else if (elements.size() == 0 ) {
            LOG(INFO) << "checkIfOneSectionOneElementForWing: Section with 0 element found for wing: " + wing->getUid();
            r = false;
        }else if( elements.size() > 1) {
            LOG(INFO) << "checkIfOneSectionOneElementForWing: Section with more than 1 element found for wing: " + wing->getUid();
            r = false;
        }
    }

    return r;
}



void cpcr::AircraftTree::reBuild() {

    std::string filenameBu = fileName;
    UniqueXPath rootXBu = m_root->getXPath();
    this->build(filenameBu, rootXBu); // take care of cleaning
}



bool cpcr::AircraftTree::checkIfPositioningsAreStandardizedForWing(UID wingUID) {

    std::vector<CPACSTreeItem *> graph;

    std::map<CPACSTreeItem*, bool > pUsedByEIsStd;


    if(! checkIfOneSectionOneElementForWing(wingUID)){
        return false;
    }

    try{
        CPACSTreeItem* wing = m_root->getChildByUid(wingUID);
        graph = formatGraph( getWingGraph(wing) ) ;
    }catch (CreatorException e){
        return false;
    }


    std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> chainTemp;
    CPACSPositioning posTemp;
    Eigen::Vector3d translateTemp, zero;
    zero << 0,0,0;
    std::string currentSectionUID, previousSectionUID;
    previousSectionUID = "";


    for( CPACSTreeItem* e : graph){

        pUsedByEIsStd[e] = true;

        chainTemp = getTransformationChainForOneElement( e);

        translateTemp = chainTemp[0].second.block(0,3,3,1);
        if( ! translateTemp.isApprox(zero, 0.001) ){
            pUsedByEIsStd[e] = false;
        }

        translateTemp = chainTemp[1].second.block(0,3,3,1);
        if( ! translateTemp.isApprox(zero, 0.001) ){
            pUsedByEIsStd[e] = false;
        }

        currentSectionUID = chainTemp[1].first->getParent()->getUid();
        if(chainTemp[2].first == nullptr ){ // case where there is no positioning

            pUsedByEIsStd[e] = false;

        }else{

            posTemp = modifier.getPositioning(chainTemp[2].first->getXPath() );

            if(posTemp.getToSectionUID() != currentSectionUID ){
                pUsedByEIsStd[e] = false;
            }

            if(posTemp.getFromSectionUID() != previousSectionUID ){
                pUsedByEIsStd[e] = false;
            }
        }

        previousSectionUID = currentSectionUID;
    }

    bool r = true;
    for(CPACSTreeItem* e: graph){
        r = r && pUsedByEIsStd[e];
    }

    return r;
}





void cpcr::AircraftTree::positioningsStandardizationForWing(UID wingUID) {


    std::vector<cpcr::CPACSTreeItem *> graph;
    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);

    if(! checkIfOneSectionOneElementForWing(wingUID)){
        throw CreatorException("positioningsStandardizationForWing: required oneSectionOneElement in the wing!");
    }

    try{
        graph = formatGraph( getWingGraph(wing) ) ;
    }catch (CreatorException e){
        throw CreatorException("positioningsStandardizationForWing: required that the wing can be expressed into a standard graph!");
    }


    std::map< CPACSTreeItem*, std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> > chains;

    for( CPACSTreeItem* e : graph){
        chains[e] = getTransformationChainForOneElement( e);
    }

    modifier.clearPositionings(wing->getXPath().toString() + "/positionings");

    // SET THE ROOT ELEMENT AND SECTION ( NO POSITIONING FOR THE ROOT)
    CPACSPositioning newP;
    auto rootChain = chains[ graph[0] ] ;
    Eigen::Matrix4d rootM =  rootChain[2].second * rootChain[1].second * rootChain[0].second ; // all transform expect wing
    CPACSTransformation semiGlobalT(rootM);
    CPACSTransformation sectionT;
    CPACSTransformation elementT;
    // we set scaling in E and rotation  in S
    elementT.setScaling( semiGlobalT.getScaling() );
    sectionT.setRotation(semiGlobalT.getRotation());

    newP.setFromVector(semiGlobalT.getTranslation().toEigen());
    newP.setToSectionUID(rootChain[1].first->getParent()->getUid() );

    // we expect a null translation, but if not it's still okay
    if( ! IsApprox( newP.getLength(), 0) ){
        DLOG(WARNING) << "positioningsStandardizationForWing: normaly the root element should be set such that section LE match the wing coordinate";
    }

    modifier.setTransformation(rootChain[1].first->getXPath().toString() , sectionT );
    modifier.setTransformation(rootChain[0].first->getXPath().toString() , elementT);
    UniqueXPath newPX = modifier.createPositioning(rootChain[3].first->getParent()->getXPath().toString() + "/positionings/positioning", newP);
    UID newPUID = rootChain[3].first->getParent()->getUid() + "_positioning_" + rootChain[1].first->getParent()->getUid();
    newPUID = modifier.makeUIDUnique(newPUID);
    modifier.setUid(newPX, newPUID);
    modifier.setValue<std::string>(newPX.toString() + "/name", newPUID + " - auto generated by positioning standardization" );




    // SET THE OTHER ELEMENTS, POSITIONINGS AND SECTIONS
    Eigen::Vector3d previousSectionPosition = semiGlobalT.getTranslation().toEigen();
    UID previousSectionUID = rootChain[1].first->getParent()->getUid();
    Eigen::Vector3d delta;
    for( int i = 1; i < graph.size(); i++ ){

        auto chain = chains[ graph[i] ] ;


        Eigen::Matrix4d semiGlobalM =  chain[2].second * chain[1].second * chain[0].second ; // all transform expect wing
        CPACSTransformation semiGlobalT(semiGlobalM);

        // the scaling is set in element
        elementT.setScaling( semiGlobalT.getScaling() );
        elementT.setRotation(Point(0,0,0));
        elementT.setTranslation(Point(0,0,0));

        // the roation in section
        sectionT.setRotation(semiGlobalT.getRotation());
        sectionT.setTranslation(Point(0,0,0));
        sectionT.setScaling(Point(1,1,1));

        // the tanslation in positioning reltaive to the previous section
        delta =  semiGlobalT.getTranslation().toEigen() - previousSectionPosition;
        newP.setFromVector(delta);
        newP.setFromSectionUID(previousSectionUID);
        newP.setToSectionUID(chain[1].first->getParent()->getUid() );

        // set in memory
        modifier.setTransformation(chain[1].first->getXPath().toString() , sectionT );
        modifier.setTransformation(chain[0].first->getXPath().toString() , elementT);
        UniqueXPath newPX = modifier.createPositioning(chain[3].first->getParent()->getXPath().toString() + "/positionings/positioning", newP);
        UID newPUID = chain[3].first->getParent()->getUid() + "_positioning_" + chain[1].first->getParent()->getUid();
        newPUID = modifier.makeUIDUnique(newPUID);
        modifier.setUid(newPX, newPUID);
        modifier.setValue<std::string>(newPX.toString() + "/name", newPUID + " - auto generated by positioning standardization" );


        previousSectionUID = chain[1].first->getParent()->getUid();
        previousSectionPosition = semiGlobalT.getTranslation().toEigen();

    }


    // need to be rebuild -> Carefull the treeItem would not be the same anymore!
    this->writeToFile();  // TODO: temp file or in memory build
    this->reBuild();


}




void cpcr::AircraftTree::completeStandardizationForWing(cpcr::UID wingUID) {

    // normalize airfoil

    LOG(INFO) << "STARTING: CREATOR STANDARDIZATION FOR WING: " + wingUID ;
    LOG(INFO) << "Airfoils phase:";
    if( this->checkIfAirfoilsAreStandardizedForWing(wingUID)){
        LOG(INFO) << " - The airfoils are already conform to the creator standard";
    }else{
        LOG(INFO) << " - Airfoils will be standardized";
        this->airfoilsStandardizationForWing(wingUID);
    }

    LOG(INFO) << "One Section One Element phase:";
    if( this->checkIfOneSectionOneElementForWing(wingUID)){
        LOG(INFO) << " - The wing has already one section per elements";
    }else{
        LOG(INFO) << " - One section one element standardization will be performed";
        this->oneSectionOneElementStandardizationForWing(wingUID);
    }

    // standardize wing transform
    LOG(INFO) << "Wing transformation phase:";
    if( checkIfWingTransformationIsStandardizedForWing(wingUID) ) {
        LOG(INFO) << " - The wing transformation is already conform to the creator standard";
    }else{
        LOG(INFO) << " - The wing transformation will be standardized";
       wingTransformationStandardization(wingUID);
    }


    LOG(INFO) << "Positionings phase:";
    if(checkIfPositioningsAreStandardizedForWing(wingUID) ){
        LOG(INFO) << " - The positionings are already conform to the creator standard\"";
    }else{
        LOG(INFO) << " - Postionings will be standardized";
        this->positioningsStandardizationForWing(wingUID);
    }


    LOG(INFO) << "END: CREATOR STANDARDIZATION FOR WING: " + wingUID ;
}



bool cpcr::AircraftTree::isWingStandardized(cpcr::UID wingUID) {

    bool r = true;
    CPACSTreeItem * wing = m_root->getChildByUid(wingUID);

    r = r && checkIfAirfoilsAreStandardizedForWing(wingUID);
    r = r && checkIfOneSectionOneElementForWing(wingUID);
    r = r && checkIfWingTransformationIsStandardizedForWing(wingUID);
    r = r && checkIfPositioningsAreStandardizedForWing(wingUID);

    return r;
}


cpcr::UID cpcr::AircraftTree::getRootOfWing(cpcr::CPACSTreeItem *wing) {

    UID rootUID = "";
    try {

        rootUID = formatGraph( getWingGraph(wing) )[0]->getUid() ; // Here is the core of the expected case

    }catch (CreatorException &e){

        LOG(WARNING) << "The wing can not be represented as a standard graph";
        // in this case we return the element the closest element of the x asis of the wing coordinates system
        std::map<cpcr::UID, Eigen::Vector4d>  chordPoints = getChordPointsOfElements(wing->getUid(), 0.5);

        CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
        Eigen::Matrix4d wingTMI = wingT.getTransformationAsMatrix().inverse();

        Eigen::Vector4d temp;
        double dMin, dTemp;
        dMin =  std::numeric_limits<double>::max();
        for(std::pair<cpcr::UID, Eigen::Vector4d> p : chordPoints ){
            temp = wingTMI * p.second;
            dTemp = pow(temp(1),2) + pow(temp(2),2);
            if( dTemp <  dMin){
                dMin = dTemp;
                rootUID = p.first;
            }
        }



    }

    return rootUID;
}

cpcr::UID cpcr::AircraftTree::getExtremityInY(cpcr::UID rootUID, std::map<cpcr::UID, Eigen::Vector4d> pretenders) {

    UID extremity ;
    Eigen::Vector4d rootP = pretenders[rootUID];

    double dMax, dTemp;
    dMax =  -1;

    for(std::pair<cpcr::UID, Eigen::Vector4d> p : pretenders ){
        dTemp = fabs( rootP(1) - p.second(1) ) ;
        if( dMax < dTemp){
            dMax = dTemp;
            extremity = p.first;
        }
    }
    return extremity;
}



double cpcr::AircraftTree::getWingSpan(cpcr::UID wingUID, double chordPercent) {

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);


    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wingUID);
    std::map<UID, Eigen::Vector4d> chordPoints = getChordPointsOfElements(wingUID, chordPercent);
    std::map<UID, Eigen::Vector4d> chordPointsM = getChordPointsOfElements(wingUID, 0.5);

    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();

    // We transform all the chord point to work in the wing system !
    for (UID u : elementUIDs ){
        chordPointsM[u] = wingTMI * chordPointsM[u];
        chordPoints[u] = wingTMI * chordPoints[u];
    }

    UID rootUID = getRootOfWing(wing);
    UID extremityUID = getExtremityInY(rootUID, chordPointsM);


    // get the segment from min to max
    Eigen::Vector4d rootToExtremity = chordPoints[extremityUID] - chordPoints[rootUID];

    return rootToExtremity[1];
}


double cpcr::AircraftTree::getSegmentArea(cpcr::CPACSTreeItem *segmentItem, PLANE plane) {

    CPACSTreeItem* wing = segmentItem->getParentOfType("wing");


    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();

    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wing->getUid());
    std::map<cpcr::UID, Eigen::Vector4d> LEPoints = getChordPointsOfElements(wing->getUid(), 0);
    std::map<cpcr::UID, Eigen::Vector4d> TEPoints = getChordPointsOfElements(wing->getUid(), 1);

    CPACSSegment segment = modifier.getSegment(segmentItem->getXPath());

    // We transform all the chord point to work in the wing system !
    for (UID u : elementUIDs ){
        LEPoints[u] = wingTMI * LEPoints[u];
        TEPoints[u] = wingTMI * TEPoints[u];
    }

    Eigen::Vector4d a = TEPoints[segment.getToElementUID() ] - LEPoints[segment.getFromElementUID()];
    Eigen::Vector4d b = TEPoints[segment.getFromElementUID() ] - LEPoints[segment.getToElementUID()];

    Eigen::Vector3d aP, bP;
    if(plane == PLANE::XY_PLANE){
        aP << a[0], a[1],0;
        bP << b[0], b[1],0;
    } else if( plane == PLANE::XZ_PLANE){
        aP << a[0],0, a[2];
        bP << b[0],0, b[2];
    } else if ( plane == PLANE::YZ_PLANE){
        aP << 0, a[1], a[2];
        bP << 0, b[1], b[2];
    } else if (plane == PLANE::NO_PLANE){
        aP << a[0], a[1], a[2];
        bP << b[0], b[1], b[2];
    } else {
        throw CreatorException("getSegmentArea: invalid or unkown PLANE given");
    }

    double area = 0.5 * (aP.cross(bP).norm());

    return area;
}

double cpcr::AircraftTree::getWingPlanformArea(cpcr::UID wingUID, cpcr::PLANE plane) {

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);
    std::vector<CPACSTreeItem *> segments = wing->findAllChildrenOfTypeRecursively("segment");

    double totalArea = 0;
    for( CPACSTreeItem* s : segments){
        totalArea += this->getSegmentArea(s, plane);
    }

    return totalArea;


}

double cpcr::AircraftTree::getWingAR(cpcr::UID wingUID) {

    double area = getWingPlanformArea(wingUID, XY_PLANE);
    double span = getWingSpan(wingUID);

    double ar = pow(span, 2) / area;

    return ar;
}



void cpcr::AircraftTree::setWingSpanKeepAR(cpcr::UID wingUID, double newSpan) {

    double aR = getWingAR(wingUID);

    // uniform scaling
    double oldSpan = getWingSpan(wingUID);
    double s = newSpan/oldSpan;

    scaleWingUniformly(wingUID, s);

    double newAR = getWingAR(wingUID);
    if(! IsApprox(aR, newAR) ){
        DLOG(WARNING) << "setWingSpanKeepAR: The AR is not properly keeped";
    }



}


void cpcr::AircraftTree::setWingSpanKeepArea(cpcr::UID wingUID, double newSpan) {

    double area = getWingPlanformArea(wingUID, XY_PLANE);

    // first we set the span by uniform scaling
    setWingSpanKeepAR(wingUID,newSpan);
    // then we set the correct area
    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);
    setWingAreaKeepLeadingEdges(wing, area);

}


void cpcr::AircraftTree::setWingSymmetry(cpcr::UID wingUID, std::string symmetry) {

    CPACSTreeItem * wing = m_root->getChildByUid(wingUID);

    modifier.setSymmetry(wing->getXPath(), symmetry);

}

std::string cpcr::AircraftTree::getWingSymmetry(cpcr::UID wingUID) {

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);

    return modifier.getSymmetry(wing->getXPath());

}

void cpcr::AircraftTree::wingTransformationStandardization(cpcr::UID wingUID) {

    cpcr::CPACSTransformation idealWingT = this->determineWingTransformation(wingUID);
    this->setWingTransformation(wingUID, idealWingT);


    this->writeToFile();  // TODO: temp file or in memory build
    this->reBuild();

    return;
}



void cpcr::AircraftTree::placeElementMinimalChanges(cpcr::CPACSTreeItem *element, Eigen::Matrix4d globalM) {

    std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> chain = getTransformationChainForOneElement(element);
    Eigen::Matrix4d newElementM = chain[1].second.inverse() * chain[2].second.inverse() * chain[3].second.inverse() * globalM;
    CPACSTransformation newElementT(newElementM);
    modifier.setTransformation(element->getXPath().toString() + "/transformation", newElementT);
}


void cpcr::AircraftTree::placeElementRespectStd(cpcr::CPACSTreeItem *element, Eigen::Matrix4d globalM) {

    std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> chain = getTransformationChainForOneElement(element);

    if(chain[2].first == nullptr){
        throw CreatorException("placeElementRespectStd: impossible to place element " + element->getUid()  +
                                       " respecting creator standard, because positioning is null.");
    }

    Eigen::Matrix4d newSemiG = chain[3].second.inverse() * globalM;
    CPACSTransformation newSemiT(newSemiG);

    CPACSTransformation newElementT ;
    newElementT.setScaling( newSemiT.getScaling() );
    modifier.setTransformation(chain[0].first->getXPath(), newElementT);


    CPACSTransformation newSectionT ;
    newSectionT.setRotation( newSemiT.getRotation() );
    modifier.setTransformation(chain[1].first->getXPath(), newSectionT);

    // for the positioning, we need first to define the effect of the other positioning on this particular positioning
    CPACSPositioning oldParticularP = modifier.getPositioning(chain[2].first->getXPath());
    Eigen::Matrix4d dependancePM = chain[2].second -oldParticularP.getPositioningAsMatrix();    // This give us the effect of the previous positionings
    Eigen::Vector3d newPV = newSemiT.getTranslation().toEigen() - dependancePM.block(0,3,3,1);
    CPACSPositioning newP = oldParticularP;
    newP.setFromVector(newPV);
    modifier.setPositioning(chain[2].first->getXPath(), newP);

}


void cpcr::AircraftTree::placeElement(cpcr::CPACSTreeItem *element, Eigen::Matrix4d globalM) {

    CPACSTreeItem * wing = element->getParentOfType("wing");

    if( checkIfOneSectionOneElementForWing(wing->getUid()) && checkIfPositioningsAreStandardizedForWing(wing->getUid()) ){
        placeElementRespectStd(element, globalM);
    }else {
        placeElementMinimalChanges(element, globalM);
    }

}

double cpcr::AircraftTree::findChordXYScaleFactor(CPACSTreeItem *wing, double targetArea) {

    // get chords
    std::vector<cpcr::CPACSTreeItem *> graph = formatGraph(getWingGraph(wing)) ;

    std::map< UID, Eigen::Vector4d>  lEsMap = getChordPointsOfElements(wing->getUid(), 0 );
    std::map< UID, Eigen::Vector4d>  tEsMap = getChordPointsOfElements(wing->getUid(), 1 );

    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTIM = wingT.getTransformationAsMatrix().inverse();

    std::vector<Eigen::Vector3d>  LEs;
    std::vector<Eigen::Vector3d>  TEs;

    Eigen::Vector3d lXY;
    Eigen::Vector3d tXY;



    for(CPACSTreeItem* e : graph){
        lXY = ( wingTIM *lEsMap[e->getUid()]).block(0,0,3,1);
        lXY(2) = 0;
        LEs.push_back(lXY);
        tXY = ( wingTIM * tEsMap[e->getUid()]).block(0,0,3,1);
        tXY(2) = 0;
        TEs.push_back(tXY);
    }


    int segmentNum = LEs.size() - 1;
    if (segmentNum < 1){
        LOG(ERROR) << "findChordXYScaleFactor: input incorrect";
        return -1;
    }


    // find quartic vectors
    Eigen::Vector3d v;
    v << 0,0,0;
    Eigen::Vector3d w;
    w << 0,0,0;
    Eigen::Vector3d a,b,c,v_temp,w_temp;
    int j,h;

    for(int i = 0; i < segmentNum; i++){

        j = i;
        h = i + 1;

        if( LEs[j](1) > LEs[h](1)    ){ // to get the area in the same direction
            j = i + 1;
            h = i;
        }
        a = LEs[h] - LEs[j];
        b = TEs[j] - LEs[j];
        c = TEs[h] - LEs[h];

        v_temp = (c + b ).cross(a);
        w_temp = b.cross(c);

        // v and w should be only describe on z since a,b,c lay on the XY plane
        if( (!IsApprox(v_temp(0),0)) && (!IsApprox(v_temp(1),0)) && (!IsApprox(w_temp(0),0)) && (!IsApprox(w_temp(1),0))  ){
            LOG(WARNING) << "findChordXYScaleFactor: some  v or w is not only on Z";
        }

        v = v + v_temp;
        w = w + w_temp;


    }

    double E = powf(v(0),2) + powf(v(1),2) + powf(v(2),2);
    double F = 2*v(0)*w(0) + 2*v(1)*w(1)  + 2*v(2)*w(2)  ;
    double G = powf(w(0),2) + powf(w(1),2) + powf(w(2),2);

    // case where the chord are parallel
    if( IsApprox(G, 0, 0.01)){
        return sqrt( powf((2*targetArea),2) / E );
    }


    // other cases -> solve quatric equation

    double area = -powf((2*targetArea),2)/G;
    E = E/G;
    F = F/G;

    double roots [4] = {-1,-1,-1,-1};
    double r = SolveP4(roots, F, E, 0, area);

    LOG(INFO) << "findChordXYScaleFactor roots" << roots[0] << ";" << roots[1] << ";" << roots[2] << ";"<< roots[3] << ";";

    double d = -1;

    if (r == 0){
        LOG(ERROR) << "findChordXYScaleFactor: only complex factor found";
        throw CreatorException("findChordXYScaleFactor: only complex factor found");
    }
    else if ( r == 2 ){
        double arrayTemp [2] = {roots[0],roots[1]};
        std::sort(arrayTemp, arrayTemp + 2);    // sort so the smaller positive  values is taken
        if ( arrayTemp[0] > 0){
            d = arrayTemp[0];
        }else if ( arrayTemp[1] > 0 ) {
            d = arrayTemp[1];
        }else{
            throw CreatorException("findChordXYScaleFactor: no positive factor found");
        }
    }
    else if ( r == 4 ) {
        std::sort(roots, roots + 4); // sort so the smaller positive  values is taken
        if ( roots[0] > 0 ){
            d = roots[0];
        }else if ( roots[1] > 0 ) {
            d = roots[1];
        } else if (roots[2] > 0 ){
            d = roots[2];
        } else if (roots[3] > 0 ){
            d = roots[3];
        }
        else{
            throw CreatorException("findChordXYScaleFactor: no positive factor found");
        }

    }

    return d;
}

void cpcr::AircraftTree::setWingAreaKeepLeadingEdges(cpcr::CPACSTreeItem *wing, double area) {

    // get scaling
    double f = findChordXYScaleFactor(wing, area);


    // get chords
    std::vector<cpcr::CPACSTreeItem *> graph = formatGraph(getWingGraph(wing)) ;

    std::map< UID, Eigen::Vector4d>  lEsMap = getChordPointsOfElements(wing->getUid(), 0 );
    std::map< UID, Eigen::Vector4d>  tEsMap = getChordPointsOfElements(wing->getUid(), 1 );

    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();




    Eigen::Vector4d sensor1, sensor2, sensor3, sensor1P, sensor2P, sensor3P , sensorN , newTEA;
    CPACSTransformation tempNewTransformationE ;


    Eigen::Vector3d lE, tE, newTE, newDelta;
    double deltaX, deltaY, deltaZ, newDeltaX, newDeltaY, newDeltaZ, normXY, newNormXY,  ratio; // ratio between xy and  z
    Eigen::Matrix4d globalM, globalMI, allExpectE, allExpectEI;
    UniqueXPath tempXPath;
    UID uid;
    std::vector<std::pair<cpcr::CPACSTreeItem *, Eigen::Matrix4d>> chain;

    // For each element find out the good transformation for element to do the shearing
    for (CPACSTreeItem*  e :graph ) {
        uid = e->getUid();
        chain = getTransformationChainForOneElement(e);
        allExpectE = chain[3].second * chain[2].second * chain[1].second;
        allExpectEI = allExpectE.inverse();

        // compute the new TE base ont the scale factor
        lE = ( wingTMI *lEsMap[uid]).block(0,0,3,1);
        tE = ( wingTMI *tEsMap[uid]).block(0,0,3,1);
        deltaX = tE(0) -lE(0);
        deltaY = tE(1) -lE(1);
        deltaZ = tE(2) -lE(2);
        normXY = sqrt( pow(deltaX,2) +  pow(deltaY,2) );
        ratio = deltaZ / normXY ;
        newDeltaX = f * deltaX;
        newDeltaY = f * deltaY;
        newNormXY = sqrt( pow(newDeltaX,2) +  pow(newDeltaY,2) );
        newDeltaZ = ratio * newNormXY;
        newDelta << newDeltaX,newDeltaY,newDeltaZ;
        newTE = lE + newDelta;  // in wing coor
        newTEA << newTE(0), newTE(1), newTE(2), 1;
        newTEA = wingTM * newTEA;

        globalM = getGlobalTransformMatrixOfElement(e->getUid());
        globalMI = globalM.inverse();

        sensor1 = globalMI * lEsMap[uid]; // give the point in the airfoil sys
        sensor2 = globalMI * tEsMap[uid];
        sensorN << 0,1,0,1 ; // sensor 1 and sensor 2 should be on the XZ-plane, because they are airfoil // todo test?
        sensor3.block<3,1>(0,0) = sensor1.block<3,1>(0,0) +  (sensorN.block<3,1>(0,0)).cross((sensor2-sensor1).block<3,1>(0,0)); // create a vector perpendicular at s1 s2 on the XZ-plane
        sensor3(3) = 1;  // set the augmented component;
        sensor1P = allExpectEI * lEsMap[uid]; // Leading edge dos not change
        sensor2P = allExpectEI * newTEA;
        sensor3P =  sensor3;

        tempNewTransformationE = TransformChord(sensor1, sensor2, sensor3, sensor1P, sensor2P, sensor3P);
        tempXPath = UniqueXPath(e->getXPath());
        tempXPath.addParticleAtEnd("transformation");
        modifier.setTransformation(tempXPath,tempNewTransformationE ); // save the result in memory
    }

    // update tigl handle // TODO check if is the correct method to maintain tigl and aircraft sychronous
    closeTiglHandle();
    openTiglHandle(m_root->getUid());



}

void cpcr::AircraftTree::setWingAreaKeepSpan(cpcr::UID wingUID, double newArea) {

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);
    setWingAreaKeepLeadingEdges(wing, newArea);


}

void cpcr::AircraftTree::setWingAreaKeepAR(cpcr::UID wingUID, double newArea) {

    double oldArea = getWingPlanformArea(wingUID, XY_PLANE);
    double scaleFactorA = newArea / oldArea;
    double scaleFactor = sqrt(scaleFactorA); // area is power 2

    scaleWingUniformly(wingUID, scaleFactor);


}

void cpcr::AircraftTree::scaleWingUniformly(cpcr::UID wingUID, double s) {

    Eigen::Matrix4d sM = Eigen::Matrix4d::Identity();

    sM(0,0) = s;
    sM(1,1) = s;
    sM(2,2) = s;

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);
    CPACSTransformation wingT = modifier.getTransformation(wing->getXPath().toString() + "/transformation");
    Eigen::Matrix4d wingTM = wingT.getTransformationAsMatrix();
    Eigen::Matrix4d wingTMI = wingTM.inverse();

    std::vector<UID> elementUIDs = getAllElementUIDsUsedInAWing(wingUID);
    std::map<UID, Eigen::Matrix4d> newGlobals ;

    for( UID uid : elementUIDs){
        newGlobals[uid] = wingTM *  sM *  wingTMI * getGlobalTransformMatrixOfElement(uid) ;
        placeElementMinimalChanges(m_root->getChildByUid(uid), newGlobals[uid]);
    }


    // update tigl handle // TODO check if is the correct method to maintain tigl and aircraft sychronous
    closeTiglHandle();
    openTiglHandle(m_root->getUid());

}



void cpcr::AircraftTree::setWingARKeepSpan(cpcr::UID wingUID, double AR) {

    double span = getWingSpan(wingUID, 0 );
    double newArea = pow(span,2)/AR;

    CPACSTreeItem* wing = m_root->getChildByUid(wingUID);
    setWingAreaKeepLeadingEdges(wing, newArea);

}

void cpcr::AircraftTree::setWingARKeepArea(cpcr::UID wingUID, double AR) {

    double area = getWingPlanformArea(wingUID, XY_PLANE);
    double newSpan = sqrt(AR * area);

    setWingSpanKeepArea(wingUID, newSpan);

}








