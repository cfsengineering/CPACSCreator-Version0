//
// Created by makem on 29/05/18.
//

#include "ModificatorManager.h"



ModificatorManager::ModificatorManager(CPACSCreatorAdapter *adapter, TIGLViewerTransformationWidget* transformationModificator) {
    this->adapter = adapter;
    this->transformationModificator = transformationModificator;
    this->transformationModificator->init();
}




void ModificatorManager::dispatch(cpcr::CPACSTreeItem *item) {

    if(item == nullptr) {
        LOG(ERROR) << "MODIFICATOR MANAGER GET A NULL ITEM";
    }
    else if(item->getType() == "transformation"){
        this->setTransformationModificator(item);
    }
    else {
        hideAll();
        LOG(INFO) <<  "MODIFICATOR MANAGER: item not suported";
    }
}


void ModificatorManager::setTransformationModificator(cpcr::CPACSTreeItem * item ) {

    hideAll();

    cpcr::CPACSTransformation tempT = adapter->getTransformation(item);

    transformationModificator->setValues(QString(item->getXPath().toString().c_str()),
                                        tempT.getScaling().x,tempT.getScaling().y,tempT.getScaling().z,
                                        tempT.getRotation().x,tempT.getRotation().y,tempT.getRotation().z,
                                        tempT.getTranslation().x,tempT.getTranslation().y,tempT.getTranslation().z);
    transformationModificator->setVisible(true);

}


void ModificatorManager::hideAll() {
    bool visible = false;
    transformationModificator->setVisible(visible);
}