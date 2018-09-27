//
// Created by cfse on 9/26/18.
//

#include "TIGLViewerFuselageWidget.h"
#include "ModificatorManager.h"

TIGLViewerFuselageWidget::TIGLViewerFuselageWidget(QWidget *parent) : ModificatorWidget(parent) {

}

void TIGLViewerFuselageWidget::init(ModificatorManager * associate ) {
    ModificatorWidget::init(associate);

    spinBoxLength = this->findChild<QDoubleSpinBox*>("spinBoxLength");


}


void TIGLViewerFuselageWidget::setFuselage(cpcr::CPACSTreeItem *fuselageItem) {
    this->fuselageItem = fuselageItem;
    internalLength = associateManager->adapter->getFuselageLength(fuselageItem);
    spinBoxLength->setValue(internalLength);
}

void TIGLViewerFuselageWidget::apply() {
   bool lengthHasChanged = ( (! isApprox(internalLength, spinBoxLength->value()) ) );

   if(lengthHasChanged){
       internalLength = spinBoxLength->value();
       associateManager->adapter->setFuselageLength(fuselageItem, internalLength);
   }

   if(lengthHasChanged){
       associateManager->adapter->writeToFile();
   }

}


void TIGLViewerFuselageWidget::reset() {
    if(fuselageItem != nullptr){
        this->setFuselage(this->fuselageItem);
    }else{
        LOG(WARNING) << "TIGLViewerWingWidget: reset call but wing is not set!";
    }
}
