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
