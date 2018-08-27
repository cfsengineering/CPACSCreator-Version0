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
// Created by makem on 11/04/18.
//

#include "CPACSPositioning.h"
#include "Helper.h"

double cpcr::CPACSPositioning::getDihedralAngle() const {
    return dihedralAngle;
}

void cpcr::CPACSPositioning::setDihedralAngle(double dihedralAngle) {
    CPACSPositioning::dihedralAngle = dihedralAngle;
}

const std::string &cpcr::CPACSPositioning::getFromSectionUID() const {
    return fromSectionUID;
}

void cpcr::CPACSPositioning::setFromSectionUID(const std::string &fromSectionUID) {
    CPACSPositioning::fromSectionUID = fromSectionUID;
}

double cpcr::CPACSPositioning::getLength() const {
    return length;
}

void cpcr::CPACSPositioning::setLength(double length) {
    CPACSPositioning::length = length;
}

double cpcr::CPACSPositioning::getSweepAngle() const {
    return sweepAngle;
}

void cpcr::CPACSPositioning::setSweepAngle(double sweepAngle) {
    CPACSPositioning::sweepAngle = sweepAngle;
}

const std::string &cpcr::CPACSPositioning::getToSectionUID() const {
    return toSectionUID;
}

void cpcr::CPACSPositioning::setToSectionUID(const std::string &toSectionUID) {
    CPACSPositioning::toSectionUID = toSectionUID;
}

cpcr::CPACSPositioning::CPACSPositioning() {

    dihedralAngle = 0;
    fromSectionUID = "";
    length = 0;
    sweepAngle = 0;
    toSectionUID = "";

}

cpcr::CPACSPositioning::CPACSPositioning(double dihedral, std::string from, double l, double sweep, std::string to) {

    dihedralAngle = dihedral;
    fromSectionUID = from;
    length = l;
    sweepAngle = sweep;
    toSectionUID = to;

}

bool cpcr::CPACSPositioning::operator==(const cpcr::CPACSPositioning &other) {

    bool r = true;
    r = r && ( other.fromSectionUID == fromSectionUID);
    r = r && ( other.length == length);
    r = r && ( other.dihedralAngle == dihedralAngle);
    r = r && ( other.sweepAngle == sweepAngle);
    r = r && ( other.toSectionUID == toSectionUID);

    return r;
}




Eigen::Matrix4d cpcr::CPACSPositioning::getPositioningAsMatrix() {

    Eigen::Vector3d t = this->getPositioningAsTranslationVector();
    Eigen::Matrix4d mt;
    mt = mt.Identity();

    mt.row(0).col(3) << t[0];
    mt.row(1).col(3) << t[1];
    mt.row(2).col(3) << t[2];

    return mt;

}


Eigen::Vector3d cpcr::CPACSPositioning::getPositioningAsTranslationVector() {

    Eigen::Vector3d v ;
    v << 0, length, 0;

    Eigen::Quaterniond q1, q2   ;
    q1 = Eigen::AngleAxisd( - DegreeToRadian(sweepAngle), Eigen::Vector3d::UnitZ() ); // the sweep angle is in the oposite direction as the posititive rotation
    q2 = Eigen::AngleAxisd( DegreeToRadian(dihedralAngle), Eigen::Vector3d::UnitX() );

    Eigen::Vector3d r;
    r = (q2 * q1) * v;      // first we multiple by q1 (sweep) then by q2 (dihedral), this rotation takes in world place

    return r;
}



void cpcr::CPACSPositioning::setFromVector(Eigen::Vector3d v) {


    length = v.norm();
    if ( IsApprox(length, 0, 0.00001)){ // to standardize de case of zero
        sweepAngle = 0;
        dihedralAngle = 0;
        return;
    }

    Eigen::Vector3d v3 ;
    v3 << 0, sqrt(pow(v(1),2) + pow(v(2),2)), 0;
    if( v(1) < 0 ){ // take care of the sign of v3
        v3 = -1 * v3;
    }

    double a = RadianToDegree( atan2( v3(1) , v(0)) ) ;
    sweepAngle = 90 - a;


    double b =  RadianToDegree( atan2(v(2), v(1)) );
    if( v(1) < 0 ){  // We start from a point on the oder side of the quadrant
        dihedralAngle = - 180 + b;
    }else{
        dihedralAngle = b;
    }

    roundValues();

}

void cpcr::CPACSPositioning::roundValues() {

    // trick to get the special value to 90, 0 // todo generalize
    if( IsApprox(dihedralAngle, 0, 0.001)) {
        dihedralAngle = 0;
    }
    if(IsApprox(dihedralAngle,90, 0.001) ) {
        dihedralAngle =90;
    }
    if( IsApprox(dihedralAngle, 180, 0.001)) {
        dihedralAngle = 180;
    }
    if(IsApprox(dihedralAngle,270, 0.001) ) {
        dihedralAngle =270;
    }
    if(IsApprox(dihedralAngle,360, 0.001) ) {
        dihedralAngle =0;
    }
    if(IsApprox(dihedralAngle,-90, 0.001) ) {
        dihedralAngle =-90;
    }
    if( IsApprox(dihedralAngle, -180, 0.001)) {
        dihedralAngle = -180;
    }
    if(IsApprox(dihedralAngle,-270, 0.001) ) {
        dihedralAngle =-270;
    }
    if(IsApprox(dihedralAngle,-360, 0.001) ) {
        dihedralAngle =0;
    }

    if( IsApprox(sweepAngle, 0, 0.001)) {
        sweepAngle = 0;
    }
    if(IsApprox(sweepAngle, 90, 0.001) ) {
        sweepAngle =90;
    }
    if( IsApprox(sweepAngle, 180, 0.001)) {
        sweepAngle = 180;
    }
    if(IsApprox(sweepAngle, 270, 0.001) ) {
        sweepAngle =270;
    }
    if(IsApprox(sweepAngle, 360, 0.001) ) {
        sweepAngle =0;
    }
    if(IsApprox(sweepAngle, -90, 0.001) ) {
        sweepAngle =-90;
    }
    if( IsApprox(sweepAngle, -180, 0.001)) {
        sweepAngle = -180;
    }
    if(IsApprox(sweepAngle, -270, 0.001) ) {
        sweepAngle =-270;
    }
    if(IsApprox(sweepAngle, -360, 0.001) ) {
        sweepAngle =0;
    }
    if(IsApprox(length,0, 0.00001)){
        length = 0;
    }
}
