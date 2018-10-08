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
// Created by makem on 29/04/18.
//




#include "gtest/gtest.h"
#include "AircraftTree.h"

#include "Helper.h"

#include "CreatorException.h"

#include "tigl.h"

#include "MyTestHelperFunctions.h"


using namespace cpcr;


/***
 * This class tests the AircraftTree class.
 * Generally, there is one test per public functions.
 * The cpacs files used for testing in folder "CreatorTests/Data".
 * If the file is modified, the result is store in "AircraftTreeTest-out.xml".
 * So you can follow the progression of the test in CPACSViewer by opening the "AircraftTreeTest-out.xml" file
 * (You need to run the test step by step, with a debugger).
 *
 */
class AircraftTreeTest : public  ::testing::Test {

protected:

    std::string DATA_DIR="./Data/";


    std::string currentFile = "not set";
    std::string outFileName = DATA_DIR + "AircraftTreeTest-out.xml";

    UniqueXPath rootXPath = UniqueXPath("not set");

    AircraftTree tree ;
    CPACSTreeItem* root;

    // To use directly the tigl and tixi library for testing
    // Be careful the handler need to be up-to-date with the tested file
    TixiDocumentHandle tixiHandle;
    TiglCPACSConfigurationHandle tiglHandle;


    // Used to test the area. Can check if the area value has changed
    // First need to backup the area values with "backupReferenceAreaValues",
    // Then compare it with the actual values with "checkCurrentAreasWithBackup"
    double tempArea, bAreaXY, bAreaXZ, bAreaYZ,bArea, aAreaXY, aAreaXZ,aAreaYZ,aArea;




    // Used to check if chords of the wing has changed.
    // Same principle as for area,
    // first need to back up the chord values with "backupChordPointsOfWing"
    // then the value can be checked with "checkCurrentChordPointsWithBackup"
    std::vector<cpcr::UID> UIDs;
    std::map<cpcr::UID, Eigen::Vector4d> lEsB;
    std::map<cpcr::UID, Eigen::Vector4d> tEsB;
    std::map<cpcr::UID, Eigen::Vector4d> lEsA;
    std::map<cpcr::UID, Eigen::Vector4d> tEsA;




    void setVariables(std::string fileName){
        rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");
        currentFile = DATA_DIR + fileName;
        tree.build(currentFile, rootXPath);
        root = tree.getRoot();
        tree.writeToFile(outFileName);  // for visual test
        setTixiAndTiglHandlers();
    }


    void setVariablesSpecialRootXPath(std::string fileName, UniqueXPath specialRootXPath ){
        rootXPath = specialRootXPath;
        currentFile = DATA_DIR + fileName;
        tree.build(currentFile, rootXPath);
        root = tree.getRoot();
        tree.writeToFile(outFileName);  // for visual test
        setTixiAndTiglHandlers();
    }


    void setTixiAndTiglHandlers(){
        // Open document
        tixiHandle = tixi::TixiOpenDocument(outFileName);
        tiglOpenCPACSConfiguration(tixiHandle, tree.getRoot()->getUid().c_str(), &tiglHandle);
    }

    void backupReferenceAreaValues() {
        setTixiAndTiglHandlers(); // to be sure that the tigl is up-to-date
        // backup before area
        tiglWingGetReferenceArea(tiglHandle,1, TIGL_X_Y_PLANE,&bAreaXY);
        // tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Z_PLANE,&bAreaXZ);
        tiglWingGetReferenceArea(tiglHandle,1, TIGL_Y_Z_PLANE,&bAreaYZ);
        // tiglWingGetReferenceArea(*tiglHandle,1, TIGL_NO_SYMMETRY,&bArea);
    }

    void checkCurrentAreasWithBackup(){
        setTixiAndTiglHandlers(); // to be sure that the tigl is up-to-date
        tiglWingGetReferenceArea(tiglHandle,1, TIGL_X_Y_PLANE,&aAreaXY);
        //tiglWingGetReferenceArea(*tiglHandle,1, TIGL_X_Z_PLANE,&aAreaXZ);
        tiglWingGetReferenceArea(tiglHandle,1, TIGL_Y_Z_PLANE,&aAreaYZ);
        //tiglWingGetReferenceArea(*tiglHandle,1, TIGL_NO_SYMMETRY,&aArea);

        EXPECT_TRUE(fabs( bAreaXY - aAreaXY) <= 0.001 );
        //EXPECT_EQ(bAreaXZ, aAreaXZ);
        EXPECT_TRUE(fabs( bAreaYZ - aAreaYZ) <= 0.001) ;
        //EXPECT_EQ(bArea, aArea);

    }



    void backupChordPointsOfWing(std::string wingUID) {

        CPACSTreeItem *wing = tree.getRoot()->getChildByUid(wingUID);

        UIDs = tree.getAllElementUIDsUsedInAWing(wing->getUid());
        lEsB = tree.getChordPointsOfElementsInWing(wing->getUid(), 0);
        tEsB = tree.getChordPointsOfElementsInWing(wing->getUid(), 1);
    }

    void checkCurrentChordPointsWithBackup(std::string wingUID){

        CPACSTreeItem *wing = tree.getRoot()->getChildByUid(wingUID);
        lEsA = tree.getChordPointsOfElementsInWing(wing->getUid(), 0);
        tEsA = tree.getChordPointsOfElementsInWing(wing->getUid(), 1);

        for(UID u: UIDs )
        {
            EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
            EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
        }

    }



};

TEST_F(AircraftTreeTest, buildAndClose ){

    // For this test, we do not use the "setVariables" function because we want to to test the functions used inside it.

    AircraftTree aircraftTree ;
    EXPECT_TRUE(aircraftTree.getRoot() == nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() == false);
    aircraftTree.close();
    EXPECT_TRUE(aircraftTree.getRoot() == nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() == false);

    std::string tempFilename = DATA_DIR + "D150_AGILE_Hangar_3.xml";
    rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");
    aircraftTree.build(tempFilename, rootXPath);

    EXPECT_TRUE(aircraftTree.getRoot() != nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() != false);
    CPACSTreeItem* backupRoot = aircraftTree.getRoot();
    EXPECT_TRUE(backupRoot->getUid() == "D150_VAMP");

    aircraftTree.close();
    EXPECT_TRUE(aircraftTree.getRoot() == nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() == false);

    aircraftTree.build(tempFilename, rootXPath);

    EXPECT_TRUE(aircraftTree.getRoot() != nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() != false);
    EXPECT_TRUE(aircraftTree.getRoot()->getUid() == "D150_VAMP");

    aircraftTree.close();
    EXPECT_TRUE(aircraftTree.getRoot() == nullptr);
    EXPECT_TRUE(aircraftTree.isBuild() == false);

}



TEST_F(AircraftTreeTest, build){


    // initial state ( aircraftTree is construct each time by the gtest lib)
    // For this test, we do not use the "setVariables" function because we want to to test the functions used inside it.

    // Call build and set root, tixi and tigl handlers, outfile , currentfile
    setVariables("AircraftTreeTest1.xml");


    // check result
    EXPECT_EQ( root->getXPath().toString(), "/cpacs/vehicles/aircraft/model[1]" );
    EXPECT_EQ( root->getType(), "model");
    EXPECT_TRUE( tree.isBuild() );
    TiglBoolean isValid;
    tiglIsCPACSConfigurationHandleValid(tiglHandle, &isValid );
    EXPECT_EQ( isValid, TIGL_TRUE);

    EXPECT_EQ( root->getChildren().size(), 3);
    EXPECT_EQ( root->hasChildOfType("name"), true );
    EXPECT_EQ( root->hasChildOfType("fuselages"), true );
    EXPECT_EQ( root->hasChildOfType("wings"), true );

    CPACSTreeItem* child = root->getChild(UniqueXPath("wings"))->getChild(UniqueXPath("wing"));
    EXPECT_EQ( child->getType(),"wing");
    EXPECT_EQ( child->getChildren().size(), 4);
    EXPECT_TRUE( child->hasChildOfType("transformation")) ;

    CPACSTreeItem* fuselage = root->getChild("./fuselages/fuselage");
    EXPECT_EQ(fuselage->getUid(), "SimpleFuselage");


    // construct a tree with the second aircraft of the file

    UniqueXPath specialRoot = UniqueXPath("/cpacs/vehicles/aircraft/model[2]");
    setVariablesSpecialRootXPath("AircraftTreeTest1b-doubleModel.xml", specialRoot);

    EXPECT_EQ(root->getUid(), "Cpacs2Test");
    tiglIsCPACSConfigurationHandleValid(tiglHandle, &isValid );
    EXPECT_EQ( isValid, TIGL_TRUE);
    int count  = 0;
    tiglGetWingCount(tiglHandle, &count);
    EXPECT_EQ(count, 0);
    EXPECT_EQ(root->findAllChildrenOfTypeRecursively("wing").size(),0);


    // construct a tree with the second aircraft of the file
    specialRoot = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");
    setVariablesSpecialRootXPath("AircraftTreeTest1b-doubleModel.xml", specialRoot);

    EXPECT_EQ(root->getUid(), "mDsave");
    tiglIsCPACSConfigurationHandleValid(tiglHandle, &isValid );
    EXPECT_EQ( isValid, TIGL_TRUE);
    count  = 0;
    tiglGetWingCount(tiglHandle, &count);
    EXPECT_EQ(count, 3);
    EXPECT_EQ(root->findAllChildrenOfTypeRecursively("wing").size(),3);


    // incorrect xpath (not a model)
    EXPECT_THROW(tree.build(DATA_DIR + "AircraftTreeTest1.xml",UniqueXPath("/cpacs/vehicles/aircraft")), CreatorException);
    EXPECT_EQ(tree.isBuild(), false);

}


TEST_F(AircraftTreeTest, getChordPointsOfElementsInWing){

    setVariables("simple-aircraft.cpacs.xml");

    CPACSTreeItem* wing = tree.getRoot()->getChildByUid("Wing");

    std::map< UID, Eigen::Vector4d> chords = tree.getChordPointsOfElementsInWing(wing->getUid(), 0.5);
    Eigen::Vector4d expected;
    expected << 0.5,0,0,1;
    EXPECT_EQ(chords["Cpacs2Test_Wing_Sec1_El1"], expected);
    expected << 0.5,1,0,1;
    EXPECT_EQ(chords["Cpacs2Test_Wing_Sec2_El1"], expected);
    expected << 0.75,2,0,1;
    EXPECT_EQ(chords["Cpacs2Test_Wing_Sec3_El1"], expected);


}

