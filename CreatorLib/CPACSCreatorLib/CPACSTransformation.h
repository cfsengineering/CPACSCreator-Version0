//
// Created by makem on 11/04/18.
//

#ifndef CPACSCREATORLIBANDTESTS_CPACSTRANSFORMATION_H
#define CPACSCREATORLIBANDTESTS_CPACSTRANSFORMATION_H

#include "Point.h"
#include "Eigen/Dense"

namespace  cpcr{

    class CPACSTransformation {

    public:

        CPACSTransformation();
        CPACSTransformation(Point scaling , Point rotation, Point translation);
        CPACSTransformation(double sx, double sy, double sz, double rx, double ry, double rz, double tx, double ty, double tz);
        CPACSTransformation(const Eigen::Matrix4d& inMatrix);



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

        bool operator==(const CPACSTransformation &other) ;

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
