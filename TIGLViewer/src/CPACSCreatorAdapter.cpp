//
// Created by cfse on 3/20/18.
//

#include "CPACSCreatorAdapter.h"

#include "CPACSCreatorLib/CPACSTransformation.h"

#include "CPACSCreatorLib/CPACSTreeItem.h"



cpcr::CPACSTransformation CPACSCreatorAdapter::getTransformation(cpcr::CPACSTreeItem *item) {

    cpcr::CPACSTransformation r;
    if (item == nullptr){
        LOG(WARNING) << "getTansform incorrect input";
        return r;
    }
    if(item->getType() != "transformation"){
        LOG(WARNING) << "getTansform incorrect input";
        return r;
    }

    r = aircraftTree.getModifier()->getTransformation(item->getXPath());
    return r;
}


void CPACSCreatorAdapter::setTransformation(QString xpath, cpcr::CPACSTransformation transformation) {

    std::string xpathStd = xpath.toStdString();

    //aircraftTree.getModifier()->setTransformation(xpathStd, transform);
    //aircraftTree.writeToFile();

    LOG(INFO) << "Set transformation Values for xPath: " + xpathStd ;

}



void CPACSCreatorAdapter::resetCpacsConfig(const TIGLViewerDocument& doc) {
    QMutexLocker locker(&mutex); // ensure that the tree is not accessed during the creation

    // Check if the new document is valid
    if(!doc.isConfigurationValid()){
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

