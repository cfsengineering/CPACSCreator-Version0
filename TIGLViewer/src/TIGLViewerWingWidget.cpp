//
// Created by makem on 30/05/18.
//

#include "TIGLViewerWingWidget.h"
#include "CPACSCreatorLib/easylogging++.h"
#include "ModificatorManager.h"

TIGLViewerWingWidget::TIGLViewerWingWidget(QWidget *parent) : ModificatorWidget(parent){

}


void TIGLViewerWingWidget::init(ModificatorManager * associate ) {
    ModificatorWidget::init(associate);
    spinBoxSweep = this->findChild<QDoubleSpinBox*>("spinBoxSweep");
    spinBoxSweep->setValue(-1.0);

}


void TIGLViewerWingWidget::setWing(cpcr::CPACSTreeItem *wing) {
    wingItem = wing;
    internalSweep = associateManager->adapter->getSweepAngle(wingItem, 0);
    spinBoxSweep->setValue(internalSweep);
}

void TIGLViewerWingWidget::apply() {
    DLOG(WARNING) << "WING apply sweep";
    if(internalSweep != spinBoxSweep->value()){
        internalSweep = spinBoxSweep->value();
        associateManager->adapter->setSweepAngle(wingItem, internalSweep, 0 );
    }
}



