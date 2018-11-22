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
         * Open and register an new CCPACSConfiguration in the CCPACSConfigurationManager
         * @param filename
         * @param modelUID
         */
        void open(std::string filename, UID modelUID);

        /**
         * Set a preexisting CCPACSConfiguration
         * @param tiglHandle
         */
        void open(TiglCPACSConfigurationHandle tiglHandle);
        void close();

        void save();
        void save(std::string newFilname);

        tigl::CTiglTransformation getTransformation(UniqueXPath xpath);

        void setTransformation(UniqueXPath xpath, tigl::CTiglTransformation t);

        std::string getUid();


    protected:
        tigl::CCPACSConfiguration&  getConfiguration();

        /**
         * Return the CCPACSTransformation pointed by the given xpath by reference.
         * @remark because the CCPACSTransformation is geven by reference modify it wil change the value store by
         * the element that has this transformation.
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
