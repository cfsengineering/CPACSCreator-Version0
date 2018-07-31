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


