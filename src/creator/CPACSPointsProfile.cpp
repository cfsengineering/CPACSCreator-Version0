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
// Created by cfse on 6/29/18.
//

#include "CPACSPointsProfile.h"
#include "Helper.h"

#include <fstream>
#include <regex>


#include "CTiglLogging.h"
#include "CreatorException.h"


namespace cpcr {
    CPACSPointsProfile::CPACSPointsProfile() {

        name = "not-set";
        uid = "not-set";
        precision = 2;
    }



    std::string CPACSPointsProfile::transformVectorToString(const std::vector<double> & vect) const {

        std::string r = "";

        for (double i : vect) {
            r = r + ToStringWithPrecision( i, 15 ) + ";";
        }

        if (r != "") {
            r.pop_back();
        }

        return r;
    }

    CPACSPointsProfile::CPACSPointsProfile(std::string inputFile) {
        precision = 2;

        std::string line;
        std::ifstream file(inputFile) ;

        if (file.is_open())
        {
            while ( getline (file,line) )
            {
                std::stringstream ss(line);
                std::string token;
                std::vector<std::string> tokens;
                double x, z;

                while (std::getline(ss, token, ' ')) {
                    tokens.push_back(token);
                }
                if(tokens.size() != 2){ // TODO handel the case of line with two worlds
                    LOG(INFO) << "AIRFOIL line " << line << " not taken as coordinates";
                }else{
                    x = std::stod(tokens.at(0));
                    z = std::stod(tokens.at(1));
                    xs.push_back(x);
                    ys.push_back(0);    // y coordinates is always 0
                    zs.push_back(z);
                }

            }
            file.close();
        }

        int extPos = inputFile.rfind(".dat");
        name = inputFile;
        uid =  inputFile.substr(0, extPos);
        int prefixPos = uid.rfind("/");
        uid = uid.substr(prefixPos + 1 , uid.size() - prefixPos -1);

    }

    Eigen::Vector3d CPACSPointsProfile::getTrailingEdge() const {
        if (xs.size() == 0) {
            throw CreatorException("CPACSPointsProfile: call getTrailingEdge but not data is set");
        }
        return Eigen::Vector3d(xs[0], ys[0], zs[0]);
    }

    // the leading point is the point the most distante from the tE
    Eigen::Vector3d CPACSPointsProfile::getLeadingEdge() const {
        Eigen::Vector3d tE = getTrailingEdge();

        Eigen::Vector3d lE ;
        double maxD = -1;
        Eigen::Vector3d tempP;
        double tempD;
        for (int i = 0; i < xs.size(); i++){
            tempP << xs[i], ys[i], zs[i];
            tempD = (tempP - tE).norm();
            if( tempD > maxD ){
                lE = tempP;
                maxD = tempD;
            }
        }

        return lE;
    }


    int CPACSPointsProfile::getLeadingEdgeIdx() const {
        Eigen::Vector3d tE = getTrailingEdge();
        Eigen::Vector3d lE ;
        double maxD = -1;
        Eigen::Vector3d tempP;
        int idx = -1;
        double tempD;
        for (int i = 0; i < xs.size(); i++){
            tempP << xs[i], ys[i], zs[i];
            tempD = (tempP - tE).norm();
            if( tempD > maxD ){
                lE = tempP;
                maxD = tempD;
                idx = i;
            }
        }
        return idx;
    }

    void CPACSPointsProfile::tryToMakeUidUnique() {
        uid = uid + "-v";
    }

    CPACSPointsProfile::CPACSPointsProfile(std::string uid, std::string name, std::string sXs, std::string sYs, std::string sZs) {

        precision = 2;

        this->uid = uid;
        this->name = name;
        xs = transformStringToVector(sXs);
        ys = transformStringToVector(sYs);
        zs = transformStringToVector(sZs);


    }

    std::vector<double> CPACSPointsProfile::transformStringToVector(std::string line) const {

        std::stringstream ss(line);
        std::string token;
        std::vector<double> r;

        double temp;
        while (std::getline(ss, token, ';')) {
            temp = std::stod(token);
            r.push_back(temp);
        }
        return r;
    }



    bool CPACSPointsProfile::isOnXZPlane() {
        bool r = true;
        for(double y: ys){
            if(y != 0){
                r = false;
            }
        }
        return r;
    }


