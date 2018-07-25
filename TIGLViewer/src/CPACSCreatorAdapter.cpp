//
// Created by cfse on 3/20/18.
//

#include "CPACSCreatorAdapter.h"

#include "CPACSCreatorLib/CPACSTransformation.h"

#include "CPACSCreatorLib/CPACSTreeItem.h"

#include "TIGLViewerException.h"


CPACSCreatorAdapter::CPACSCreatorAdapter(ProfilesDBManager *profilesDBManager) {
    profilesDB = profilesDBManager;
}


double CPACSCreatorAdapter::getDihedralAngle(cpcr::CPACSTreeItem *item, double chordPercent) {

    double angle = -1;
    if( ! testItem(item, "wing") )
        return angle;

    angle = aircraftTree.getWingDihedral(item->getUid(), chordPercent);
    return angle;
}


void CPACSCreatorAdapter::setDihedralAngle(cpcr::CPACSTreeItem *item, double angle, double chordPercent) {
    if( ! testItem(item, "wing") )
        return;
    aircraftTree.setWingDihedral(item->getUid(), angle, chordPercent);
}


void CPACSCreatorAdapter::setSweepAngle(cpcr::CPACSTreeItem *item, double angle, double chordPercent, QString method) {
    if( ! testItem(item, "wing") )
        return ;

    if(method == "Translation"){
        aircraftTree.setWingSweepByTranslation(item->getUid(), angle, chordPercent);
    }
    else if( method == "Shearing"){
        aircraftTree.setWingSweepByShearing(item->getUid(), angle, chordPercent);
    }else {
        throw TIGLViewerException("ADAPTER: setSweepAngle: unknown method given");
    }

    return;
}



double CPACSCreatorAdapter::getSweepAngle(cpcr::CPACSTreeItem *item, double chordPercent) {

    double angle = -1;
    if( ! testItem(item, "wing") )
        return angle;

    angle = aircraftTree.getWingSweep(item->getUid(), chordPercent);
    return angle;

}

cpcr::CPACSTransformation CPACSCreatorAdapter::getTransformation(cpcr::CPACSTreeItem *item) {
    cpcr::CPACSTransformation r;
    if( ! testItem(item, "transformation") )
        return r;

    r = aircraftTree.getModifier()->getTransformation(item->getXPath());
    return r;
}


void CPACSCreatorAdapter::setTransformation(cpcr::CPACSTreeItem *item, cpcr::CPACSTransformation transformation) {

    // TODO MODIFIER A LITTEL WIRD
    aircraftTree.getModifier()->setTransformation(item->getXPath(), transformation);
    LOG(INFO) << "Set transformation Values for xPath: ";

}


bool CPACSCreatorAdapter::testItem(cpcr::CPACSTreeItem *item, cpacsType type) {

    bool pass = true;
    if (item == nullptr){
        LOG(WARNING) << "Adapter receive null pointer item";
        pass = false;
    }
    if(item->getType() != type)  {
        LOG(WARNING) << "Adapter receive incorrect type";
        pass = false;
    }
    return pass;
}



void CPACSCreatorAdapter::close() {
    QMutexLocker locker(&mutex);
    aircraftTree.close();
}



void CPACSCreatorAdapter::resetCpacsConfig(const TIGLViewerDocument& doc) {
    QMutexLocker locker(&mutex); // ensure that the tree is not accessed during the creation

    // Check if the new document is valid
    if(!doc.isConfigurationValid()){
        aircraftTree.close();
        return;
    }

    // check rotorcraft
    tigl::CCPACSConfiguration& config = doc.GetConfiguration();
    if( config.IsRotorcraft() ){
        std::cout << "Rotorcraft is not supported by the tree viewer" << std::endl;
        return;
    }


    // todo: allow multiple model selection
    std::string rootXPath = "/cpacs/vehicles/aircraft/model[1]";

    aircraftTree.build(doc.getLoadedDocumentFileName().toStdString(), rootXPath );  // the build function take care to clean the old one
    return;

}

cpcr::CPACSTreeItem* CPACSCreatorAdapter::getRoot()const {

    QMutexLocker locker(&mutex); // ensure that the tree is not accessed during the creation
    cpcr::CPACSTreeItem* root = aircraftTree.getRoot();
    return root;
}



bool CPACSCreatorAdapter::isValid() {
    return aircraftTree.isBuild();
}


double CPACSCreatorAdapter::getWingArea(cpcr::CPACSTreeItem *item, cpcr::PLANE plane) {
    double area = -1;
    if( ! testItem(item, "wing")){
        return area;
    }
    else{
        area = aircraftTree.getWingPlanformArea(item->getUid(), plane);
    }
    return area;
}


QStringList CPACSCreatorAdapter::getAirfoilsUid() {
    QStringList r;
    std::vector<std::string> uids = aircraftTree.getModifier()->getAirfoilsUid();

    for(std::string uid : uids){
        r.push_back( QString(uid.c_str()) );
    }
    return r;

}



QString CPACSCreatorAdapter::getAirfoilValueForWing(cpcr::CPACSTreeItem *item) {

    QString r = profilesDB->noneAirfoil;
    if( ! testItem(item, "wing")){
        return r ;
    }
    std::vector<std::string> uids = aircraftTree.getAllAirfoilsUIDInThisWing(item->getUid());

    if(uids.size() < 1){
        return r;
    }

    if(uids.size() >= 2 ){
        r = profilesDB->multipleAirfoilsInUse;
        return r;
    }

    r = uids[0].c_str() + profilesDB->suffixForInFile;
    return r;
}

