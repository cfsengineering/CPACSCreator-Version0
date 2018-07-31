//
// Created by makem on 07/06/18.
//



#include "gtest/gtest.h"
#include "MyTestHelperFunctions.h"

TEST(MyTestHelperFunctionsTest, CompareDoubleEpsilon){

    EXPECT_EQ( 0.01, mthf::EPSILON) ;

    EXPECT_TRUE( mthf::CompareDoubleEpsilon(13.12, 13.12 ,0));
    EXPECT_FALSE( mthf::CompareDoubleEpsilon(13.12, 13.13 ,0));

    EXPECT_TRUE( mthf::CompareDoubleEpsilon(13.12, 13.12 ) );
    EXPECT_TRUE( mthf::CompareDoubleEpsilon(13.12, 13.125 ) );
    EXPECT_TRUE( mthf::CompareDoubleEpsilon(13.12, 13.129 ) );
    EXPECT_TRUE( mthf::CompareDoubleEpsilon(13.12, 13.111 ) );
    EXPECT_FALSE( mthf::CompareDoubleEpsilon(13.12, 13.14 ) );
    EXPECT_TRUE( mthf::CompareDoubleEpsilon(13.12, 13.14, 0.03 ) );
    EXPECT_FALSE( mthf::CompareDoubleEpsilon(13.12, -13.12 ) );

};