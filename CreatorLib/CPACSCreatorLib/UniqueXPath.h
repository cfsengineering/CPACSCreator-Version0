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



        // remove the first element and return it
        std::string popFirst();
        // remove the last element and return it
        std::string popLast();

        // return the xpath relatively to the other xpath
        // if the two xpath seems incompatible "" is return and a error is thrown
        UniqueXPath relativeTo(const UniqueXPath& other);

        inline bool operator==(const UniqueXPath& other) { return other.xpath == xpath; };

        inline bool operator==(const std::string& string) { return string == xpath; };


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
