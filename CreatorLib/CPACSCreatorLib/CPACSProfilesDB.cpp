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
// Created by cfse on 7/12/18.
//

#include "CPACSProfilesDB.h"
#include "easylogging++.h"

void cpcr::CPACSProfilesDB::init(cpcr::CPACSFile *newFile) {

    modifier = newFile;
    clean();
    if(modifier != nullptr && modifier->isValid() ){
        set();
        isSet = true;
    }else{
        isSet = false;
        LOG(WARNING) << "The given CPACSFile object is not valid";
    }
}


void cpcr::CPACSProfilesDB::set() {

    airfoilUIDs = modifier->getAirfoilsUid();
    CPACSPointsProfile tempProfile;
    bool tempIsPoints, tempIsNormalized;

    for(std::string uid : airfoilUIDs){

        tempIsPoints = modifier->isWingAirfoilPointList(uid);
        isPoints[uid] = tempIsPoints;

        if(tempIsPoints ){

            tempProfile = modifier->getAirfoil(uid);
            pointsProfiles[uid] = tempProfile;
            tempIsNormalized = tempProfile.isNormalized();
            isNormalized[uid] = tempIsNormalized;

            if( tempIsNormalized ){
                normalizedVersion[uid] = uid;
                normalizationM[uid] = Eigen::Matrix4d::Identity();
            }
            else{
                normalizedVersion[uid] = "";
                normalizationM[uid] = Eigen::Matrix4d::Identity();
            }
        }
        else{ // not point List
            // for the moment we simply not put any thing
            isNormalized[uid] = false; // we are not sure about this
        }

    }
}



void cpcr::CPACSProfilesDB::createAssociateNormalizedProfiles() {

    if(! isSet){
        LOG(WARNING) << "The profile DB is not set!";
        return ;
    }

    CPACSPointsProfile newProfile;
    std::vector<std::string> newAirfoilUIDs; // profile added by the normalization process;
    std::string newUID ;
    Eigen::Matrix4d tempNormalizationM;

    for(std::string uid : airfoilUIDs){

        if( isPoints[uid] && (! isNormalized[uid] ) && (normalizedVersion[uid] == "")  ){ // We support only point list profile

            newProfile = CPACSPointsProfile(pointsProfiles[uid]);
            newUID =  newProfile.getUID() + "-creatorNormalized";
            newProfile.setUID(newUID);
            newProfile.setName(newProfile.getName() + "-creatorNormalized; should not be modified manually, change the uid if you want to make some change.");
            tempNormalizationM = newProfile.normalize();
            newAirfoilUIDs.push_back(newUID);
            isPoints[newUID] = true;
            isNormalized[newUID] = true;
            normalizedVersion[newUID] = newUID;
            normalizationM[newUID] = Eigen::Matrix4d::Identity();
            pointsProfiles[newUID] = newProfile;

            modifier->addWingAirfoilOverwriteIfExist(newProfile); // add in the CPACS file (not saved)

            // Update normalization for old uid
            normalizedVersion[uid] = newProfile.getUID(); // update old
            normalizationM[uid] = tempNormalizationM; // update old


        }

    }
    // Update the airfoil uids
    for(std::string uid : newAirfoilUIDs){
        if( std::find( airfoilUIDs.begin(), airfoilUIDs.end(), uid) == airfoilUIDs.end()   ){
            airfoilUIDs.push_back(uid);
        }
    }
    modifier->save(); // save in file
}

cpcr::CPACSProfilesDB::CPACSProfilesDB() {
    isSet = false;
}

cpcr::CPACSProfilesDB::CPACSProfilesDB(cpcr::CPACSFile *file) {
    init(file);
}

void cpcr::CPACSProfilesDB::clean() {

    pointsProfiles.clear();
    isNormalized.clear();
    normalizedVersion.clear();
    normalizationM.clear();
    isPoints.clear();
    airfoilUIDs.clear();


}



