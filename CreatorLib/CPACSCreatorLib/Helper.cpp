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
// Created by makem on 25/04/18.
//

#include "Helper.h"
#include "Point.h"
#include "CreatorException.h"
#include "easylogging++.h"


/*
   Calculate the line segment PaPb that is the shortest route between
   two lines P1P2 and P3P4. Calculate also the values of mua and mub where
      Pa = P1 + mua (P2 - P1)
      Pb = P3 + mub (P4 - P3)
   Return FALSE if no solution exists.
   Original code taken from : http://paulbourke.net/geometry/pointlineplane/lineline.c
   Done by:
*/

bool cpcr::LineLineIntersect(const cpcr::Point &p1, const cpcr::Point &p2, const cpcr::Point &p3, const cpcr::Point &p4,
                             cpcr::Point &pa, cpcr::Point &pb, double &mua, double &mub)
{

    Point p13,p43,p21;
    double EPS = 0.0001; //TODO how to manage epsilon and macro in this software
    double d1343,d4321,d1321,d4343,d2121;
    double numer,denom;

    p13.x = p1.x - p3.x;
    p13.y = p1.y - p3.y;
    p13.z = p1.z - p3.z;
    p43.x = p4.x - p3.x;
    p43.y = p4.y - p3.y;
    p43.z = p4.z - p3.z;
    if (abs(p43.x) < EPS && abs(p43.y) < EPS && abs(p43.z) < EPS)
        return(false);  // value to close
    p21.x = p2.x - p1.x;
    p21.y = p2.y - p1.y;
    p21.z = p2.z - p1.z;
    if (abs(p21.x) < EPS && abs(p21.y) < EPS && abs(p21.z) < EPS)
        return(false);

    d1343 = p13.x * p43.x + p13.y * p43.y + p13.z * p43.z;
    d4321 = p43.x * p21.x + p43.y * p21.y + p43.z * p21.z;
    d1321 = p13.x * p21.x + p13.y * p21.y + p13.z * p21.z;
    d4343 = p43.x * p43.x + p43.y * p43.y + p43.z * p43.z;
    d2121 = p21.x * p21.x + p21.y * p21.y + p21.z * p21.z;

    denom = d2121 * d4343 - d4321 * d4321;
    if (abs(denom) < EPS)
        return(false);
    numer = d1343 * d4321 - d1321 * d4343;

    mua = numer / denom;
    mub = (d1343 + d4321 * mua) / d4343;

    pa.x = p1.x + mua * p21.x;
    pa.y = p1.y + mua * p21.y;
    pa.z = p1.z + mua * p21.z;
    pb.x = p3.x + mub * p43.x;
    pb.y = p3.y + mub * p43.y;
    pb.z = p3.z + mub * p43.z;

    return(true);
}



cpcr::Point cpcr::LineLineStrictIntersect(const cpcr::Point &p1, const cpcr::Point &p2, const cpcr::Point &p3,
                                          const cpcr::Point &p4) {

    cpcr::Point pa, pb, intersection;
    double mua, mub;
    bool r = LineLineIntersect(p1, p2, p3, p4, pa, pb, mua, mub);
    if( ! r ){
        throw CreatorException("Lines are not correctly defined");
    }
    if( ! pa.toEigen().isApprox(pb.toEigen(), 0.0001)){
        throw CreatorException("Lines do not intesect");
    }

    return pa;
}






