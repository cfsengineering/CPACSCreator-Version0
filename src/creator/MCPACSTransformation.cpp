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

#include "CTiglLogging.h"
#include "MCPACSTransformation.h"
#include "Helper.h"
#include "CreatorException.h"

cpcr::MCPACSTransformation::MCPACSTransformation() {

    s = Point(1,1,1);
    r = Point(0,0,0);
    t = Point(0,0,0);


}

cpcr::MCPACSTransformation::MCPACSTransformation(cpcr::Point scaling, cpcr::Point rotation, cpcr::Point translation) {
    s = scaling;
    r = rotation;
    t = translation;

}

cpcr::MCPACSTransformation::MCPACSTransformation(double sx, double sy, double sz,
                                               double rx, double ry, double rz,
                                               double tx, double ty, double tz) {

    //TODO check 0 for scaling warning

    s = Point(sx,sy,sz);
    r = Point(rx,ry,rz);
    t = Point(tx,ty,tz);

}

bool cpcr::MCPACSTransformation::operator==(const cpcr::MCPACSTransformation &other) {
    return ( s == other.s && r == other.r && t == other.t );
}


/*
 * return the matrix that represent all the transform
 * We first apply the scale, then rotation, then the translation
 * The rotation is done first around x axis, then y axis, then z axis
 */
Eigen::Matrix4d cpcr::MCPACSTransformation::getTransformationAsMatrix() const {


    Eigen::Matrix4d r, ms, mr, mt;
    r = r.Identity();
    ms = getScalingAsMatrix();
    mr = getRotationAsMatrix();
    mt = getTranslationAsMatrix();

    // the apply rule is from right to left
    r = mt * mr * ms ;
    return r;
}

Eigen::Quaterniond cpcr::MCPACSTransformation::getRotationAsQuaternion() const {

    Eigen::Quaterniond q ;

    // The transform is express as Euler angle XY'Z".
    // We use the fact that an intrinsic rotation XY'Z" is equivalent to a extrinsic rotation ZYX :)
    q =  Eigen::AngleAxisd( r.x/180.0 * M_PI, Eigen::Vector3d::UnitX() )
         * Eigen::AngleAxisd(r.y/180.0 * M_PI, Eigen::Vector3d::UnitY() )
         * Eigen::AngleAxisd(r.z/180.0 * M_PI, Eigen::Vector3d::UnitZ() );
    return q;
}

Eigen::Matrix4d cpcr::MCPACSTransformation::getScalingAsMatrix() const{

    Eigen::Matrix4d ms;
    ms = ms.Identity();

    ms(0,0) =  s.x;
    ms(1,1) =  s.y;
    ms(2,2) =  s.z;

    return ms;
}


Eigen::Matrix4d cpcr::MCPACSTransformation::getRotationAsMatrix() const{

    Eigen::Matrix4d mr;
    mr = mr.Identity();

    Eigen::Quaterniond q = getRotationAsQuaternion();
    Eigen::Matrix3d qm = q.toRotationMatrix();
    mr.block(0,0,3,3) = qm;

    return mr;
}

Eigen::Matrix4d cpcr::MCPACSTransformation::getTranslationAsMatrix() const{

    Eigen::Matrix4d mt;
    mt = mt.Identity();

    mt(0,3) = t.x;
    mt(1,3) = t.y;
    mt(2,3) = t.z;

    return mt;
}

cpcr::MCPACSTransformation::MCPACSTransformation(const Eigen::Matrix4d &inMatrix) {

    Eigen::Transform<double, 3, Eigen::Affine> tempEigenTransform(inMatrix);
    t.x = tempEigenTransform.translation()(0);
    t.y = tempEigenTransform.translation()(1);
    t.z = tempEigenTransform.translation()(2);

    Eigen::Matrix3d mr, ms;

    // use eigen to decompose the matrix (using SVD inside)
    tempEigenTransform.computeRotationScaling( &mr , &ms);

     // set the scaling as the diagonal of the scaling matrix
    s.x = ms(0,0);
    s.y = ms(1,1);
    s.z = ms(2,2);

    Eigen::Vector3d tempRot = mr.eulerAngles(0,1,2);
    r.x = RadianToDegree(tempRot(0));
    r.y = RadianToDegree(tempRot(1));
    r.z = RadianToDegree(tempRot(2));

    Eigen::Matrix4d newM = this->getTransformationAsMatrix();
    if( ! inMatrix.isApprox(newM, 0.001) ){
        LOG(ERROR) << "CPACSTransfomation: The matrix given as input seem impossible to decompose in scale, rotation, translation."
                "The decomposition was not performed correctly!"
                "It probably need one more rotation matrix to represent this transformation (decomposable in rotation, scale, rotation, translation) ";
    }


}

bool cpcr::MCPACSTransformation::isApprox(const cpcr::MCPACSTransformation &other, double precision) {

    return other.getTransformationAsMatrix().isApprox( this->getTransformationAsMatrix() , precision) ;

}



