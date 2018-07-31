//
// Created by makem on 08/04/18.
//


#include "gtest/gtest.h"
#include "Point.h"


class PointTest : public ::testing::Test {

protected:

    cpcr::Point * a;
    cpcr::Point * b;
    cpcr::Point * c;


    virtual void SetUp() {

        a = new cpcr::Point(0,0,0);
        b = new cpcr::Point(1.1,0,0);
        c = new cpcr::Point(0,1.2,0);


    }

    virtual void TearDown() {
        delete a;
        delete b;
        delete c;
    }


};


TEST_F(PointTest, basic) {

    // just to test if the class was correctly copied

    // test constructor
    EXPECT_EQ(a->x, 0.0);
    EXPECT_EQ(a->y, 0.0);
    EXPECT_EQ(a->z, 0.0);

    // test addition
    cpcr::Point r = *a + *b + *c;
    EXPECT_EQ(r.x, 1.1 );
    EXPECT_EQ(r.y, 1.2 );
    EXPECT_EQ(r.z, 0.0 );


}

TEST_F(PointTest, equalequal){

    cpcr::Point a(0,0,0);
    cpcr::Point b(0,0,0);

    EXPECT_TRUE( a == b);

    cpcr::Point c(0,0.3,0);
    EXPECT_TRUE( !( a == c) );

    cpcr::Point d(0,0.3,0.3);
    EXPECT_TRUE( !( c == d ) );

    cpcr::Point e(2000,0,0);
    EXPECT_TRUE( !( a == e ) );


    cpcr::Point f = a + cpcr::Point(2000,0,0);
    EXPECT_TRUE( f == e);

}




TEST_F(PointTest, toStdVector){

    cpcr::Point a(-1,0,2.3);
    std::vector<double> r = a.toStdVector();

    EXPECT_EQ(r[0], a.x);
    EXPECT_EQ(r[1], a.y);
    EXPECT_EQ(r[2], a.z);
}




TEST_F(PointTest, constructorFromStdVector){


    std::vector<double> r(3,-1);
    r[0] = -11;
    r[1] = 0.3;
    r[2] = 2.3;

    cpcr::Point a(r);
    EXPECT_EQ(r[0], a.x);
    EXPECT_EQ(r[1], a.y);
    EXPECT_EQ(r[2], a.z);

    // if a not right size vector is given the constructor should set the value to -1, need to add a Warning?


    std::vector<double> v(2,-3);
    cpcr::Point b(v);
    EXPECT_EQ(b.x, -1);
    EXPECT_EQ(b.y, -1);
    EXPECT_EQ(b.z, -1 );

}


