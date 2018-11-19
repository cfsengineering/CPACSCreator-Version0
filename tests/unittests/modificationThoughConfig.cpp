//
// Created by cfse on 11/12/18.
//

#include "CCPACSWingSection.h"
#include "test.h"
#include "tigl.h"
#include "CCPACSConfiguration.h"
#include "CCPACSConfigurationManager.h"
#include "CPACSWing.h"
#include "CCPACSTransformation.h"
#include "CTiglPoint.h"
#include "CCPACSWingSectionElements.h"
#include "CCPACSWingSectionElement.h"
#include "CCPACSWingSegment.h"

class modifications : public ::testing::Test
{
protected:


    TixiDocumentHandle           tixiHandle;
    TiglCPACSConfigurationHandle tiglHandle;

    virtual void SetUp()
    {
        const char* filename = "TestData/simpletest2.cpacs.xml";
        ReturnCode tixiRet;
        TiglReturnCode tiglRet;

        tiglHandle = -1;
        tixiHandle = -1;

        tixiRet = tixiOpenDocument(filename, &tixiHandle);
        ASSERT_TRUE (tixiRet == SUCCESS);
        tiglRet = tiglOpenCPACSConfiguration(tixiHandle, "Cpacs2Test", &tiglHandle);
        ASSERT_TRUE(tiglRet == TIGL_SUCCESS);


        ASSERT_TRUE(true);
    }

    virtual void TearDown()
    {
        ASSERT_TRUE(tiglCloseCPACSConfiguration(tiglHandle) == TIGL_SUCCESS);
        ASSERT_TRUE(tixiCloseDocument(tixiHandle) == SUCCESS);
        tiglHandle = -1;
        tixiHandle = -1;
    }

};


TEST_F(modifications, createAWing){

    tigl::CCPACSConfigurationManager& manager = tigl::CCPACSConfigurationManager::GetInstance();
    tigl::CCPACSConfiguration& config = manager.GetConfiguration(tiglHandle);
    tigl::CTiglUIDManager& uidManager = config.GetUIDManager();


    bool isRegister = uidManager.IsUIDRegistered("wingMD");
    EXPECT_FALSE(isRegister);

    tigl::CCPACSWings&  wings = config.GetWings();
    tigl::CCPACSWing&  newWing = wings.AddWing();
    newWing.SetUID("wingMD");

    isRegister = uidManager.IsUIDRegistered("wingMD");
    EXPECT_TRUE(isRegister);



    tigl::CCPACSTransformation& wingT =newWing.GetTransformation();
    wingT.setScaling( tigl::CTiglPoint(1,1,1));
    wingT.setTranslation( tigl::CTiglPoint(0,0,0));
    wingT.setRotation( tigl::CTiglPoint(0,0,0));

    // create section
    tigl::CCPACSWingSections& sections =newWing.GetSections();
    for (int i = 0; i < 10; i++){

        tigl::CCPACSWingSection& section = sections.AddSection();
        section.SetUID("sec"+std::to_string(i));
        tigl::CCPACSTransformation& sectionT =section.GetTransformation();
        sectionT.setScaling( tigl::CTiglPoint(2,2,2));
        sectionT.setTranslation( tigl::CTiglPoint(0,i*2,0));
        sectionT.setRotation( tigl::CTiglPoint(0,0,0));


        tigl::CCPACSWingSectionElements&  elements = section.GetElements();
        tigl::CCPACSWingSectionElement&  element =elements.AddElement();
        tigl::CCPACSTransformation& elementT =element.GetTransformation();
        elementT.setScaling( tigl::CTiglPoint(2,2,2));
        elementT.setTranslation( tigl::CTiglPoint(0,0,0));
        elementT.setRotation( tigl::CTiglPoint(0,0,0));
        element.SetAirfoilUID("NACA0012");
        element.SetUID("e"+std::to_string(i));
    }


    tigl::CCPACSWingSegments&  segments =newWing.GetSegments();
    for(int i = 0; i<9; i++ ){
        tigl::CCPACSWingSegment&  segment = segments.AddSegment();
        segment.SetUID("seg" + std::to_string(i));
        segment.SetFromElementUID("e" +std::to_string(i));
        segment.SetToElementUID("e"+ std::to_string(i+1));

    }




    config.WriteCPACS("Cpacs2Test");
    tixiSaveDocument(tixiHandle, "TestData/soubiou.xml");


    EXPECT_TRUE(true);
}




TEST_F(modifications, getTransforamtion){

    tigl::CCPACSConfigurationManager& manager = tigl::CCPACSConfigurationManager::GetInstance();
    tigl::CCPACSConfiguration& config = manager.GetConfiguration(tiglHandle);
    tigl::CTiglUIDManager& uidManager = config.GetUIDManager();






}