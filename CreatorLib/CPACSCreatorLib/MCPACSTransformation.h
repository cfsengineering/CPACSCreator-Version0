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

#ifndef CPACSCREATORLIBANDTESTS_CPACSTRANSFORMATION_H
#define CPACSCREATORLIBANDTESTS_CPACSTRANSFORMATION_H

#include "Point.h"
#include "Eigen/Dense"

namespace  cpcr{

    class MCPACSTransformation {

    public:

        MCPACSTransformation();
        MCPACSTransformation(Point scaling , Point rotation, Point translation);
        MCPACSTransformation(double sx, double sy, double sz, double rx, double ry, double rz, double tx, double ty, double tz);
        MCPACSTransformation(const Eigen::Matrix4d& inMatrix);



        inline Point getScaling() const {return s; } ;
        inline Point getRotation() const {return r;} ;
        inline Point getTranslation() const { return  t; };

        Eigen::Matrix4d getScalingAsMatrix() const;
        Eigen::Matrix4d getRotationAsMatrix() const;
        Eigen::Matrix4d getTranslationAsMatrix() const;


        void setScaling(const Point& newS) { s = newS; };
        void setRotation(const Point& newR) { r = newR; };
        void setTranslation(const Point &newT) { t = newT; };




        Eigen::Matrix4d getTransformationAsMatrix() const;   // not implemented

        bool operator==(const MCPACSTransformation &other) ;

        bool  isApprox( const MCPACSTransformation &other , double precision = 0.0001);
        Eigen::Quaterniond getRotationAsQuaternion() const ;




    private:


        Point s;    // scaling as written in cpacs file
        Point r;    // rotation
        Point t;    // translation




        /*
        Point effectiveS;   // scaling in the world coordinate
        Point effectiveR;   // rotation in the world coordinate
        Point effectiveT;   // transformation in the world coordinate
        */
    };


}


#endif //CPACSCREATORLIBANDTESTS_CPACSTRANSFORMATION_H
