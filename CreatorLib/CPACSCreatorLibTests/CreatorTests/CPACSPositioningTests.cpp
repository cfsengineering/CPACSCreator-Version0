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
#include "MCPACSPositioning.h"
#include "Helper.h"


using namespace cpcr;


class CPACSPositioningTest : public ::testing::Test {



};

TEST_F(CPACSPositioningTest, getset){

    cpcr::MCPACSPositioning pos;

    EXPECT_EQ( pos.getDihedralAngle() , 0 );
    EXPECT_EQ(pos.getFromSectionUID(), "");
    EXPECT_EQ(pos.getLength(), 0);
    EXPECT_EQ(pos.getSweepAngle(), 0);
    EXPECT_EQ(pos.getToSectionUID(), "");


    pos.setDihedralAngle(3);
    EXPECT_EQ( pos.getDihedralAngle() ,3 );
    pos.setFromSectionUID("malo");
    EXPECT_EQ(pos.getFromSectionUID(), "malo");
    pos.setLength(67.67);
    EXPECT_EQ(pos.getLength(), 67.67);
    pos.setSweepAngle(23);
    EXPECT_EQ(pos.getSweepAngle(), 23);
    pos.setToSectionUID("cc");
    EXPECT_EQ(pos.getToSectionUID(), "cc");


    cpcr::MCPACSPositioning pos2(23,"aa", 3.3, 34,"bb") ;

    EXPECT_EQ(pos2.getDihedralAngle() ,23 );
    EXPECT_EQ(pos2.getFromSectionUID(), "aa");
    EXPECT_EQ(pos2.getLength(), 3.3);
    EXPECT_EQ(pos2.getSweepAngle(), 34);
    EXPECT_EQ(pos2.getToSectionUID(), "bb");


}


TEST_F(CPACSPositioningTest, equalequal){

    cpcr::MCPACSPositioning posA;
    cpcr::MCPACSPositioning posB;

    EXPECT_TRUE( posA == posB);

    posA.setSweepAngle(2);
    EXPECT_FALSE(posA == posB);

    posB.setSweepAngle(2);
    EXPECT_TRUE(posA == posB);

    posA.setToSectionUID("aa");
    EXPECT_FALSE(posA == posB);

    posB.setToSectionUID("aa");
    EXPECT_TRUE( posA == posB);

    posA.setLength(3.3);
    posB.setLength(17);
    EXPECT_FALSE(posA == posB);

    posB.setLength( posA.getLength());
    EXPECT_TRUE( posA == posB);

    posA.setFromSectionUID("");
    EXPECT_TRUE( posA == posB);

    posA.setFromSectionUID("ss");
    EXPECT_FALSE( posA == posB);

    posB.setFromSectionUID("ss");
    EXPECT_TRUE( posA == posB);

    posB.setDihedralAngle(0.22222);
    EXPECT_FALSE(posA == posB);

    posA.setDihedralAngle(0.22222);
    EXPECT_TRUE(posA == posB);


}






TEST_F(CPACSPositioningTest, getPositioningAsTranslationVector){


    MCPACSPositioning p ;

    Eigen::Vector3d r, e ;

    // sweep and dihedral angle in positioning element does not act as Euler angle
    // first the sweep angle rotation is done around the Z axis of a Y-vector of length "length"
    // then the dihedral angle rotation is done around the X original axis
    // remark that this transformation are done in the world coordinate system but then it's transformed by the wing
    // coordinate system
    p = MCPACSPositioning(30, "", 10, 45, "");
    e << 7.07,6.13,3.35;
    r = p.getPositioningAsTranslationVector();
    EXPECT_TRUE(r.isApprox(e, 0.02));

    p = MCPACSPositioning(0, "",9 , 0, "");
    e << 0,9,0;
    r = p.getPositioningAsTranslationVector();
    EXPECT_TRUE(r.isApprox(e, 0.02));


    p = MCPACSPositioning(30, "",1 , 0, "");
    e << 0,0.86,0.5;
    r = p.getPositioningAsTranslationVector();
    EXPECT_TRUE(r.isApprox(e, 0.02));


    p = MCPACSPositioning(0, "",1 , 30, "");
    e << 0.5, 0.86, 0;
    r = p.getPositioningAsTranslationVector();
    EXPECT_TRUE(r.isApprox(e, 0.02));

}






