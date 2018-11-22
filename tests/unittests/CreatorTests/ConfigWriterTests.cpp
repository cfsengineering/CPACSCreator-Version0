//
// Created by cfse on 11/14/18.
//


#include "gtest/gtest.h"

#include "ConfigWriter.h"


using namespace cpcr;

class ConfigWriterTests :   public ::testing::Test {

protected:

    std::string DATA_DIR="./Data/";

    virtual void SetUp() {

    }

    virtual void TearDown() {
    }




};


TEST_F(ConfigWriterTests, getTransformation){

    UID uid = "Cpacs2Test";
    std::string currentFileName = "simple-aircraft-3.xml";
    UniqueXPath xPath;
    tigl::CTiglTransformation  current, expected;

    ConfigWriter cw;
    cw.open( DATA_DIR + currentFileName , uid);

    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]");

    current = cw.getTransformation(xPath);
    expected.SetIdentity();
    expected.AddScaling(1.1,2.2,3.3);
    EXPECT_TRUE( current.IsEqual(expected));



    xPath.setXPath("/cpacs/vehicles/aircraft/model/fuselages/fuselage[1]");

    current = cw.getTransformation(xPath);
    expected.SetIdentity();
    expected.AddScaling(1,0.5,0.5);
    EXPECT_TRUE( current.IsEqual(expected));


    xPath.setXPath("/cpacs/vehicles/aircraft/model/fuselages/fuselage[1]/sections/section[2]");

    current = cw.getTransformation(xPath);
    expected.SetIdentity();
    expected.AddTranslation(0.5,0,0);
    EXPECT_TRUE( current.IsEqual(expected));


}



TEST_F(ConfigWriterTests, setTransformation) {

    UID uid = "Cpacs2Test";
    std::string currentFileName = "simple-aircraft-3.xml";
    UniqueXPath xPath;
    ConfigWriter cw;
    tigl::CTiglTransformation  after, forced;

    cw.open( DATA_DIR + currentFileName , uid);

    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]");

    forced.AddScaling(3,4,5);
    forced.AddTranslation(13,23,56);
    forced.AddRotationX(3);
    forced.AddRotationY(7);
    forced.AddRotationZ(8);

    cw.setTransformation(xPath, forced);
    after = cw.getTransformation(xPath);

    EXPECT_TRUE(after.IsEqual(forced));
    after.AddTranslation(3,3,3);
    EXPECT_FALSE(after.IsEqual(forced));


    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]/sections/section[2]");

    forced.SetIdentity();
    forced.AddScaling(2,2,2);
    forced.AddTranslation(-1,-1,-1);
    forced.AddRotationX(3);
    forced.AddRotationY(3);
    forced.AddRotationZ(3);

    cw.setTransformation(xPath, forced);
    after = cw.getTransformation(xPath);

    EXPECT_TRUE(after.IsEqual(forced));



    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]/sections/section[2]/elements/element[1]");

    forced.SetIdentity();
    forced.AddScaling(2,2,2);
    forced.AddTranslation(-1,-1,-1);
    forced.AddRotationX(3);
    forced.AddRotationY(3);
    forced.AddRotationZ(3);

    cw.setTransformation(xPath, forced);
    after = cw.getTransformation(xPath);

    EXPECT_TRUE(after.IsEqual(forced));




}