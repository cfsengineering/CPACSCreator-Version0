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
// Created by makem on 21/05/18.
//


#include "gtest/gtest.h"
#include "Helper.h"
#include "Point.h"


using namespace cpcr;

TEST(HelperTest, LineLineIntersection){

    Point a,b,c,d,r1,r2,  zero;
    double m1, m2;
    bool r = false;

    // Unit vector intersection
    a = Point(1,0,0);
    b = Point(0,1,0);
    c = Point(-1,0,0);
    d = Point(0,-1,0);
    zero = Point(0,0,0);

    r = LineLineIntersect(a,c,b,d,r1,r2,m1,m2);
    EXPECT_TRUE(r);
    EXPECT_TRUE(r1 == r2);
    EXPECT_TRUE(r1 == zero);
    EXPECT_TRUE(r2 == zero);
    EXPECT_EQ(m1, 0.5);
    EXPECT_EQ(m2, 0.5);

    // one line not defined ( same point)
    a = Point(1,0,0);
    b = Point(1,1,0);
    c = Point(1,0,0);
    d = Point(0,-1,0);
    zero = Point(0,0,0);

    r = LineLineIntersect(a,c,b,d,r1,r2,m1,m2);
    EXPECT_TRUE(! r);


    // general case (constructing the intersection
    a = Point(1,1,1);
    c = Point(2.3,-4,7);
    Eigen::Vector3d i =  0.22 *( c.toEigen()-a.toEigen() ) + a.toEigen();
    b = Point(0.34,3,9);
    Eigen::Vector3d temp  = 13 * (i - b.toEigen()) + b.toEigen();
    d = Point(temp(0),temp(1), temp(2));
    zero = Point(0,0,0);


    r = LineLineIntersect(a,c,b,d,r1,r2,m1,m2);

    EXPECT_TRUE(r);
    EXPECT_TRUE(r1.toEigen().isApprox( r2.toEigen(), 0.000001));
    EXPECT_TRUE(r1.toEigen().isApprox( i, 0.0000001) );
    EXPECT_TRUE(r2.toEigen().isApprox( i, 0.0000001) );
    EXPECT_DOUBLE_EQ(m1, 0.22);




    // general case (constructing the intersection
    a = Point(4,6,7);
    c = Point(2.377,-4,7);
    i =  -888 *( c.toEigen()-a.toEigen() ) + a.toEigen();
    b = Point(0.34,3,9);
    temp  = 13 * (i - b.toEigen()) + b.toEigen();
    d = Point(temp(0),temp(1), temp(2));
    zero = Point(0,0,0);


    r = LineLineIntersect(a,c,b,d,r1,r2,m1,m2);

    EXPECT_TRUE(r);
    EXPECT_TRUE(r1.toEigen().isApprox( r2.toEigen(), 0.000001));
    EXPECT_TRUE(r1.toEigen().isApprox( i, 0.0000001) );
    EXPECT_TRUE(r2.toEigen().isApprox( i, 0.0000001) );
    EXPECT_TRUE(m1 > -888.01 && m1 < -887.99);




}