TEST_F(AircraftTreeTest, getCenterPointsOfElementsInFuselage){

    setVariables("simple-aircraft.cpacs.xml");


    CPACSTreeItem* fusleage = tree.getRoot()->getChildByUid("SimpleFuselage");
    Eigen::Vector4d expected;

    std::map< UID, Eigen::Vector4d> centers = tree.getCenterPointsOfElementsInFuselage(fusleage->getUid());
    expected << -0.5,0,0,1;
    EXPECT_TRUE(centers["D150_Fuselage_1Section1IDElement1"].isApprox(expected, 0.01) );
    expected << 0.5,0,0,1;
    EXPECT_TRUE(centers["D150_Fuselage_1Section2IDElement1"].isApprox(expected, 0.01) );
    expected << 1.5,0,0,1;
    EXPECT_TRUE(centers["D150_Fuselage_1Section3IDElement1"].isApprox(expected, 0.01) );

}



TEST_F(AircraftTreeTest, getTransformToPlaceElementAt ){


    setVariables("AircraftTreeTest3.xml");

    Eigen::Vector4d wantedP ;
    wantedP << 30,14,3, 1;
    UID elementToPlace = "Wing_section1_element1";

    CPACSTransformation e(1,1,1,0,0,0,30,14,-2);
    CPACSTransformation t = tree.getTransformToPlaceElementByTranslationAt(elementToPlace, wantedP);
    EXPECT_TRUE( t == e);

    wantedP << 0,10,0, 1;
    elementToPlace = "Wing_section2_element1";
    e = CPACSTransformation(1,1,1,0,0,0,0,7.0710678118654,-7.0710678118654);
    t = tree.getTransformToPlaceElementByTranslationAt(elementToPlace, wantedP);
    EXPECT_TRUE( t.getTransformationAsMatrix().isApprox(e.getTransformationAsMatrix(), 0.0001) );


    wantedP << 0,0,0, 1;
    elementToPlace = "Wing_section3_element1";
    e = CPACSTransformation(1,1,1,0,0,0,4.22-1,7.84-1,4.53-0);
    t = tree.getTransformToPlaceElementByTranslationAt(elementToPlace, wantedP);
    EXPECT_TRUE( t.getTransformationAsMatrix().isApprox(e.getTransformationAsMatrix(), 0.01) );


}



