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
// Created by cfse on 7/9/18.
//

#include "CPACSSegment.h"

void cpcr::CPACSSegment::setFromElementUID(const std::string &fromElementUID) {
    this->fromElementUID = fromElementUID;
}

void cpcr::CPACSSegment::setToElementUID(const std::string &toElementUID) {
    this->toElementUID = toElementUID;
}

void cpcr::CPACSSegment::setName(const std::string &name) {
    this->name = name;
}

cpcr::CPACSSegment::CPACSSegment() {
    setName("");
    setFromElementUID("");
    setToElementUID("");
}

cpcr::CPACSSegment::CPACSSegment(std::string name, std::string fromElementUid, std::string toElementUid) {
    setName(name);
    setFromElementUID(fromElementUid);
    setToElementUID(toElementUid);
}
