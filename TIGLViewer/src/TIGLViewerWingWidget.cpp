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

    // Retrieve component of the sweep interface
    btnExpendSweepDetails = this->findChild<QPushButton*>("btnExpendSweepDetails");
    spinBoxSweep = this->findChild<QDoubleSpinBox*>("spinBoxSweep");
    widgetSweepDetails = this->findChild<QWidget*>("widgetSweepDetails");
    spinBoxSweepChord = this->findChild<QDoubleSpinBox*>("spinBoxSweepChord");
    intSpinBoxMethod = this->findChild<QSpinBox*>("intSpinBoxMethod");

    // Retrieve component of the dihedral interface
    btnExpendDihedralDetails = this->findChild<QPushButton*>("btnExpendDihedralDetails");
    spinBoxDihedral = this->findChild<QDoubleSpinBox*>("spinBoxDihedral");
    widgetDihedralDetails = this->findChild<QWidget*>("widgetDihedralDetails");
    spinBoxDihedralChord = this->findChild<QDoubleSpinBox*>("spinBoxDihedralChord");

    // Retrieve component of the area interface
    btnExpendAreaDetails = this->findChild<QPushButton*>("btnExpendAreaDetails");
    spinBoxAreaXY = this->findChild<QDoubleSpinBox*>("spinBoxAreaXY");
    widgetAreaDetails = this->findChild<QWidget*>("widgetAreaDetails");
    spinBoxAreaXZ = this->findChild<QDoubleSpinBox*>("spinBoxAreaXZ");
    spinBoxAreaYZ = this->findChild<QDoubleSpinBox*>("spinBoxAreaYZ");
    spinBoxAreaT = this->findChild<QDoubleSpinBox*>("spinBoxAreaT");


    // Retrieve component of the airfoil interface
    btnExpendAirfoilDetails = this->findChild<QPushButton*>("btnExpendAirfoilDetails");
    comboBoxAirfoil = this->findChild<QComboBox*>("comboBoxAirfoil");
    widgetAirfoilDetails = this->findChild<QWidget*>("widgetAirfoilDetails");


    // set the initials values of the display interface (should be overwritten when the wingItem is set)
    spinBoxSweep->setValue(-1.0);
    spinBoxSweepChord->setValue(0);
    intSpinBoxMethod->setValue(1);

    spinBoxSweep->setValue(-1.0);
    spinBoxDihedralChord->setValue(0);

    spinBoxAreaXY->setValue(-1.0);
    spinBoxAreaXZ->setValue(-1);
    spinBoxAreaYZ->setValue(-1);
    spinBoxAreaT->setValue(-1);

    spinBoxAreaXY->setReadOnly(true);
    spinBoxAreaXZ->setReadOnly(true);
    spinBoxAreaYZ->setReadOnly(true);
    spinBoxAreaT->setReadOnly(true);

    comboBoxAirfoil->addItems(associate->profilesDB->getAvailableAirfoils());


    // hide the advanced options
    widgetAreaDetails->hide();
    widgetDihedralDetails->hide();
    widgetSweepDetails->hide();
    widgetAirfoilDetails->hide();

    // connect the extend buttons with their slot
    connect(btnExpendAreaDetails, SIGNAL(clicked(bool)), this, SLOT(expendAreaDetails(bool)) );
    connect(btnExpendDihedralDetails, SIGNAL(clicked(bool)), this, SLOT(expendDihedralDetails(bool)) );
    connect(btnExpendSweepDetails, SIGNAL(clicked(bool)), this, SLOT(expendSweepDetails(bool)));
    connect(btnExpendAirfoilDetails, SIGNAL(clicked(bool)), this, SLOT(expendAirfoilDetails(bool)));



}

// inverse the visibility
void TIGLViewerWingWidget::expendAreaDetails(bool checked) {
    widgetAreaDetails->setVisible(! (widgetAreaDetails->isVisible() ));
}


// inverse the visibility
void TIGLViewerWingWidget::expendDihedralDetails(bool checked) {
    widgetDihedralDetails->setVisible(! (widgetDihedralDetails->isVisible() ));
}

