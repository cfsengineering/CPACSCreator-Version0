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


    std::string DATA_DIR="./Data/";

    std::string currentFile = "not set";
    std::string outFileName = DATA_DIR + "TreeTest-out.xml";

    UniqueXPath rootXPath = UniqueXPath("not set");
    CPACSTree tree ;
    CPACSTreeItem* root;

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
    currentFile = DATA_DIR + "CPACSTreeTest.xml";
    rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");
    tree.build( currentFile, rootXPath );

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

    // CHECK EXCEPTIONS BEHAVIOR

    // Wrong root Xpath
    currentFile = DATA_DIR + "CPACSTreeTest.xml";
    rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/fasafd");
    EXPECT_THROW(tree.build( currentFile, rootXPath ), CreatorException );

    // Wrong file
    currentFile = DATA_DIR + "CPACSTreefasdfaTest.xml";
    rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");
    EXPECT_THROW(tree.build(currentFile, rootXPath ), CreatorException );


}



TEST_F(CPACSTreeTest, writeToFile){


    // construct the tree
    currentFile = DATA_DIR + "CPACSTreeTest.xml";
    rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");

    tree.build( currentFile, rootXPath);
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
    checker.open(currentFile);
    CPACSTransformation rT = checker.getTransformation(wingT->getXPath());
    EXPECT_TRUE( rT == newT) ;
    checker.close();

    // reset the original value;
    modifer->setTransformation(wingT->getXPath(), originalT);
    tree.writeToFile();


    // write to a other file
    newT =  CPACSTransformation(5.1,5.2,5.3, 2.1,2.2,2.3, 3.1,3.2,3.3);
    modifer->setTransformation(wingT->getXPath(), newT);
    std::string otherFileName = outFileName;
    tree.writeToFile(otherFileName);

    EXPECT_EQ(tree.getFilename(), otherFileName);
    checker.open(otherFileName);
    rT = checker.getTransformation(wingT->getXPath());
    EXPECT_TRUE( rT == newT) ;
    checker.close();


    // if a invalid file is given
    newT =  CPACSTransformation(6.1,6.2,6.3, 2.1,2.2,2.3, 3.1,3.2,3.3);
    modifer->setTransformation(wingT->getXPath(), newT);
    otherFileName =  DATA_DIR + "fsafdsa/out-CPACSTresasdeTest-writeToFile.xml";
    EXPECT_THROW( tree.writeToFile(otherFileName), CreatorException ) ;
    EXPECT_EQ(tree.getFilename(), outFileName ); // the tree should have the same file name has before
    rT =  modifer->getTransformation(wingT->getXPath());
    EXPECT_TRUE(rT == newT);

}
