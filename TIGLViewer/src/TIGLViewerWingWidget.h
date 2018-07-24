//
// Created by makem on 30/05/18.
//

#ifndef TIGL_TIGLVIEWERWINGWIDGET_H
#define TIGL_TIGLVIEWERWINGWIDGET_H

#include "ModificatorWidget.h"
#include "QDoubleSpinBox"
#include "QPushButton"
#include "QWidget"
#include "QComboBox"
#include "CPACSCreatorLib/CPACSTreeItem.h"
#include "QCheckBox"

class TIGLViewerWingWidget : public ModificatorWidget {

    Q_OBJECT

public slots:

    void expendAreaDetails(bool checked);
    void expendDihedralDetails(bool checked);
    void expendSweepDetails(bool checked);
    void expendAirfoilDetails(bool checked);
    void expendAnchorDetails(bool checked);
    void expendStandardizationDetails(bool checked);

    void setAreaConstant(bool checked);
    void setSpanConstant(bool checked);
    void setARConstant(bool checked);


public:


    TIGLViewerWingWidget(QWidget * parent = 0);

    void init(ModificatorManager * associate ) override ;
    void apply() override ;

    void setWing(cpcr::CPACSTreeItem* wing);

private:

    cpcr::CPACSTreeItem * wingItem;

    // anchor interface
    QDoubleSpinBox * spinBoxAnchorX ;
    QDoubleSpinBox * spinBoxAnchorY ;
    QDoubleSpinBox * spinBoxAnchorZ ;
    QPushButton* btnExpendAnchorDetails;
    QWidget* widgetAnchorDetails;
    QComboBox* comboBoxAnchorOrientation;


    // sweep interface
    QDoubleSpinBox * spinBoxSweep ;
    QPushButton* btnExpendSweepDetails;
    QWidget* widgetSweepDetails;
    QDoubleSpinBox* spinBoxSweepChord;
    QComboBox* comboBoxSweepMethod;

    // dihedral interface
    QDoubleSpinBox * spinBoxDihedral ;
    QPushButton* btnExpendDihedralDetails;
    QWidget* widgetDihedralDetails;
    QDoubleSpinBox* spinBoxDihedralChord;


    // area interface
    QPushButton* btnExpendAreaDetails;
    QWidget* widgetAreaDetails;
    QDoubleSpinBox * spinBoxAreaXY;
    QDoubleSpinBox * spinBoxAreaXZ;
    QDoubleSpinBox * spinBoxAreaYZ;
    QDoubleSpinBox * spinBoxAreaT;
    QCheckBox * checkBoxIsAreaConstant;

    // span interface;
    QDoubleSpinBox * spinBoxSpan;
    QCheckBox * checkBoxIsSpanConstant;

    // AR interface;
    QDoubleSpinBox * spinBoxAR;
    QCheckBox * checkBoxIsARConstant;

    // airfoil interface
    QPushButton* btnExpendAirfoilDetails;
    QWidget* widgetAirfoilDetails;
    QComboBox* comboBoxAirfoil;

    // standardization interface
    QComboBox* comboBoxGlobalStd;
    QPushButton* btnExpendStdDetails;
    QWidget* widgetStdDetails;
    QCheckBox* checkBoxStdAirfoils;
    QCheckBox* checkBoxStdPositionings;
    QCheckBox* checkBoxStdSections;
    QCheckBox* checkBoxStdAnchor;


    // internal anchor

    // todo

    // internal standardization

    // todo





    // internal sweep
    double internalSweep;
    double internalSweepChord;
    QString internalMethod;


    // internal dihedral
    double internalDihedral;
    double internalDihedralChord;

    // internal area
    double internalAreaXY;
    double internalAreaXZ;
    double internalAreaYZ;
    double internalAreaT;

    // internal span
    double internalSpan;

    // internal AR
    double internalAR;


    // internal airfoil
    QString internalAirfoilUID;

};


#endif //TIGL_TIGLVIEWERWINGWIDGET_H