TEST_F(AircraftTreeTest, getTransformationChainForOneElement){


    setVariables("AircraftTreeTest6-positionings.xml");

    CPACSTransformation identity, expected;


    // Case 1 (basic)
    CPACSTreeItem* element = root->getChildByUid("Wing_section2_element1");

    auto r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );


    expected = CPACSTransformation(1,1,1,0,0,0,0,3.3,0);
    EXPECT_EQ(r[2].first->getUid(), "pos1");
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix()) );


    expected = CPACSTransformation(0.5,1,1,0,0,0,0,0,0);
    EXPECT_EQ(r[1].first->getUid(), "Wing_section2_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( expected.getTransformationAsMatrix()) );

    expected = CPACSTransformation(2,1,1,0,0,0,0,3,0);
    EXPECT_EQ(r[0].first->getUid(), "Wing_section2_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( expected.getTransformationAsMatrix()) );


    // Case 2 (no positioning )
    element = root->getChildByUid("Wing_section1_element1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );


    EXPECT_EQ(r[2].first, nullptr);
    EXPECT_TRUE(r[2].second.isApprox( identity.getTransformationAsMatrix()) );


    expected = CPACSTransformation(1,1,1,0,0,0,0,-0.5,0);
    EXPECT_EQ(r[1].first->getUid(), "Wing_section1_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( expected.getTransformationAsMatrix()) );

    expected = CPACSTransformation(2.2,1,1,0,0,0,0,0,0);
    EXPECT_EQ(r[0].first->getUid(), "Wing_section1_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( expected.getTransformationAsMatrix()) );


    // case 3 ( multiple positioning)

    // positioning 1
    element = root->getChildByUid("Wing2_section1_element1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing2_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );

    expected = CPACSTransformation(1,1,1,0,0,0,4.22,7.84,4.53);
    EXPECT_EQ(r[2].first->getUid(), "Wing2_positioning1" );
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix(), 0.05) );

    EXPECT_EQ(r[1].first->getUid(), "Wing2_section1_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( identity.getTransformationAsMatrix()) );

    EXPECT_EQ(r[0].first->getUid(), "Wing2_section1_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( identity.getTransformationAsMatrix()) );

    // positioning 2
    element = root->getChildByUid("Wing2_section2_element1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing2_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );

    expected = CPACSTransformation(1,1,1,0,0,0,7.07,5.42,4.54);
    EXPECT_EQ(r[2].first->getUid(), "Wing2_positioning2");
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix(), 0.01) );

    EXPECT_EQ(r[1].first->getUid(), "Wing2_section2_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( identity.getTransformationAsMatrix()) );

    EXPECT_EQ(r[0].first->getUid(), "Wing2_section2_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( identity.getTransformationAsMatrix()) );

    // positioning 3
    element = root->getChildByUid("Wing2_section3_element1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    EXPECT_EQ(r[3].first->getUid(), "Wing2_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( identity.getTransformationAsMatrix()) );

    expected = CPACSTransformation(1,1,1,0,0,0,11.29,13.25,9.07);
    EXPECT_EQ(r[2].first->getUid(), "Wing2_positioning3");
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix(), 0.02) );

    EXPECT_EQ(r[1].first->getUid(), "Wing2_section3_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( identity.getTransformationAsMatrix()) );

    EXPECT_EQ(r[0].first->getUid(), "Wing2_section3_element1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( identity.getTransformationAsMatrix()) );


    /*
     * FUSELAGE CASE
     */
    setVariables("simple-aircraft-fuselages.xml");

    element = root->getChildByUid("D150_Fuselage_1Section1IDElement1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    expected = CPACSTransformation(1,0.5,0.5,0,0,0,0,0,0);
    EXPECT_EQ(r[3].first->getUid(), "SimpleFuselage_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( expected.getTransformationAsMatrix(), 0.001) );

    expected = CPACSTransformation(1,1,1,0,0,0,-0.5,0,0);
    EXPECT_EQ(r[2].first->getUid(), "D150_Fuselage_1Positioning1ID");
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix(), 0.02) );

    EXPECT_EQ(r[1].first->getUid(), "D150_Fuselage_1Section1ID_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( identity.getTransformationAsMatrix()) );

    EXPECT_EQ(r[0].first->getUid(), "D150_Fuselage_1Section1IDElement1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( identity.getTransformationAsMatrix()) );



    element = root->getChildByUid("D150_Fuselage_2Section3IDElement1");
    r = tree.getTransformationChainForOneElement(element);

    EXPECT_EQ(r.size(), 4);

    expected = CPACSTransformation(1,0.5,0.5,0,0,0,0,3,0);
    EXPECT_EQ(r[3].first->getUid(), "FuselageUnconventionalOrdering_transformation1");
    EXPECT_TRUE(r[3].second.isApprox( expected.getTransformationAsMatrix(), 0.001) );

    expected = CPACSTransformation(1,1,1,0,0,0,1.5,0,0);
    EXPECT_EQ(r[2].first->getUid(), "D150_Fuselage_2Positioning3ID");
    EXPECT_TRUE(r[2].second.isApprox( expected.getTransformationAsMatrix(), 0.02) );

    EXPECT_EQ(r[1].first->getUid(), "D150_Fuselage_2Section3ID_transformation1");
    EXPECT_TRUE(r[1].second.isApprox( identity.getTransformationAsMatrix()) );

    expected = CPACSTransformation(1,1,1,0,0,0,0.5,0,0);
    EXPECT_EQ(r[0].first->getUid(), "D150_Fuselage_2Section3IDElement1_transformation1");
    EXPECT_TRUE(r[0].second.isApprox( expected.getTransformationAsMatrix()) );






}





TEST_F(AircraftTreeTest, getGlobalTransformMatrixOfElement){


    setVariables("AircraftTreeTest7-getGlobalTransformMatrixOfElement.xml");

    Eigen::Vector4d o, r ,e;

    Eigen::Matrix3d mEuler ;
    Eigen::Vector3d o3d, e3d, r3d , r13d, r23d;
    // Euler rotation matrix X45 Y'30 Z"20 taken from internet
    mEuler.row(0) <<  0.8137977, -0.2961981,  0.5000000;
    mEuler.row(1) <<   0.5740763,  0.5435407, -0.6123725;
    mEuler.row(2) <<   -0.0903867,  0.7853854,  0.6123725 ;



    auto m = tree.getGlobalTransformMatrixOfElement("Wing_section2_element1");

    o3d << 3,-2,10;
    r3d = mEuler * o3d;

    o << 0,0,0,1;
    e << r3d[0], r3d[1] , r3d[2],  1 ;

    r = m * o;

    EXPECT_TRUE( r.isApprox(e, 0.0001) );



    o3d << 0,0,0;
    r3d = mEuler * o3d;

    o << -3,2,-10,1;
    e << r3d[0], r3d[1] , r3d[2],  1 ;

    r = m * o;

    EXPECT_TRUE( r.isApprox(e, 0.0001) );


    o3d << 3 + 1,-2 + 3 ,10 + 4;
    r3d = mEuler * o3d;

    o << 1,3,4,1;
    e << r3d[0], r3d[1] , r3d[2],  1 ;

    r = m * o;

    EXPECT_TRUE( r.isApprox(e, 0.0001) );

}



TEST_F(AircraftTreeTest, writeToFile){

    setVariables("AircraftTreeTest5-setWingSweep2-D150.xml");

    tree.writeToFile();
    EXPECT_EQ(tree.isBuild(), true);
    EXPECT_EQ(tree.getFilename(), outFileName);


    tree.writeToFile( DATA_DIR + "test-write.xml");
    EXPECT_EQ(tree.isBuild(), true);
    EXPECT_EQ(tree.getFilename(), DATA_DIR + "test-write.xml");

}


TEST_F(AircraftTreeTest, determinePositionBySweepAngle ){

    setVariables("AircraftTreeTest2-getWingSweep2.xml");

    Eigen::Vector4d a,b,c, r, e ;
    a << 0,0,0,1;
    b << 10,4,0,1;
    c << 0,4,0,1;
    e << 3,4,0,1; // the expected value

    double angle = RadianToDegree( (acos(0.8)) );
    r = tree.computePositionToHaveSweepAngle(a, b, angle);
    EXPECT_TRUE( e.isApprox(r) );

    a << 3,3,3,1;
    b << 13,7,3,1;
    e << 6,7,3,1; // the expected value

    angle = RadianToDegree( (acos(0.8)) );
    r = tree.computePositionToHaveSweepAngle(a, b, angle);
    EXPECT_TRUE( e.isApprox(r) );

    a << 3,3,3,1;
    b << 13,3.866025403,-1,1;
    e << 3.5,3.866025403,-1,1; // the expected value
    angle = 30 ;
    r = tree.computePositionToHaveSweepAngle(a, b, angle);
    EXPECT_TRUE( e.isApprox(r, 0.0001) );


}



TEST_F(AircraftTreeTest, getWingSweep){


    double sweep = -1;

    // fileName2 is define with leading edge airfoil at (0,0,0)

    std::string filename = "AircraftTreeTest2-getWingSweep2.xml";
    setVariables(filename);

    sweep = tree.getWingSweep("D150_VAMP_wing_W1",0);
    EXPECT_TRUE( sweep > 19 && sweep < 21 );

    sweep = tree.getWingSweep("D150_VAMP_htp_HL1",0);
    EXPECT_TRUE( sweep > 26.5 && sweep < 26.6 );

    sweep = tree.getWingSweep("D150_VAMP_vtp_SL1",0);
    EXPECT_TRUE( sweep > 40 && sweep < 42 );



    filename = "AircraftTreeTest9-getWingSweep.xml";
    setVariables(filename);

    sweep = tree.getWingSweep("D150_VAMP_wing_W1",0.5);
    EXPECT_TRUE( sweep > 19 && sweep < 21 );

    sweep = tree.getWingSweep("D150_VAMP_htp_HL1",0.5);
    EXPECT_TRUE( sweep > 26.5 && sweep < 26.6 );

}



TEST_F(AircraftTreeTest, setWingSweepByTranslation){


    //
    //  TEST leading edge set wing sweep (chordPercent = 0)
    //


    setVariables("AircraftTreeTest5-setWingSweep2-D150.xml");


    // set to 40
    double before = tree.getWingSweep("D150_VAMP_wing_W1",0);
    EXPECT_TRUE( before > 24 && before < 25);

    tree.setWingSweepByTranslation("D150_VAMP_wing_W1", 40, 0);

    tree.writeToFile(outFileName);
    double after = tree.getWingSweep("D150_VAMP_wing_W1", 0);
    EXPECT_TRUE(after > 39.9 && after < 40.1);


    tree.setWingSweepByTranslation("D150_VAMP_wing_W1", 70);

    after = tree.getWingSweep("D150_VAMP_wing_W1");
    EXPECT_TRUE(after > 69.9 && after < 70.1);

    tree.writeToFile(outFileName);


    // set to 7
    tree.setWingSweepByTranslation("D150_VAMP_wing_W1", 7);

    after = tree.getWingSweep("D150_VAMP_wing_W1");
    EXPECT_TRUE(after > 6.9 && after < 7.1);

    tree.writeToFile(outFileName);

    // TODO : limit case around 90 degrees


    //
    //  TEST set wing sweep with chord middle (chordPercent = 0.5)
    //
    // fileName9 is the same file as fileName2 but with centered airfoil
    // -> so getWingSweepOfOrigin( x ) is more or less  equivalent to getWingSweep(x, 0.5)

    setVariables( "AircraftTreeTest9-getWingSweep.xml");

    before = tree.getWingSweep("D150_VAMP_wing_W1",0.5);

    tree.setWingSweepByTranslation("D150_VAMP_wing_W1", 30, 0.5);

    after = tree.getWingSweep("D150_VAMP_wing_W1",0.5);

    EXPECT_TRUE( after > 29 && after < 31 );

    double alterSweep = tree.getWingSweep("D150_VAMP_wing_W1",0);
    EXPECT_FALSE(  alterSweep > 29 && alterSweep < 31 );

    tree.writeToFile(outFileName);

    //
    setVariables( "wing-simple.xml");

    before = tree.getWingSweep("Wing");
    EXPECT_TRUE( before > -0.1 && before < 0.1 );
    tree.setWingSweepByTranslation("Wing",20,0);
    after = tree.getWingSweep("Wing");
    EXPECT_TRUE( after > 19.9 && after < 20.1 );
    tree.writeToFile(outFileName);


    // TEST CASE bwb

    setVariables("TestCases/blendedWingBody.xml");
    std::string wingUID = "BWB450_wingID";
    before = tree.getWingSweep(wingUID,0);
    EXPECT_TRUE( before > 50 && before < 55 );
    tree.setWingSweepByTranslation(wingUID,20,0);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep(wingUID);
    EXPECT_TRUE( after > 19.9 && after < 20.1 );
    tree.writeToFile(outFileName);


    // The wing transform should not influence the wing sweep
    setVariables("blendedWingBody-rot20.xml");

    before = tree.getWingSweep(wingUID,0);
    EXPECT_TRUE( before > 50 && before < 55 );
    tree.setWingSweepByTranslation(wingUID,20,0);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep(wingUID);
    EXPECT_TRUE( after > 19.9 && after < 20.1 );


}



TEST_F(AircraftTreeTest, setWingSweepByShearingSimpleWing){


    /*
     * WING SIMPLE
     */

    setVariables("wing-simple.xml");

    // Test the value before the modification
    double before = tree.getWingSweep("Wing",0);

    backupReferenceAreaValues();

    // set to 60
    tree.setWingSweepByShearing("Wing", 60, 0);
    tree.writeToFile(outFileName);

    // check the values after
    double after = tree.getWingSweep("Wing", 0);
    EXPECT_TRUE(after > 59.9 && after < 70.1);
    std::map<cpcr::UID, Eigen::Vector4d>  chordPoints = tree.getChordPointsOfElementsInWing("Wing", 0);
    Eigen::Vector4d chord1E, chord2E  ;
    chord1E << -1, 0, 0,1;
    chord2E << 0.73205081, 1, 0,1;
    EXPECT_TRUE(chordPoints["Wing_section1_element1"].isApprox(chord1E, 0.0001));
    EXPECT_TRUE(chordPoints["Wing_section2_element1"].isApprox(chord2E, 0.0001));

    checkCurrentAreasWithBackup(); // areas need to stand the same



    /*
     * WING SIMPLE ROTATIONS
     */

    // create the tree
    setVariables( "wing-simple-rotations-2.xml");
    // check the values before
    before = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE( before > -0.1 && before < 0.1);
    backupReferenceAreaValues();
    // set to 60
    tree.setWingSweepByShearing("Wing", 60, 0);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep("Wing", 0);
    checkCurrentAreasWithBackup();




    /*
     * WING SIMPLE ONE KICK
     */
    setVariables( "wing-one-kick.xml");
    before = tree.getWingSweep("Wing",0);
    backupReferenceAreaValues();
    EXPECT_TRUE( before > 26.56 && before < 26.9);
    tree.setWingSweepByShearing("Wing", 60, 0);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep("Wing", 0);
    EXPECT_TRUE(after > 59.9 && after < 70.1);
    checkCurrentAreasWithBackup();


    /*
     * WING SIMPLE ONE KICK + ROTATIONS
     */

    setVariables("wing-one-kick-rotations-scales.xml");
    before = tree.getWingSweep("Wing",0.5);
    backupReferenceAreaValues();
    EXPECT_TRUE( before > 26.56 && before < 26.9);
    tree.setWingSweepByShearing("Wing", 60, 0.5);
    tree.writeToFile(outFileName);
    after = tree.getWingSweep("Wing", 0);
    EXPECT_TRUE(after > 59.9 && after < 70.1);
    checkCurrentAreasWithBackup();


    // TEST CASE D150

    setVariables("TestCases/d150.xml");
    std::string wingUID = "D150_VAMP_vtp_SL1";
    tree.writeToFile();

    before = tree.getWingSweep(wingUID, 0);
    backupReferenceAreaValues();
    EXPECT_TRUE(before > 40 && before < 41);
    tree.setWingSweepByShearing(wingUID, 12);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 0);
    EXPECT_TRUE(after > 11.9 && after < 12.1);
    checkCurrentAreasWithBackup();


    before = tree.getWingSweep(wingUID, 1);
    backupReferenceAreaValues();
    EXPECT_TRUE(before > -22 && before <  -20);
    tree.setWingSweepByShearing(wingUID, 12, 1);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 1);
    EXPECT_TRUE(after > 11.9 && after < 12.1);
    checkCurrentAreasWithBackup();



    // TEST CASE BOXWING

    setVariables("TestCases/boxWing.xml");
    wingUID = "D150_VAMP_W1";


    before = tree.getWingSweep(wingUID, 0);
    backupReferenceAreaValues();
    EXPECT_TRUE(before > 26 && before < 28);

    tree.setWingSweepByShearing(wingUID, 12, 0.5);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 0.5);
    EXPECT_TRUE(after > 11.9 && after < 12.1);
    checkCurrentAreasWithBackup();


    backupReferenceAreaValues();
    tree.setWingSweepByShearing(wingUID, 72, 0.5);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 0.5);
    EXPECT_TRUE(after > 71.9 && after < 72.1);
    checkCurrentAreasWithBackup();


    backupReferenceAreaValues();
    tree.setWingSweepByShearing(wingUID, 23, 1);
    tree.writeToFile();
    after = tree.getWingSweep(wingUID, 1);
    EXPECT_TRUE(after > 22.9 && after < 23.1);
    checkCurrentAreasWithBackup();


}



TEST_F(AircraftTreeTest, getWingDihedral)
{

    double dihedral = -1;
    double sweep = -1;


    //
    //  SIMPLE WING WITH NO DIHEDRAL AND NOR SWEEP
    //


    setVariables( "wing-simple.xml") ;

    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 0));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 0));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 0));


    //
    //  SIMPLE WING WITH DIHEDRAL AND SWEEP
    //

    setVariables( "wing-simple-d30-s30-by-positioning.xml");


    // just some check about the sweep (remember the sweep angle is not the same as in the positiong in cpacs file)
    sweep = tree.getWingSweep("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,33.69));

    sweep = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,33.69));

    // dihedral
    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    //
    //  SIMPLE WING WITH NEGATIVE DIHEDRAL AND NEGATIVE SWEEP
    //

    setVariables( "wing-simple-dm30-sm30-by-positioning.xml");


    // just some check about the sweep (remember the sweep angle is not the same as in the positiong in cpacs file)
    sweep = tree.getWingSweep("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,-33.69));

    sweep = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,-33.69));

    // dihedral
    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));



    //
    //  SIMPLE WING WITH NEGATIVE DIHEDRAL AND POSITIVE SWEEP
    //

    setVariables( "wing-simple-dm30-s30-by-positioning.xml");

    // just some check about the sweep (remember the sweep angle is not the same as in the positiong in cpacs file)
    sweep = tree.getWingSweep("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,33.69));

    sweep = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,33.69));

    // dihedral
    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, -30));



    //
    //  SIMPLE WING WITH POSITIVE DIHEDRAL AND NEGATIVE SWEEP
    //

    setVariables( "wing-simple-d30-sm30-by-positioning.xml");

    // just some check about the sweep (remember the sweep angle is not the same as in the positiong in cpacs file)
    sweep = tree.getWingSweep("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,-33.69));

    sweep = tree.getWingSweep("Wing",0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(sweep,- 33.69));

    // dihedral
    dihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    dihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));

    dihedral = tree.getWingDihedral("Wing", 1);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(dihedral, 30));


    // TEST CASE D150

    setVariables("d150-vt-dihedral.xml");
    std::string wingUID = "D150_VAMP_vtp_SL1";
    tree.writeToFile();

    double before = tree.getWingDihedral(wingUID, 0);
    EXPECT_TRUE(before > 9.9 && before < 10.1);

    before = tree.getWingDihedral(wingUID, 1);
    EXPECT_TRUE(before > 9.9 && before < 10.1);

}



