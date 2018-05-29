//
// Created by makem on 29/05/18.
//

#ifndef TIGL_MODIFICATORMANAGER_H
#define TIGL_MODIFICATORMANAGER_H


#include <CPACSCreatorLib/CPACSTreeItem.h>
#include "TIGLViewerTransformationWidget.h"
#include "CPACSCreatorAdapter.h"


class ModificatorManager: public QObject {
    Q_OBJECT

public slots:
    void dispatch(cpcr::CPACSTreeItem * item ) ;

public:
    ModificatorManager(CPACSCreatorAdapter* adapter, TIGLViewerTransformationWidget* transformationModificator);

    void setTransformationModificator(cpcr::CPACSTreeItem * item );
    void hideAll();

private:
    CPACSCreatorAdapter* adapter;
    TIGLViewerTransformationWidget* transformationModificator;
};


#endif //TIGL_MODIFICATORMANAGER_H