cpcr::CPACSTransformation
cpcr::TransformChord(const Eigen::Vector4d &p1, const Eigen::Vector4d &p2, const Eigen::Vector4d &p3,
                     const Eigen::Vector4d &p1P, const Eigen::Vector4d &p2P, const Eigen::Vector4d &p3P) {


    Eigen::Vector4d center = p1 + 0.5  *(p2-p1) ; // center of segment ab
    Eigen::Vector4d centerP = p1P + 0.5  *(p2P-p1P) ; // center of segment ab


    // transformation: center of p -> origin
    Eigen::Matrix4d t1 = Eigen::Matrix4d::Identity();
    t1(0,3) = - center(0);
    t1(1,3) = - center(1);
    t1(2,3) = - center(2);

    Eigen::Vector4d p1a,p2a,p3a; // pxXa is the point with the center at orign
    p1a = t1 * p1;
    p2a = t1 * p2;
    p3a = t1 * p3;


    // transformation: center of pP -> orgin
    Eigen::Matrix4d t1P = Eigen::Matrix4d::Identity();
    t1P(0,3) = - centerP(0);
    t1P(1,3) = - centerP(1);
    t1P(2,3) = - centerP(2);

    Eigen::Vector4d  p1Pa,p2Pa,p3Pa; // pxXa is the point with the intersection at orign
    p1Pa = t1P * p1P;
    p2Pa = t1P * p2P;
    p3Pa = t1P * p3P;


    // normal of plane p
    Eigen::Vector3d segATemp = p2.block<3,1>(0,0) - p1.block<3,1>(0,0);
    Eigen::Vector3d segBTemp = p3.block<3,1>(0,0) - p1.block<3,1>(0,0);
    Eigen::Vector3d normal = segATemp.cross(segBTemp);
    normal.normalize();

    // normal of plane pP
    segATemp = p2P.block<3,1>(0,0) - p1P.block<3,1>(0,0);
    segBTemp = p3P.block<3,1>(0,0) - p1P.block<3,1>(0,0);
    Eigen::Vector3d normalP = segATemp.cross(segBTemp);
    normalP.normalize();

    // rotation to get from plane pP orientation to plane p orientation
    Eigen::Quaterniond q1, q2,q;
    q1.setFromTwoVectors(normalP, normal);

    // rotation of the plane to get p1ap2a in the same "direction" as p1Pa p2Pa, remark normaly pa and pPa can not be null
    Eigen::Vector3d p1PTemp;
    p1PTemp = q1 * p1Pa.block<3,1>(0,0);
    q2.setFromTwoVectors(p1PTemp,p1a.block<3,1>(0,0) ); // assuming that the origin is at intersection for both plane
    // and that p1a is not zero

    q = q2 * q1 ;// first q1 then q2
    q.normalize();
    Eigen::Matrix4d rotPM = Eigen::Matrix4d::Identity();
    rotPM.block<3,3>(0,0) = q.toRotationMatrix(); // rotM transform pPa into the same direction as pa with one rotation
    Eigen::Matrix4d rotM = rotPM.inverse();


    // get the uniform scaling
    double s;
    Eigen::Vector4d p1Pb, p2Pb, p3Pb; // pxPb should be the coordinate pP rotated such that the are on the same orientation as pa
    p1Pb = rotPM * p1Pa;
    p2Pb = rotPM * p2Pa;
    p3Pb = rotPM * p3Pa;

    // Now normally, we have p1Pb and p2Pb in the same direction as p1a and p2a
    // So we have s * p1PB = p1a, with s a scalar
    // Remark that is not necessary the case for p3Pb and p3a, shear efect for example!

    // We take the bigger coordinate of p1Pb to make the scaling
    int maxCoorIdx = 0;
    for( int i = 0; i < 3; i++){
        if( p1Pb(i) > p1Pb(i) ){
            maxCoorIdx = i;
        }
    }

    s = p1a(maxCoorIdx) / p1Pb(maxCoorIdx);

    Eigen::Matrix4d scalPM = Eigen::Matrix4d::Identity();
    scalPM(0,0) = s;
    scalPM(1,1) = s;
    scalPM(2,2) = s;
    Eigen::Matrix4d scalM = scalPM.inverse();

    // Test if its work
    Eigen::Vector4d testP1, testP2,testP3;
    testP1 = scalPM * rotPM * p1Pa;
    testP2 = scalPM * rotPM * p2Pa;
    testP3 = scalPM * rotPM * p3Pa;

    if( ! ( testP1.isApprox(p1a, 0.000001 ) && testP2.isApprox(p2a, 0.000001 ) ) ){
        throw CreatorException( "TransformChord: the to principal coord are not preserved!" );
    }
    if( !(testP3.isApprox(p3a, 0.00001) ) ) {
        LOG(WARNING) << " third point not conserved";
    }

    // get the global translation
    // T1 * M * T2 = M * T with T = t2 + M^-1*t1
    Eigen::Matrix4d transM = Eigen::Matrix4d::Identity();
    transM = t1P.inverse();
    Eigen::Vector3d APt =  rotM.block<3,3>(0,0) * scalM.block<3,3>(0,0) * t1.block<3,1>(0,3);
    transM.block<3,1>(0,3) = transM.block<3,1>(0,3) + APt;
    Eigen::Matrix4d transPM = transM.inverse();;

    // create the transformation
    Eigen::Vector3d r = (rotM.block<3,3>(0,0)).eulerAngles(0,1,2);
    cpcr::CPACSTransformation transformation(
            scalM(0,0),scalM(1,1),scalM(2,2),
            RadianToDegree(r(0)), RadianToDegree(r(1)), RadianToDegree(r(2)),
            transM(0,3),transM(1,3),transM(2,3)
    );


    testP1 = transformation.getTransformationAsMatrix() * p1;
    testP2 = transformation.getTransformationAsMatrix() * p2;
    testP3 = transformation.getTransformationAsMatrix() * p3;

    if( ! ( testP1.isApprox(p1P, 0.000001 ) && testP2.isApprox(p2P, 0.000001 ) ) ){
        throw CreatorException( "TransformChord: the to principal coord are not preserved!" );
    }
    if( !(testP3.isApprox(p3P, 0.00001) ) ) {
        LOG(WARNING) << " third point not conserved";
    }


    return transformation;
}

bool cpcr::IsApprox(double x, double y, double delta) {
    if( fabs( x - y ) < delta ){
        return true;
    }else{
        return false;
    }
}

