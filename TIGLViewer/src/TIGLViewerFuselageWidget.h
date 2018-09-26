//
// Created by cfse on 9/26/18.
//

#ifndef TIGL_TIGLIVIEWERFUSELAGEWIDGET_H
#define TIGL_TIGLIVIEWERFUSELAGEWIDGET_H

#include "ModificatorWidget.h"
#include "Crea"
#include <QDoubleSpinBox>

class TIGLIViewerFuselageWidget : public ModificatorWidget {

Q_OBJECT


public:
    TIGLIViewerFuselageWidget(QWidget * parent = 0);
    // Initialize the linked objects
    void init(ModificatorManager* associate) override ;

    void apply() override ;
    void reset() override ;

    void setFuselage(cpcr::CPACSTreeItem* fuselageItem)


private:

    cpcr::CPACSTreeItem * fuselageItem;

    QDoubleSpinBox* spinBoxLength;
    double internalLength;




};


#endif //TIGL_TIGLIVIEWERFUSELAGEWIDGET_H
