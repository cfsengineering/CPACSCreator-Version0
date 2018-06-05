//
// Created by makem on 30/05/18.
//

#ifndef TIGL_TIGLVIEWERWINGWIDGET_H
#define TIGL_TIGLVIEWERWINGWIDGET_H

#include "ModificatorWidget.h"
#include "QDoubleSpinBox"
#include "CPACSCreatorLib/CPACSTreeItem.h"


class TIGLViewerWingWidget : public ModificatorWidget {

    Q_OBJECT

public:

    TIGLViewerWingWidget(QWidget * parent = 0);

    void init(ModificatorManager * associate ) override ;
    void apply() override ;

    void setWing(cpcr::CPACSTreeItem* wing);
    void setSweepValue(double);


private:

    cpcr::CPACSTreeItem * wingItem;
    QDoubleSpinBox * spinBoxSweep ;
    QDoubleSpinBox * spinBoxAreaXY;
    QDoubleSpinBox * spinBoxAreaT;
    double internalSweep;
    double internalAreaXY;
    double internalAreaT;
};


#endif //TIGL_TIGLVIEWERWINGWIDGET_H
