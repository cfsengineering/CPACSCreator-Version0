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
// Created by makem on 13/06/18.
//

#include <gtest/gtest.h>
#include "AircraftTree.h"


using namespace cpcr;

TEST(GenerateFile, wingSweep){


    std::string DATA_DIR="/home/makem/JobProject/SkStage/CPACSCreatorLib/CPACSCreatorLibTests/CreatorTests/Data/GeneratedCFDInputs/";

    std::string baseFile = "D150_AGILE_Hangar_3_orignal.xml";
    AircraftTree tree ;
    CPACSTreeItem* root;
    UniqueXPath rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");
    std::string outFileName =  "notSet.xml";


    for (double d = 0 ; d < 50.0; d=d+5){

        tree.build(DATA_DIR + baseFile, rootXPath);
        outFileName = "creator-s" + std::to_string(d) + ".cpacs.xml";
        tree.writeToFile(DATA_DIR + outFileName );
        tree.setWingSweepByTranslation("D150_VAMP_wing_W1", d, 0);
        tree.writeToFile();
    }


}


TEST(GenerateFile, wingDihedral){


    std::string DATA_DIR="/home/makem/JobProject/SkStage/CPACSCreatorLib/CPACSCreatorLibTests/CreatorTests/Data/GeneratedCFDInputs/";

    std::string baseFile = "D150_AGILE_Hangar_3_orignal.xml";
    AircraftTree tree ;
    CPACSTreeItem* root;
    UniqueXPath rootXPath = UniqueXPath("/cpacs/vehicles/aircraft/model[1]");
    std::string outFileName =  "notSet.xml";


    for (double d = 0 ; d < 20.0; d=d+5){

        tree.build(DATA_DIR + baseFile, rootXPath);
        outFileName = "creator-d" + std::to_string(d) + ".cpacs.xml";
        tree.writeToFile(DATA_DIR + outFileName );
        tree.setWingDihedral("D150_VAMP_wing_W1", d, 0);
        tree.writeToFile();
    }


}