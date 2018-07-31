//
// Created by cfse on 7/12/18.
//

#ifndef CPACSCREATORLIBANDTESTS_CPACSPROFILESDB_H
#define CPACSCREATORLIBANDTESTS_CPACSPROFILESDB_H

#include "CPACSFile.h"
#include "CPACSPointsProfile.h"
#include "CreatorException.h"
#include <map>

/***
 *
 * Manage all the wing profiles of one particular CPACS file.
 *
 */

namespace cpcr{

    class CPACSProfilesDB {


    public:

        CPACSProfilesDB();
        CPACSProfilesDB(CPACSFile* file);

        void init(CPACSFile* file);

        /***
         * @remark Save directly the generate profile in file.
         *      If some normalization was already performed -> overwrite the previous normalization in memory and in file!
         */
        void createAssociateNormalizedProfiles();


        // DATA
        std::vector<std::string> airfoilUIDs;
        std::map<std::string, bool> isPoints; // true if the profile is define as point list
        std::map<std::string, bool> isNormalized; // true if the profile normalized
        std::map<std::string, CPACSPointsProfile> pointsProfiles;
        // its own uid if normalized,
        // otherwise uid of the normalized version if exist and "" if no normalized version exist
        std::map<std::string, std::string> normalizedVersion;
        std::map<std::string, Eigen::Matrix4d> normalizationM; // the matrix to transform the profile into is normalized version


    protected:

        // create the entries for the profile present in file ( no normalization is performed)
        void set();
        void clean();


    private:


        CPACSFile* modifier;

        // tell if the dB is set
        bool isSet;

    };
}


#endif //CPACSCREATORLIBANDTESTS_CPACSPROFILESDB_H