    bool CPACSPointsProfile::areLEAndTEOnZeroAndOne() {

        Eigen::Vector3d zero, oneX ;
        zero << 0,0,0;
        oneX << 1,0,0;

        //double delta = pow(10, -precision) / 2.0 ;

        if(!getLeadingEdge().isApprox(zero, 0.005)|| (!getTrailingEdge().isApprox(oneX, 0.005)) ){ // small difference are accepted for trailing edge to simplify normalization
            return false;
        }else{
            return true;
        }

    }

    bool CPACSPointsProfile::isNormalized() {
        bool r = true;

        r = r && areLEAndTEOnZeroAndOne();
        r = r && isOnXZPlane();
        r = r && isInMathematicalOrder();

        return r;
    }

    Eigen::Matrix4d CPACSPointsProfile::normalize() {

        // TODO find why there is sometimes big "approximationo error" ??
        // TODO: Maybe and normalization for profile not on XZ-plane

        if( ! isOnXZPlane() ){
            throw CreatorException("Only XZ profile can be normalized");
        }

        Eigen::Matrix4d normalizationM =  Eigen::Matrix4d::Identity();

        if(isNormalized()){
            return   normalizationM ;
        }


        // get particular point of the profile
        int lEIdx = getLeadingEdgeIdx();    // we prefer to use idx to be sure that the choice is not influenced by some small calculation changes
        int furthestIdx = getFurthestPointFromChordIdx();
        Eigen::Vector3d lE = getLeadingEdge();
        Eigen::Vector3d tE = getTrailingEdge();
        Eigen::Vector3d furthest = getPointAtIdx(furthestIdx);


        // set the chord length = 1
        Eigen::Vector3d lETE = tE - lE;
        double s = 1.0 / lETE.norm();

        for (int i = 0; i < xs.size(); i++) {
            xs[i] = s * xs[i];
            ys[i] = s * ys[i];
            zs[i] = s * zs[i];
        };

        Eigen::Matrix4d ms = Eigen::Matrix4d::Identity() ;
        // set the scaling as the diagonal of the scaling matrix
        ms(0,0) = s;
        ms(1,1) = s;
        ms(2,2) = s;
        normalizationM = ms * normalizationM;



        // set LE to zero
        Eigen::Vector3d zero, translate;
        zero << 0,0,0;
        translate = - getPointAtIdx(lEIdx);

        if( lE != zero ){
            for (int i = 0; i < xs.size(); i++) {
                xs[i] = xs[i] + translate(0);
                ys[i] = ys[i] + translate(1);
                zs[i] = zs[i] + translate(2);
            };
        }
        Eigen::Matrix4d ts = Eigen::Matrix4d::Identity() ;
        ts(0,3) = translate(0);
        ts(1,3) = translate(1);
        ts(2,3) = translate(2);

        normalizationM = ts * normalizationM;

        // Rotate such that tE is on the x axis

        Eigen::Vector3d oneX, oneY;
        oneX << 1,0,0;
        oneY << 0,1,0;

        tE = getPointAtIdx(0);

        // rotation to get  the chord one the X axis
        Eigen::Quaterniond q1, q2, q;
        q1.setFromTwoVectors(tE, oneX);

//        OLD METHOD; tries to get to generalize ( buggy with mathematical order)
//        perp = q1 * perp; // update perp
//        tE = q1 * tE;
//
//        // rotation to get the airfoil in XZ plane
//        Eigen::Vector3d n;
//        if( perpIdx < lEIdx ) {  // We consider that the point are given in mathematical order,
//            // so after leading edge it should be the upper part of the airfoil
//            n = tE.cross(perp);
//        }else{
//            n = perp.cross(tE);
//        }
//        q2.setFromTwoVectors(n,oneY);
//
//        q = q2 * q1 ;   // first q1 then q2

        q = q1;
        q.normalize();

        Eigen::Vector3d tempP;
        for (int i = 0; i < xs.size(); i++) {

            tempP << xs[i], ys[i], zs[i];
            tempP = q * tempP;
            xs[i] = tempP(0);
            ys[i] = tempP(1);
            zs[i] = tempP(2);

            // Remove some approximation due to calculation
            if( ys[i] < 0.000001 && ys[i] > -0.000001 ){
                ys[i] = 0;
            }else {
                throw CreatorException("The profile " + this->getUID() + "  cannot be transformed as expected");
            }
        }

        Eigen::Matrix4d rot = Eigen::Matrix4d::Identity();
        rot.block<3,3>(0,0) = q.toRotationMatrix();

        normalizationM = rot * normalizationM;

        if( ! isInMathematicalOrder() ){
            this->reverseOrder();
        }

        if( ! isNormalized() ){
            DLOG(ERROR) << "The profile "  + this->getUID() + " was not transformed has expected ";
        }

        return normalizationM;


    }






