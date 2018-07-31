//
// Created by makem on 08/04/18.
//




#include "gtest/gtest.h"
#include "CPACSFile.h"
#include "Point.h"
#include "CPACSTransformation.h"
#include "CPACSPositioning.h"
#include "UniqueXPath.h"


static std::string DATA_DIR="/home/cfse/Stage_Malo/CPACSCreatorLib/CPACSCreatorLibTests/CreatorTests/Data/";


using namespace cpcr;

class CPACSFileTest :   public ::testing::Test {

protected:


    cpcr::CPACSFile cpacsFile;
    cpcr::CPACSFile cpacsFile2;


    virtual void SetUp() {

    }

    virtual void TearDown() {
        cpacsFile.close();
        cpacsFile2.close();
    }

};


TEST_F(CPACSFileTest, openclose) {




    std::string validCpacsFileName = DATA_DIR + "D150_AGILE_Hangar_3.xml";
    std::string nonExistentFile = DATA_DIR + "aafdfadf.xml";
    std::string nonValidCpacsFile = DATA_DIR + "non-valid.cpacs.xml";

    // open a valid cpacs file
    cpacsFile.open(validCpacsFileName);
    EXPECT_TRUE( cpacsFile.isValid() );

    //
    cpacsFile.close();
    EXPECT_TRUE( ! cpacsFile.isValid() );

    // re-open a valid cpacs file
    cpacsFile.open(validCpacsFileName);
    EXPECT_TRUE( cpacsFile.isValid() );
    cpacsFile.open(validCpacsFileName);
    EXPECT_TRUE( cpacsFile.isValid() );


    // open non-existent file
    cpacsFile.open(nonExistentFile);
    EXPECT_TRUE( ! cpacsFile.isValid() );
    // closing a non correctly opened file
    cpacsFile.close();
    EXPECT_TRUE( ! cpacsFile.isValid() );


    // TODO
    /*
    // open non-existent file
    cpacsFile.open(nonValidCpacsFile);
    EXPECT_TRUE( ! cpacsFile.isValid() );
    // closing a non correctly opened file
    cpacsFile.close();
    EXPECT_TRUE( ! cpacsFile.isValid() );
    */


}




TEST_F(CPACSFileTest, getPoint) {

    cpacsFile.open(DATA_DIR + "test-points.cpacs.xml");

    std::string xpath = "/cpacs/vehicles/aircraft/model[@uID=\"model\"]/fuselages/fuselage/transformation/scaling";
    cpcr::Point result = cpacsFile.getPoint(xpath);
    cpcr::Point expected (1,1.1,1.11);
    EXPECT_TRUE( expected == result);


    xpath = "/cpacs/vehicles/aircraft/model[@uID=\"model\"]/fuselages/fuselage/sections/section[1]/transformation/rotation";
    result = cpacsFile.getPoint(xpath);
    expected = cpcr::Point(0,0,0);
    EXPECT_TRUE( expected == result);

    xpath = "/cpacs/vehicles/aircraft/model[@uID=\"model\"]/wings/wing/sections/section[1]/elements/element/transformation/translation";
    result = cpacsFile.getPoint(xpath);
    expected = cpcr::Point(1.23,0,-23);
    EXPECT_TRUE( expected == result);


    // non-correct path should return -1 -1 -1 and //TODO a proper warning
    xpath = "fasdfaa";
    result = cpacsFile.getPoint(xpath);
    expected = cpcr::Point(-1,-1,-1);
    EXPECT_TRUE( expected == result);


}





