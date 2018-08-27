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

#include "UniqueXPath.h"


#include "easylogging++.h"

#include <sstream>


std::string cpcr::UniqueXPath::getFirstElementType() const {

    std::string first = this->getFirstParticle();
    std::string r = this->removeBrackets(first);
    return r;

}

std::string cpcr::UniqueXPath::getLastElementType() const {

    std::string last = this->getLastParticle();
    std::string r = this->removeBrackets(last);
    return r;
}

int cpcr::UniqueXPath::getFirstElementIndex() const {

    std::string first = getFirstParticle();
    int r = getIndexOfParticle(first);
    return r;

}

int cpcr::UniqueXPath::getLastElementIndex() const {

    std::string last = getLastParticle();
    int r = getIndexOfParticle(last);
    return r;
}

std::string cpcr::UniqueXPath::getFirstParticle() const {

    std::string temp = xpath;

    // get the first particle
    if(temp.size() >= 1 && temp[0] == '/'){  // case when the xPath start with a /
        temp.erase(0,1);
    }
    std::istringstream f(temp);
    std::string first;
    getline(f, first, '/');

    return first;
}

std::string cpcr::UniqueXPath::getLastParticle() const {

    std::string temp = xpath;

    // if the temp ended with '/', we first remove it
    if(temp[temp.size()-1] == '/'){
        temp.erase(temp.size()-1, 1);
    }


    int found = temp.find_last_of("/");
    if(found < 0){
        return temp;
    }
    std::string r = temp.substr(found + 1);
    return r;

}

std::string cpcr::UniqueXPath::removeBrackets(std::string stringIn) const {

    if( stringIn[stringIn.size()-1] == ']'){
        int found = stringIn.find_last_of("[");
        if( found <0 ){
            LOG(ERROR) << "INVALID XPATH (stringIn: " + stringIn + " )";
        }else{
            stringIn.erase(found, stringIn.size() - found );
        }

    }
    return stringIn ;
}

int cpcr::UniqueXPath::getIndexOfParticle(std::string particle) const {

    int r = 1;  // be default the index is one

    if( particle[particle.size()-1] == ']'){
        int found = particle.find_last_of("[");
        if( found <0 ){
            LOG(ERROR) << "INVALID XPATH (xpath: " + xpath + " )";
        }else{
            particle.erase(particle.size()-1, 1); // erase last
            particle.erase(0, found + 1 );
            r = std::stoi(particle);
        }
    }
    return r;
}

std::string cpcr::UniqueXPath::popFirst() {


    // get the first particle
    if(xpath.size() >= 1 && xpath[0] == '/'){  // case when the xPath start with a /
        xpath.erase(0,1);
    }
    std::istringstream f(xpath);
    std::string first;
    getline(f, first, '/');

    // update xpath ( remove temp and /)
    if(xpath.size() == first.size()){
        xpath.erase(0, first.size());
    }else{
        xpath.erase(0, first.size() + 1);
    }

    return first;

}

std::string cpcr::UniqueXPath::popLast() {


    // if the xpath ended with '/', we first remove it
    if(xpath[xpath.size()-1] == '/'){
        xpath.erase(xpath.size()-1, xpath.size());
    }


    std::string r ;
    int found = xpath.find_last_of("/");
    if(found < 0){
        r = xpath;
        xpath = "";
    }
    else {
        r = xpath.substr(found + 1);
        xpath.erase(found , r.size() + 1) ;
    }

    return r;

}

cpcr::UniqueXPath::UniqueXPath(std::string x) {
    xpath = x;
}

void cpcr::UniqueXPath::setXPath(std::string newXPath) {
    xpath = newXPath;
}

cpcr::UniqueXPath::UniqueXPath() {
    xpath = "";
}

void cpcr::UniqueXPath::addParticleAtEnd(std::string particle) {

    if ( particle[ particle.size()-1 ] == '/') {
        particle.erase(particle.size()-1, 1);
    }

    if ( xpath[xpath.size() - 1 ] != '/' && particle[0] != '/' && xpath.size() > 0 ){
        xpath = xpath + '/';
    }

    xpath = xpath + particle;


}

cpcr::UniqueXPath cpcr::UniqueXPath::relativeTo(const cpcr::UniqueXPath &other) {


    std::string temp = xpath.substr(0, other.xpath.size());
    std::string newXpath = "";
    if( temp == other.toString()){
        newXpath = xpath.substr(other.xpath.size(), xpath.size() - other.xpath.size());
        if( newXpath[0] == '/'){
            newXpath.erase(0,1);
        }
    }


    return UniqueXPath(newXpath);
}



