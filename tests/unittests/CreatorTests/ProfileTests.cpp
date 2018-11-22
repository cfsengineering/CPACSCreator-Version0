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
// Created by cfse on 6/29/18.
//


#include "gtest/gtest.h"
#include "CPACSPointsProfile.h"
#include "Eigen/Dense"
#include "CreatorException.h"

class CPACSProfileTest :   public ::testing::Test {

protected:


    std::string DATA_DIR="./Data/";


    virtual void SetUp() {

    }

    virtual void TearDown() {
    }

    std::vector<double> createVectorFromString(std::string in ){
        std::vector<double> r;
        std::stringstream ss(in);
        std::string token;
        double value;
        while (std::getline(ss, token, ';')) {
            value = std::stod(token);
            r.push_back(value);
        }
        return r;
    }


};


TEST_F(CPACSProfileTest, createFromAFile) {

    cpcr::CPACSPointsProfile airfoil(DATA_DIR + "profile-BW050209.dat" );
    std::vector<double> eXs = createVectorFromString("1.00000;0.99999;0.95000;0.90000;0.80000;0.70000;0.60000;0.50000;0.40000;0.30000;0.25000;0.20000;0.15000;0.10000;0.07500;0.05000;0.02500;0.01250;0.00750;0.00375;0.00200;0.00100;0.00010;0.00000;0.00010;0.00100;0.00200;0.00375;0.00750;0.01250;0.02500;0.05000;0.07500;0.10000;0.15000;0.20000;0.25000;0.30000;0.40000;0.50000;0.60000;0.70000;0.80000;0.90000;0.95000;0.99999;1.00000");
    std::vector<double> eZs = createVectorFromString("0.00000;0.00100;0.00450;0.00813;0.01833;0.02937;0.04157;0.05337;0.06236;0.06650;0.06500;0.06100;0.05550;0.04600;0.03950;0.03150;0.02125;0.01425;0.01035;0.00650;0.00450;0.00285;0.00155;0.00000;-0.00050;-0.00150;-0.00250;-0.00375;-0.00550;-0.00725;-0.01050;-0.01450;-0.01725;-0.01945;-0.02231;-0.02350;-0.02477;-0.02547;-0.02655;-0.02755;-0.02699;-0.02576;-0.02184;-0.01400;-0.00777;-0.00100;0.00000");

    for(int i = 0; i < eXs.size(); i++){
        EXPECT_EQ(eXs[i],airfoil.xs[i]);
        EXPECT_EQ(0,airfoil.ys[i]);
        EXPECT_EQ(eZs[i],airfoil.zs[i]);
    }

    EXPECT_EQ("profile-BW050209", airfoil.getUID());

    EXPECT_EQ(DATA_DIR + "profile-BW050209.dat", airfoil.getName());


}


TEST_F(CPACSProfileTest, getTEandLE) {

    cpcr::CPACSPointsProfile airfoil(DATA_DIR + "profile-BW050209.dat" );

    Eigen::Vector3d expectedTE(1, 0, 0);
    EXPECT_TRUE(airfoil.getTrailingEdge().isApprox(expectedTE )) ;

    Eigen::Vector3d expectedLE(0, 0, 0);
    EXPECT_TRUE(airfoil.getLeadingEdge().isApprox(expectedLE )) ;


    cpcr::CPACSPointsProfile airfoil2(DATA_DIR + "profile-simple-shifted.dat" );

    expectedTE << 11, 0, 0;
    EXPECT_TRUE(airfoil2.getTrailingEdge().isApprox(expectedTE )) ;

    expectedLE <<  9, 0, 0;
    EXPECT_TRUE(airfoil2.getLeadingEdge().isApprox(expectedLE )) ;




}


TEST_F(CPACSProfileTest, getFurthestPointFromTheChord) {

    cpcr::CPACSPointsProfile airfoil(DATA_DIR + "profile-BW050209.dat" );

    Eigen::Vector3d e, r;
    e << 0.3, 0, 0.0665;
    r = airfoil.getFurthestPointFromChord();
    EXPECT_EQ(e, r);

    cpcr::CPACSPointsProfile airfoil2(DATA_DIR + "profile-simple-shifted.dat" );
    e << 10, 0, -0.2;
    r = airfoil2.getFurthestPointFromChord();
    EXPECT_EQ(e, r);



}




TEST_F(CPACSProfileTest, equalequal) {

    cpcr::CPACSPointsProfile airfoil(DATA_DIR + "profile-BW050209.dat" );
    cpcr::CPACSPointsProfile airfoil2(DATA_DIR + "profile-BW050209.dat" );
    cpcr::CPACSPointsProfile airfoil3(DATA_DIR + "profile-simple-shifted.dat" );

    EXPECT_TRUE( airfoil == airfoil2 );
    airfoil2.zs[3] = 0.009;
    EXPECT_FALSE( airfoil == airfoil2 );
    EXPECT_FALSE( airfoil == airfoil3 );


}


