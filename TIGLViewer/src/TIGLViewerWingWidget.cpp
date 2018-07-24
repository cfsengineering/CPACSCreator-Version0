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

    // Retrieve component of the anchor interface
    btnExpendAnchorDetails = this->findChild<QPushButton*>("btnExpendAnchorDetails");
    spinBoxAnchorX = this->findChild<QDoubleSpinBox*>("spinBoxAnchorX");
    spinBoxAnchorY = this->findChild<QDoubleSpinBox*>("spinBoxAnchorY");
    spinBoxAnchorZ = this->findChild<QDoubleSpinBox*>("spinBoxAnchorZ");
    widgetAnchorDetails = this->findChild<QWidget*>("widgetAnchorDetails");
    comboBoxAnchorOrientation = this->findChild<QComboBox*>("comboBoxAnchorOrientation");


    // Retrieve component of the sweep interface
    btnExpendSweepDetails = this->findChild<QPushButton*>("btnExpendSweepDetails");
    spinBoxSweep = this->findChild<QDoubleSpinBox*>("spinBoxSweep");
    widgetSweepDetails = this->findChild<QWidget*>("widgetSweepDetails");
    spinBoxSweepChord = this->findChild<QDoubleSpinBox*>("spinBoxSweepChord");
    comboBoxSweepMethod = this->findChild<QComboBox*>("comboBoxSweepMethod");

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
    checkBoxIsAreaConstant = this->findChild<QCheckBox*>("checkBoxIsAreaConstant");

    // Retrieve component of the span interface
    spinBoxSpan = this->findChild<QDoubleSpinBox*>("spinBoxSpan");
    checkBoxIsSpanConstant = this->findChild<QCheckBox*>("checkBoxIsSpanConstant");

    // Retrieve component of the span interface
    spinBoxAR = this->findChild<QDoubleSpinBox*>("spinBoxAR");
    checkBoxIsARConstant = this->findChild<QCheckBox*>("checkBoxIsARConstant");

    // Retrieve component of the airfoil interface
    btnExpendAirfoilDetails = this->findChild<QPushButton*>("btnExpendAirfoilDetails");
    comboBoxAirfoil = this->findChild<QComboBox*>("comboBoxAirfoil");
    widgetAirfoilDetails = this->findChild<QWidget*>("widgetAirfoilDetails");


    // Retrieve component of the standardization interface
    btnExpendStdDetails = this->findChild<QPushButton*>("btnExpendStandardizationDetails");
    comboBoxGlobalStd = this->findChild<QComboBox*>("comboBoxGlobalStd");
    checkBoxStdAirfoils = this->findChild<QCheckBox*>("checkBoxStdAirfoils");
    checkBoxStdSections = this->findChild<QCheckBox*>("checkBoxStdSections");
    checkBoxStdPositionings = this->findChild<QCheckBox*>("checkBoxStdPositionings");
    checkBoxStdAnchor = this->findChild<QCheckBox*>("checkBoxStdAnchor");
    widgetStdDetails = this->findChild<QWidget*>("widgetStandardizationDetails");

    // set the initials values of the display interface (should be overwritten when the wingItem is set)
    spinBoxSweep->setValue(-1.0);
    spinBoxSweepChord->setValue(0);
    comboBoxSweepMethod->addItem("Translation");
    comboBoxSweepMethod->addItem("Shearing");
    comboBoxSweepMethod->setCurrentIndex(0);

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


    spinBoxAR->setValue(-1);

    spinBoxSpan->setValue(-1);

    comboBoxAirfoil->addItems(associate->profilesDB->getAvailableAirfoils());


    // alterable span area ar
    checkBoxIsAreaConstant->setChecked(false);
    checkBoxIsSpanConstant->setChecked(false);
    checkBoxIsARConstant->setChecked(true);


    comboBoxAnchorOrientation->addItem("XY Orientation");
    comboBoxAnchorOrientation->addItem("XZ Orientation");
    comboBoxAnchorOrientation->addItem("Custom");



    // hide the advanced options
    widgetAreaDetails->hide();
    widgetDihedralDetails->hide();
    widgetSweepDetails->hide();
    widgetAirfoilDetails->hide();
    widgetStdDetails->hide();
    widgetAnchorDetails->hide();

    // connect the extend buttons with their slot
    connect(btnExpendAreaDetails, SIGNAL(clicked(bool)), this, SLOT(expendAreaDetails(bool)) );
    connect(btnExpendDihedralDetails, SIGNAL(clicked(bool)), this, SLOT(expendDihedralDetails(bool)) );
    connect(btnExpendSweepDetails, SIGNAL(clicked(bool)), this, SLOT(expendSweepDetails(bool)));
    connect(btnExpendAirfoilDetails, SIGNAL(clicked(bool)), this, SLOT(expendAirfoilDetails(bool)));
    connect(btnExpendAnchorDetails, SIGNAL(clicked(bool)), this, SLOT(expendAnchorDetails(bool)));
    connect(btnExpendStdDetails, SIGNAL(clicked(bool)), this, SLOT(expendStandardizationDetails(bool)));



    // connect change alterable
    connect(checkBoxIsAreaConstant,SIGNAL(clicked(bool)), this, SLOT(setAreaConstant(bool)));
    connect(checkBoxIsSpanConstant,SIGNAL(clicked(bool)), this, SLOT(setSpanConstant(bool)));
    connect(checkBoxIsARConstant,SIGNAL(clicked(bool)), this, SLOT(setARConstant(bool)));


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