// inverse the visibility
void TIGLViewerWingWidget::expendSweepDetails(bool checked) {
    widgetSweepDetails->setVisible(! (widgetSweepDetails->isVisible() ));
}

void TIGLViewerWingWidget::expendAirfoilDetails(bool checked) {
    widgetAirfoilDetails->setVisible( ! (widgetAirfoilDetails->isVisible()));
}

void TIGLViewerWingWidget::setWing(cpcr::CPACSTreeItem *wing) {
    wingItem = wing;
    // set sweep
    internalMethod = intSpinBoxMethod->value(); // retrieve the information of the interface -> when we switch from one wing to the other method and chord are conserved
    internalSweepChord = spinBoxSweepChord->value();
    internalSweep = associateManager->adapter->getSweepAngle(wingItem, internalSweepChord);
    spinBoxSweep->setValue(internalSweep);

    // set dihedral
    internalDihedralChord = spinBoxDihedralChord->value();
    internalDihedral = associateManager->adapter->getDihedralAngle(wingItem, internalDihedralChord);
    spinBoxDihedral->setValue(internalDihedral);

    // set area
    internalAreaXY = associateManager->adapter->getWingArea(wingItem, TIGL_X_Y_PLANE);
    spinBoxAreaXY->setValue(internalAreaXY);

    internalAreaXZ = associateManager->adapter->getWingArea(wingItem, TIGL_X_Z_PLANE);
    spinBoxAreaXZ->setValue(internalAreaXZ);

    internalAreaYZ = associateManager->adapter->getWingArea(wingItem, TIGL_Y_Z_PLANE);
    spinBoxAreaYZ->setValue(internalAreaYZ);

    internalAreaT = associateManager->adapter->getWingArea(wingItem, TIGL_NO_SYMMETRY);
    spinBoxAreaT->setValue(internalAreaT);

    // set wingAirfoil1
    comboBoxAirfoil->clear();
    comboBoxAirfoil->addItems(associateManager->profilesDB->getAvailableAirfoils());

    internalAirfoilUID = associateManager->adapter->getAirfoilValueForWing(wingItem);
    int idx = comboBoxAirfoil->findText(internalAirfoilUID);
    if(idx == -1){  // case for combined or None
        idx = comboBoxAirfoil->count();
        comboBoxAirfoil->addItem(internalAirfoilUID);
    }
    comboBoxAirfoil->setCurrentIndex(idx);



}

void TIGLViewerWingWidget::apply() {

    DLOG(WARNING) << "WING apply sweep";

    // check if a change of sweep, chord or method occured
    bool sweepHasChanged = ( internalSweep != spinBoxSweep->value()
                             || internalSweepChord != spinBoxSweepChord->value()
                             || internalMethod != intSpinBoxMethod->value()) ;

    bool dihedralHasChanged = (internalDihedral != spinBoxDihedral->value()
                               || internalDihedralChord != spinBoxDihedralChord->value());

    bool airfoilHasChanged = (internalAirfoilUID != comboBoxAirfoil->currentText() );

    if(sweepHasChanged){ //TODO do not change if the change is to small
        internalSweep = spinBoxSweep->value();
        internalMethod = intSpinBoxMethod->value();
        internalSweepChord = spinBoxSweepChord->value();
        associateManager->adapter->setSweepAngle(wingItem, internalSweep, internalSweepChord, internalMethod );
    }

    if(dihedralHasChanged){
        internalDihedral = spinBoxDihedral->value();
        internalDihedralChord = spinBoxDihedralChord->value();
        associateManager->adapter->setDihedralAngle(wingItem, internalDihedral, internalDihedralChord);
    }

    if(airfoilHasChanged){
        internalAirfoilUID = comboBoxAirfoil->currentText();
        associateManager->adapter->setAllAirfoilsInWing(wingItem, internalAirfoilUID);

    }

    if(sweepHasChanged || airfoilHasChanged || dihedralHasChanged){
        associateManager->adapter->writeToFile();   // we do this here to update all the change at once in the file
    }


}




