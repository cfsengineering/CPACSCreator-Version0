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
// Created by makem on 19/04/18.
//


#include "gtest/gtest.h"
#include "CPACSTreeItem.h"
#include "CPACSTree.h"


using namespace cpcr;



class  CPACSTreeItemTest : public testing::Test{

protected:
    std::string DATA_DIR="./Data/";
    std::string fileName = DATA_DIR + "CPACSTreeItemTest.xml";
    CPACSTree tree;
    CPACSTreeItem* root ;

    std::string fileName2 = DATA_DIR + "CPACSTreeItemTest2-D150.xml";
    CPACSTree tree2;
    CPACSTreeItem* root2 ;

    virtual void SetUp(){
        tree.build(fileName, UniqueXPath("/cpacs/vehicles/aircraft/model[1]"));
        root = tree.getRoot();

        tree2.build(fileName2, UniqueXPath("/cpacs/vehicles/aircraft/model[1]"));
        root2 = tree2.getRoot();


    }

    virtual  void TearDown(){

    }
};


TEST_F(CPACSTreeItemTest, getChild ){

    UniqueXPath xpath = UniqueXPath("wings");
    CPACSTreeItem* r = root->getChild(xpath);
    EXPECT_EQ(r->getType(), "wings");
    EXPECT_EQ(r->getChildren().size(), 1);

    xpath.setXPath("./wings");
    r = root->getChild(xpath);
    EXPECT_EQ(r->getType(), "wings");
    EXPECT_EQ(r->getChildren().size(), 1);

    xpath.setXPath("/wings");
    r = root->getChild(xpath);
    EXPECT_EQ(r->getType(), "wings");
    EXPECT_EQ(r->getChildren().size(), 1);


    xpath.setXPath("fuselages/fuselage[1]/transformation/scaling/");
    r = root->getChild(xpath);
    EXPECT_EQ(r->getType(), "scaling");
    EXPECT_EQ(r->getChildren().size(), 3);


    xpath.setXPath("fuselages/fuselage/transformation");
    CPACSTreeItem* r2 = root->getChild(xpath);
    EXPECT_EQ(r2->getType(), "transformation");
    EXPECT_EQ(r2->getChildren().size(), 3);
    EXPECT_EQ(r2, r->getParent());


    CPACSTreeItem* segments = root2->getChild("wings/wing[2]/segments/");
    EXPECT_EQ(segments->getType(), "segments");
    EXPECT_EQ(segments->getChildren().size(), 1);


}


TEST_F(CPACSTreeItemTest, getChildByUid){

    CPACSTreeItem* r = root2->getChildByUid("D150_VAMP_W1_CompSeg1");
    EXPECT_EQ(r->getType(), "componentSegment");
    EXPECT_EQ(r->getUid(),"D150_VAMP_W1_CompSeg1" );
    EXPECT_EQ(r->getChildren().size(), 5);


    r = root2->getChildByUid("D150_VAMP_HL1_Sec2");
    EXPECT_EQ(r->getType(), "section");
    EXPECT_EQ(r->getUid(),"D150_VAMP_HL1_Sec2" );
    EXPECT_EQ(r->getChildren().size(), 4);


    r = root2->getChildByUid("D150_VAMPffs_HL1_Sec2");
    EXPECT_EQ(r, nullptr);

}




TEST_F(CPACSTreeItemTest, findAllChildrenOfTypeRecusrsively){


    auto c = root2->findAllChildrenOfTypeRecursively("wings");
    EXPECT_EQ( c.size(), 1);
    EXPECT_EQ( c[0] , root2->getChild("wings"));
    EXPECT_NE( c[0] , root2->getChild("fuselages"));

    c = root2->findAllChildrenOfTypeRecursively("afdsafdsa");
    EXPECT_EQ( c, std::vector<CPACSTreeItem*>());

    CPACSTreeItem* segments = root2->getChild("wings/wing[1]/segments/");
    c = segments->findAllChildrenOfTypeRecursively("fromElementUID");
    EXPECT_EQ(c.size() , 3);
    EXPECT_EQ(c.at(1)->getType() , "fromElementUID");
    EXPECT_EQ(c.at(1)->getXPath().toString() , "/cpacs/vehicles/aircraft/model[1]/wings/wing[1]/segments/segment[2]/fromElementUID");

}


TEST_F(CPACSTreeItemTest, getParentOfType ){

    CPACSTreeItem *r, *child;
    r = root->getParentOfType("faf");

    EXPECT_EQ(r , nullptr) ;

    child = root->getChild("wings");
    r = child->getParentOfType("model");
    EXPECT_EQ(r, root);

    child = root2->getChild("wings/wing[3]/segments/segment[1]");
    r = child->getParentOfType("wing");
    EXPECT_EQ(r->getUid(), "D150_VAMP_vtp_SL1");

}

