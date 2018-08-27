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
// Created by makem on 23/04/18.
//




#include "gtest/gtest.h"
#include <string>
#include "UniqueXPath.h"

using namespace cpcr;

class UniqueXPathTest: public  testing::Test{
protected:



};


TEST_F(UniqueXPathTest, equalequal){

    UniqueXPath xpath1 = UniqueXPath("");
    UniqueXPath xpath2 = UniqueXPath("");

    EXPECT_TRUE( xpath1 == xpath2);
    EXPECT_EQ(xpath1.toString(), "");
    EXPECT_TRUE( xpath2 == "");


    UniqueXPath xpath3 = UniqueXPath("f");
    EXPECT_FALSE( xpath1 == xpath3);

    xpath1 = UniqueXPath("/a/s/f");
    xpath2.setXPath("/a/s/f");
    EXPECT_TRUE( xpath1 == xpath2);

    EXPECT_EQ(xpath1.toString(), "/a/s/f");
    EXPECT_TRUE( xpath2 == "/a/s/f");

}


TEST_F(UniqueXPathTest, getFirstElementType){

    UniqueXPath xpath = UniqueXPath("");
    std::string r ;

    xpath.setXPath("fds");
    r = xpath.getFirstElementType();
    EXPECT_TRUE(xpath == r);
    EXPECT_TRUE(xpath == xpath);

    xpath.setXPath("/fts/f/g/g[1]");
    r = xpath.getFirstElementType();
    EXPECT_TRUE(r == "fts");
    EXPECT_TRUE(xpath == xpath);


    xpath.setXPath("ftp[12]/f/g/g[1]");
    r = xpath.getFirstElementType();
    EXPECT_TRUE( r== "ftp");
    EXPECT_TRUE(xpath ==  xpath);
}


TEST_F(UniqueXPathTest, getLastElementType){

    UniqueXPath xpath = UniqueXPath("");
    std::string r;

    xpath.setXPath("fds");
    r = xpath.getLastElementType();
    EXPECT_TRUE(xpath == r);
    EXPECT_TRUE(xpath ==  xpath);

    xpath.setXPath("./gg/zz/hh");
    r = xpath.getLastElementType();
    EXPECT_TRUE(r == "hh");
    EXPECT_TRUE(xpath ==  xpath);


    xpath.setXPath("./gg/zz/hh/");
    r = xpath.getLastElementType();
    EXPECT_TRUE(r == "hh");
    EXPECT_TRUE(xpath == xpath);


    xpath.setXPath(".hh/");
    r = xpath.getLastElementType();
    EXPECT_TRUE(r == ".hh");


    xpath.setXPath("/hh/gg/h[ddfsas]");
    r = xpath.getLastElementType();
    EXPECT_TRUE(r == "h");

    xpath.setXPath("/hh/gg/hddfsas]");
    r = xpath.getLastElementType();
    EXPECT_TRUE(r == "hddfsas]");
}


TEST_F(UniqueXPathTest, getFirstElementIndex){

    UniqueXPath xpath = UniqueXPath("");

    // by default 1 should be return
    EXPECT_EQ( 1, xpath.getFirstElementIndex());

    xpath.setXPath("a[333]");
    EXPECT_EQ(333, xpath.getFirstElementIndex());
    EXPECT_TRUE( xpath == "a[333]");

    xpath.setXPath("/b/gg[6]/");
    EXPECT_EQ(1, xpath.getFirstElementIndex() );


    xpath.setXPath("b/gg[6]/");
    EXPECT_EQ(1, xpath.getFirstElementIndex() );



}


TEST_F(UniqueXPathTest, getLastElementIndex){

    UniqueXPath xpath = UniqueXPath("");

    // by default 1 should be return
    EXPECT_EQ( 1, xpath.getLastElementIndex());

    xpath.setXPath("a[333]");
    EXPECT_EQ(333, xpath.getLastElementIndex());
    EXPECT_TRUE( xpath == "a[333]");

    xpath.setXPath("/b/gg[6]/");
    EXPECT_EQ(6, xpath.getLastElementIndex() );


    xpath.setXPath("b/gg[6]/");
    EXPECT_EQ(6, xpath.getLastElementIndex() );



}


TEST_F(UniqueXPathTest, popFisrt){

    UniqueXPath xpath = UniqueXPath("fas");
    std::string r = "";
    r = xpath.popFirst();
    EXPECT_TRUE( r == "fas");
    EXPECT_TRUE( xpath == "");


    xpath.setXPath("/");
    r = xpath.popFirst();
    EXPECT_TRUE( r == "");
    EXPECT_TRUE( xpath == "" );


    xpath.setXPath("a/");
    r = xpath.popFirst();
    EXPECT_TRUE( r == "a");
    EXPECT_TRUE( xpath == "");

    xpath.setXPath("a/f/d");
    r = xpath.popFirst();
    EXPECT_TRUE( r == "a");
    EXPECT_TRUE( xpath == "f/d" );


    xpath.setXPath("/b/f/d");
    r = xpath.popFirst();
    EXPECT_TRUE( r == "b");
    EXPECT_TRUE( xpath == "f/d");

    xpath.setXPath("./ff/gg/fdsa/");
    r = xpath.popFirst();
    EXPECT_TRUE( r == ".");
    EXPECT_TRUE( xpath == "ff/gg/fdsa/");

    xpath.setXPath("/ff[66]/gg/fdsa/");
    r = xpath.popFirst();
    EXPECT_TRUE( r == "ff[66]");
    EXPECT_TRUE( xpath == "gg/fdsa/");

    xpath.setXPath("ff/gg/fdsa[3]/");
    r = xpath.popFirst();
    EXPECT_TRUE( r == "ff");
    EXPECT_TRUE( xpath == "gg/fdsa[3]/");


}


TEST_F(UniqueXPathTest, popLast){

    UniqueXPath xpath = UniqueXPath("");
    std::string r;

    r = xpath.popLast();
    EXPECT_TRUE( xpath == "");
    EXPECT_TRUE(r == "");

    xpath.setXPath("g/j/hh/");
    r = xpath.popLast();
    EXPECT_TRUE( r == "hh");
    EXPECT_TRUE(xpath == "g/j/");


    xpath.setXPath("g/j/hh");
    r = xpath.popLast();
    EXPECT_TRUE( r == "hh");
    EXPECT_TRUE(xpath == "g/j/");

}


TEST_F(UniqueXPathTest, addParticleAtEnd){

    UniqueXPath xpath = UniqueXPath("");
    std::string r;
    xpath.addParticleAtEnd("a");
    EXPECT_TRUE( xpath == "a");

    xpath.addParticleAtEnd("a");
    EXPECT_TRUE( xpath == "a/a");

    xpath.addParticleAtEnd("a/");
    EXPECT_TRUE( xpath == "a/a/a");


    xpath.addParticleAtEnd("/b/");
    EXPECT_TRUE( xpath == "a/a/a/b");

    xpath.setXPath("/");
    xpath.addParticleAtEnd("f");
    EXPECT_TRUE( xpath == "/f");

}



TEST_F(UniqueXPathTest, relativeTo){

    UniqueXPath xpath1 = UniqueXPath("/a/b/c");
    UniqueXPath xpath2 = UniqueXPath("/a/b");

    UniqueXPath r = xpath1.relativeTo(xpath2);
    EXPECT_TRUE(r == "c");

    xpath1.setXPath("a/c/v/gg");
    r = xpath1.relativeTo(xpath2);
    EXPECT_TRUE( r == UniqueXPath() );


}