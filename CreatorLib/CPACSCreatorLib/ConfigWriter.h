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

        void open(std::string filename, UID modelUID);

        tigl::CTiglTransformation getTransformation(UniqueXPath xpath); 
 

    protected:
        tigl::CCPACSConfiguration&  GetConfiguration();

    private:

        std::string filename;
        TixiDocumentHandle           tixiHandle;
        TiglCPACSConfigurationHandle tiglHandle;


    };
}

#endif //TIGL_CONFIGWRITER_H
