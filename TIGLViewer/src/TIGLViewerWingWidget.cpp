/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
//
// Created by makem on 30/05/18.
//

#include "TIGLViewerWingWidget.h"
#include "ModificatorManager.h"

TIGLViewerWingWidget::TIGLViewerWingWidget(QWidget *parent) : ModificatorWidget(parent){

}


void TIGLViewerWingWidget::init(ModificatorManager * associate ) {
    ModificatorWidget::init(associate);

    // Retrieve component of the anchor interface
    spinBoxAnchorX = this->findChild<QDoubleSpinBox*>("spinBoxAnchorX");
    spinBoxAnchorY = this->findChild<QDoubleSpinBox*>("spinBoxAnchorY");
    spinBoxAnchorZ = this->findChild<QDoubleSpinBox*>("spinBoxAnchorZ");

    // orientation interface
    comboBoxWingOrientation = this->findChild<QComboBox*>("comboBoxWingOrientation");
    comboBoxSymmetry = this->findChild<QComboBox*>("comboBoxSymmetry");

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

    spinBoxAreaXZ->setReadOnly(true);
    spinBoxAreaYZ->setReadOnly(true);
    spinBoxAreaT->setReadOnly(true);


    spinBoxAR->setValue(-1);

    spinBoxSpan->setValue(-1);

    comboBoxAirfoil->addItems(associate->getProfilesDB()->getAvailableAirfoils());

    comboBoxWingOrientation->addItem("horizontal");
    comboBoxWingOrientation->addItem("vertical");

    comboBoxSymmetry->addItem("x-y-plane");
    comboBoxSymmetry->addItem("x-z-plane");
    comboBoxSymmetry->addItem("y-z-plane");
    comboBoxSymmetry->addItem("no-symmetry");



    // alterable span area ar
    checkBoxIsAreaConstant->setChecked(false);
    checkBoxIsSpanConstant->setChecked(false);
    checkBoxIsARConstant->setChecked(true);

    // anchor orientation



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



void TIGLViewerWingWidget::setAreaConstant(bool checked) {
    checkBoxIsARConstant->setChecked(false);
    spinBoxAR->setReadOnly(false);
    checkBoxIsSpanConstant->setChecked(false);
    spinBoxSpan->setReadOnly(false);
    checkBoxIsAreaConstant->setChecked(true);
    spinBoxAreaXY->setReadOnly(true);

}

void TIGLViewerWingWidget::setSpanConstant(bool checked) {

    checkBoxIsARConstant->setChecked(false);
    spinBoxAR->setReadOnly(false);
    checkBoxIsAreaConstant->setChecked(false);
    spinBoxAreaXY->setReadOnly(false);
    checkBoxIsSpanConstant->setChecked(true);
    spinBoxSpan->setReadOnly(true);
}

void TIGLViewerWingWidget::setARConstant(bool checked) {
    checkBoxIsAreaConstant->setChecked(false);
    spinBoxAreaXY->setReadOnly(false);
    checkBoxIsSpanConstant->setChecked(false);
    spinBoxSpan->setReadOnly(false);
    checkBoxIsARConstant->setChecked(true);
    spinBoxAR->setReadOnly(true);

}

void TIGLViewerWingWidget::setWing(cpcr::CPACSTreeItem *wing) {
    wingItem = wing;

    // set anchor
    associateManager->getAdapter()->getAnchorValues(wing, internalAnchorX, internalAnchorY, internalAnchorZ);
    spinBoxAnchorX->setValue(internalAnchorX);
    spinBoxAnchorY->setValue(internalAnchorY);
    spinBoxAnchorZ->setValue(internalAnchorZ);

    // set orientration & symmetry
    internalWingOrientation = associateManager->getAdapter()->getWingOrientation(wingItem);
    int idx = comboBoxWingOrientation->findText(internalWingOrientation);
    if(idx == -1){  // case for custom
        idx = comboBoxWingOrientation->count();
        comboBoxWingOrientation->addItem(internalWingOrientation);
    }
    comboBoxWingOrientation->setCurrentIndex(idx);

    internalSymmetry = associateManager->getAdapter()->getWingSymmetry(wingItem);
    idx = comboBoxSymmetry->findText(internalSymmetry);
    comboBoxSymmetry->setCurrentIndex(idx);


    // set sweep
    internalMethod = comboBoxSweepMethod->currentText(); // retrieve the information of the interface -> when we switch from one wing to the other method and chord are conserved
    internalSweepChord = spinBoxSweepChord->value();
    internalSweep = associateManager->getAdapter()->getSweepAngle(wingItem, internalSweepChord);
    spinBoxSweep->setValue(internalSweep);

    // set dihedral
    internalDihedralChord = spinBoxDihedralChord->value();
    internalDihedral = associateManager->getAdapter()->getDihedralAngle(wingItem, internalDihedralChord);
    spinBoxDihedral->setValue(internalDihedral);

    // set area
    internalAreaXY = associateManager->getAdapter()->getWingArea(wingItem, cpcr::PLANE::XY_PLANE);
    spinBoxAreaXY->setValue(internalAreaXY);

    internalAreaXZ = associateManager->getAdapter()->getWingArea(wingItem, cpcr::PLANE::XZ_PLANE);
    spinBoxAreaXZ->setValue(internalAreaXZ);

    internalAreaYZ = associateManager->getAdapter()->getWingArea(wingItem, cpcr::PLANE::YZ_PLANE);
    spinBoxAreaYZ->setValue(internalAreaYZ);

    internalAreaT = associateManager->getAdapter()->getWingArea(wingItem, cpcr::PLANE::NO_PLANE);
    spinBoxAreaT->setValue(internalAreaT);

    // set span
    internalSpan = associateManager->getAdapter()->getWingSpan(wingItem);
    spinBoxSpan->setValue(internalSpan);

    // set AR
    internalAR = associateManager->getAdapter()->getWingAR(wingItem);
    spinBoxAR->setValue(internalAR);

    // set constant between ar, span and area
    setARConstant(true);


    // set wingAirfoil1
    comboBoxAirfoil->clear();
    comboBoxAirfoil->addItems(associateManager->getProfilesDB()->getAvailableAirfoils());

    internalAirfoilUID = associateManager->getAdapter()->getAirfoilValueForWing(wingItem);
    idx = comboBoxAirfoil->findText(internalAirfoilUID);
    if(idx == -1){  // case for combined or None
        idx = comboBoxAirfoil->count();
        comboBoxAirfoil->addItem(internalAirfoilUID);
    }
    comboBoxAirfoil->setCurrentIndex(idx);

}


void TIGLViewerWingWidget::reset() {
    if(wingItem != nullptr){
        this->setWing(this->wingItem);
    }else{
        LOG(WARNING) << "TIGLViewerWingWidget: reset call but wing is not set!";
    }

}


void TIGLViewerWingWidget::apply() {

    bool anchorHasChanged = ( (!isApprox(internalAnchorX, spinBoxAnchorX->value()))
                              || (! isApprox(internalAnchorY, spinBoxAnchorY->value()))
                              || (! isApprox(internalAnchorZ , spinBoxAnchorZ->value())) );

    bool orientationHasChanged = ( internalWingOrientation != comboBoxWingOrientation->currentText() );

    bool symmetryHasChanged = (internalSymmetry != comboBoxSymmetry->currentText() );

    bool sweepHasChanged = ( (!isApprox(internalSweep, spinBoxSweep->value()) )
                             ||(!isApprox(internalSweepChord, spinBoxSweepChord->value() ) )
                             || internalMethod != comboBoxSweepMethod->currentText()) ;

    bool dihedralHasChanged = ( (!isApprox(internalDihedral, spinBoxDihedral->value()))
                               || (!isApprox(internalDihedralChord, spinBoxDihedralChord->value())) );

    bool airfoilHasChanged = (internalAirfoilUID != comboBoxAirfoil->currentText() );

    bool spanHasChanged = ( ! isApprox( internalSpan, spinBoxSpan->value()) );

    bool aRHasChanged = ( ! isApprox(internalAR, spinBoxAR->value() ) );

    bool areaXYHasChanged = ( ! isApprox(internalAreaXY, spinBoxAreaXY->value() ));


    if( anchorHasChanged ){
        internalAnchorX = spinBoxAnchorX->value();
        internalAnchorY = spinBoxAnchorY->value();
        internalAnchorZ = spinBoxAnchorZ->value();
        associateManager->getAdapter()->setAnchorValues(wingItem, internalAnchorX, internalAnchorY, internalAnchorZ);
    }

    if( orientationHasChanged ){
        internalWingOrientation = comboBoxWingOrientation->currentText();
        associateManager->getAdapter()->setWingOrientation(wingItem, internalWingOrientation);
    }


    if (symmetryHasChanged){
        internalSymmetry = comboBoxSymmetry->currentText();
        associateManager->getAdapter()->setWingSymmetry(wingItem, internalSymmetry);
    }

    if(sweepHasChanged){ //TODO do not change if the change is to small
        internalSweep = spinBoxSweep->value();
        internalMethod = comboBoxSweepMethod->currentText();
        internalSweepChord = spinBoxSweepChord->value();
        associateManager->getAdapter()->setSweepAngle(wingItem, internalSweep, internalSweepChord, internalMethod );
    }

    if(dihedralHasChanged){
        internalDihedral = spinBoxDihedral->value();
        internalDihedralChord = spinBoxDihedralChord->value();
        associateManager->getAdapter()->setDihedralAngle(wingItem, internalDihedral, internalDihedralChord);
    }

    if(airfoilHasChanged){
        internalAirfoilUID = comboBoxAirfoil->currentText();
        associateManager->getAdapter()->setAllAirfoilsInWing(wingItem, internalAirfoilUID);

    }

    if( areaXYHasChanged){
        internalAreaXY = spinBoxAreaXY->value();
        if(checkBoxIsSpanConstant->isChecked()){
            associateManager->getAdapter()->setWingAreaKeepSpan(wingItem, internalAreaXY);
        }
        else if( checkBoxIsARConstant->isChecked() ){
            associateManager->getAdapter()->setWingAreaKeepAR(wingItem, internalAreaXY);
        }
        else {
            LOG(ERROR) << "TIGLViewerWingWidget: set area called, but not correct constant checkbox set";
        }

    }


    if(spanHasChanged ){
        internalSpan = spinBoxSpan->value();
        if(checkBoxIsAreaConstant->isChecked()){
            associateManager->getAdapter()->setWingSpanKeepArea(wingItem, internalSpan);
        }
        else if(checkBoxIsARConstant->isChecked()){
            associateManager->getAdapter()->setWingSpanKeepAR(wingItem, internalSpan);
        }
        else {
            LOG(ERROR) << "TIGLViewerWingWidget: set span called, but not correct constant checkbox set";
        }
    }

    if(aRHasChanged ){
        internalAR = spinBoxAR->value();
        if(checkBoxIsAreaConstant->isChecked()){
            associateManager->getAdapter()->setWingARKeepArea(wingItem, internalAR);
        }
        else if(checkBoxIsSpanConstant->isChecked()){
            associateManager->getAdapter()->setWingARKeepSpan(wingItem, internalAR);
        }
        else {
            LOG(ERROR) << "TIGLViewerWingWidget: set AR called, but not correct constant checkbox set";
        }
    }




    if(sweepHasChanged || airfoilHasChanged || dihedralHasChanged || areaXYHasChanged || spanHasChanged
       || aRHasChanged || anchorHasChanged || symmetryHasChanged || orientationHasChanged){
        associateManager->getAdapter()->writeToFile();   // we do this here to update all the change at once in the file
    }



}