TEST_F(AircraftTreeTest, setWingDihedral)
{

    double oldDihedral, newDihedral;


    //
    //  SIMPLE WING WITH NO DIHEDRAL AND NOR SWEEP
    //

    setVariables( "wing-simple.xml") ;

    oldDihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(oldDihedral, 0));

    backupReferenceAreaValues();
    tree.setWingDihedral("Wing",30);
    tree.writeToFile(outFileName);
    newDihedral = tree.getWingDihedral("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(newDihedral, 30));
    checkCurrentAreasWithBackup();


    //
    //  SIMPLE WING WITH POSITIVE DIHEDRAL AND NEGATIVE SWEEP
    //

    setVariables( "wing-simple-d30-sm30-by-positioning.xml");


    oldDihedral = tree.getWingDihedral("Wing", 0);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(oldDihedral, 30));
    backupReferenceAreaValues();

    tree.setWingDihedral("Wing",20);
    tree.writeToFile(outFileName);
    newDihedral = tree.getWingDihedral("Wing");
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(newDihedral, 20));
    checkCurrentAreasWithBackup();



    /*
     * WING SIMPLE ONE KICK + ROTATIONS
     */

    setVariables( "wing-one-kick-rotations-scales.xml");
    oldDihedral = tree.getWingDihedral("Wing");
    backupReferenceAreaValues();

    tree.setWingDihedral("Wing", 15 , 0.5);
    tree.writeToFile(outFileName);
    newDihedral = tree.getWingDihedral("Wing", 0.5);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(newDihedral, 15));



    // TEST CASE BOXWING

    double before , after;

    setVariables("TestCases/boxWing.xml");
    std::string wingUID = "D150_VAMP_W1";

    before = tree.getWingDihedral(wingUID, 0);
    backupReferenceAreaValues();
    EXPECT_TRUE(before > 2 && before < 8);
    tree.setWingDihedral(wingUID, -12, 0.5);
    tree.writeToFile();
    after = tree.getWingDihedral(wingUID, 0.5);
    EXPECT_TRUE(after > -12.1 && after < -11.9);
    checkCurrentAreasWithBackup();


    backupReferenceAreaValues();
    tree.setWingDihedral(wingUID, 72, 0.5);
    tree.writeToFile();
    after = tree.getWingDihedral(wingUID, 0.5 );
    EXPECT_TRUE(after > 71.9 && after < 72.1);
    checkCurrentAreasWithBackup();


    backupReferenceAreaValues();
    tree.setWingDihedral(wingUID, 23, 1);
    tree.writeToFile();
    after = tree.getWingDihedral(wingUID, 1);
    EXPECT_TRUE(after > 22.9 && after < 23.1);
    checkCurrentAreasWithBackup();





}



TEST_F(AircraftTreeTest, setWingAirfoils)
{
    std::string filename = "AircraftTreeTest-setAirfoils.xml";
    setVariables(filename);
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-simple.dat", false);
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-mdAirfoil2.dat");
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-BW050209.dat");
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-BW050209.dat"); // should add a suffix
    tree.writeToFile(outFileName);

    tree.setWingAirfoilsByUID("Wing", "profile-mdAirfoil2");
    tree.writeToFile(outFileName);

    EXPECT_THROW(tree.setWingAirfoilsByUID("Wing","dasdfas"), CreatorException);


    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-simple-shifted.dat", true); // should not shift
    tree.writeToFile(outFileName);


    tree.setWingAirfoilsByUID("Wing","profile-BW050209", true); // should shift one more
    tree.writeToFile(outFileName);


    tree.setWingAirfoilsFromExternalFile("Wing", DATA_DIR + "profile-simple-shifted.dat", false); // should shift one more
    tree.writeToFile(outFileName);


}



TEST_F(AircraftTreeTest, getAirfoilsUID)
{
    setVariables("AircraftTreeTest-getAirfoils.xml");

    std::vector<UID> r = tree.getAllAirfoilsUIDInThisWing("Wing");
    std::vector<UID> e;
    e.push_back("profile-mdAirfoil2");
    e.push_back("profile-mdAirfoil3");

    EXPECT_EQ(r,e);

}



TEST_F(AircraftTreeTest, getWingOrFuselageGraph)
{


    /**
     * Test Wing graph
     */

    setVariables("wing-simple-1.xml");

    // Test invalid input
    EXPECT_THROW(tree.getWingOrFuselageGraph(tree.getRoot()), CreatorException) ;

    // Test basic case

    CPACSTreeItem* wing = tree.getRoot()->getChildByUid("Wing");
    std::map<cpcr::CPACSTreeItem *, std::vector<cpcr::CPACSTreeItem *> >  r = tree.getWingOrFuselageGraph(wing);

    EXPECT_EQ(r.size(), 2);

    CPACSTreeItem* e1 = tree.getRoot()->getChildByUid("Wing_section1_element1");
    CPACSTreeItem* e2 = tree.getRoot()->getChildByUid("Wing_section2_element1");
    EXPECT_EQ(r[e1][0], e2);
    EXPECT_EQ(r[e1].size(), 1);
    EXPECT_EQ(r[e2][0], e1);
    EXPECT_EQ(r[e2].size(), 1);

    // Test cyclic case
    setVariables("wing-double-segments.xml");

    wing = tree.getRoot()->getChildByUid("Wing");
    r = tree.getWingOrFuselageGraph(wing);

    EXPECT_EQ(r.size(), 3);

    e1 = tree.getRoot()->getChildByUid("Wing_section1_element1");
    e2 = tree.getRoot()->getChildByUid("Wing_section2_element1");
    CPACSTreeItem* e3 = tree.getRoot()->getChildByUid("Wing_section3_element1");
    EXPECT_EQ(r[e1][0], e2);
    EXPECT_EQ(r[e1][1], e3);
    EXPECT_EQ(r[e1].size(), 2);
    EXPECT_EQ(r[e2][0], e1);
    EXPECT_EQ(r[e2][1], e3);
    EXPECT_EQ(r[e1].size(), 2);
    EXPECT_EQ(r[e3][0], e1);
    EXPECT_EQ(r[e3][1], e2);
    EXPECT_EQ(r[e1].size(), 2);



    // Test use case

    setVariables("BWB_DoE_102_modWP4.4_CS_v3.xml");

    wing = tree.getRoot()->getChildByUid("BWB450_wingID");
    r = tree.getWingOrFuselageGraph(wing);

    EXPECT_EQ(r.size(), 13);

    for(CPACSTreeItem* e : tree.getRoot()->findAllChildrenOfTypeRecursively("element")){

        EXPECT_TRUE( 0 < r[e].size() && r[e].size()  < 3 );

    }



    /**
     * Test Fuselage graph
     */


    setVariables("simple-aircraft.cpacs.xml");

    // Test basic case
    CPACSTreeItem* fuselage = tree.getRoot()->getChildByUid("SimpleFuselage");
    r = tree.getWingOrFuselageGraph(fuselage);

    EXPECT_EQ(r.size(), 3);

    e1 = tree.getRoot()->getChildByUid("D150_Fuselage_1Section1IDElement1");
    e2 = tree.getRoot()->getChildByUid("D150_Fuselage_1Section2IDElement1");
    e3 = tree.getRoot()->getChildByUid("D150_Fuselage_1Section3IDElement1");
    EXPECT_EQ(r[e1][0], e2);
    EXPECT_EQ(r[e1].size(), 1);
    EXPECT_EQ(r[e2][0], e1);
    EXPECT_EQ(r[e2][1], e3);
    EXPECT_EQ(r[e2].size(), 2);
    EXPECT_EQ(r[e3][0], e2);
    EXPECT_EQ(r[e3].size(), 1);





}



