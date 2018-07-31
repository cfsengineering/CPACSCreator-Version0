//
// Created by cfse on 6/29/18.
//

#ifndef CPACSCREATORLIBANDTESTS_CPACSPOINTSPROFILE_H
#define CPACSCREATORLIBANDTESTS_CPACSPOINTSPROFILE_H


#include <vector>
#include <string>

#include "Eigen/Dense"

namespace cpcr {

    /**
     * @brief Reprensent a CPACS Profile
     *
     * This class can be view as structure that hold a CPACS profile.
     *
     */
    class CPACSPointsProfile {
    public:

        CPACSPointsProfile();

        CPACSPointsProfile(std::string inputFile);

        CPACSPointsProfile(std::string uid, std::string name, std::string sXs, std::string sYs, std::string sZs);

        CPACSPointsProfile(const CPACSPointsProfile& oother);

        bool operator==(const CPACSPointsProfile& other);


        inline std::string getName() const {return name;}
        void setName(std::string newName) {this->name = newName;}

        inline std::string getUID() const {return uid;}
        void setUID(std::string newUID) {this->uid = newUID;}

        void tryToMakeUidUnique();

        std::string getXsAsString() const {return transformVectorToString(xs);};
        std::string getYsAsString() const {return transformVectorToString(ys);};
        std::string getZsAsString() const {return transformVectorToString(zs);};

        Eigen::Vector3d getTrailingEdge() const;
        Eigen::Vector3d getLeadingEdge() const;
        int getLeadingEdgeIdx() const;
        // return the furthest point from chord, this mean the point that have the higher perpendicular distance from the chord
        Eigen::Vector3d getFurthestPointFromChord() const;
        int getFurthestPointFromChordIdx() const;

        // Tries to determine if the profile is in mathematical order
        bool isInMathematicalOrder();
        void reverseOrder(); // use to get the mathemeatical order

        bool areLEAndTEOnZeroAndOne();
        bool isOnXZPlane();
        bool isNormalized();
        /***
         * Tries to normalize the profile by the following step:
         * 1) translate LE to (0,0,0)
         * 2) scale uniformly such that the length from LE to TE equal 1
         * 3) rotate the profile such that TE is at (1,0,0)
         * 4) try to write the point in mathematical order
         *
         *
         * @remark The input profile must already be in the XZ plane and have its point define
         * in mathematical order or counter mathematical order.
         * @return The transformation matrix that was use to transform the point (the order is not present in this matrix)
         */
        Eigen::Matrix4d normalize();



        std::vector<double> xs;
        std::vector<double> ys;
        std::vector<double> zs;


    protected:

        std::string transformVectorToString(const std::vector<double>&) const;
        std::vector<double> transformStringToVector(std::string line) const;


        Eigen::Vector3d getPointAtIdx(int idx);


    private:

        std::string name;
        std::string uid;
        double precision;

    };
}


#endif //CPACSCREATORLIBANDTESTS_CPACSPOINTSPROFILE_H
