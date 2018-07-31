//
// Created by cfse on 7/13/18.
//



#include "gtest/gtest.h"
#include "CPACSProfilesDB.h"



class CPACSProfilesDBTest : public ::testing::Test {
public:
    std::string DATA_DIR="/home/cfse/Stage_Malo/CPACSCreatorLib/CPACSCreatorLibTests/CreatorTests/Data/";



};


TEST_F(CPACSProfilesDBTest, base){

    cpcr::CPACSProfilesDB db;
    cpcr::CPACSFile file;

    file.open(DATA_DIR + "airfoils.xml");
    file.save(DATA_DIR + "airfoils-out.xml");

    db.init(&file);
    db.airfoilUIDs.size();
    std::vector<std::string> e;
    e.push_back("mdAirfoil2");
    e.push_back("mdAirfoil2Normalized");
    e.push_back("mdAirfoil6");
    e.push_back("mdAirfoilShifted");
    e.push_back("mdAirfoil3");
    e.push_back("mdAirfoil4");
    e.push_back("mdAirfoilCst2D");
    EXPECT_EQ(db.airfoilUIDs,e);

    EXPECT_TRUE(db.isPoints["mdAirfoil2"]);
    EXPECT_TRUE(db.isPoints["mdAirfoil4"]);
    EXPECT_FALSE(db.isPoints["mdAirfoilCst2D"] );

    EXPECT_TRUE(db.isNormalized["mdAirfoil2Normalized"]);
    EXPECT_FALSE(db.isNormalized["mdAirfoil2"]);
    EXPECT_FALSE(db.isNormalized["mdAirfoilShifted"]);

    EXPECT_EQ(db.normalizedVersion["mdAirfoil2"], "");
    EXPECT_EQ(db.normalizedVersion["mdAirfoil2Normalized"], "mdAirfoil2Normalized");
    EXPECT_EQ(db.normalizedVersion["mdAirfoil6"], "");

    db.createAssociateNormalizedProfiles();
    e.push_back("mdAirfoil2-creatorNormalized");
    e.push_back("mdAirfoil6-creatorNormalized");
    e.push_back("mdAirfoilShifted-creatorNormalized");
    e.push_back("mdAirfoil3-creatorNormalized");
    e.push_back("mdAirfoil4-creatorNormalized");

    EXPECT_EQ(db.airfoilUIDs,e);


    EXPECT_TRUE(db.isPoints["mdAirfoil2-creatorNormalized"]);
    EXPECT_TRUE(db.isPoints["mdAirfoil4-creatorNormalized"]);

    EXPECT_TRUE(db.isNormalized["mdAirfoil2-creatorNormalized"]);
    EXPECT_TRUE(db.isNormalized["mdAirfoilShifted-creatorNormalized"]);

    EXPECT_EQ(db.normalizedVersion["mdAirfoil2"], "mdAirfoil2-creatorNormalized");
    EXPECT_EQ(db.normalizedVersion["mdAirfoil6"], "mdAirfoil6-creatorNormalized");

    file.open(DATA_DIR + "airfoils-out.xml");
    db.init(&file);
    db.createAssociateNormalizedProfiles(); //

    EXPECT_EQ(db.airfoilUIDs,e);

    EXPECT_TRUE(db.isPoints["mdAirfoil2-creatorNormalized"]);
    EXPECT_TRUE(db.isPoints["mdAirfoil4-creatorNormalized"]);

    EXPECT_TRUE(db.isNormalized["mdAirfoil2-creatorNormalized"]);
    EXPECT_TRUE(db.isNormalized["mdAirfoilShifted-creatorNormalized"]);

    EXPECT_EQ(db.normalizedVersion["mdAirfoil2"], "mdAirfoil2-creatorNormalized");
    EXPECT_EQ(db.normalizedVersion["mdAirfoil6"], "mdAirfoil6-creatorNormalized");



}