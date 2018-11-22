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

#ifndef CPACSCREATORLIBANDTESTS_XPATHPARSER_H
#define CPACSCREATORLIBANDTESTS_XPATHPARSER_H

#include <string>
#include <vector>

#include <string>


namespace cpcr {

    /*
     * UniqueXPath to one element of the tree.
     *
     * The UniqueXPath should be unique and as the following constraints:
     * 1) the xpath should only contain element
     * 2) the only valdide predicate is [index] (starting form 1)
     *
     */
    class UniqueXPath {

    public:

        UniqueXPath();
        UniqueXPath(std::string x);

        inline bool isEmpty() const {return xpath == ""; };
        inline std::string toString() const { return  xpath; };
        void setXPath(std::string newXPath);
        void addParticleAtEnd(std::string particle);

        std::string getFirstElementType() const;
        std::string getLastElementType() const ;
        int getFirstElementIndex() const ;
        int getLastElementIndex() const ;


        void replaceLastTixiIndexByUidAttribute(std::string attribute) ;

        // remove the first element and return it
        std::string popFirst();
        // remove the last element and return it
        std::string popLast();

        // return the xpath relatively to the other xpath
        // if the two xpath seems incompatible "" is return and a error is thrown
        UniqueXPath relativeTo(const UniqueXPath& other);

        inline bool operator==(const UniqueXPath& other) { return other.xpath == xpath; };

        inline bool operator==(const std::string& string) { return string == xpath; };

        /**
         * Check if the first element is of the given type.
         * If yes, return the tixi idx of the first elment and remove the first element.
         * If no, throw a CreatorException.
         * The naming comes form the fact that we walk though the path safely.
         *
         * @param type
         * @return
         */
        int walkSafely(std::string type);

    protected:
        // return the first particle of the path, basic the string before the first /
        std::string getFirstParticle() const ;
        std::string getLastParticle() const;

        // return the same string without the brackets and the content
        std::string removeBrackets(std::string string) const;
        int getIndexOfParticle(std::string particle) const;

    private:

        std::string xpath;

    };


}   // end namespace cpcr
#endif //CPACSCREATORLIBANDTESTS_XPATHPARSER_H
