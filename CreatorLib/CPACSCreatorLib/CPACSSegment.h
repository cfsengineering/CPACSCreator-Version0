//
// Created by cfse on 7/9/18.
//

#ifndef CPACSCREATORLIBANDTESTS_CPACSSEGMENT_H
#define CPACSCREATORLIBANDTESTS_CPACSSEGMENT_H

#include <string>

namespace cpcr{

    class CPACSSegment {

    public:

        CPACSSegment();
        CPACSSegment(std::string name, std::string fromElementUid, std::string toElementUid  ) ;

        inline const std:: string & getName() const { return name;};
        void setName(const std::string & name);

        inline const std::string &getFromElementUID() const { return fromElementUID;};
        void setFromElementUID(const std::string &fromElementUID);

        inline const std::string &getToElementUID() const { return toElementUID;};
        void setToElementUID(const std::string &toElementUID);

    private:

        std::string name;
        std::string fromElementUID;
        std::string toElementUID;


    };

}

#endif //CPACSCREATORLIBANDTESTS_CPACSSEGMENT_H