void CPACSCreatorAdapter::setAllAirfoilsInWing(cpcr::CPACSTreeItem *item, QString airfoil) {
    if( ! testItem(item, "wing") )
        return ;

    if (! profilesDB->idIsValid(airfoil)){
        throw TIGLViewerException("Trying to set a invalid airfoil");
    }

    if (profilesDB->idIsDBID(airfoil) ){
        std::string path = profilesDB->getPathForDBAirfoil(airfoil).toStdString();
        aircraftTree.setWingAirfoilsFromExternalFile(item->getUid(), path);
    }
    else if (profilesDB->idIsCPACSID(airfoil)) {
        aircraftTree.setWingAirfoilsByUID(item->getUid(), profilesDB->getIdWithoutSuffix(airfoil).toStdString() );
    } else {
        throw  TIGLViewerException("Unexpected airfoil case");
    }



}

void CPACSCreatorAdapter::writeToFile() {
    if(isValid()){
        aircraftTree.writeToFile();
    }

}


std::list<std::pair<cpcr::CPACSTreeItem*, cpcr::CPACSPositioning >>  CPACSCreatorAdapter::getPositionings(cpcr::CPACSTreeItem * item) {

    std::list<std::pair<cpcr::CPACSTreeItem*, cpcr::CPACSPositioning >> positionings;

    if(! testItem(item, "positionings")){
        return positionings;
    }

    cpcr::CPACSPositioning posTemp;
    for(cpcr::CPACSTreeItem* e : item->findAllChildrenOfTypeRecursively("positioning")){
        posTemp = aircraftTree.getModifier()->getPositioning(e->getXPath());
        positionings.push_back(std::pair<cpcr::CPACSTreeItem*, cpcr::CPACSPositioning >(e,posTemp));
    }

    positionings.sort(
            [](const std::pair<cpcr::CPACSTreeItem*, cpcr::CPACSPositioning >& p1,
               const std::pair<cpcr::CPACSTreeItem*, cpcr::CPACSPositioning >& p2)
            {return p1.first->getTixiIndex() <= p2.first->getTixiIndex(); });

    return positionings;

}

void CPACSCreatorAdapter::setPositioning(cpcr::CPACSTreeItem *item, cpcr::CPACSPositioning newPositioning) {

    if(! isValid()){
        return;
    }

    if(! testItem(item, "positioning")){
        return ;
    }
    aircraftTree.getModifier()->setPositioning(item->getXPath(), newPositioning );
}

double CPACSCreatorAdapter::getWingSpan(cpcr::CPACSTreeItem *item){
    double span = -1;
    if( ! testItem(item, "wing")){
        return span;
    }
    span = aircraftTree.getWingSpan(item->getUid());
    return span;
}

double CPACSCreatorAdapter::getWingAR(cpcr::CPACSTreeItem *item) {
    double aR = -1;
    if( ! testItem(item, "wing")){
        return aR;
    }
    aR = aircraftTree.getWingAR(item->getUid());
    return aR;
}



void
CPACSCreatorAdapter::getAnchorValues(cpcr::CPACSTreeItem *item, double &x, double &y, double &z, QString &orientation) {

    if( ! testItem(item, "wing")){
        return ;
    }
    cpcr::CPACSTransformation wingT = getTransformation(item->getChild("transformation") ) ;

    x = wingT.getTranslation().x;
    y = wingT.getTranslation().y;
    z = wingT.getTranslation().z;

    if( wingT.getRotation() == cpcr::Point(0,0,0)){
        orientation = "XY-Plane";
    }else if(wingT.getRotation() == cpcr::Point(90,0,0) ){
        orientation = "XZ-Plane";
    }else {
        orientation = "Custom";
    }

    if( (!( wingT.getScaling() == cpcr::Point(1,1,1)))  || orientation == "Custom"  ){
        DLOG(INFO) << "getAnchorValues: None standard anchor detected for wing:" + item->getUid();
    }

}

void
CPACSCreatorAdapter::setAnchorValues(cpcr::CPACSTreeItem *item, double x, double y, double z, QString orientation) {

    if( ! testItem(item, "wing")){
        return ;
    }
    cpcr::CPACSTransformation wingT = getTransformation(item->getChild("transformation") ) ;
    wingT.setTranslation(cpcr::Point(x,y,z));
    if(orientation == "XY-Plane"){
        wingT.setRotation(cpcr::Point(0,0,0));
    }else if( orientation == "XZ-Plane"){
        wingT.setRotation(cpcr::Point(90,0,0));
    }else if( orientation == "Custom"){
        LOG(WARNING) << "setAnchorValues: orientation is custom -> no change in orientation will be performed";
    }

    if( (!( wingT.getScaling() == cpcr::Point(1,1,1)))  ){
        DLOG(INFO) << "setAnchorValues:: None standard anchor detected for wing:" + item->getUid() + ". Consider to standardize the anchor.";
    }

    setTransformation(item->getChild("transformation"), wingT);

}

void
CPACSCreatorAdapter::getStdValues(cpcr::CPACSTreeItem *item, bool &stdAirfoil, bool &stdSections, bool &stdPositionings,
                                  bool &stdAnchor) {


    if( ! testItem(item, "wing")){
        return ;
    }

    stdSections = aircraftTree.checkIfOneSectionOneElementForWing(item);
    stdAirfoil = aircraftTree.checkIfAirfoilsAreStandardizedForWing(item);
    stdPositionings = aircraftTree.checkIfPositioningsAreStandardizedForWing(item);
    stdAnchor = aircraftTree.checkIfWingTransformationIsStandardizedForWing(item);
}
