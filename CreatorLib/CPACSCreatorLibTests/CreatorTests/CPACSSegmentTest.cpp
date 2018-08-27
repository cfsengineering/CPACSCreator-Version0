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
// Created by cfse on 7/9/18.
//


#include "gtest/gtest.h"
#include "CPACSSegment.h"
#include "easylogging++.h"
#include "CreatorException.h"



class CPACSSegmentTest : public ::testing::Test {



};



TEST_F(CPACSSegmentTest, all){

    cpcr::CPACSSegment segment;

    EXPECT_EQ(segment.getName() , "");
    EXPECT_EQ(segment.getFromElementUID() , "");
    EXPECT_EQ(segment.getToElementUID() , "");

    segment.setName("malo");
    segment.setToElementUID("23");
    segment.setFromElementUID("from");

    EXPECT_EQ(segment.getName() , "malo");
    EXPECT_EQ(segment.getFromElementUID() , "23");
    EXPECT_EQ(segment.getToElementUID() , "from");

    cpcr::CPACSSegment segment2("hel", "l", "o");

    EXPECT_EQ(segment.getName() , "hel");
    EXPECT_EQ(segment.getFromElementUID() , "l");
    EXPECT_EQ(segment.getToElementUID() , "o");

}


