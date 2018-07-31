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
