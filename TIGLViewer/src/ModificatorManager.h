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
#include "ProfilesDBManager.h"
#include "TIGLViewerPositioningsWidget.h"


class ModificatorManager: public QObject {
    Q_OBJECT

public slots:
    void dispatch(cpcr::CPACSTreeItem * item ) ;
    void applyCurrentModifications();
    // simply reset the values displayed by the current modificator from the file
    void applyCurrentCancellation();

public:
    ModificatorManager(
                       CPACSCreatorAdapter* adapter,
                       QWidget* applyInterface,
                       TIGLViewerTransformationWidget* transformationModificator,
                       TIGLViewerWingWidget* wingModificator,
                       ProfilesDBManager* profilesDB,
                       TIGLViewerPositioningsWidget* positioningsModificator
                       );

    void reset();
    void setTransformationModificator(cpcr::CPACSTreeItem * item );
    void setWingModificator(cpcr::CPACSTreeItem * item);
    void setPositioningsModificator(cpcr::CPACSTreeItem * item);
    void hideAll();

    CPACSCreatorAdapter* adapter;
    ProfilesDBManager* profilesDB;

private:

    TIGLViewerTransformationWidget* transformationModificator;
    TIGLViewerWingWidget* wingModificator;
    TIGLViewerPositioningsWidget* positioningsModificator;

    ModificatorWidget* currentModificator;
    QWidget* widgetApply;
    QPushButton* commitButton;
    QPushButton* cancelButton;


};


#endif //TIGL_MODIFICATORMANAGER_H
