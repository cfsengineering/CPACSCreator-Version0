//
// Created by cfse on 11/14/18.
//


#include "gtest/gtest.h"

#include "ConfigWriter.h"
#include "ITiglGeometricComponent.h"

using namespace cpcr;

class ConfigWriterTests :   public ::testing::Test {

protected:

    std::string DATA_DIR="./Data/";

    virtual void SetUp() {

    }

    virtual void TearDown() {
    }

    double getDouble(ConfigWriter cw, std::string tempXpath){

        TixiDocumentHandle tixiHandle = cw.getConfiguration().GetTixiDocumentHandle();;
        double doubleTemp = tixi::TixiGetElement<double>(tixiHandle, tempXpath);
        return doubleTemp;
    }

    ConfigWriter initCW(std::string filename, std::string modelUID){
        TiglCPACSConfigurationHandle tiglHandle;
        TixiDocumentHandle  tixiHandle = tixi::TixiOpenDocument(filename);
        TiglReturnCode tiglRet = tiglOpenCPACSConfiguration(tixiHandle, modelUID.c_str(),  &tiglHandle);
        if(tiglRet != TIGL_SUCCESS){
            tiglHandle = -1;
             LOG(ERROR) << "ConfigWriterTests::setCW:: Error open the configuration" <<std::endl;
        }
        ConfigWriter cw;
        cw.setTiglHandle(tiglHandle);
        return cw;

    }

    void closeCW(ConfigWriter& cw ){
        TixiDocumentHandle tixiHandle = cw.getConfiguration().GetTixiDocumentHandle();
        tiglCloseCPACSConfiguration(cw.getTiglHandle());
        tixiCloseDocument(tixiHandle);
    }


};







TEST_F(ConfigWriterTests, getTransformation){

    UID uid = "Cpacs2Test";
    std::string currentFileName = "simple-aircraft-3.xml";
    UniqueXPath xPath;
    tigl::CTiglTransformation  current, expected;

    ConfigWriter cw = initCW( DATA_DIR + currentFileName , uid);

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

    closeCW(cw);


}



TEST_F(ConfigWriterTests, setTransformation) {

    UID uid = "Cpacs2Test";
    std::string currentFileName = "simple-aircraft-3.xml";
    UniqueXPath xPath;
    ConfigWriter cw;
    tigl::CTiglTransformation  after, forced;

    cw = initCW( DATA_DIR + currentFileName , uid);

    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]");

    forced.AddScaling(3,4,5);
    forced.AddTranslation(13,23,56);
    forced.AddRotationX(3);
    forced.AddRotationY(7);
    forced.AddRotationZ(8);

    cw.setTransformation(xPath, forced);
    after = cw.getTransformation(xPath);

    EXPECT_TRUE(after.IsApprox(forced));
    after.AddTranslation(3,3,3);
    EXPECT_FALSE(after.IsApprox(forced));


    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]/sections/section[2]");

    forced.SetIdentity();
    forced.AddScaling(2,2,2);
    forced.AddTranslation(-1,-1,-1);
    forced.AddRotationX(3);
    forced.AddRotationY(3);
    forced.AddRotationZ(3);

    cw.setTransformation(xPath, forced);
    after = cw.getTransformation(xPath);

    EXPECT_TRUE(after.IsApprox(forced));



    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]/sections/section[2]/elements/element[1]");

    forced.SetIdentity();
    forced.AddScaling(2,2,2);
    forced.AddTranslation(-1,-1,-1);
    forced.AddRotationX(3);
    forced.AddRotationY(3);
    forced.AddRotationZ(3);

    cw.setTransformation(xPath, forced);
    after = cw.getTransformation(xPath);

    EXPECT_TRUE(after.IsApprox(forced));

    closeCW(cw);


}


TEST_F(ConfigWriterTests, setTransformationDeepTest){

    UID uid = "Cpacs2Test";
    std::string currentFileName = "simple-aircraft-3.xml";
    std::string saveFileName = "simple-aircraft-3-out.xml";

    UniqueXPath xPath;
    tigl::CTiglTransformation  afterT, newT;
    double yBefore, yAfter, yAfterSaving;

    ConfigWriter cw = initCW(DATA_DIR + currentFileName , uid);

    // test to modify the transformation of the wing of the simple-aircraft-3
    xPath.setXPath("/cpacs/vehicles/aircraft/model/wings/wing[1]");

    yBefore = getDouble(cw, xPath.toString() + "/transformation/translation/y");
    EXPECT_DOUBLE_EQ(yBefore, 0);

    newT.SetIdentity();
    // remark doing the rotation before can cause trouble because the matrix decomposition seems impossible
    newT.AddScaling(4,77,2);
    newT.AddRotationX(40);
    newT.AddRotationY(20);
    newT.AddRotationZ(10);
    newT.AddTranslation(-3,-3,-3);

    // check the state after setting the transformation
    cw.setTransformation(xPath,newT);
    afterT = cw.getTransformation(xPath);
    EXPECT_TRUE( afterT.IsApprox(newT) ) ;
    yAfter = getDouble(cw,xPath.toString() + "/transformation/translation/y" );
    EXPECT_DOUBLE_EQ(yAfter, -3);

    // rewrite it with a other transformation
    newT.SetIdentity();
    newT.AddScaling(2,2,2);
    newT.AddRotationX(20);
    newT.AddRotationY(10);
    newT.AddRotationZ(0);
    newT.AddTranslation(-4,-4,-4);

    cw.setTransformation(xPath,newT);
    afterT = cw.getTransformation(xPath);
    EXPECT_TRUE( afterT.IsApprox(newT) ) ;
    yAfter = getDouble(cw,xPath.toString() + "/transformation/translation/y" );
    EXPECT_DOUBLE_EQ(yAfter, -4);

    // check the state after closing and reopening

    closeCW(cw);
}



TEST_F(ConfigWriterTests, save){
    //TODO


}