TEST_F(CPACSFileTest, setPoint) {


    cpacsFile.open(DATA_DIR + "test-setPoint.cpacs.xml");

    std::string xpath = "/cpacs/vehicles/aircraft/model[@uID=\"model\"]/fuselages/fuselage/transformation/scaling";
    cpcr::Point original = cpacsFile.getPoint(xpath);
    cpcr::Point expected = cpcr::Point(1,1,1);
    EXPECT_TRUE( expected == original);

    cpcr::Point newPoint(3.5,1,56 );
    cpacsFile.setPoint(xpath, newPoint);
    cpcr::Point result = cpacsFile.getPoint(xpath);
    EXPECT_TRUE(result == newPoint);

    // save the file1
    cpacsFile.save(DATA_DIR + "temp-test-setPoint.cpacs.xml");
    result = cpcr::Point(0,0,0);
    result = cpacsFile.getPoint(xpath);
    EXPECT_TRUE(result == newPoint);

    // try to get from the second CPACSFile
    cpacsFile2.open(DATA_DIR + "temp-test-setPoint.cpacs.xml");
    result = cpcr::Point(0,0,0);
    result = cpacsFile2.getPoint(xpath);
    EXPECT_TRUE( result == newPoint  );

    // set the point again
    cpcr::Point newPoint2(2,2,2 );
    cpacsFile.setPoint(xpath, newPoint2);
    result = cpacsFile.getPoint(xpath);
    EXPECT_TRUE(result == newPoint2);

    // save the file1
    cpacsFile.save(DATA_DIR + "temp-test-setPoint.cpacs.xml");
    result = cpcr::Point(0,0,0);
    result = cpacsFile.getPoint(xpath);
    EXPECT_TRUE(result == newPoint2);

    // if we do not reload the file2 still contains the newPoint1
    result = cpcr::Point(0,0,0);
    result = cpacsFile2.getPoint(xpath);
    EXPECT_TRUE( result == newPoint  );

    // if we reopen / reload the file, we should get the point2
    cpacsFile2.open(DATA_DIR + "temp-test-setPoint.cpacs.xml");
    result = cpcr::Point(0,0,0);
    result = cpacsFile2.getPoint(xpath);
    EXPECT_TRUE( result == newPoint2  );




}


TEST_F(CPACSFileTest, getSetTransformation ){

    cpcr::CPACSTransformation defaultT ;

    // not opened cpacsFile
    cpcr::CPACSTransformation r = cpacsFile.getTransformation(UniqueXPath("ss"));
    EXPECT_TRUE( r == defaultT);


    cpacsFile.open(DATA_DIR + "CPACSFileTest-getSetTransformation.cpacs.xml");

    // not valid xpath
    r = cpacsFile.getTransformation(UniqueXPath("fdsfa"));
    EXPECT_TRUE( r == defaultT );

    std::string xpath = "/cpacs/vehicles/aircraft/model[@uID=\"model\"]/fuselages/fuselage/transformation";
    cpcr::CPACSTransformation t1(cpcr::Point(1,1.1,1.11),cpcr::Point(0,-2,0),cpcr::Point(13.1,13.2,13.3) );
    r = cpacsFile.getTransformation(xpath);
    EXPECT_TRUE(r == t1);



    // set Transformation Test

    xpath = "/cpacs/vehicles/aircraft/model[@uID=\"model\"]/fuselages/fuselage/transformation";

    cpcr::CPACSTransformation original = cpacsFile.getTransformation(xpath);

    cpcr::CPACSTransformation newTransform( 1.1, 1.2, 1.3 ,2.1, 2.2, 2.3, 3.1,3.2, 3.3 );
    cpacsFile.setTransformation(xpath, newTransform);
    cpcr::CPACSTransformation result = cpacsFile.getTransformation(xpath);
    EXPECT_TRUE(result == newTransform);


    // save in the file
    cpacsFile.save();
    // open with a other cpacsFileModifier and check the value
    cpacsFile2.open(DATA_DIR + "CPACSFileTest-getSetTransformation.cpacs.xml");
    cpcr::CPACSTransformation t2 = cpacsFile2.getTransformation(xpath);
    EXPECT_TRUE( t2 == newTransform);
    cpacsFile2.close();

    // reset the original value
    cpacsFile.setTransformation(xpath, original);
    result = cpacsFile.getTransformation(xpath);
    EXPECT_TRUE(result == t1);
    cpacsFile.save();
    cpacsFile.close();

}





