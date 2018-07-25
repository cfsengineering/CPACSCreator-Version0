//
// Created by makem on 29/05/18.
//

#include "ModificatorManager.h"



ModificatorManager::ModificatorManager(CPACSCreatorAdapter *adapter,
                                       QWidget* widgetApply,
                                       TIGLViewerTransformationWidget* transformationModificator,
                                       TIGLViewerWingWidget* wingModificator,
                                       ProfilesDBManager* profilesDB,
                                       TIGLViewerPositioningsWidget* positioningsModificator) {
    this->adapter = adapter;
    this->profilesDB = profilesDB;
    this->widgetApply = widgetApply;
    this->commitButton = widgetApply->findChild<QPushButton*>("commitButton");
    this->cancelButton = widgetApply->findChild<QPushButton*>("cancelButton");
    this->transformationModificator = transformationModificator;
    this->transformationModificator->init(this);
    this->wingModificator = wingModificator;
    this->wingModificator->init(this);
    this->positioningsModificator = positioningsModificator;
    this->positioningsModificator->init(this);
    currentModificator = nullptr;

    this->hideAll();

}


void ModificatorManager::reset() {
    currentModificator = nullptr;
    this->hideAll();
}


void ModificatorManager::applyCurrentModifications(){
    if(currentModificator != nullptr) {
        currentModificator->apply();
    }
}



void ModificatorManager::applyCurrentCancellation() {
    if(currentModificator != nullptr){
        currentModificator->reset();
    }
}


void ModificatorManager::dispatch(cpcr::CPACSTreeItem *item) {

    if(item == nullptr) {
        LOG(ERROR) << "MODIFICATOR MANAGER GET A NULL ITEM";
    }
    else if(item->getType() == "transformation"){
        currentModificator = transformationModificator;
        this->setTransformationModificator(item);
    }
    else if(item->getType() == "wing"){
        currentModificator = wingModificator;
        this->setWingModificator(item);
    }
    else if (item->getType() == "positionings"){
        currentModificator = positioningsModificator;
        this->setPositioningsModificator(item);
    }
    else {
        currentModificator = nullptr;
        hideAll();
        LOG(INFO) <<  "MODIFICATOR MANAGER: item not suported";
    }
}


void ModificatorManager::setTransformationModificator(cpcr::CPACSTreeItem * item ) {

    hideAll();
    transformationModificator->setTransformation(item);
    transformationModificator->setVisible(true);
    widgetApply->setVisible(true);

}


void ModificatorManager::setWingModificator(cpcr::CPACSTreeItem *item) {
    hideAll();
    wingModificator->setWing(item);
    wingModificator->setVisible(true);
    widgetApply->setVisible(true);
}


void ModificatorManager::setPositioningsModificator(cpcr::CPACSTreeItem *item) {
    hideAll();
    positioningsModificator->setPositionings(item);
    positioningsModificator->setVisible(true);
    widgetApply->setVisible(true);
}

void ModificatorManager::hideAll() {
    bool visible = false;
    transformationModificator->setVisible(visible);
    wingModificator->setVisible(visible);
    positioningsModificator->setVisible(visible);
    widgetApply->setVisible(visible);

}

