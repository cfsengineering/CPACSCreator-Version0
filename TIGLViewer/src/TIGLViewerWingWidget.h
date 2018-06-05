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
    void expendSweepDetails(bool checked);

public:


    TIGLViewerWingWidget(QWidget * parent = 0);

    void init(ModificatorManager * associate ) override ;
    void apply() override ;

    void setWing(cpcr::CPACSTreeItem* wing);
    void setSweepValue(double);


private:

    cpcr::CPACSTreeItem * wingItem;
    // sweep interface
    QDoubleSpinBox * spinBoxSweep ;
    QPushButton* btnExpendSweepDetails;
    QWidget* widgetSweepDetails;
    QDoubleSpinBox* spinBoxChord;
    QSpinBox* intSpinBoxMethod;

    // area interface
    QPushButton* btnExpendAreaDetails;
    QWidget* widgetAreaDetails;
    QDoubleSpinBox * spinBoxAreaXY;
    QDoubleSpinBox * spinBoxAreaXZ;
    QDoubleSpinBox * spinBoxAreaYZ;
    QDoubleSpinBox * spinBoxAreaT;


    // internal sweep
    double internalSweep;
    double internalChord;
    int internalMethod;

    // internal area
    double internalAreaXY;
    double internalAreaXZ;
    double internalAreaYZ;
    double internalAreaT;
};


#endif //TIGL_TIGLVIEWERWINGWIDGET_H
