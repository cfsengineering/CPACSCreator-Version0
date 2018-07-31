//
// Created by makem on 18/04/18.
//


#include "gtest/gtest.h"

#include "CPACSTreeItem.h"
#include "CPACSTree.h"
#include "Helper.h"
#include "CreatorException.h"
#include <stdio.h>

using namespace cpcr;

class CPACSTreeTest: public ::testing::Test{

protected:
    std::string DATA_DIR="/home/makem/JobProject/SkStage/CPACSCreatorLib/CPACSCreatorLibTests/CreatorTests/Data/";
    std::string fileName = DATA_DIR + "CPACSTreeTest.xml";


    CPACSTree tree;
    CPACSTreeItem* root ;
    CPACSFile* modifer;

    virtual void SetUp(){

    }

    virtual  void TearDown(){

    }
};


TEST_F(CPACSTreeTest, build){

    // CHECK NO EXCEPTIONS BEHAVIOR
    // initial state
    EXPECT_FALSE( tree.isBuild());

    // construct the tree
    tree.build(fileName, UniqueXPath("/cpacs/vehicles/aircraft/model[1]"));
    root = tree.getRoot();

    // check result
    EXPECT_EQ( root->getXPath().toString(), "/cpacs/vehicles/aircraft/model[1]" );
    EXPECT_EQ( root->getType(), "model");
    EXPECT_TRUE( tree.isBuild() );

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
}



TEST_F(CPACSTreeTest, writeToFile){

    // TODO determine where to wrtie the file and how to access the modifier
    /*
    // construct the tree
    tree.build(fileName, UniqueXPath("/cpacs/vehicles/aircraft/model[1]"));
    root = tree.getRoot();
    modifer = tree.getModifier();

    // set a new transform
    CPACSTreeItem * wingT = root->getChildByUid("Wing_transformation1");
    CPACSTransformation originalT = modifer->getTransformation(wingT->getXPath());
    CPACSTransformation newT(1.1,1.2,1.3, 2.1,2.2,2.3, 3.1,3.2,3.3);
    modifer->setTransformation(wingT->getXPath(), newT);
    // write to file
    tree.writeToFile();

    // check if the file is correctly modified
    CPACSFile checker;
    checker.open(fileName);
    CPACSTransformation rT = checker.getTransformation(wingT->getXPath());
    EXPECT_TRUE( rT == newT) ;
    checker.close();

    // reset the original value;
    modifer->setTransformation(wingT->getXPath(), originalT);
    tree.writeToFile();


    // write to a other file
    newT =  CPACSTransformation(5.1,5.2,5.3, 2.1,2.2,2.3, 3.1,3.2,3.3);
    modifer->setTransformation(wingT->getXPath(), newT);
    std::string otherFileName = DATA_DIR + "out-CPACSTreeTest-writeToFile.xml";
    tree.writeToFile(otherFileName);

    EXPECT_EQ(tree.getFilename(), otherFileName);
    checker.open(otherFileName);
    rT = checker.getTransformation(wingT->getXPath());
    EXPECT_TRUE( rT == newT) ;
    checker.close();

    // delete the other file name
    remove(otherFileName.c_str());


    // if a invalid file is given
    newT =  CPACSTransformation(6.1,6.2,6.3, 2.1,2.2,2.3, 3.1,3.2,3.3);
    modifer->setTransformation(wingT->getXPath(), newT);
    otherFileName =  "./fsafdsa/out-CPACSTreeTest-writeToFile.xml";
    EXPECT_THROW( tree.writeToFile(otherFileName), CreatorException ) ;
    EXPECT_EQ(tree.getFilename(), DATA_DIR + "out-CPACSTreeTest-writeToFile.xml" ); // the tree should have the same file name has before
*/



}