TEST_F(AircraftTreeTest, formatWingOrFuselalgeGraph)
{

    /*
     *  TEST WING GRAPH
     */
    setVariables("wing-simple-1.xml");

    // Test basic case

    CPACSTreeItem* wing = tree.getRoot()->getChildByUid("Wing");
    std::map<cpcr::CPACSTreeItem *, std::vector<cpcr::CPACSTreeItem *> >  graph = tree.getWingOrFuselageGraph(wing);

    std::vector<cpcr::CPACSTreeItem *> formatedGraph = tree.formatWingOrFuselageGraph(graph);

    EXPECT_EQ(formatedGraph.size(), 2);

    CPACSTreeItem* e1 = tree.getRoot()->getChildByUid("Wing_section1_element1");
    CPACSTreeItem* e2 = tree.getRoot()->getChildByUid("Wing_section2_element1");
    EXPECT_EQ(formatedGraph[0], e1);
    EXPECT_EQ(formatedGraph[1], e2);




    // Test cyclic case

    setVariables("wing-double-segments.xml");


    wing = tree.getRoot()->getChildByUid("Wing");
    graph = tree.getWingOrFuselageGraph(wing);

    EXPECT_THROW(tree.formatWingOrFuselageGraph(graph), CreatorException );



    // Test use case

    setVariables("BWB_DoE_102_modWP4.4_CS_v3.xml");

    wing = tree.getRoot()->getChildByUid("BWB450_wingID");
    graph = tree.getWingOrFuselageGraph(wing);
    formatedGraph = tree.formatWingOrFuselageGraph(graph);

    EXPECT_EQ( formatedGraph.size() , 13);
    EXPECT_EQ( formatedGraph[0]->getUid(), "BWB450_wingSection1IDElement1");
    EXPECT_EQ( formatedGraph[6]->getUid(), "BWB450_wingSection7IDElement1");
    EXPECT_EQ( formatedGraph[12]->getUid(), "BWB450_wingSection13IDElement1");




    /*
     *  TEST FUSELAGE GRAPH
     */


    setVariables("simple-aircraft.cpacs.xml");

    CPACSTreeItem* fuselage = tree.getRoot()->getChildByUid("SimpleFuselage");
    graph = tree.getWingOrFuselageGraph(fuselage);
    formatedGraph = tree.formatWingOrFuselageGraph(graph);

    EXPECT_EQ( formatedGraph.size() , 3);
    EXPECT_EQ( formatedGraph[0]->getUid(), "D150_Fuselage_1Section1IDElement1");
    EXPECT_EQ( formatedGraph[1]->getUid(), "D150_Fuselage_1Section2IDElement1");
    EXPECT_EQ( formatedGraph[2]->getUid(), "D150_Fuselage_1Section3IDElement1");


    setVariables("simple-aircraft-fuselages.xml");

    fuselage = tree.getRoot()->getChildByUid("FuselageUnconventionalOrdering");
    graph = tree.getWingOrFuselageGraph(fuselage);
    formatedGraph = tree.formatWingOrFuselageGraph(graph);

    EXPECT_EQ( formatedGraph.size() , 3);
    EXPECT_EQ( formatedGraph[0]->getUid(), "D150_Fuselage_2Section1IDElement1");
    EXPECT_EQ( formatedGraph[1]->getUid(), "D150_Fuselage_2Section2IDElement1");
    EXPECT_EQ( formatedGraph[2]->getUid(), "D150_Fuselage_2Section3IDElement1");


}








TEST_F(AircraftTreeTest, airfoilWingNormalization ){

    setVariables("wing-one-kick-rotations-scales-dihedral-multiple-airfoils.xml");
    std::string wingUID = "Wing";

    std::vector<cpcr::UID> UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    std::map<cpcr::UID, Eigen::Vector4d> lEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d> tEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    std::vector<std::string> airfoilUIDsB = tree.getAllAirfoilsUIDInThisWing(wingUID);

    tree.airfoilsStandardizationForWing(wingUID);
    tree.writeToFile();

    std::map<cpcr::UID, Eigen::Vector4d> lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d> tEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    std::vector<std::string> airfoilUIDsA = tree.getAllAirfoilsUIDInThisWing(wingUID);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.000001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.000001) ) ;
    }

    EXPECT_FALSE(airfoilUIDsA == airfoilUIDsB);




    setVariables("wing-one-kick-multiple-airfoils.xml");
    wingUID = "Wing";


    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    airfoilUIDsB = tree.getAllAirfoilsUIDInThisWing(wingUID);

    tree.airfoilsStandardizationForWing(wingUID);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tree.getAllAirfoilsUIDInThisWing(wingUID);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.000001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.000001) ) ;
    }

    EXPECT_FALSE(airfoilUIDsA == airfoilUIDsB);



    setVariables("BWB_DoE_102_modWP4.4_CS_v3.xml");
    wingUID = "BWB450_wingID";

    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    airfoilUIDsB = tree.getAllAirfoilsUIDInThisWing(wingUID);

    tree.airfoilsStandardizationForWing(wingUID);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tree.getAllAirfoilsUIDInThisWing(wingUID);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.000001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.000001) ) ;
    }

    EXPECT_FALSE(airfoilUIDsA == airfoilUIDsB);


}



TEST_F(AircraftTreeTest, setWingTransformation ) {





    setVariables("TestCases/d150.xml");
    std::string wingUID = "D150_VAMP_wing_W1";

    std::vector<cpcr::UID> UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    std::map<cpcr::UID, Eigen::Vector4d> lEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d> tEsB = tree.getChordPointsOfElementsInWing(wingUID, 1);


    CPACSTransformation trans;
    trans.setRotation(Point(0,45,0));
    trans.setTranslation(Point(0,5,0));
    trans.setScaling(Point(2,2,2));
    tree.writeToFile();
    tree.setWingTransformation(wingUID, trans);
    tree.writeToFile();

    std::map<cpcr::UID, Eigen::Vector4d>  lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d>  tEsA = tree.getChordPointsOfElementsInWing(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }


    CPACSTransformation dT = tree.determineWingTransformation(wingUID);
    EXPECT_TRUE(dT.getRotation() == Point(0,0,0));
    EXPECT_TRUE(dT.getScaling() == Point(1,1,1));
    EXPECT_TRUE(dT.getTranslation() == Point(12.745585588751897,0,-1.1362781709599128));


    tree.setWingTransformation(wingUID, dT);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsA = tree.getChordPointsOfElementsInWing(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }


    // Vertical wing
    wingUID = "D150_VAMP_vtp_SL1";

    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsB = tree.getChordPointsOfElementsInWing(wingUID, 1);


    dT = tree.determineWingTransformation(wingUID);
    EXPECT_TRUE(dT.getRotation() == Point(90,0,0));
    EXPECT_TRUE(dT.getScaling() == Point(1,1,1));
    EXPECT_TRUE(dT.getTranslation() == Point(29.837965090800001, -0.0020029219731199999, 1.89101464137));


    tree.setWingTransformation(wingUID, dT);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsA = tree.getChordPointsOfElementsInWing(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }

    // optimal aircraft

    setVariables("TestCases/Optimale17.xml");
    wingUID = "Wing";


    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsB = tree.getChordPointsOfElementsInWing(wingUID, 1);


    dT = tree.determineWingTransformation(wingUID);
    EXPECT_TRUE(dT.getRotation() == Point(0,0,0));
    EXPECT_TRUE(dT.getScaling() == Point(1,1,1));
   // EXPECT_TRUE(dT.getTranslation() == Point(29.837965090800001, -0.0020029219731199999, 1.89101464137));


    tree.setWingTransformation(wingUID, dT);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsA = tree.getChordPointsOfElementsInWing(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }


    // Blended wing


    setVariables( "BWB_DoE_102_modWP4.4_CS_v3.xml");

    wingUID = "BWB450_wingID";


    UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    lEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsB = tree.getChordPointsOfElementsInWing(wingUID, 1);


    trans;
    trans.setRotation(Point(0,45,0));
    trans.setTranslation(Point(0,5,0));
    trans.setScaling(Point(2,2,2));
    tree.writeToFile();
    tree.setWingTransformation(wingUID, trans);
    tree.writeToFile();

    lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    tEsA = tree.getChordPointsOfElementsInWing(wingUID, 1);
    tree.getAllAirfoilsUIDInThisWing(wingUID);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }


}




TEST_F(AircraftTreeTest, oneElementOneSection ) {


    setVariables("wing-one-kick-double-elements-in-section.xml");

    std::string wingUID = "Wing";

    std::vector<cpcr::UID> UIDs = tree.getAllElementUIDsUsedInAWing(wingUID);
    std::map<cpcr::UID, Eigen::Vector4d> lEsB = tree.getChordPointsOfElementsInWing(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d> tEsB = tree.getChordPointsOfElementsInWing(wingUID, 1);

    EXPECT_FALSE( tree.checkIfOneSectionOneElementForWing(wingUID));
    tree.oneSectionOneElementStandardizationForWing(wingUID);
    EXPECT_TRUE( tree.checkIfOneSectionOneElementForWing(wingUID));

    tree.writeToFile();

    std::map<cpcr::UID, Eigen::Vector4d>  lEsA = tree.getChordPointsOfElementsInWing(wingUID, 0);
    std::map<cpcr::UID, Eigen::Vector4d>  tEsA = tree.getChordPointsOfElementsInWing(wingUID, 1);

    for(UID u: UIDs )
    {
        EXPECT_TRUE(lEsA[u].isApprox( lEsB[u], 0.0001) );
        EXPECT_TRUE( tEsA[u].isApprox(tEsB[u], 0.0001) ) ;
    }



    setVariables("BWB_DoE_102_modWP4.4_CS_v3.xml");

    wingUID = "BWB450_wingID";

    EXPECT_TRUE(tree.checkIfOneSectionOneElementForWing(wingUID));



}



TEST_F(AircraftTreeTest, positioningsStandardization  ) {


    // temp varaibles
   CPACSTransformation newWingT;
    std::string filename;
    std::string wingUID;


    wingUID = "Wing";
    setVariables("wing-one-kick-rotations-scales-dihedral-2.xml");


    backupChordPointsOfWing(wingUID);

    EXPECT_FALSE(tree.checkIfPositioningsAreStandardizedForWing(wingUID));
    tree.positioningsStandardizationForWing(wingUID);
    tree.writeToFile();

    EXPECT_TRUE(tree.checkIfPositioningsAreStandardizedForWing(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);



    wingUID = "BWB450_wingID";
    setVariables( "BWB_DoE_102_modWP4.4_CS_v3.xml");

    EXPECT_TRUE(tree.checkIfPositioningsAreStandardizedForWing(wingUID));

    // Optimal aircraft case
    setVariables("TestCases/Optimale17.xml");
    wingUID = "Wing";

    backupChordPointsOfWing(wingUID);

    EXPECT_FALSE(tree.checkIfPositioningsAreStandardizedForWing(wingUID));
    tree.positioningsStandardizationForWing(wingUID);
    tree.writeToFile();

    EXPECT_TRUE(tree.checkIfPositioningsAreStandardizedForWing(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);

}



TEST_F(AircraftTreeTest, completeNormalization  ) {


    // temp varaibles

    CPACSTransformation newWingT;
    std::string filename;
    std::string wingUID;


    // TEST CASE: BlendedWingBody

    wingUID = "BWB450_wingID";
    setVariables("TestCases/blendedWingBody.xml");


    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);


    // TEST CASE : BoxWing

    wingUID = "D150_VAMP_W1";
    setVariables("TestCases/boxWing.xml");

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);


    // TEST CASE: crm (strange format)

    wingUID = "NASA_CRM_wing1";
    setVariables("TestCases/crm.xml");

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);




    // TEST CASE: d150

    wingUID = "D150_VAMP_wing_W1";
    setVariables("TestCases/d150.xml");

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);





    // TEST CASE: tp

    wingUID = "wing";
    setVariables("TestCases/tp.xml");

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);



    // TEST CASE: Optimale17

    wingUID = "Wing";
    setVariables("TestCases/Optimale17.xml");

    backupChordPointsOfWing(wingUID);
    EXPECT_FALSE(tree.isWingStandardized(wingUID));
    tree.completeStandardizationForWing(wingUID);
    tree.writeToFile();
    EXPECT_TRUE(tree.isWingStandardized(wingUID));
    checkCurrentChordPointsWithBackup(wingUID);


