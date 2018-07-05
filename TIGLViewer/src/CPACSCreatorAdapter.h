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
#include "ProfilesDBManager.h"

typedef std::string cpacsType;

class CPACSCreatorAdapter : public QObject{

    Q_OBJECT

public:

    CPACSCreatorAdapter(ProfilesDBManager* profilesDBManager );

    void setTransformation(cpcr::CPACSTreeItem *item, cpcr::CPACSTransformation transformation);
    cpcr::CPACSTransformation getTransformation(cpcr::CPACSTreeItem *item );

    double getSweepAngle(cpcr::CPACSTreeItem * item, double chordPercent);
    enum SweepMethod {ByTranslation =1 , ByShearing = 2};
    void setSweepAngle(cpcr::CPACSTreeItem * item, double angle, double chordPercent, int method);

    double getDihedralAngle(cpcr::CPACSTreeItem * item, double chordPercent);
    void setDihedralAngle(cpcr::CPACSTreeItem *item, double angle, double chordPercent);


    QStringList getAirfoilsUid();
    // return "Combined" if multiple airfoil is used,
    // "None" if no airfoil is find
    // "AifoilUid (IN FILE)" if one airfoil is used for all the degement
    QString getAirfoilValueForWing(cpcr::CPACSTreeItem *item);

    // set all airfoils in this wing
    void setAllAirfoilsInWing(cpcr::CPACSTreeItem *item, QString airfoil);


    double getWingArea(cpcr::CPACSTreeItem * item, TiglSymmetryAxis axis);

    cpcr::CPACSTreeItem * getRoot()const;
    void resetCpacsConfig(const TIGLViewerDocument& config);
    bool isValid();

    void writeToFile();

    void close();

protected:

    bool testItem(cpcr::CPACSTreeItem * item, cpacsType type );

private:

    cpcr::AircraftTree aircraftTree;
    mutable QMutex mutex;   // to enshure that the tree root is not accessed when update is done

    ProfilesDBManager* profilesDB;  // used to adapt airfoil values

};


#endif //TIGL_CPACSCREATORADAPTER_H
