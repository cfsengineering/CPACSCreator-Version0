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