//
//   // TODO manage case with trailing edge define with two points
//
//    filename = "TestCases/tp.xml";
//    wingUID = "vtp";
//    setVariables(filename);
//
//    backupChordPointsOfWing(wingUID);
//    EXPECT_FALSE(tree.isWingStandardized(wingUID));
//    tree.completeStandardizationForWing(wingUID);
//    EXPECT_TRUE(tree.isWingStandardized(wingUID));
//    checkCurrentChordPointsWithBackup(wingUID);



}




TEST_F(AircraftTreeTest, area){

    setVariables( "wing-simple.xml");

    double myArea;
    CPACSTreeItem* segment = tree.getRoot()->getChildByUid("Wing_segment1");

    // If there is no wing transformation and only one segment the area should be the same as in tigl

    tiglWingGetReferenceArea(tiglHandle,1, TIGL_X_Y_PLANE,&tempArea);
    myArea = tree.getSegmentArea(segment, PLANE::XY_PLANE);
    EXPECT_EQ(tempArea, 2);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(tiglHandle,1, TIGL_X_Z_PLANE,&tempArea);
    myArea = tree.getSegmentArea(segment, PLANE::XZ_PLANE);
    EXPECT_EQ(tempArea, 0);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(tiglHandle,1, TIGL_Y_Z_PLANE,&tempArea);
    myArea = tree.getSegmentArea(segment, PLANE::YZ_PLANE);
    EXPECT_EQ(tempArea, 0);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(tiglHandle,1, TIGL_NO_SYMMETRY,&tempArea);
    myArea = tree.getSegmentArea(segment, PLANE::NO_PLANE);
    EXPECT_EQ(tempArea, 2);
    EXPECT_EQ(tempArea, myArea);

    // TEST CASE bwb

    setVariables("TestCases/blendedWingBody.xml");
    std::string wingUID = "BWB450_wingID";

    tiglWingGetReferenceArea(tiglHandle,1, TIGL_X_Y_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::XY_PLANE);
    EXPECT_EQ(tempArea, myArea);

    tiglWingGetReferenceArea(tiglHandle,1, TIGL_X_Z_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::XZ_PLANE);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(tempArea, myArea));

    tiglWingGetReferenceArea(tiglHandle,1, TIGL_Y_Z_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::YZ_PLANE);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(tiglHandle,1, TIGL_NO_SYMMETRY,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::NO_PLANE);
    EXPECT_EQ(tempArea, myArea);


    // In the case the wing is rotated by 90 degree

    setVariables("d150-vt0.xml");
    wingUID = "D150_VAMP_vtp_SL1";


    tiglWingGetReferenceArea(tiglHandle,3, TIGL_X_Y_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::XZ_PLANE);
    EXPECT_TRUE(mthf::CompareDoubleEpsilon(tempArea, myArea));

    tiglWingGetReferenceArea(tiglHandle,3, TIGL_X_Z_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::XY_PLANE);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(tiglHandle,3, TIGL_Y_Z_PLANE,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::YZ_PLANE);
    EXPECT_EQ(tempArea, myArea);


    tiglWingGetReferenceArea(tiglHandle,3, TIGL_NO_SYMMETRY,&tempArea);
    myArea = tree.getWingPlanformArea(wingUID, PLANE::NO_PLANE);
    EXPECT_EQ(tempArea, myArea);


}




TEST_F(AircraftTreeTest, symmetry){

    setVariables("TestCases/d150.xml");

    std::string symmetry = tree.getWingSymmetry("D150_VAMP_wing_W1");
    EXPECT_EQ(symmetry, "x-z-plane");

    symmetry = tree.getWingSymmetry("D150_VAMP_vtp_SL1");
    EXPECT_EQ(symmetry, "no-symmetry");

    tree.setWingSymmetry("D150_VAMP_vtp_SL1", "x-y-plane");
    symmetry = tree.getWingSymmetry("D150_VAMP_vtp_SL1");
    EXPECT_EQ(symmetry, "x-y-plane");
    tree.writeToFile();

    tree.setWingSymmetry("D150_VAMP_wing_W1", "y-z-plane");
    symmetry = tree.getWingSymmetry("D150_VAMP_wing_W1");
    EXPECT_EQ(symmetry, "y-z-plane");
    tree.writeToFile();

    tree.setWingSymmetry("D150_VAMP_wing_W1", "no-symmetry");
    symmetry = tree.getWingSymmetry("D150_VAMP_wing_W1");
    EXPECT_EQ(symmetry, "no-symmetry");
    tree.writeToFile();


}




TEST_F(AircraftTreeTest, findPerpendicularScaleFactor){

    double area, scaleA, scaleC;
    CPACSTreeItem* wing;


    // cord are parallel -> scaleA area = scaleA chord should be result
    setVariables("wing-simple.xml");
    area = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("Wing");
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC));
    scaleA = 0.33;
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC));

    // chord are parallel
    setVariables("wing-simple-shift.xml");
    area = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("Wing");
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC));
    scaleA = 0.33;
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC));

    // chord are parallel
    setVariables("wing-simple-two-sections.xml");
    area = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("Wing");
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC));
    scaleA = 0.33;
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC));


    // chord are not parallel -> approximation
    setVariables("wing-simple-rot30.xml");
    area = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("Wing");
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC,0.1));
    scaleA = 0.33;
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC,0.1));


    // chord are not parallel
    setVariables("wing-simple-two-sections-rot.xml");
    area = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("Wing");
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC,0.1));
    scaleA = 0.33;
    scaleC = tree.findChordXYScaleFactor(wing, area * scaleA);
    EXPECT_TRUE( IsApprox(scaleA, scaleC,0.1));


}