TEST_F(CPACSFileTest, getPositioning){


    std::string fileName = DATA_DIR + "CPACSFileTest-getSetPositioning.xml";
    std::string baseXpath = "/cpacs/vehicles/aircraft/model[1]/";
    std::string xpath;

    cpcr::CPACSPositioning d ;  // default
    cpcr::CPACSPositioning r ;  // result
    cpcr::CPACSPositioning temp;


    r = cpacsFile.getPositioning(UniqueXPath("fafas"));  // should return the default positioning with a warning
    EXPECT_TRUE( r == d);

    cpacsFile.open(fileName);
    r = cpacsFile.getPositioning(UniqueXPath("fafas"));  // should return the default positioning with a warning
    EXPECT_TRUE( r == d);

    temp = cpcr::CPACSPositioning(-1.2, "", 0.9, 90, "D150_VAMP_FL1_Sec1");
    xpath = baseXpath + "fuselages/fuselage[1]/positionings/positioning[1]";
    r = cpacsFile.getPositioning(xpath);
    EXPECT_TRUE(r == temp);

}



TEST_F(CPACSFileTest, setPositioning){


    std::string fileName = DATA_DIR + "CPACSFileTest-getSetPositioning.xml";
    std::string baseXpath = "/cpacs/vehicles/aircraft/model[1]/";
    std::string xpath;

    cpcr::CPACSPositioning d ;  // default
    cpcr::CPACSPositioning r ;  // result
    cpcr::CPACSPositioning temp;
    cpcr::CPACSPositioning temp2;
    cpcr::CPACSPositioning original;


    cpacsFile.open(fileName);
    temp = cpcr::CPACSPositioning(-1.2, "", 0.9, 90, "D150_VAMP_FL1_Sec1");
    xpath = baseXpath + "fuselages/fuselage[1]/positionings/positioning[1]";
    r = cpacsFile.getPositioning(xpath);
    EXPECT_TRUE(r == temp);

    temp2 = cpcr::CPACSPositioning(-1.3, "3", 0.93, 903, "D1530_VAMP_FL1_Sec1");
    xpath = baseXpath + "fuselages/fuselage[1]/positionings/positioning[1]";
    original = cpacsFile.getPositioning(xpath);
    cpacsFile.setPositioning(xpath, temp2);
    r = cpacsFile.getPositioning(xpath);
    EXPECT_FALSE(r == original);
    EXPECT_TRUE(r == temp2);

    // save and open from a other cpacsFile
    cpacsFile.save();
    cpacsFile2.open(fileName);
    r = cpacsFile2.getPositioning(xpath);
    EXPECT_TRUE(r == temp2);
    cpacsFile2.close();

    // reset the first positoning
    cpacsFile.setPositioning(xpath, original);
    cpacsFile.save();

    // case where the optional element fromSectionUID exist and we replace it
    xpath = baseXpath + "fuselages/fuselage[1]/positionings/positioning[2]";
    original = cpacsFile.getPositioning(xpath);
    cpacsFile.setPositioning(xpath, temp2);
    r = cpacsFile.getPositioning(xpath);
    EXPECT_TRUE( r == temp2);

    // case where the optional element fromSectionUID exist and we remove it
    temp2 = cpcr::CPACSPositioning(-1.3, "", 0.93, 903, "D1530_VAMP_FL1_Sec1");
    cpacsFile.setPositioning(xpath, temp2);
    r = cpacsFile.getPositioning(xpath);
    EXPECT_TRUE( r == temp2);



}



TEST_F(CPACSFileTest, getUid){


    std::string fileName = DATA_DIR + "CPACSFileTest-getSetPositioning.xml";
    std::string baseXpath = "/cpacs/vehicles/aircraft/model[1]/";
    std::string xpath;

    cpacsFile.open(fileName);
    std::string r = cpacsFile.getUid(baseXpath);
    EXPECT_EQ(r, "D150_VAMP");

    r = cpacsFile.getUid(baseXpath + "name");
    EXPECT_EQ(r, "");


    r = cpacsFile.getUid(baseXpath + "name", "rc");
    EXPECT_EQ(r, "rc");


}





TEST_F(CPACSFileTest, wingAirfoilExist){


    std::string fileName = DATA_DIR + "airfoils.xml";

    cpacsFile.open(fileName);
    EXPECT_TRUE(cpacsFile.wingAirfoilExist("mdAirfoil2"));
    EXPECT_FALSE(cpacsFile.wingAirfoilExist("mdFDFADFASDFAFAirfoil2"));
    EXPECT_TRUE(cpacsFile.wingAirfoilExist("mdAirfoil4"));
}



