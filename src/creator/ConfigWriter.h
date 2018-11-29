//
// Created by cfse on 11/14/18.
//

#ifndef TIGL_CONFIGWRITER_H
#define TIGL_CONFIGWRITER_H


#include "tixi.h"
#include "tixi3/tixicpp.h"
#include "tigl.h"
#include "CCPACSConfiguration.h"
#include "CCPACSConfigurationManager.h"
#include "CPACSTree.h"
#include "UniqueXPath.h"



namespace cpcr {

    class ConfigWriter {

    public:
        ConfigWriter();

        bool isValid();


        /**
         * Set a preexisting CCPACSConfigurationHandle
         * @remark the CCPACSConfigurationHandle need to be valid anbd open
         * @param tiglHandle
         */
        void setTiglHandle(TiglCPACSConfigurationHandle tiglHandle);

        /**
         * Get the current CCPACSConfigurationHandle
         * @return TiglCPACSConfigurationHandle
         */
        inline TiglCPACSConfigurationHandle getTiglHandle(){return tiglHandle; };

        //TODO: find a way to save it back in the file without issue for tigl
        void save();  // not implemented
        void save(std::string newFilname); // not implemented

        /**
         *  Return the CTiglTransformation that is pointed by the xpath.
         *  If the xpath is not pointing on a transformation, it's return a trivial transformation and rise a warning.
         *  @remark Currently only the transformation for fuselage and wing are supported
         * @param xpath
         * @return
         */
        tigl::CTiglTransformation getTransformation(UniqueXPath xpath);

        /**
         *  Set the transformation pointed by the xpath.
         *  If the xpath is not pointing on a transformation, it will do nothing and rise a warning.
         *  @remark Currently only the transformation for fuselage and wing are supported
         * @param xpath
         * @return
         */
        void setTransformation(UniqueXPath xpath, tigl::CTiglTransformation t);


        tigl::CCPACSConfiguration&  getConfiguration();
        std::string getModelUid();

    protected:

        /**
         * Return the CCPACSTransformation pointed by the given xpath by reference.
         * @remark we can modify this reference and store it in tixi "memory" using WriteCPACS on it.
         * @param xpath
         * @return
         */
        tigl::CCPACSTransformation& getTransformationReference(UniqueXPath xpath);

        bool isValidWithWarning();



    private:

        TiglCPACSConfigurationHandle tiglHandle;


    };
}

#endif //TIGL_CONFIGWRITER_H
