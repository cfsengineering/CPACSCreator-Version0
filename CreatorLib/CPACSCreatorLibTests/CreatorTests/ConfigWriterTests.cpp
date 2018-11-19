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

    ConfigWriter cw;
    cw.open( DATA_DIR + currentFileName , uid);

    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]");

    tigl::CTiglTransformation  t = cw.getTransformation(xPath);
    tigl::CTiglTransformation expected ;
    expected.AddScaling(1.1,2.2,3.3);

    for(int i =  0; i < 3; i++ ){
        for(int j =  0; j < 3; j++ ) {
            EXPECT_TRUE( expected.GetValue(i,j) == t.GetValue(i,j));
        }
    }



    xPath.setXPath("/cpacs/vehicles/aircraft/model/fuselages/fuselage[1]");

    t = cw.getTransformation(xPath);
    expected.SetIdentity();
    expected.AddScaling(1,0.5,0.5);
    for(int i =  0; i < 3; i++ ){
        for(int j =  0; j < 3; j++ ) {
            EXPECT_TRUE( expected.GetValue(i,j) == t.GetValue(i,j));
        }
    }



    xPath.setXPath("/cpacs/vehicles/aircraft/model/fuselages/fuselage[1]/sections/section[2]");

    t = cw.getTransformation(xPath);
    expected.SetIdentity();
    expected.AddTranslation(0.5,0,0);
    for(int i =  0; i < 3; i++ ){
        for(int j =  0; j < 3; j++ ) {
            EXPECT_TRUE( expected.GetValue(i,j) == t.GetValue(i,j));
        }
    }


    EXPECT_TRUE(true);

}