TEST_F(CPACSFileTest, addWingAirfoil){


    std::string fileName = DATA_DIR + "airfoils.xml";
    std::string outFileName = DATA_DIR + "airfoils-out.xml";
    CPACSPointsProfile profile1;

    cpacsFile.open(fileName);
    cpacsFile.save(outFileName);
    EXPECT_FALSE(cpacsFile.wingAirfoilExist("not-set"));
    cpacsFile.addWingAirfoil( profile1 );
    cpacsFile.save();
    EXPECT_TRUE(cpacsFile.wingAirfoilExist("not-set"));

    CPACSPointsProfile profile2(DATA_DIR + "profile-BW050209.dat");
    EXPECT_FALSE(cpacsFile.wingAirfoilExist("profile-BW050209"));
    cpacsFile.addWingAirfoil( profile2 );
    cpacsFile.save();
    EXPECT_TRUE(cpacsFile.wingAirfoilExist("profile-BW050209"));

    cpacsFile.addWingAirfoil(profile2);
    cpacsFile.save();
    EXPECT_TRUE(cpacsFile.wingAirfoilExist(profile2.getUID()));
    EXPECT_EQ(profile2.getUID(),"profile-BW050209-v" );

    profile2.setUID("profile-BW050209");
    profile2.setName("fafdsaTest");
    cpacsFile.addWingAirfoilOverwriteIfExist(profile2);
    profile1 = cpacsFile.getAirfoil("profile-BW050209");
    EXPECT_EQ(profile1.getName(), "fafdsaTest");
    cpacsFile.save();


}



TEST_F(CPACSFileTest, getAirfoilUids) {

    std::string fileName = DATA_DIR + "airfoils.xml";
    cpacsFile.open(fileName);
    std::vector<std::string> r = cpacsFile.getAirfoilsUid();
    std::vector<std::string> e;
    e.push_back("mdAirfoil2");
    e.push_back("mdAirfoil6");
    e.push_back("mdAirfoilShifted");
    e.push_back("mdAirfoil3");
    e.push_back("mdAirfoil4");
    EXPECT_EQ(r,e);
}



TEST_F(CPACSFileTest, testIsPointsList) {

    std::string fileName = DATA_DIR + "airfoils.xml";
    cpacsFile.open(fileName);

    EXPECT_TRUE( cpacsFile.isWingAirfoilPointList("mdAirfoil2") );

    EXPECT_TRUE( cpacsFile.isWingAirfoilPointList("mdAirfoil6") );

    EXPECT_TRUE( cpacsFile.isWingAirfoilPointList("mdAirfoilShifted") );

    EXPECT_FALSE( cpacsFile.isWingAirfoilPointList("fasdfadfa"));
}





TEST_F(CPACSFileTest, segment ){

    std::string fileNameIn = DATA_DIR + "CPACSFileTest-segment.xml";
    std::string fileNameOut = DATA_DIR + "CPACSFileTest-segment-out.xml";
    cpacsFile.open(fileNameIn);
    cpacsFile.save(fileNameOut);


    // get segment
    std::string baseXpath = "/cpacs/vehicles/aircraft/model[1]/";
    CPACSSegment s = cpacsFile.getSegment(baseXpath + "wings/wing[1]/segments/segment[1]");

    EXPECT_EQ(s.getName(), "Wing_segment1");
    EXPECT_EQ(s.getFromElementUID(), "Wing_section1_element1");
    EXPECT_EQ(s.getToElementUID(), "Wing_section2_element1");


    s = cpacsFile.getSegment(baseXpath + "wings/wing[1]/segments/segment[2]");
    EXPECT_EQ(s.getName(), "Wing_segment1");
    EXPECT_EQ(s.getFromElementUID(), "Wing_section2_element1");
    EXPECT_EQ(s.getToElementUID(), "Wing_section3_element1");

    // set segment

    CPACSSegment s2 ("male", "dupond","source");
    cpacsFile.setSegment(baseXpath + "wings/wing[1]/segments/segment[2]", s2);
    cpacsFile.save();
    CPACSSegment r = cpacsFile.getSegment(baseXpath + "wings/wing[1]/segments/segment[2]");
    EXPECT_EQ(s2.getName(), r.getName());
    EXPECT_EQ(s2.getFromElementUID(), r.getFromElementUID());
    EXPECT_EQ(s2.getToElementUID(), r.getToElementUID());


}




