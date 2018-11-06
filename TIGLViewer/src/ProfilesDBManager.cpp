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

#include <QtCore/QCoreApplication>
#include "ProfilesDBManager.h"

#include "TIGLViewerException.h"

ProfilesDBManager::ProfilesDBManager() {
    rootDir = QDir("../AirfoilDB");
}


void ProfilesDBManager::clearAirfoilsFromCurrentCpacsFile() {
    airfoilsFromCurentCpacsFile.clear();
}



void ProfilesDBManager::setAirfoilsFromCurrentCpacsFile(QStringList newAirfoils) {
    clearAirfoilsFromCurrentCpacsFile();

    QString tempA;
    for( QString a : newAirfoils){
        tempA = a + suffixForInFile;
        airfoilsFromCurentCpacsFile.push_back(tempA);
    }
}



QStringList ProfilesDBManager::getAvailableAirfoils() {
    QStringList total;
    total = airfoilsFromCurentCpacsFile;

    QStringList filters;
    filters << "*.dat";
    for( QString dir : rootDir.entryList( filters ) ){
        total.push_back(dir + suffixForDB);
    }
    return total;
}


bool ProfilesDBManager::idIsValid(QString airfoilId) {

    if (airfoilId == multipleAirfoilsInUse || airfoilId == noneAirfoil){
        return false;
    }

    if( getAvailableAirfoils().contains(airfoilId)){
        return true;
    }

    return false;

}


bool ProfilesDBManager::idIsCPACSID(QString airfoilId) {
    QString suffix = airfoilId.right(suffixForInFile.size());
    return (suffix == suffixForInFile);
}

bool ProfilesDBManager::idIsDBID(QString airfoilId) {
    QString suffix = airfoilId.right(suffixForDB.size());
    return (suffix == suffixForDB);
}


QString ProfilesDBManager::getPathForDBAirfoil(QString airfoilId) {
    if(!idIsValid(airfoilId)){
        throw TIGLViewerException("invalid airfoil id");
    }
    if(!idIsDBID(airfoilId)){
        throw TIGLViewerException("airfoil is not a DB airfoil");
    }

    QString fn( airfoilId.left(airfoilId.size() - suffixForDB.count() ) );
    return rootDir.absoluteFilePath(fn);

}

QString ProfilesDBManager::getIdWithoutSuffix(QString airfoilId) {

    if(idIsCPACSID(airfoilId)){
        return airfoilId.left(airfoilId.size() - suffixForInFile.count() );
    }

    if(idIsDBID(airfoilId)){
        return airfoilId.left(airfoilId.size() - suffixForDB.count() );
    }

    return airfoilId;
}