TEST_F(CPACSProfileTest, normalize) {

    cpcr::CPACSPointsProfile airfoil(DATA_DIR + "profile-BW050209.dat" );
    cpcr::CPACSPointsProfile airfoil2(DATA_DIR + "profile-BW050209.dat" );


    EXPECT_FALSE( airfoil.isNormalized() );
    EXPECT_TRUE( airfoil == airfoil2);

    airfoil.normalize();
    EXPECT_TRUE( airfoil.isNormalized() );
    EXPECT_TRUE(airfoil.getLeadingEdge().isApprox( airfoil2.getLeadingEdge(), 0.000001) );
    EXPECT_TRUE(airfoil.getTrailingEdge().isApprox(airfoil2.getTrailingEdge(), 0.000001));
    EXPECT_FALSE( airfoil.zs[3] ==  airfoil2.zs[3] );


    cpcr::CPACSPointsProfile airfoil3(DATA_DIR + "profile-simple-shifted.dat" );
    cpcr::CPACSPointsProfile airfoil4(DATA_DIR + "profile-simple-normalized.dat" );

    EXPECT_FALSE( airfoil3.isNormalized() );
    EXPECT_TRUE( airfoil4.isNormalized() );


    airfoil3.normalize();
    EXPECT_TRUE(airfoil3.isNormalized());

    cpcr::CPACSPointsProfile airfoil5;
    airfoil5.xs.push_back(1);
    airfoil5.xs.push_back(2);
    airfoil5.xs.push_back(2);

    airfoil5.ys.push_back(2);
    airfoil5.ys.push_back(1);
    airfoil5.ys.push_back(3);

    airfoil5.zs.push_back(0);
    airfoil5.zs.push_back(0);
    airfoil5.zs.push_back(0);

    Eigen::Vector3d temp;
    temp << 1,2,0;
    EXPECT_TRUE( airfoil5.getTrailingEdge() == temp );

    temp << 2,1,0;
    EXPECT_TRUE( airfoil5.getLeadingEdge() == temp );

    EXPECT_FALSE( airfoil5.isNormalized() );

    EXPECT_THROW(airfoil5.normalize(), CreatorException);

}




TEST_F(CPACSProfileTest, reverseOrder) {



    cpcr::CPACSPointsProfile airfoil5;
    airfoil5.xs.push_back(1);
    airfoil5.xs.push_back(2);
    airfoil5.xs.push_back(3);

    airfoil5.ys.push_back(4);
    airfoil5.ys.push_back(5);
    airfoil5.ys.push_back(6);

    airfoil5.zs.push_back(7);
    airfoil5.zs.push_back(8);
    airfoil5.zs.push_back(9);

    airfoil5.reverseOrder();


    cpcr::CPACSPointsProfile airfoil6;
    airfoil6.xs.push_back(3);
    airfoil6.xs.push_back(2);
    airfoil6.xs.push_back(1);

    airfoil6.ys.push_back(6);
    airfoil6.ys.push_back(5);
    airfoil6.ys.push_back(4);

    airfoil6.zs.push_back(9);
    airfoil6.zs.push_back(8);
    airfoil6.zs.push_back(7);

    EXPECT_TRUE(airfoil5 == airfoil6);

}

TEST_F(CPACSProfileTest, mathematicalOrder) {

    cpcr::CPACSPointsProfile airfoil5;
    std::vector<double> xs = createVectorFromString("1.00000;0.99999;0.95000;0.90000;0.80000;0.70000;0.60000;0.50000;0.40000;0.30000;0.25000;0.20000;0.15000;0.10000;0.07500;0.05000;0.02500;0.01250;0.00750;0.00375;0.00200;0.00100;0.00010;0.00000;0.00010;0.00100;0.00200;0.00375;0.00750;0.01250;0.02500;0.05000;0.07500;0.10000;0.15000;0.20000;0.25000;0.30000;0.40000;0.50000;0.60000;0.70000;0.80000;0.90000;0.95000;0.99999;1.00000");
    std::vector<double> ys = createVectorFromString("0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0");
    std::vector<double> zs = createVectorFromString("0.00000;0.00100;0.00450;0.00813;0.01833;0.02937;0.04157;0.05337;0.06236;0.06650;0.06500;0.06100;0.05550;0.04600;0.03950;0.03150;0.02125;0.01425;0.01035;0.00650;0.00450;0.00285;0.00155;0.00000;-0.00050;-0.00150;-0.00250;-0.00375;-0.00550;-0.00725;-0.01050;-0.01450;-0.01725;-0.01945;-0.02231;-0.02350;-0.02477;-0.02547;-0.02655;-0.02755;-0.02699;-0.02576;-0.02184;-0.01400;-0.00777;-0.00100;0.00000");

    airfoil5.zs = zs;
    airfoil5.ys = ys;
    airfoil5.xs = xs;

    EXPECT_FALSE(airfoil5.isInMathematicalOrder());
    airfoil5.reverseOrder();

    EXPECT_TRUE(airfoil5.isInMathematicalOrder());


    xs = createVectorFromString("1;0.5;0;1");
    ys = createVectorFromString("0;0;0;0");
    zs = createVectorFromString("0;-0.3;0;0");

    airfoil5.zs = zs;
    airfoil5.ys = ys;
    airfoil5.xs = xs;

    EXPECT_TRUE(airfoil5.isInMathematicalOrder());



}