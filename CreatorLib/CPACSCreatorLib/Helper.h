//
// Created by makem on 25/04/18.
//

#ifndef CPACSCREATORLIBANDTESTS_HELPER_H
#define CPACSCREATORLIBANDTESTS_HELPER_H

#include "Eigen/Dense"
#include "Point.h"

#include <sstream>
#include <iomanip>
#include "CPACSTransformation.h"

namespace cpcr{


    inline static double RadianToDegree(double rad) {
            return (180.0/M_PI)*rad;
    };

    inline static double DegreeToRadian(double deg) {
        return (M_PI/180.0)*deg;
    };


    cpcr::Point LineLineStrictIntersect( const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    bool LineLineIntersect( const Point& p1, const Point& p2, const Point& p3, const Point& p4, Point& pa, Point& pb,double& mua, double& mub);

 

    /**
     * Return a transform that set a -> aP, b -> bP
     * And try to set c -> cP
     * the returned transform guarantee to se c' to same plane as cP, but the scaling get be very different
     *
     * @param a
     * @param b
     * @param c
     * @param aP
     * @param bP
     * @param cP
     * @return
     */
    CPACSTransformation TransformChord(const Eigen::Vector4d& a, const Eigen::Vector4d& b,const Eigen::Vector4d& c,
                                       const Eigen::Vector4d& aP, const Eigen::Vector4d& bP,const Eigen::Vector4d& cP );




    template <typename T>
    std::string ToStringWithPrecision(const T a_value, const int n = 6)
    {
        std::ostringstream out;
        out << std::setprecision(n) << a_value;
        return out.str();
    }


    bool IsApprox(double x, double y, double delta = 0.0001);

}


#endif //CPACSCREATORLIBANDTESTS_HELPER_H
