//
// Created by cfse on 3/20/18.
//

#ifndef TIGL_CPACSCREATORADAPTER_H
#define TIGL_CPACSCREATORADAPTER_H

#include <QObject>
#include <QMutex>

#include "TIGLViewerDocument.h"

#include "CPACSCreatorLib/AircraftTree.h"
#include "CPACSCreatorLib/CPACSTreeItem.h"

class CPACSCreatorAdapter : public QObject{

    Q_OBJECT

signals:
    void newTransformationValues( QString xpath,
                                  double sx, double sy, double  sz,
                                  double rx, double ry, double  rz,
                                  double tx, double ty, double  tz);

public slots:

    void prepareTransformationValues(cpcr::CPACSTreeItem * item);
    void setTransformation(QString xpath,
                           double sx, double sy, double  sz,
                           double rx, double ry, double  rz,
                           double tx, double ty, double  tz);

public:

    cpcr::CPACSTreeItem * getRoot()const;
    void resetCpacsConfig(const TIGLViewerDocument& config);
    bool isValid();

private:

    cpcr::AircraftTree aircraftTree;
    mutable QMutex mutex;   // to enshure that the tree root is not accessed when update is done

};


#endif //TIGL_CPACSCREATORADAPTER_H