void TIGLViewerWingWidget::expendAnchorDetails(bool checked) {
    widgetAnchorDetails->setVisible(!(widgetAnchorDetails->isVisible()));
}

void TIGLViewerWingWidget::expendStandardizationDetails(bool checked) {
    widgetStdDetails->setVisible( !(widgetStdDetails->isVisible()));
}




void TIGLViewerWingWidget::setAreaConstant(bool checked) {
    if(checked){
        checkBoxIsARConstant->setChecked(false);
        checkBoxIsSpanConstant->setChecked(false);
    }else{
        checkBoxIsAreaConstant->setChecked(true); // one box should be always checked
    }
}

void TIGLViewerWingWidget::setSpanConstant(bool checked) {
    if(checked){
        checkBoxIsARConstant->setChecked(false);
        checkBoxIsAreaConstant->setChecked(false);
    }else{
        checkBoxIsSpanConstant->setChecked(true); // one box should be always checked
    }
}

void TIGLViewerWingWidget::setARConstant(bool checked) {
    if(checked){
        checkBoxIsAreaConstant->setChecked(false);
        checkBoxIsSpanConstant->setChecked(false);
    }else{
        checkBoxIsARConstant->setChecked(true); // one box should be always checked
    }
}






void TIGLViewerWingWidget::setWing(cpcr::CPACSTreeItem *wing) {
    wingItem = wing;
    // set sweep
    internalMethod = comboBoxSweepMethod->currentText(); // retrieve the information of the interface -> when we switch from one wing to the other method and chord are conserved
    internalSweepChord = spinBoxSweepChord->value();
    internalSweep = associateManager->adapter->getSweepAngle(wingItem, internalSweepChord);
    spinBoxSweep->setValue(internalSweep);

    // set dihedral
    internalDihedralChord = spinBoxDihedralChord->value();
    internalDihedral = associateManager->adapter->getDihedralAngle(wingItem, internalDihedralChord);
    spinBoxDihedral->setValue(internalDihedral);

    // set area
    internalAreaXY = associateManager->adapter->getWingArea(wingItem, cpcr::PLANE::XY_PLANE);
    spinBoxAreaXY->setValue(internalAreaXY);

    internalAreaXZ = associateManager->adapter->getWingArea(wingItem, cpcr::PLANE::XZ_PLANE);
    spinBoxAreaXZ->setValue(internalAreaXZ);

    internalAreaYZ = associateManager->adapter->getWingArea(wingItem, cpcr::PLANE::YZ_PLANE);
    spinBoxAreaYZ->setValue(internalAreaYZ);

    internalAreaT = associateManager->adapter->getWingArea(wingItem, cpcr::PLANE::NO_PLANE);
    spinBoxAreaT->setValue(internalAreaT);

    // set span
    internalSpan = associateManager->adapter->getWingSpan(wingItem);
    spinBoxSpan->setValue(internalSpan);

    // set AR
    internalAR = associateManager->adapter->getWingAR(wingItem);
    spinBoxAR->setValue(internalAR);


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
                             || internalMethod != comboBoxSweepMethod->currentText()) ;

    bool dihedralHasChanged = (internalDihedral != spinBoxDihedral->value()
                               || internalDihedralChord != spinBoxDihedralChord->value());

    bool airfoilHasChanged = (internalAirfoilUID != comboBoxAirfoil->currentText() );

    bool spanHasChanged = (internalSpan != spinBoxSpan->value() );

    bool aRHasChanged = (internalAR != spinBoxAR->value() );


    if(sweepHasChanged){ //TODO do not change if the change is to small
        internalSweep = spinBoxSweep->value();
        internalMethod = comboBoxSweepMethod->currentText();
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

    if(spanHasChanged ){
        internalSpan = spinBoxSpan->value();
        //associateManager->adapter->setWingSpan(wingItem, internalSpan);
    }

    if(aRHasChanged ){
        internalAR = spinBoxAR->value();
        //associateManager->adapter->setWingWing(wingItem, internalAR);
    }


    if(sweepHasChanged || airfoilHasChanged || dihedralHasChanged || spanHasChanged || aRHasChanged ){
        associateManager->adapter->writeToFile();   // we do this here to update all the change at once in the file
    }




}






