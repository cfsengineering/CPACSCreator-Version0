//
// Created by cfse on 3/20/18.
//

#include "CPACSCreatorAdapter.h"

#include "CPACSCreatorLib/CPACSTransformation.h"


void CPACSCreatorAdapter::prepareTransformationValues(CPACSOverTreeItem *item) {

    if(item == nullptr)
        return;

    if(item->getCpacsType() != "transformation"){
        return;
    }

    cpcr::CPACSTransformation transform = aircraftTree.getTransformation(item->getXPath());


    QString xpath = QString(item->getXPath().c_str());

    LOG(INFO) << "Prepare Transformation Values";

    emit newTransformationValues(xpath,
                                 transform.getScaling().x, transform.getScaling().y, transform.getScaling().z,
                                 transform.getRotation().x, transform.getRotation().y, transform.getRotation().z,
                                 transform.getTransformation().x, transform.getTransformation().y, transform.getTransformation().z
                                 );

}

void CPACSCreatorAdapter::setTransformation(QString xpath,
                                            double sx, double sy, double sz,
                                            double rx, double ry, double rz,
                                            double tx, double ty, double tz) {


    std::string xpathStd = xpath.toStdString();

    cpcr::CPACSTransformation transform(sx, sy, sz, rx, ry, rz, tx, ty, tz );
    aircraftTree.setTransformation(xpathStd, transform);
    aircraftTree.save();

    LOG(INFO) << "Set transformation Values for xPath: cccccccccccccccccccccccccccccc" + xpathStd ;



}




void CPACSCreatorAdapter::resetCpacsConfig(const TIGLViewerDocument& doc) {
    QMutexLocker locker(&mutex); // ensure that the tree is not accessed during the creation

    aircraftTree = AircraftTree();

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

    aircraftTree.build(doc.getLoadedDocumentFileName().toStdString(), config.GetUID() );

    return;

}

CSharedPtr<CPACSOverTreeItem> CPACSCreatorAdapter::getRoot()const {

    QMutexLocker locker(&mutex); // ensure that the tree is not accessed during the creation

    CSharedPtr<CPACSOverTreeItem> root = CSharedPtr<CPACSOverTreeItem>();
    root = aircraftTree.getRoot();
    return root;
}
