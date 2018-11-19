//
// Created by cfse on 11/14/18.
//

#include "ConfigWriter.h"
#include "CreatorException.h"
#include "CCPACSFuselageSection.h"


cpcr::ConfigWriter::ConfigWriter() {
    this->filename = "";
    tixiHandle = -1;
    tiglHandle = -1;

}

void cpcr::ConfigWriter::open(std::string filename, UID modelUID) {

    this->filename = filename;

    tixiHandle = tixi::TixiOpenDocument(filename);

    TiglReturnCode tiglRet = tiglOpenCPACSConfiguration(tixiHandle, modelUID.c_str(),  &tiglHandle);
    if(tiglRet != TIGL_SUCCESS){
        throw CreatorException("ConfigWriter::open:: Error open tigl");
    }

    return ;
}


tigl::CCPACSConfiguration &cpcr::ConfigWriter::GetConfiguration() {
    tigl::CCPACSConfigurationManager& manager = tigl::CCPACSConfigurationManager::GetInstance();
    return manager.GetConfiguration(tiglHandle);
}



tigl::CTiglTransformation cpcr::ConfigWriter::getTransformation(cpcr::UniqueXPath xpath) {

    tigl::CTiglTransformation trans;

    while( (! xpath.isEmpty() )  && xpath.getFirstElementType() != "fuselages"  && xpath.getFirstElementType() != "wings" )  {
        xpath.popFirst();
    }

    if (xpath.isEmpty()){
        LOG(WARNING) << "ConfigWriter::getTransformation: XPATH NOT VALID";
        return trans;
    }


    tigl::CCPACSConfiguration & config = GetConfiguration();

    if( xpath.getFirstElementType() == "fuselages"){

        xpath.popFirst();
        if( xpath.getFirstElementType() != "fuselage"){
            throw CreatorException("ConfigWriter::getTransformation: invalid path");
        }
        int fuselageIdx = xpath.getFirstElementIndex();
        xpath.popFirst();

        if(xpath.isEmpty()){
            trans = config.GetFuselage(fuselageIdx).GetTransformation().getTransformationMatrix();
        }else {
            if( xpath.getFirstElementType() != "sections"){
                throw CreatorException("ConfigWriter::getTransformation: invalid path");
            }
            xpath.popFirst();

            if( xpath.getFirstElementType() != "section"){
                throw CreatorException("ConfigWriter::getTransformation: invalid path");
            }
            int sectionIdx = xpath.getFirstElementIndex();
            xpath.popFirst();
            if (xpath.isEmpty()){
                trans = config.GetFuselage(fuselageIdx).GetSections().GetSection(sectionIdx).GetTransformation().getTransformationMatrix();
            }



        }


    }

    if( xpath.getFirstElementType() == "wings"){
        xpath.popFirst();
        xpath.getFirstElementType();
        int wingIdx = xpath.getFirstElementIndex();
        trans = config.GetWing(wingIdx).GetTransformation().getTransformationMatrix();
    }

    return trans;
}


