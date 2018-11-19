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


#include "gtest/gtest.h"
#include "MCPACSTransformation.h"
#include "Point.h"
#include "easylogging++.h"

#include "Eigen/Dense"
#include "CreatorException.h"


using namespace cpcr;

class MCPACSTransformationTest : public testing::Test {

};


TEST_F(MCPACSTransformationTest, constructSetGet){

    Eigen::Matrix4d m;

    cpcr::MCPACSTransformation trans;

    EXPECT_TRUE(trans.getScaling() == cpcr::Point(1,1,1) );
    EXPECT_TRUE(trans.getRotation() == cpcr::Point(0,0,0) );
    EXPECT_TRUE(trans.getTranslation() == cpcr::Point(0,0,0));
    EXPECT_TRUE( trans.getScalingAsMatrix().isApprox( Eigen::Matrix4d::Identity() ) );
    EXPECT_TRUE( trans.getRotationAsMatrix().isApprox( Eigen::Matrix4d::Identity() ) );
    EXPECT_TRUE( trans.getTranslationAsMatrix().isApprox( Eigen::Matrix4d::Identity() ) );


    cpcr::MCPACSTransformation trans2(cpcr::Point(1,2,1), cpcr::Point(2,2,2), cpcr::Point(3,3,3) );

    EXPECT_TRUE(trans2.getScaling() == cpcr::Point(1,2,1) );
    EXPECT_TRUE(trans2.getRotation() == cpcr::Point(2,2,2) );
    EXPECT_TRUE(trans2.getTranslation() == cpcr::Point(3,3,3));

    m << 1,0,0,0, 0,2,0,0 , 0,0,1,0, 0,0,0,1;
    EXPECT_TRUE( trans2.getScalingAsMatrix().isApprox( m ) );

    m <<   0.9987820, -0.0348782,  0.0348995, 0,
            0.0360955,  0.9987395, -0.0348782, 0,
            -0.0336390,  0.0360955,  0.9987820, 0,
             0,0,0,1;

    EXPECT_TRUE( trans2.getRotationAsMatrix().isApprox( m, 0.0001 ) );

    m << 1,0,0,3, 0,1,0,3 , 0,0,1,3, 0,0,0,1;
    EXPECT_TRUE( trans2.getTranslationAsMatrix().isApprox( m ) );


    cpcr::MCPACSTransformation trans3(9,8,7,6,5,4,3,2,1 );

    EXPECT_TRUE(trans3.getScaling() == cpcr::Point(9,8,7) );
    EXPECT_TRUE(trans3.getRotation() == cpcr::Point(6,5,4) );
    EXPECT_TRUE(trans3.getTranslation() == cpcr::Point(3,2,1) );


    // test setters ang getters

    cpcr::MCPACSTransformation pos4;
    cpcr::Point a(1.67,2,2);

    pos4.setScaling(a);
    EXPECT_TRUE(pos4.getScaling() == a);

    pos4.setRotation(a);
    EXPECT_TRUE(pos4.getRotation() == a);

    pos4.setTranslation(a);
    EXPECT_TRUE(pos4.getTranslation() == a);
}

TEST_F(MCPACSTransformationTest, equalequal) {

    cpcr::MCPACSTransformation a;
    cpcr::MCPACSTransformation b;
    EXPECT_TRUE( a == b);

    b.setScaling(cpcr::Point(2,4.5,9));
    EXPECT_FALSE( a == b);

    a.setScaling(cpcr::Point(2,4.5,9));
    EXPECT_TRUE( a == b);

    a.setRotation(cpcr::Point(4.4,5,5));
    EXPECT_FALSE( a == b);

    b.setRotation(cpcr::Point(4.4,5,5));
    EXPECT_TRUE( a == b);

    a.setTranslation(cpcr::Point(0, -1, 4));
    EXPECT_FALSE( a == b);

    b.setTranslation(cpcr::Point(0, -1, 4));
    EXPECT_TRUE( a == b);
}



TEST_F(MCPACSTransformationTest, getRotationAsQuaternion){

    cpcr::MCPACSTransformation a(1,1,1,0,0,0,0,0,0);

    Eigen::Quaterniond r = a.getRotationAsQuaternion();
    Eigen::Quaterniond q = Eigen::Quaterniond().Identity();

    EXPECT_TRUE(r.isApprox(q) );

    a.setRotation(cpcr::Point(12,3,4));
    r = a.getRotationAsQuaternion();
    q = Eigen::Quaterniond(0.99348, 0.1053375, 0.0223709, 0.037431 );

    a.setRotation(cpcr::Point(90,7,89));
    r = a.getRotationAsQuaternion();
    q = Eigen::Quaterniond( 0.4731468, 0.5336603, -0.4639038, 0.5254827) ;
    EXPECT_TRUE(r.isApprox(q, 0.0001)  );


    a.setRotation(cpcr::Point(90,7,89));
    a.setScaling( cpcr::Point(34,34,342));
    r = a.getRotationAsQuaternion();
    q = Eigen::Quaterniond( 0.4731468, 0.5336603, -0.4639038, 0.5254827) ;
    EXPECT_TRUE(r.isApprox(q, 0.0001)  );



}


