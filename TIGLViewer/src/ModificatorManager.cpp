//
// Created by makem on 29/05/18.
//

#include "ModificatorManager.h"



ModificatorManager::ModificatorManager(CPACSCreatorAdapter *adapter,
                                       QPushButton* commitButton,
                                       TIGLViewerTransformationWidget* transformationModificator,
                                       TIGLViewerWingWidget* wingModificator) {
    this->adapter = adapter;
    this->transformationModificator = transformationModificator;
    this->transformationModificator->init(this);
    this->wingModificator = wingModificator;
    this->wingModificator->init(this);
    this->commitButton = commitButton;
    currentModificator = nullptr;
    this->hideAll();
}


void ModificatorManager::reset() {
    currentModificator = nullptr;
    this->hideAll();
}


void ModificatorManager::applyCurrentModifications(){
    if(currentModificator != nullptr)
        currentModificator->apply();
    LOG(WARNING) << "apply current modifications executed!";
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
    commitButton->setVisible(true);
}


void ModificatorManager::setWingModificator(cpcr::CPACSTreeItem *item) {
    hideAll();
    wingModificator->setWing(item);
    wingModificator->setVisible(true);
    commitButton->setVisible(true);
}


void ModificatorManager::hideAll() {
    bool visible = false;
    transformationModificator->setVisible(visible);
    wingModificator->setVisible(visible);
    commitButton->setVisible(visible);
}