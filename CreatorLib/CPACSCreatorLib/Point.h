//
// Created by makem on 08/04/18.
//

/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id$
*
* Version: $Revision$
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



/**
* @file
* @brief  Implementation of a CPREATOR point.
 *  More or less imported from the TIGLPoint without the oce feature
 * 
*/
#ifndef CPACSCREATORLIBANDTESTS_POINT_H
#define CPACSCREATORLIBANDTESTS_POINT_H


#include <climits>
#include <iostream>
#include <vector>
#include <Eigen/Dense>

namespace cpcr
{

    class Point
    {

    public:
        // Constructor
         Point(double xval = 0.0, double yval = 0.0, double zval = 0.0);

         Point(const std::vector<double>& vector);

        // Copy constructor
         Point(const Point& aPoint);

        // Assignment operator
         Point& operator=(const Point& aPoint);

        // Addition of points
         Point operator+(const Point& aPoint) const;

        // Addition of a point
         Point& operator+=(const Point& aPoint);

        // Subtraction of points
         Point operator-(const Point& aPoint) const;

        // Subtraction of a point
         Point& operator-=(const Point& aPoint);

        // Scaling of points
         Point operator*(double) const;

         // Comparing two point

        bool operator==(const Point& other);


        Eigen::Vector3d toEigen() const;

        // return the point as a augmented coordinate point
        Eigen::Vector4d toAugmentedEigen() const;


        // returns a'*a
         double norm2Sqr() const;

        // returns the length of the vector
         double norm2() const;

        // Virtual Destructor
         virtual ~Point();

        // Dump internal point data
         void Dump(std::ostream& aStream) const;

        // scalar product
         static double inner_prod(const Point& aPoint, const Point& bPoint);

        // cross product
         static Point cross_prod(const Point& a, const Point& b);

        // scalar projection of a vector a onto a nonzero vector b
         static double scalar_projection(const Point& a, const Point& b);

        // vector projection of a vector a onto a nonzero vector b
         static Point vector_projection(const Point& a, const Point& b);

        // square distance to another point
         double distance2(const Point& point) const;

        // returns minimum and maximum component
         void getMinMax(double & min, double & max) const;

         // toSdtVector
         std::vector<double> toStdVector();


        double x;
        double y;
        double z;
    };

} // end namespace cpacscreator








#endif //CPACSCREATORLIBANDTESTS_POINT_H