TEST_F(MCPACSTransformationTest, getTransforamtionAsMatrix ){


    cpcr::MCPACSTransformation a, b;
    Eigen::Matrix4d r ;
    Eigen::Matrix4d m, m2;

    // Test saling
    a = cpcr::MCPACSTransformation(3,1.45,7,0,0,0,0,0,0);
    r = a.getTransformationAsMatrix();
    m.row(0) << 3 , 0,0,0;
    m.row(1) <<0, 1.45, 0,0;
    m.row(2) << 0,0,7 , 0;
    m.row(3) << 0, 0, 0, 1;

    LOG(INFO) << "\n" << m;
    LOG(INFO) << "\n" << r;
    EXPECT_TRUE( m.isApprox(r, 0.00001 ));


    // Test rotation
    a = cpcr::MCPACSTransformation(1,1,1,4,7,8,0,0,0);
    r = a.getTransformationAsMatrix();
    m.row(0) << 0.9828867, -0.1381357,  0.1218693, 0;
    m.row(1) << 0.1472525,  0.9866727, -0.0692365, 0;
    m.row(2) << -0.1106811,  0.0859972,  0.9901283 , 0;
    m.row(3) << 0, 0, 0, 1;

    LOG(INFO) << "\n" << m;
    LOG(INFO) << "\n" << r;
    EXPECT_TRUE( m.isApprox(r, 0.00001 ));

    // test translation
    a = cpcr::MCPACSTransformation(1,1,1,0,0,0,17.3,-5,26);
    r = a.getTransformationAsMatrix();
    m.row(0) << 1,0,0, 17.3;
    m.row(1) << 0,1,0, -5;
    m.row(2) << 0,0,1, 26;
    m.row(3) << 0,0,0, 1;

    LOG(INFO) << "\n" << m;
    LOG(INFO) << "\n" << r;
    EXPECT_TRUE( m.isApprox(r, 0.00001 ));


    // Test effect on a Point
    Eigen::Vector4d v, vr,ve;
    v << 1,0,0,1;
    ve << 2,0,0,1;
    a = cpcr::MCPACSTransformation(2,2,2,0,0,0,0,0,0);
    m = a.getTransformationAsMatrix();
    vr = m*v;
    LOG(INFO) << "\n" << vr;
    EXPECT_TRUE( vr.isApprox(ve) );


    v << 1,0,0,1;
    ve << 0,0,-2,1;
    a = cpcr::MCPACSTransformation(2,2,2,0,90,0,0,0,0);
    m = a.getTransformationAsMatrix();
    vr = m*v;
    LOG(INFO) << "\n" << vr;
    EXPECT_TRUE( vr.isApprox(ve, 0.00001) );


    v << 1,0,0,1;
    ve << 2,0,3,1;
    a = cpcr::MCPACSTransformation(2,2,2,0,0,0,0,0,3);
    m = a.getTransformationAsMatrix();
    vr = m*v;
    LOG(INFO) << "\n" << vr;
    EXPECT_TRUE( vr.isApprox(ve, 0.00001) );


    // Test order of transform application
    v << 1,0,0,1;
    ve << 2,0,3,1;
    a = cpcr::MCPACSTransformation(2,2,2,0,0,0,0,0,0);
    b = cpcr::MCPACSTransformation(1,1,1,0,0,0,0,0,3);
    m = a.getTransformationAsMatrix();
    m2 = b.getTransformationAsMatrix();
    vr = m*v;
    vr = m2 * vr;
    LOG(INFO) << "\n" << vr;
    EXPECT_TRUE( vr.isApprox(ve, 0.00001) );


    v << 1,0,0,1;
    ve << 2,0,6,1;
    a = cpcr::MCPACSTransformation(2,2,2,0,0,0,0,0,0);
    b = cpcr::MCPACSTransformation(1,1,1,0,0,0,0,0,3);
    m = a.getTransformationAsMatrix();
    m2 = b.getTransformationAsMatrix();
    vr = m2 * v;
    vr = m * vr;    // we change the apply order
    LOG(INFO) << "\n" << vr;
    EXPECT_TRUE( vr.isApprox(ve, 0.00001) );


}


