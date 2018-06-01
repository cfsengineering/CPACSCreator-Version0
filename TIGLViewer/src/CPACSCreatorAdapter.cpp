//
// Created by cfse on 3/20/18.
//

#include "CPACSCreatorAdapter.h"

#include "CPACSCreatorLib/CPACSTransformation.h"

#include "CPACSCreatorLib/CPACSTreeItem.h"





void CPACSCreatorAdapter::setSweepAngle(cpcr::CPACSTreeItem *item, double angle, double chordPercent) {
    if( ! testItem(item, "wing") )
        return ;

    aircraftTree.setWingSweepByShearing(item->getUid(), angle, chordPercent);
    aircraftTree.writeToFile();
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
    aircraftTree.writeToFile();

    LOG(INFO) << "Set transformation Values for xPath: ";

}


bool CPACSCreatorAdapter::testItem(cpcr::CPACSTreeItem *item, cpacsType type) {

    bool pass = true;
    if (item == nullptr){
        LOG(WARNING) << "Adapter receive null pointer item";
        pass = false;
    }
    if(item->getType() != type)  {
        LOG(WARNING) << "Adapter receive incorect type";
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

