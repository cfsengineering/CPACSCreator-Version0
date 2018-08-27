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

#ifndef CPACSCREATORLIBANDTESTS_CPACSPOSITIONING_H
#define CPACSCREATORLIBANDTESTS_CPACSPOSITIONING_H


#include <string>
#include "Eigen/Dense"

namespace  cpcr{

    class CPACSPositioning {


    public:

        CPACSPositioning();
        CPACSPositioning(double dihaedral, std::string from, double l, double sweep, std::string to );

        // transform the vector into length sweep and dihedral
        void setFromVector(Eigen::Vector3d);

        void setDihedralAngle(double dihedralAngle);
        double getDihedralAngle() const;

        const std::string &getFromSectionUID() const;
        void setFromSectionUID(const std::string &fromSectionUID);

        double getLength() const;
        void setLength(double length);

        double getSweepAngle() const;
        void setSweepAngle(double sweepAngle);

        const std::string &getToSectionUID() const;
        void setToSectionUID(const std::string &toSectionUID);

        bool operator==(const CPACSPositioning& other);

        // in fact a positioning is just a translation, so we que express it as a affine translation matrix
        Eigen::Matrix4d getPositioningAsMatrix();

        Eigen::Vector3d getPositioningAsTranslationVector();

    protected:

        // use to round the values around special values of 0, 90, 270, 360
        void roundValues();

    private:


        double dihedralAngle;
        std::string fromSectionUID;
        double length;
        double sweepAngle;
        std::string toSectionUID;

    };




}


#endif //CPACSCREATORLIBANDTESTS_CPACSPOSITIONING_H
