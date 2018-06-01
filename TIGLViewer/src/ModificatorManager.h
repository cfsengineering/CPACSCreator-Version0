//
// Created by makem on 29/05/18.
//

#ifndef TIGL_MODIFICATORMANAGER_H
#define TIGL_MODIFICATORMANAGER_H


#include <CPACSCreatorLib/CPACSTreeItem.h>
#include <QPushButton>
#include "TIGLViewerTransformationWidget.h"
#include "CPACSCreatorAdapter.h"
#include "TIGLViewerWingWidget.h"
#include "ModificatorWidget.h"



class ModificatorManager: public QObject {
    Q_OBJECT

public slots:
    void dispatch(cpcr::CPACSTreeItem * item ) ;
    void applyCurrentModifications();

public:
    ModificatorManager(
                       CPACSCreatorAdapter* adapter,
                       QPushButton* commitButton,
                       TIGLViewerTransformationWidget* transformationModificator,
                       TIGLViewerWingWidget* wingModificator
                       );

    void reset();
    void setTransformationModificator(cpcr::CPACSTreeItem * item );
    void setWingModificator(cpcr::CPACSTreeItem * item);
    void hideAll();

    CPACSCreatorAdapter* adapter;

private:

    TIGLViewerTransformationWidget* transformationModificator;
    TIGLViewerWingWidget* wingModificator;

    ModificatorWidget* currentModificator;
    QPushButton* commitButton;


};


#endif //TIGL_MODIFICATORMANAGER_H
