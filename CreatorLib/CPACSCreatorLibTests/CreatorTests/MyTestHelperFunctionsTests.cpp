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