    Eigen::Vector3d CPACSPointsProfile::getFurthestPointFromChord() const {

        Eigen::Vector3d lE, lETE, tempP, lETempP, selectedP;
        double tempA, maxA;
        maxA = 0;
        int maxIdx = 0;
        selectedP << 0,0,0;
        lE = getLeadingEdge();
        lETE =  getTrailingEdge() - lE;
        for (int i = 0; i < xs.size(); i++) {
            tempP << xs[i], ys[i], zs[i];
            lETempP = tempP - lE;
            tempA = lETE.cross(lETempP).norm();
            if( tempA > maxA){
                maxA = tempA;
                maxIdx = i;
                selectedP = tempP;
            }
        }

        return selectedP;
    }



    int CPACSPointsProfile::getFurthestPointFromChordIdx() const {

        Eigen::Vector3d lE, lETE, tempP, lETempP, selectedP;
        double tempA, maxA;
        maxA = 0;
        int maxIdx = 0;
        selectedP << 0,0,0;
        lE = getLeadingEdge();
        lETE =  getTrailingEdge() - lE;
        for (int i = 0; i < xs.size(); i++) {
            tempP << xs[i], ys[i], zs[i];
            lETempP = tempP - lE;
            tempA = lETE.cross(lETempP).norm();
            if( tempA > maxA){
                maxA = tempA;
                maxIdx = i;
                selectedP = tempP;
            }
        }

        return maxIdx;
    }





    bool CPACSPointsProfile::operator==(const CPACSPointsProfile &other) {

        if(other.getName() != this->getName()){
           return false;
        }

        if( xs.size() != other.xs.size() ) {
            return false;
        }

        Eigen::Vector3d otherP, thisP;
        for (int i = 0; i < xs.size(); i++) {
            if(xs[i] != other.xs[i] || ys[i] != other.ys[i] || zs[i] != other.zs[i]){
                return false;
            }
        }

        return true;
    }

    CPACSPointsProfile::CPACSPointsProfile(const CPACSPointsProfile &other) {
        precision = 2;

        this->name = other.name;
        this->uid = other.uid;
        this->xs = other.xs;
        this->ys = other.ys;
        this->zs = other.zs;


    }

    void CPACSPointsProfile::reverseOrder() {

        std::vector<double> tempXs;
        std::vector<double> tempYs;
        std::vector<double> tempZs;

        for( int i = xs.size() - 1; i >= 0 ; i -- ){
            tempXs.push_back(xs[i]);
            tempYs.push_back(ys[i]);
            tempZs.push_back(zs[i]);
        }

        xs = tempXs;
        ys = tempYs;
        zs = tempZs;

    }

    bool CPACSPointsProfile::isInMathematicalOrder() {

        // we determine the mathematical order by simply assuming that a positive mathematical order
        // have average sum before leading edge smaller than the average sum after leading edge.

        int lEIdx = getLeadingEdgeIdx();

        double sumInZBeforLE = 0;
        double sumInZAfterLE = 0;


        for( int i = 0; i < lEIdx ; i++){
            sumInZBeforLE += zs[i];
        }

        for(int i = lEIdx + 1; i < zs.size(); i ++){ // the lE is no taken in account
            sumInZAfterLE += zs[i];
        }

        double aB = sumInZBeforLE / lEIdx;
        double aA = sumInZAfterLE / (xs.size()-(lEIdx + 1) );
        if ( aB <= aA ){
            return true;
        } else{
            return false;
        }

    }

    Eigen::Vector3d CPACSPointsProfile::getPointAtIdx(int idx) {
        Eigen::Vector3d r;
        if(idx > xs.size()){
            CreatorException("CPACSPointsProfile: invalid index");
        }
        r << xs[idx], ys[idx], zs[idx];
        return r;
    };


}

