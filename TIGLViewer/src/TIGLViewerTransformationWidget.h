//
// Created by cfse on 3/21/18.
//

#ifndef TIGL_TIGLVIEWERTRANSFORMATIONWIDGET_H
#define TIGL_TIGLVIEWERTRANSFORMATIONWIDGET_H

#include "ModificatorWidget.h"
#include "CPACSCreatorLib/CPACSTreeItem.h"
#include "CPACSCreatorLib/CPACSTransformation.h"
#include "CPACSCreatorLib/Point.h"
#include <QDoubleSpinBox>

class TIGLViewerTransformationWidget : public ModificatorWidget
{
    Q_OBJECT


public:
    TIGLViewerTransformationWidget(QWidget * parent = 0);
    // Initialize the linked objects
    void init(ModificatorManager* associate) override ;

    void setTransformation(cpcr::CPACSTreeItem* transformationItem);
    void setSpinBoxesFromInternal();
    void setInternalFromSpinBoxes();

    void apply() override ;

protected:

    void keyPressEvent(QKeyEvent *event);

private:

    cpcr::CPACSTreeItem * transformationItem;

    QDoubleSpinBox* boxSX;
    QDoubleSpinBox* boxSY;
    QDoubleSpinBox* boxSZ;

    QDoubleSpinBox* boxRX;
    QDoubleSpinBox* boxRY;
    QDoubleSpinBox* boxRZ;

    QDoubleSpinBox* boxTX;
    QDoubleSpinBox* boxTY;
    QDoubleSpinBox* boxTZ;

    cpcr::CPACSTransformation transformation;


};



#endif //TIGL_TIGLVIEWERTRANSFORMATIONWIDGET_H