TEST_F(MCPACSTransformationTest, constructFromMatrix){

    Eigen::Matrix4d inM;
    inM.row(0) << 3,0,0,6;
    inM.row(1) << 0,2,0,7;
    inM.row(2) << 0,0,5,8;
    inM.row(3) << 0,0,0,1;

    MCPACSTransformation c(inM);
    EXPECT_TRUE(c.getTranslation() == Point(6,7,8) );
    EXPECT_TRUE(c.getScaling() == Point(3,2,5) );

    Point s, r, t ;
    s = Point(1,1,1);
    r = Point(23,44,66);
    t = Point(0,0,0);
    MCPACSTransformation temp(s, r, t );
    MCPACSTransformation c2(temp.getTransformationAsMatrix());
    EXPECT_TRUE(s.toEigen().isApprox( c2.getScaling().toEigen(), 0.000001 ) );
    EXPECT_TRUE(t == c2.getTranslation());
    EXPECT_TRUE(r.toEigen().isApprox( c2.getRotation().toEigen() , 0.00001) );

    s = Point(1,1,1);
    r = Point(23,-44,66);
    t = Point(0,0,0);
    MCPACSTransformation temp3(s, r, t );
    MCPACSTransformation c3(temp3.getTransformationAsMatrix());
    EXPECT_TRUE(s.toEigen().isApprox( c3.getScaling().toEigen(), 0.000001 ) );
    EXPECT_TRUE(t == c3.getTranslation());
    EXPECT_TRUE(r.toEigen().isApprox( c3.getRotation().toEigen() , 0.00001) );


    s = Point(1,1,1);
    r = Point(-230,44,-77);
    t = Point(0,0,0);
    MCPACSTransformation temp4(s, r, t );
    MCPACSTransformation c4(temp4.getTransformationAsMatrix());
    EXPECT_TRUE(s.toEigen().isApprox( c4.getScaling().toEigen(), 0.000001 ) );
    EXPECT_TRUE(t == c4.getTranslation());
    // -230 is converted into 130
    EXPECT_TRUE(Point(130,44,-77).toEigen().isApprox( c4.getRotation().toEigen() , 0.00001) );




    s = Point(1,1,1);
    r = Point(-23,44,-77);
    t = Point(0,0,0);
    MCPACSTransformation temp5(s, r, t );
    MCPACSTransformation c5(temp5.getTransformationAsMatrix());
    EXPECT_TRUE(s.toEigen().isApprox( c5.getScaling().toEigen(), 0.000001 ) );
    EXPECT_TRUE(t == c5.getTranslation());
    // in this case the r is not the same because the first rotation is converted positivly by eigen
    //EXPECT_TRUE(r.toEigen().isApprox( c5.getRotation().toEigen() , 0.00001) );
    Eigen::Matrix4d m1 = temp5.getTransformationAsMatrix();
    Eigen::Matrix4d m2 = c5.getTransformationAsMatrix();
    EXPECT_TRUE(m1.isApprox(m2, 0.0001));




    s = Point(1.1,1.2,2.2);
    r = Point(14,44,-77);
    t = Point(45,9,7);
    MCPACSTransformation temp6(s, r, t );
    MCPACSTransformation c6(temp6.getTransformationAsMatrix());
    EXPECT_TRUE(s.toEigen().isApprox( c6.getScaling().toEigen(), 0.000001 ) );
    EXPECT_TRUE(t == c6.getTranslation());
    EXPECT_TRUE(r.toEigen().isApprox( c6.getRotation().toEigen() , 0.00001) );


    s = Point(1000,12.2,2.2);
    r = Point(14,0.44,66);
    t = Point(3.3,9,7.7);
    MCPACSTransformation temp7(s, r, t );
    MCPACSTransformation c7(temp7.getTransformationAsMatrix());
    EXPECT_TRUE(s.toEigen().isApprox( c7.getScaling().toEigen(), 0.000001 ) );
    EXPECT_TRUE(t == c7.getTranslation());
    EXPECT_TRUE(r.toEigen().isApprox( c7.getRotation().toEigen() , 0.00001) );


    s = Point(1000,1,1);
    r = Point(0,0,0);
    t = Point(7,7,7);

    inM.row(0) << 1000,0,0,7;
    inM.row(1) << 0,1,0,7;
    inM.row(2) << 0,0,1,7;
    inM.row(3) << 0,0,0,1;
    MCPACSTransformation c8(inM);
    EXPECT_TRUE(s.toEigen().isApprox( c8.getScaling().toEigen(), 0.000001 ) );
    EXPECT_TRUE(t == c8.getTranslation());
    EXPECT_TRUE(r.toEigen().isApprox( c8.getRotation().toEigen() , 0.00001) );


    /*
     * Shearing matrix is impossible to transform into SRT
     */
    s = Point(1000,1,1);
    r = Point(0,0,0);
    t = Point(7,7,7);
    inM.row(0) << 1,0.5,0,0;
    inM.row(1) << 0,1,0,0;
    inM.row(2) << 0,0,1,0;
    inM.row(3) << 0,0,0,1;
    MCPACSTransformation c9(inM);
    // TODO: How we wnat to manage this case ?
    //EXPECT_THROW(MMCPACSTransformation c9(inM), CreatorException);




}