TEST_F(CPACSPositioningTest, getPositioningAsMatrix){


    MCPACSPositioning p ;

    Eigen::Matrix4d r,e;

    p = MCPACSPositioning(30, "", 10, 45, "");
    r = Eigen::Matrix4d::Identity();
    e = Eigen::Matrix4d::Identity();
    e.row(0).col(3) << 7.07;
    e.row(1).col(3) << 6.13;
    e.row(2).col(3) << 3.35;

    r = p.getPositioningAsMatrix();

    EXPECT_TRUE(r.isApprox(e, 0.02));


}





TEST_F(CPACSPositioningTest, setFromVector) {


    MCPACSPositioning p ;

    Eigen::Vector3d v;
    v << 1,1,0;
    p.setFromVector(v);

    EXPECT_TRUE( IsApprox( p.getDihedralAngle(), 0));
    EXPECT_TRUE( IsApprox( p.getSweepAngle(), 45));
    EXPECT_TRUE( IsApprox( p.getLength(), sqrt(2)));

    v << -1,1,0;
    p.setFromVector(v);

    EXPECT_TRUE( IsApprox( p.getDihedralAngle(), 0));
    EXPECT_TRUE( IsApprox( p.getSweepAngle(), -45));
    EXPECT_TRUE( IsApprox( p.getLength(), sqrt(2)));


    v << 1,-1,0;
    p.setFromVector(v);

    EXPECT_TRUE( IsApprox( p.getDihedralAngle(), 0));
    EXPECT_TRUE( IsApprox( p.getSweepAngle(), 90 + 45 ));
    EXPECT_TRUE( IsApprox( p.getLength(), sqrt(2)));


    v << -1,-1,0;
    p.setFromVector(v);

    EXPECT_TRUE( IsApprox( p.getDihedralAngle(), 0));
    EXPECT_TRUE( IsApprox( p.getSweepAngle(), 360 - 135 ));
    EXPECT_TRUE( IsApprox( p.getLength(), sqrt(2)));


    double l, d, s;
    l = 23;
    s = 23;
    d = 23;
    p.setLength(l);
    p.setSweepAngle(s);
    p.setDihedralAngle(d);
    v = p.getPositioningAsTranslationVector();
    p.setFromVector(v);

    EXPECT_TRUE(IsApprox(p.getLength(), l));
    EXPECT_TRUE(IsApprox(p.getSweepAngle(), s));
    EXPECT_TRUE(IsApprox(p.getDihedralAngle(), d));


    l = 23;
    s = 23;
    d = 23;
    p.setLength(l);
    p.setSweepAngle(s);
    p.setDihedralAngle(d);
    v = p.getPositioningAsTranslationVector();
    p.setFromVector(v);

    EXPECT_TRUE(IsApprox(p.getLength(), l));
    EXPECT_TRUE(IsApprox(p.getSweepAngle(), s));
    EXPECT_TRUE(IsApprox(p.getDihedralAngle(), d));


    l = 0.7;
    s = -34;
    d = 2;
    p.setLength(l);
    p.setSweepAngle(s);
    p.setDihedralAngle(d);
    v = p.getPositioningAsTranslationVector();
    p.setFromVector(v);

    EXPECT_TRUE(IsApprox(p.getLength(), l));
    EXPECT_TRUE(IsApprox(p.getSweepAngle(), s));
    EXPECT_TRUE(IsApprox(p.getDihedralAngle(), d));


    l = 123;
    s = 129;
    d = -7;
    p.setLength(l);
    p.setSweepAngle(s);
    p.setDihedralAngle(d);
    v = p.getPositioningAsTranslationVector();
    p.setFromVector(v);

    EXPECT_TRUE(IsApprox(p.getLength(), l));
    EXPECT_TRUE(IsApprox(p.getSweepAngle(), s));
    EXPECT_TRUE(IsApprox(p.getDihedralAngle(), d));


}




