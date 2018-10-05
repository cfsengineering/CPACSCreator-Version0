/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
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

    void setSweepAngle(cpcr::CPACSTreeItem * item, double angle, double chordPercent, QString method);

    double getDihedralAngle(cpcr::CPACSTreeItem * item, double chordPercent);
    void setDihedralAngle(cpcr::CPACSTreeItem *item, double angle, double chordPercent);

    std::list<std::pair<cpcr::CPACSTreeItem*, cpcr::CPACSPositioning >> getPositionings(cpcr::CPACSTreeItem* item);
    void setPositioning(cpcr::CPACSTreeItem* item, cpcr::CPACSPositioning );

    // set the anchor values passed as argument
    void getAnchorValues(cpcr::CPACSTreeItem* item, double& x, double& y, double& z);

    void setAnchorValues(cpcr::CPACSTreeItem* item, double x, double y, double z );

    QString getWingOrientation(cpcr::CPACSTreeItem* item);

    void setWingOrientation(cpcr::CPACSTreeItem* item, QString wingOrientation );


    QString getWingSymmetry(cpcr::CPACSTreeItem* item);

    void setWingSymmetry( cpcr::CPACSTreeItem* itemt, QString newSymmetry);

    QStringList getAirfoilsUid();
    // return "Combined" if multiple airfoil is used,
    // "None" if no airfoil is find
    // "AifoilUid (IN FILE)" if one airfoil is used for all the degement
    QString getAirfoilValueForWing(cpcr::CPACSTreeItem *item);

    // set all airfoils in this wing
    void setAllAirfoilsInWing(cpcr::CPACSTreeItem *item, QString airfoil);

    double getWingArea(cpcr::CPACSTreeItem * item, cpcr::PLANE plane);

    void setWingAreaKeepAR(cpcr::CPACSTreeItem * item, double newArea);

    void setWingAreaKeepSpan(cpcr::CPACSTreeItem * item, double newArea);

    double getWingSpan(cpcr::CPACSTreeItem * item);

    void setWingSpanKeepAR(cpcr::CPACSTreeItem * item, double newSpan);

    void setWingSpanKeepArea(cpcr::CPACSTreeItem * item, double newSpan);

    double getWingAR(cpcr::CPACSTreeItem * item);

    void setWingARKeepSpan(cpcr::CPACSTreeItem * item, double ar);

    void setWingARKeepArea(cpcr::CPACSTreeItem * item, double ar);

    void getStdValues(cpcr::CPACSTreeItem * item, bool& stdAirfoil, bool& stdSections, bool& stdPositionings, bool& stdAnchor);

    void setStdValues(cpcr::CPACSTreeItem * item, bool stdAirfoil, bool stdSections, bool stdPositionings, bool stdAnchor);


    double getFuselageLength(cpcr::CPACSTreeItem * item);

    void setFuselageLength(cpcr::CPACSTreeItem * item, double newLength);

    // Get all the uid of the elements from the fuselage in the fuselage order
    QStringList getFuselageElementUIDs(cpcr::CPACSTreeItem * item);

    double getFuselageLengthBetween(QString UID1, QString UID2);

    void setFuselageLengthBetween(QString Uid1, QString Uid2, double newLength);

    double getFuselageMaximalCircumference(cpcr::CPACSTreeItem* item);

    void setFuselageMaximalCircumference(cpcr::CPACSTreeItem* item, double newCircumference);


    cpcr::CPACSTreeItem * getRoot()const;
    void resetCpacsConfig(const TIGLViewerDocument& config);
    bool isValid();

    void setSavingFile(QString savingFile);

    void writeToFile();

    void close();

protected:

    bool testItem(cpcr::CPACSTreeItem * item, cpacsType type );

private:

    cpcr::AircraftTree aircraftTree;
    // mutable QMutex mutex;   // to enshure that the tree root is not accessed when update is done

    ProfilesDBManager* profilesDB;  // used to adapt airfoil values

};


#endif //TIGL_CPACSCREATORADAPTER_H