TEST_F(CPACSFileTest, create ){

    std::string fileNameIn = DATA_DIR + "CPACSFileTest-create.xml";
    std::string fileNameOut = DATA_DIR + "CPACSFileTest-create-out.xml";
    cpacsFile.open(fileNameIn);
    cpacsFile.save(fileNameOut);


    // create point

    Point p(1.1,1.2,1.3);
    std::string baseXpath = "/cpacs/vehicles/aircraft/model[1]/";
    UniqueXPath x(baseXpath + "fuselages/test");
    cpacsFile.createPoint(x,p);
    cpacsFile.save();
    Point r = cpacsFile.getPoint(x);
    EXPECT_TRUE(r == p);


    // create transformation

    CPACSTransformation t(1.1,1.2,1.3, 2.1,2.2,2.2,3.1,3.2,3.3);
    x.setXPath(baseXpath + "fuselages/transformation");
    cpacsFile.createTransformation(x, t);
    cpacsFile.save();
    CPACSTransformation rt = cpacsFile.getTransformation(x);
    EXPECT_TRUE(rt == t);


    // create postioning

    CPACSPositioning pos(1, "a", 3, 45, "b" );
    x.setXPath(baseXpath + "wings/wing[1]/positionings/positioning[2]");
    cpacsFile.createPositioning(x , pos);
    cpacsFile.save();
    CPACSPositioning rpos = cpacsFile.getPositioning(x);
    EXPECT_TRUE(rpos == pos);

    // create segment

    CPACSSegment seg("ttt","rrr","sss");
    x.setXPath(baseXpath + "wings/wing[1]/segments/segment[2]");
    cpacsFile.createSegment(x , "fda-uid", seg);
    cpacsFile.save();
    CPACSSegment rseg = cpacsFile.getSegment(x);
    EXPECT_TRUE(rseg.getName() == "ttt");
    EXPECT_TRUE(rseg.getFromElementUID() == "rrr");
    EXPECT_TRUE(rseg.getToElementUID() == "sss");

    x.setXPath(baseXpath + "wings/wing");
    cpacsFile.createEmptyWing(x , "newWing");
    cpacsFile.save();

    x.setXPath(baseXpath + "wings/wing[1]/sections/section[2]/elements/element[2]");
    cpacsFile.createEmptyElement(x , "ellle-uid");
    cpacsFile.save();
    EXPECT_EQ("ellle-uid",  cpacsFile.getUid(x,""));


    x.setXPath(baseXpath + "wings/wing[1]/sections/section");
    cpacsFile.createEmptySection(x , "sect-uid");
    cpacsFile.save();
    EXPECT_EQ("sect-uid",  cpacsFile.getUid(x,""));


}

TEST_F(CPACSFileTest, removePositionings ) {


    std::string fileNameIn = DATA_DIR + "CPACSFileTest-removePositionings.xml";
    std::string fileNameOut = DATA_DIR + "CPACSFileTest-removePositionings-out.xml";
    cpacsFile.open(fileNameIn);
    cpacsFile.save(fileNameOut);

    std::string baseXpath = "/cpacs/vehicles/aircraft/model[1]/";


    int countB = tixi::TixiGetNamedChildrenCount( cpacsFile.getTixiHandle(), baseXpath + "wings/wing[1]/positionings/positioning");

    EXPECT_EQ(countB, 4 );
    cpacsFile.clearPositionings( baseXpath + "wings/wing[1]/positionings");
    cpacsFile.save(fileNameOut);


    int countA = tixi::TixiGetNamedChildrenCount( cpacsFile.getTixiHandle(), baseXpath + "wings/wing[1]/positionings/positioning");

    EXPECT_EQ(countA, 0);

}


TEST_F(CPACSFileTest, makeUIDUnique) {

    std::string fileName = DATA_DIR + "airfoils.xml";
    cpacsFile.open(fileName);

    std::string in, out;
    in = "fafdafdas";
    out = cpacsFile.makeUIDUnique(in);
    EXPECT_EQ(in, out);

    in = "mdAirfoil2";
    out = cpacsFile.makeUIDUnique(in);
    EXPECT_NE(in, out);

    in = "";
    out = cpacsFile.makeUIDUnique(in);
    EXPECT_EQ("", out);


}