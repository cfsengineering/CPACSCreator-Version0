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
// Created by cfse on 7/3/18.
//

#ifndef TIGL_PROFILESDBMANAGER_H
#define TIGL_PROFILESDBMANAGER_H

#include "QObject"
#include "QDir"

class ProfilesDBManager: public QObject {

Q_OBJECT

public:
    ProfilesDBManager();
    void setAirfoilsFromCurrentCpacsFile(QStringList newAirfoils);
    QStringList getAvailableAirfoils();

    // Return true if the airfoil id is in airfoisFromCPACS or in the DB
    // Return false otherwise ( also for Combined and None)
    bool idIsValid(QString airfoilId);

    bool idIsCPACSID(QString airfoilId);

    bool idIsDBID(QString airfoilId);

    QString getPathForDBAirfoil(QString airfoilId);

    QString getIdWithoutSuffix(QString airfoilId);

    QString suffixForInFile = " (IN FILE)" ;
    QString suffixForDB  = " (DB)";
    QString multipleAirfoilsInUse = " Combined";
    QString noneAirfoil = " None";


private:
    QDir rootDir;
    QStringList airfoilsFromCurentCpacsFile;



};


#endif //TIGL_PROFILESDBMANAGER_H