TEST_F(AircraftTreeTest, setWingAreaKeepLeadingEdges) {

    double areaBefore, areaAfter,  scaleA;
    std::string uid;
    CPACSTreeItem *wing;

    setVariables("wing-simple.xml");
    areaBefore = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("Wing");
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea("Wing", XY_PLANE);
    EXPECT_TRUE( IsApprox(areaBefore * scaleA, areaAfter) );

    scaleA = 1.7;
    wing = tree.getRoot()->getChildByUid("Wing");
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea("Wing", XY_PLANE);
    EXPECT_TRUE( IsApprox(areaBefore * scaleA, areaAfter));


    setVariables("TestCases/blendedWingBody.xml");
    areaBefore = tree.getWingPlanformArea("BWB450_wingID", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("BWB450_wingID");
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea("BWB450_wingID", XY_PLANE);
    EXPECT_TRUE( IsApprox(areaBefore * scaleA, areaAfter ));


    setVariables("wing-simple-roty30.xml");
    areaBefore = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("Wing");
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea("Wing", XY_PLANE);
    EXPECT_TRUE( IsApprox( areaBefore * scaleA, areaAfter));


    setVariables("wing-simple-two-sections.xml");
    areaBefore = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.5;
    wing = tree.getRoot()->getChildByUid("Wing");
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea("Wing", XY_PLANE);
    EXPECT_EQ( areaBefore * scaleA, areaAfter);

    scaleA = 1.7;
    wing = tree.getRoot()->getChildByUid("Wing");
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea("Wing", XY_PLANE);
    EXPECT_TRUE( IsApprox( areaBefore * scaleA, areaAfter) );


    setVariables("wing-simple-two-sections-rot.xml");
    areaBefore = tree.getWingPlanformArea("Wing", XY_PLANE);
    scaleA = 0.8;
    wing = tree.getRoot()->getChildByUid("Wing");
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea("Wing", XY_PLANE);
    EXPECT_TRUE( IsApprox( areaBefore * scaleA, areaAfter) );

    scaleA = 1.2;
    wing = tree.getRoot()->getChildByUid("Wing");
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea("Wing", XY_PLANE);
    EXPECT_TRUE( IsApprox( areaBefore * scaleA, areaAfter) );



    setVariables("TestCases/boxWing.xml");
    uid = "D150_VAMP_W1";
    areaBefore = tree.getWingPlanformArea(uid, XY_PLANE);
    scaleA = 0.2;
    wing = tree.getRoot()->getChildByUid(uid);
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE( IsApprox( areaBefore * scaleA, areaAfter) );

    scaleA = 5;
    wing = tree.getRoot()->getChildByUid(uid);
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE( IsApprox( areaBefore * scaleA, areaAfter) );



    setVariables("TestCases/boxWing-withDihedral.xml");
    uid = "D150_VAMP_W1";
    areaBefore = tree.getWingPlanformArea(uid, XY_PLANE);
    scaleA = 0.2;
    wing = tree.getRoot()->getChildByUid(uid);
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE( IsApprox( areaBefore * scaleA, areaAfter) );

    scaleA = 5;
    wing = tree.getRoot()->getChildByUid(uid);
    tree.setWingAreaKeepLeadingEdges(wing, scaleA * areaBefore);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE( IsApprox( areaBefore * scaleA, areaAfter) );


}




TEST_F(AircraftTreeTest, setWingSpanKeepArea) {

    double areaBefore, areaAfter, spanBefore, newSpan, spanAfter;
    std::string uid;


    setVariables("wing-simple-two-sections-rot.xml");
    uid = "Wing";
    areaBefore = tree.getWingPlanformArea(uid, XY_PLANE);
    spanBefore = tree.getWingSpan(uid);
    newSpan = 20;
    tree.setWingSpanKeepArea(uid, newSpan);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    spanAfter = tree.getWingSpan(uid);

    EXPECT_TRUE(IsApprox(spanAfter, newSpan));
    EXPECT_TRUE(IsApprox(areaAfter, areaBefore));



    setVariables("TestCases/boxWing-withDihedral.xml");
    uid = "D150_VAMP_W1";
    areaBefore = tree.getWingPlanformArea(uid, XY_PLANE);
    spanBefore = tree.getWingSpan(uid);
    newSpan = 7;
    tree.setWingSpanKeepArea(uid, newSpan);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    spanAfter = tree.getWingSpan(uid);

    EXPECT_TRUE(IsApprox(spanAfter, newSpan));
    EXPECT_TRUE(IsApprox(areaAfter, areaBefore));

    areaBefore = tree.getWingPlanformArea(uid, XY_PLANE);
    spanBefore = tree.getWingSpan(uid);
    newSpan = 17.2;
    tree.setWingSpanKeepArea(uid, newSpan);
    tree.writeToFile();
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    spanAfter = tree.getWingSpan(uid);

    EXPECT_TRUE(IsApprox(spanAfter, newSpan));
    EXPECT_TRUE(IsApprox(areaAfter, areaBefore));


}



TEST_F(AircraftTreeTest, setWingSpanKeepAR) {

    double arBefore, arAfter, newSpan, spanAfter;
    std::string uid;


    setVariables("wing-simple-two-sections-rot.xml");
    uid = "Wing";
    arBefore = tree.getWingAR(uid);
    newSpan = 20;
    tree.setWingSpanKeepAR(uid, newSpan);
    tree.writeToFile();
    arAfter = tree.getWingAR(uid);
    spanAfter = tree.getWingSpan(uid);
    EXPECT_TRUE(IsApprox(spanAfter, newSpan));
    EXPECT_TRUE(IsApprox(arAfter, arBefore));


    setVariables("TestCases/boxWing-withDihedral.xml");
    uid = "D150_VAMP_W1";
    arBefore = tree.getWingAR(uid);
    newSpan = 13;
    tree.setWingSpanKeepAR(uid, newSpan);
    tree.writeToFile();
    arAfter = tree.getWingAR(uid);
    spanAfter = tree.getWingSpan(uid);
    EXPECT_TRUE(IsApprox(spanAfter, newSpan));
    EXPECT_TRUE(IsApprox(arAfter, arBefore));



}




TEST_F(AircraftTreeTest, setWingAreaKeepAR) {

    double arBefore, arAfter, newArea, areaAfter;
    std::string uid;


    setVariables("wing-simple-two-sections-rot.xml");
    uid = "Wing";
    arBefore = tree.getWingAR(uid);
    newArea = 13;
    tree.setWingAreaKeepAR(uid, newArea);
    arAfter = tree.getWingAR(uid);
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE(IsApprox(arBefore, arAfter));
    EXPECT_TRUE(IsApprox(areaAfter, newArea));
    tree.writeToFile();

    arBefore = tree.getWingAR(uid);
    newArea = 130;
    tree.setWingAreaKeepAR(uid, newArea);
    arAfter = tree.getWingAR(uid);
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE(IsApprox(arBefore, arAfter));
    EXPECT_TRUE(IsApprox(areaAfter, newArea, 0.1));
    tree.writeToFile();


    setVariables("TestCases/boxWing-withDihedral.xml");
    uid = "D150_VAMP_W1";

    arBefore = tree.getWingAR(uid);
    newArea = 3.3;
    tree.setWingAreaKeepAR(uid, newArea);
    arAfter = tree.getWingAR(uid);
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE(IsApprox(arBefore, arAfter));
    EXPECT_TRUE(IsApprox(areaAfter, newArea));
    tree.writeToFile();

    arBefore = tree.getWingAR(uid);
    newArea = 40;
    tree.setWingAreaKeepAR(uid, newArea);
    arAfter = tree.getWingAR(uid);
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE(IsApprox(arBefore, arAfter));
    EXPECT_TRUE(IsApprox(areaAfter, newArea));
    tree.writeToFile();

}



TEST_F(AircraftTreeTest, setWingAreaKeepSpan) {

    double spanBefore, spanAfter, newArea, areaAfter;
    std::string uid;


    setVariables("wing-simple-two-sections-rot.xml");
    uid = "Wing";
    spanBefore = tree.getWingSpan(uid);
    newArea = 12;
    tree.setWingAreaKeepSpan(uid, newArea);
    spanAfter = tree.getWingSpan(uid);
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE(IsApprox(spanBefore, spanAfter));
    EXPECT_TRUE(IsApprox(areaAfter, newArea));
    tree.writeToFile();



    setVariables("TestCases/boxWing-withDihedral.xml");
    uid = "D150_VAMP_W1";
    spanBefore = tree.getWingSpan(uid);
    newArea = 17;
    tree.setWingAreaKeepSpan(uid, newArea);
    spanAfter = tree.getWingSpan(uid);
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    EXPECT_TRUE(IsApprox(spanBefore, spanAfter));
    EXPECT_TRUE(IsApprox(areaAfter, newArea));
    tree.writeToFile();


}



TEST_F(AircraftTreeTest, setWingARKeepSpan) {

    double spanBefore, spanAfter, newAR, arAfter;
    std::string uid;


    setVariables("wing-simple-two-sections-rot.xml");
    uid = "Wing";

    spanBefore = tree.getWingSpan(uid);
    newAR = 2;
    tree.setWingARKeepSpan(uid, newAR);
    spanAfter = tree.getWingSpan(uid);
    arAfter = tree.getWingAR(uid);
    EXPECT_TRUE(IsApprox(spanBefore, spanAfter));
    EXPECT_TRUE(IsApprox(newAR, arAfter));
    tree.writeToFile();


    spanBefore = tree.getWingSpan(uid);
    newAR = 20;
    tree.setWingARKeepSpan(uid, newAR);
    spanAfter = tree.getWingSpan(uid);
    arAfter = tree.getWingAR(uid);
    EXPECT_TRUE(IsApprox(spanBefore, spanAfter));
    EXPECT_TRUE(IsApprox(newAR, arAfter));
    tree.writeToFile();




    setVariables("TestCases/boxWing-withDihedral.xml");
    uid = "D150_VAMP_W1";

    spanBefore = tree.getWingSpan(uid);
    newAR = 2;
    tree.setWingARKeepSpan(uid, newAR);
    spanAfter = tree.getWingSpan(uid);
    arAfter = tree.getWingAR(uid);
    EXPECT_TRUE(IsApprox(spanBefore, spanAfter));
    EXPECT_TRUE(IsApprox(newAR, arAfter));
    tree.writeToFile();


    spanBefore = tree.getWingSpan(uid);
    newAR = 20;
    tree.setWingARKeepSpan(uid, newAR);
    spanAfter = tree.getWingSpan(uid);
    arAfter = tree.getWingAR(uid);
    EXPECT_TRUE(IsApprox(spanBefore, spanAfter));
    EXPECT_TRUE(IsApprox(newAR, arAfter));
    tree.writeToFile();
}



TEST_F(AircraftTreeTest, setWingARKeepArea) {

    double areaBefore, areaAfter, newAR, arAfter;
    std::string uid;


    setVariables("wing-simple-two-sections-rot.xml");
    uid = "Wing";

    areaBefore = tree.getWingPlanformArea(uid, XY_PLANE);
    newAR = 2;
    tree.setWingARKeepArea(uid, newAR);
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    arAfter = tree.getWingAR(uid);
    EXPECT_TRUE(IsApprox(areaBefore, areaAfter));
    EXPECT_TRUE(IsApprox(newAR, arAfter));
    tree.writeToFile();



    setVariables("TestCases/boxWing-withDihedral.xml");
    uid = "D150_VAMP_W1";



    areaBefore = tree.getWingPlanformArea(uid, XY_PLANE);
    newAR = 5;
    tree.setWingARKeepArea(uid, newAR);
    areaAfter = tree.getWingPlanformArea(uid, XY_PLANE);
    arAfter = tree.getWingAR(uid);
    EXPECT_TRUE(IsApprox(areaBefore, areaAfter));
    EXPECT_TRUE(IsApprox(newAR, arAfter));
    tree.writeToFile();

}




TEST_F(AircraftTreeTest, getFuselageLengthBetween) {

    setVariables("simple-aircraft-fuselages.xml");

    double r = tree.getFuselageLengthBetween("D150_Fuselage_1Section1IDElement1", "D150_Fuselage_1Section2IDElement1");
    EXPECT_EQ(r, 1);

    r = tree.getFuselageLengthBetween("D150_Fuselage_1Section2IDElement1", "D150_Fuselage_1Section3IDElement1");
    EXPECT_EQ(r, 1);


    r = tree.getFuselageLengthBetween( "D150_Fuselage_1Section3IDElement1", "D150_Fuselage_1Section2IDElement1");
    EXPECT_EQ(r, 1);


    r = tree.getFuselageLengthBetween("D150_Fuselage_4Section1IDElement1", "D150_Fuselage_4Section3IDElement1");
    EXPECT_DOUBLE_EQ(r, 2);

    // invalid input
    EXPECT_THROW(
            tree.getFuselageLengthBetween("D150_Fuselage_4Section1IDElement1", "D150_Fuselage_4Section3IDElement1fas"), CreatorException );


}


TEST_F(AircraftTreeTest, getFuselageLength) {

    setVariables("simple-aircraft-fuselages.xml");

    double r = tree.getFuselageLength("SimpleFuselage");
    EXPECT_EQ(r, 2);

    r = tree.getFuselageLength("FuselageUnconventionalOrdering");
    EXPECT_EQ(r, 2.5);


    r = tree.getFuselageLength("SimpleFuselage3");
    EXPECT_DOUBLE_EQ(r, 2); // 2 only because we evaluate the length in fuselage coordinate system

    r = tree.getFuselageLength("SimpleFuselage4"); // this fuselage use shiffted profiles
    EXPECT_DOUBLE_EQ(r, 2); // 2 only because we evaluate the length in fuselage coordinate system



    setVariables("TestCases/crm.xml");
    r = tree.getFuselageLength("NASA_CRM_fuselage1");
    EXPECT_TRUE(r > 60*20);
    EXPECT_TRUE(r < 63*20);


    setVariables("TestCases/boxWing.xml");
    r = tree.getFuselageLength("D150_VAMP_FL1");
    EXPECT_GE(r , 35);
    EXPECT_LE(r, 40);


}



TEST_F(AircraftTreeTest, setFuselageLengthBetween) {

    setVariables("simple-aircraft-fuselages.xml");

    double newPartialL, oldPartialL,  globalL, oldGlobalL, r;
    cpcr::UID fuselageUID;

    newPartialL = 3;
    tree.setFuselageLengthBetween("D150_Fuselage_1Section1IDElement1", "D150_Fuselage_1Section2IDElement1",  newPartialL);
    r = tree.getFuselageLengthBetween("D150_Fuselage_1Section1IDElement1", "D150_Fuselage_1Section2IDElement1");
    tree.writeToFile();
    EXPECT_DOUBLE_EQ(r, newPartialL);


    newPartialL = 5;
    tree.setFuselageLengthBetween("D150_Fuselage_4Section2IDElement1", "D150_Fuselage_4Section3IDElement1" , newPartialL);
    r = tree.getFuselageLengthBetween("D150_Fuselage_4Section2IDElement1", "D150_Fuselage_4Section3IDElement1");
    tree.writeToFile();
    EXPECT_LE(r, newPartialL + 0.00001);
    EXPECT_GE(r, newPartialL - 0.00001);


    oldGlobalL =  tree.getFuselageLength("SimpleFuselage4");
    oldPartialL = tree.getFuselageLengthBetween("D150_Fuselage_4Section3IDElement1", "D150_Fuselage_4Section1IDElement1");
    newPartialL = 1;
    tree.setFuselageLengthBetween("D150_Fuselage_4Section3IDElement1", "D150_Fuselage_4Section1IDElement1" , newPartialL);
    r = tree.getFuselageLengthBetween("D150_Fuselage_4Section3IDElement1", "D150_Fuselage_4Section1IDElement1");
    globalL =  tree.getFuselageLength("SimpleFuselage4");
    tree.writeToFile();
    EXPECT_LE(r, newPartialL + 0.00001);
    EXPECT_GE(r, newPartialL - 0.00001);
    EXPECT_DOUBLE_EQ(globalL, oldGlobalL-oldPartialL+newPartialL );



    // invalid input
    EXPECT_THROW(tree.setFuselageLengthBetween("D150_Fuselage_4Section2IDElement1asdfsa", "D150_Fuselage_4Section3IDElement1" , newPartialL), CreatorException);
    EXPECT_THROW(tree.setFuselageLengthBetween("D150_Fuselage_4Section3IDElement1", "D150_Fuselage_4Section3IDElement1" , newPartialL), CreatorException);

}




TEST_F(AircraftTreeTest, setFuselageLength) {

    setVariables("simple-aircraft-fuselages.xml");

    double newLength, r;
    cpcr::UID fuselageUID;

    fuselageUID = "SimpleFuselage";
    newLength = 3;
    tree.setFuselageLength(fuselageUID, newLength);
    r = tree.getFuselageLength(fuselageUID);
    EXPECT_DOUBLE_EQ(r, newLength);

    fuselageUID = "SimpleFuselage4";
    newLength = 5;
    tree.setFuselageLength(fuselageUID, newLength);
    r = tree.getFuselageLength(fuselageUID);
    EXPECT_DOUBLE_EQ(r, newLength);

}




TEST_F(AircraftTreeTest, shiftElement) {

    setVariables("simple-aircraft-fuselages.xml");

    std::vector<UID> elementToShift;

    Eigen::Vector3d shift ;
    Eigen::Matrix4d globalMAfter, globalMBefore, shiftM;


    elementToShift.push_back("D150_Fuselage_1Section1IDElement1");
    globalMBefore = tree.getGlobalTransformMatrixOfElement(elementToShift[0]);
    shift << -2, 3.3, 0.8;
    shiftM = Eigen::Matrix4d::Identity();
    shiftM.block<3,1>(0,3) = shift;
    tree.shiftElements(elementToShift, shift);
    tree.writeToFile();
    globalMAfter  = tree.getGlobalTransformMatrixOfElement(elementToShift[0]);
    EXPECT_TRUE(globalMAfter.isApprox(shiftM * globalMBefore, 0.00001));


    globalMBefore = tree.getGlobalTransformMatrixOfElement(elementToShift[0]);
    shift = - shift;
    shiftM = Eigen::Matrix4d::Identity();
    shiftM.block<3,1>(0,3) = shift;
    tree.shiftElements(elementToShift, shift);
    tree.writeToFile();
    globalMAfter  = tree.getGlobalTransformMatrixOfElement(elementToShift[0]);
    EXPECT_TRUE(globalMAfter.isApprox(shiftM * globalMBefore, 0.00001));

    elementToShift.clear();

    elementToShift.push_back("D150_Fuselage_4Section1IDElement1");
    elementToShift.push_back( "D150_Fuselage_4Section2IDElement1");
    elementToShift.push_back("D150_Fuselage_4Section3IDElement1");
    shift << -3,2,1.2;
    shiftM = Eigen::Matrix4d::Identity();
    shiftM.block<3,1>(0,3) = shift;
    globalMBefore = tree.getGlobalTransformMatrixOfElement(elementToShift[1]);
    tree.shiftElements(elementToShift, shift);
    tree.writeToFile();
    globalMAfter  = tree.getGlobalTransformMatrixOfElement(elementToShift[1]);
    EXPECT_TRUE(globalMAfter.isApprox(shiftM * globalMBefore, 0.00001));


    shift = -shift;
    shiftM = Eigen::Matrix4d::Identity();
    shiftM.block<3,1>(0,3) = shift;
    globalMBefore = tree.getGlobalTransformMatrixOfElement(elementToShift[1]);
    tree.shiftElements(elementToShift, shift);
    tree.writeToFile();
    globalMAfter  = tree.getGlobalTransformMatrixOfElement(elementToShift[1]);
    EXPECT_TRUE(globalMAfter.isApprox(shiftM * globalMBefore, 0.00001));


    // invalid input
    elementToShift.clear();
    elementToShift.push_back("fdadfsas");
    EXPECT_THROW(tree.shiftElements(elementToShift, shift), CreatorException) ;
}




TEST_F(AircraftTreeTest, getCircumferenceOfElementsInFuselage) {

    setVariables("simple-aircraft-fuselages.xml");

    std::map<cpcr::UID, double> circumferences;
    UID fuselageUID;

    fuselageUID= "SimpleFuselageCircumference";
    circumferences = tree.getCircumferenceOfElementsInFuselage(fuselageUID);

    EXPECT_EQ(circumferences.size(), 3);
    EXPECT_TRUE( IsApprox(circumferences["D150_Fuselage_CSection1IDElement1"], 2 * M_PI, 0.5 ) ); // the interpolation can gives significant difference from the perfect circle
    EXPECT_TRUE( IsApprox(circumferences["D150_Fuselage_CSection2IDElement1"], 19, 1 ) );
    EXPECT_TRUE( IsApprox(circumferences["D150_Fuselage_CSection3IDElement1"], 3.23, 1 ) );

}


TEST_F(AircraftTreeTest, getFuselageMaximalCircumference) {

    setVariables("simple-aircraft-fuselages.xml");

    double circumference;
    UID fuselageUID;

    fuselageUID= "SimpleFuselageCircumference";
    circumference = tree.getFuselageMaximalCircumference(fuselageUID);
    EXPECT_TRUE( IsApprox(circumference, 19 , 1 ) ); // the interpolation can gives significant difference from the perfect circle


}





TEST_F(AircraftTreeTest, scaleFuselageCircumferences) {



    setVariables("simple-aircraft-fuselages.xml");


    std::map<cpcr::UID, double> circumferencesBefore,  circumferencesAfter ;
    UID fuselageUID;
    double scale;

    fuselageUID= "SimpleFuselage";
    circumferencesBefore = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    scale = 3.3;
    tree.scaleFuselageCircumferences(fuselageUID, scale);
    circumferencesAfter = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    tree.writeToFile();
    for(std::pair<UID, double> p : circumferencesBefore){
        EXPECT_DOUBLE_EQ(circumferencesAfter[p.first], p.second * scale );
    }


    fuselageUID= "FuselageUnconventionalOrdering";
    circumferencesBefore = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    scale = 0.3;
    tree.scaleFuselageCircumferences(fuselageUID, scale);
    circumferencesAfter = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    tree.writeToFile();
    for(std::pair<UID, double> p : circumferencesBefore){
        EXPECT_DOUBLE_EQ(circumferencesAfter[p.first], p.second * scale );
    }


    fuselageUID= "SimpleFuselageCircumference";
    circumferencesBefore = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    scale = 0.6;
    tree.scaleFuselageCircumferences(fuselageUID, scale);
    circumferencesAfter = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    tree.writeToFile();
    for(std::pair<UID, double> p : circumferencesBefore){
        EXPECT_DOUBLE_EQ(circumferencesAfter[p.first], p.second * scale );
    }


    fuselageUID= "SimpleFuselage3";
    circumferencesBefore = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    scale = 3;
    tree.scaleFuselageCircumferences(fuselageUID, scale);
    circumferencesAfter = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    tree.writeToFile();
    for(std::pair<UID, double> p : circumferencesBefore){
        EXPECT_DOUBLE_EQ(circumferencesAfter[p.first], p.second * scale );
    }

    fuselageUID= "SimpleFuselage4";
    circumferencesBefore = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    scale = 44;
    tree.scaleFuselageCircumferences(fuselageUID, scale);
    circumferencesAfter = tree.getCircumferenceOfElementsInFuselage(fuselageUID);
    tree.writeToFile();
    for(std::pair<UID, double> p : circumferencesBefore){
        EXPECT_DOUBLE_EQ(circumferencesAfter[p.first], p.second * scale );
    }

}





TEST_F(AircraftTreeTest, setFuselageMaximalCircumference) {

    setVariables("simple-aircraft-fuselages.xml");
    UID fuselageUID;
    double newMaxC, maxCBefore, maxCAfter ;

    fuselageUID = "SimpleFuselageCircumference";
    newMaxC = 5;
    maxCBefore = tree.getFuselageMaximalCircumference(fuselageUID);
    tree.setFuselageMaximalCircumference(fuselageUID, newMaxC);
    maxCAfter = tree.getFuselageMaximalCircumference(fuselageUID);
    tree.writeToFile();
    EXPECT_TRUE(IsApprox(maxCAfter, newMaxC));


    fuselageUID = "SimpleFuselage4";
    newMaxC = 5;
    maxCBefore = tree.getFuselageMaximalCircumference(fuselageUID);
    tree.setFuselageMaximalCircumference(fuselageUID, newMaxC);
    maxCAfter = tree.getFuselageMaximalCircumference(fuselageUID);
    tree.writeToFile();
    EXPECT_TRUE(IsApprox(maxCAfter, newMaxC) );


    EXPECT_THROW(tree.setFuselageMaximalCircumference(fuselageUID, -3), CreatorException);
    EXPECT_THROW(tree.setFuselageMaximalCircumference("fdsa", 3), CreatorException);
    tree.setFuselageMaximalCircumference(fuselageUID, 0); // is accpeted with warning
    tree.writeToFile();

}