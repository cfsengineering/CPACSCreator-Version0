//
// Created by cfse on 3/20/18.
//

#include "CPACSCreatorAdapter.h"

#include "CPACSCreatorLib/CPACSTransformation.h"

#include "CPACSCreatorLib/CPACSTreeItem.h"



void CPACSCreatorAdapter::prepareTransformationValues(cpcr::CPACSTreeItem *item) {

    if(item == nullptr)
        return;

    if(item->getType() != "transformation"){
        return;
    }

    cpcr::CPACSTransformation transform = aircraftTree.getModifier()->getTransformation(item->getXPath());


    QString xpath = QString(item->getXPath().toString().c_str());

    LOG(INFO) << "Prepare Transformation Values";

    emit newTransformationValues(xpath,
                                 transform.getScaling().x, transform.getScaling().y, transform.getScaling().z,
                                 transform.getRotation().x, transform.getRotation().y, transform.getRotation().z,
                                 transform.getTranslation().x, transform.getTranslation().y, transform.getTranslation().z
                                 );

}

void CPACSCreatorAdapter::setTransformation(QString xpath,
                                            double sx, double sy, double sz,
                                            double rx, double ry, double rz,
                                            double tx, double ty, double tz) {


    std::string xpathStd = xpath.toStdString();

    cpcr::CPACSTransformation transform(sx, sy, sz, rx, ry, rz, tx, ty, tz );
    aircraftTree.getModifier()->setTransformation(xpathStd, transform);
    aircraftTree.writeToFile();

    LOG(INFO) << "Set transformation Values for xPath: " + xpathStd ;



}




void CPACSCreatorAdapter::resetCpacsConfig(const TIGLViewerDocument& doc) {
    QMutexLocker locker(&mutex); // ensure that the tree is not accessed during the creation

    aircraftTree = cpcr::AircraftTree();

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
