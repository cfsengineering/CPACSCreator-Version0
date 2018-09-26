//
// Created by cfse on 9/26/18.
//

#ifndef TIGL_TIGLVIEWERFUSELAGEWIDGET_H
#define TIGL_TIGLVIEWERFUSELAGEWIDGET_H

#include "ModificatorWidget.h"
#include "CPACSCreatorLib/CPACSTreeItem.h"
#include <QDoubleSpinBox>

class TIGLViewerFuselageWidget : public ModificatorWidget {

Q_OBJECT


public:
    TIGLViewerFuselageWidget(QWidget * parent = 0);
    // Initialize the linked objects
    void init(ModificatorManager* associate) override ;

    void apply() override ;
    void reset() override ;

    void setFuselage(cpcr::CPACSTreeItem* fuselageItem);


private:

    cpcr::CPACSTreeItem * fuselageItem;

    QDoubleSpinBox* spinBoxLength;
    double internalLength;




};


#endif //TIGL_TIGLVIEWERFUSELAGEWIDGET_H
