//
// Created by makem on 30/05/18.
//

#ifndef TIGL_TIGLVIEWERWINGWIDGET_H
#define TIGL_TIGLVIEWERWINGWIDGET_H

#include "ModificatorWidget.h"
#include "QDoubleSpinBox"
#include "QPushButton"
#include "QWidget"
#include "CPACSCreatorLib/CPACSTreeItem.h"


class TIGLViewerWingWidget : public ModificatorWidget {

    Q_OBJECT

public slots:

    void expendAreaDetails(bool checked);
    void expendDihedralDetails(bool checked);
    void expendSweepDetails(bool checked);

public:


    TIGLViewerWingWidget(QWidget * parent = 0);

    void init(ModificatorManager * associate ) override ;
    void apply() override ;

    void setWing(cpcr::CPACSTreeItem* wing);

private:

    cpcr::CPACSTreeItem * wingItem;

    // sweep interface
    QDoubleSpinBox * spinBoxSweep ;
    QPushButton* btnExpendSweepDetails;
    QWidget* widgetSweepDetails;
    QDoubleSpinBox* spinBoxSweepChord;
    QSpinBox* intSpinBoxMethod;

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


    // internal sweep
    double internalSweep;
    double internalSweepChord;
    int internalMethod;


    // internal dihedral
    double internalDihedral;
    double internalDihedralChord;

    // internal area
    double internalAreaXY;
    double internalAreaXZ;
    double internalAreaYZ;
    double internalAreaT;
};


#endif //TIGL_TIGLVIEWERWINGWIDGET_H
