//
// Created by cfse on 11/14/18.
//

#include "ConfigWriter.h"
#include "CreatorException.h"
#include "CCPACSFuselageSection.h"
#include "CCPACSWingSection.h"


cpcr::ConfigWriter::ConfigWriter() {
    tiglHandle = -1;

}



tigl::CCPACSConfiguration &cpcr::ConfigWriter::getConfiguration() {
    tigl::CCPACSConfigurationManager& manager = tigl::CCPACSConfigurationManager::GetInstance();
    return manager.GetConfiguration(tiglHandle);
}



tigl::CTiglTransformation cpcr::ConfigWriter::getTransformation(cpcr::UniqueXPath xpath) {

    tigl::CTiglTransformation r;

    if( ! isValidWithWarning() ){
        LOG(WARNING) << "ConfigWriter::getTransformation:: Impossible to get the transformation, the configWriter is not in a valid state!" << std::endl;
        return r;
    }

    try {
        r = this->getTransformationReference(xpath).getTransformationMatrix();
    }
    catch( const CreatorException& e){
        LOG(ERROR)  << "ConfigWriter::getTransformation throw error with message: "
                    << e.what()
                    << " Default CTiglTransformation will be returned!"
                    << std::endl;

    }
    return r;
}




void cpcr::ConfigWriter::setTransformation(cpcr::UniqueXPath xpath, tigl::CTiglTransformation newTransformation) {


    if( ! isValidWithWarning() ){
        LOG(WARNING) << "ConfigWriter::getTransformation:: Impossible to set the transformation, the configWriter is not in a valid state!" << std::endl;
        return;
    }

    try {

        tigl::CCPACSTransformation& refTransformation = this->getTransformationReference(xpath);

        // patch because the  refTransformation.setTransformationMatrix(newTransformation) is not working (decomposition of the matrix not implemented)
        Eigen::Matrix4d tempM;
        for(int i =  0; i < 4; i++ ){
            for(int j =  0; j < 4; j++ ) {
                tempM(i,j)  = newTransformation.GetValue(i,j);
            }
        }
        MCPACSTransformation tempMT(tempM);

        refTransformation.setScaling(tigl::CTiglPoint(tempMT.getScaling().x,tempMT.getScaling().y, tempMT.getScaling().z ));
        double rotX = tempMT.getRotation().x;
        double rotY = tempMT.getRotation().y;
        double rotZ = tempMT.getRotation().z;
        refTransformation.setRotation(tigl::CTiglPoint( rotX, rotY, rotZ ));
        refTransformation.setTranslation(tigl::CTiglPoint(tempMT.getTranslation().x,tempMT.getTranslation().y, tempMT.getTranslation().z ));
        // end patch

        xpath.addParticleAtEnd("transformation[1]");
        refTransformation.WriteCPACS(getConfiguration().GetTixiDocumentHandle(), xpath.toString() ) ;

    }
    catch( const CreatorException& e){
        LOG(ERROR)  << "ConfigWriter::getTransformation throw error with message: "
                    << e.what()
                    << " Nothing has changed!"
                    << std::endl;
    }

}



tigl::CCPACSTransformation &cpcr::ConfigWriter::getTransformationReference(cpcr::UniqueXPath xpath) {

    // go down until fuselages or wings
    while( (! xpath.isEmpty() )  && xpath.getFirstElementType() != "fuselages"  && xpath.getFirstElementType() != "wings" )  {
        xpath.popFirst();
    }

    if (xpath.isEmpty()){
        throw CreatorException("ConfigWriter::GetTransformationReference: Invalid xpath");
    }


    tigl::CCPACSConfiguration & config = getConfiguration();

    // fuselages cases
    if( xpath.getFirstElementType() == "fuselages"){

        xpath.walkSafely("fuselages");
        int fuselageIdx = xpath.walkSafely("fuselage");

        // fuselage[idx] transformation
        if(xpath.isEmpty()){
            return config.GetFuselage(fuselageIdx).GetTransformation();
        }

        xpath.walkSafely("sections");
        int sectionIdx = xpath.walkSafely("section");

        // fuselage[idx]/sections/section[idx] transformation
        if (xpath.isEmpty()){
            return config.GetFuselage(fuselageIdx).GetSections().GetSection(sectionIdx).GetTransformation();
        }

        xpath.walkSafely("elements");
        int elementIdx = xpath.walkSafely("element");


        // fuselage[idx]/sections/section[idx]/elements/element[idx] transformation
        if(xpath.isEmpty()){
            return config.GetFuselage(fuselageIdx).GetSections().GetSection(sectionIdx).GetElements().GetSectionElement(elementIdx).GetTransformation();
        }

        throw CreatorException("ConfigWriter::GetTransformationReference: Invalid xpath");
    }


    if( xpath.getFirstElementType() == "wings"){
        xpath.walkSafely("wings");
        int wingIdx = xpath.walkSafely("wing");

        // wing[idx] transformation
        if(xpath.isEmpty()){
            return config.GetWing(wingIdx).GetTransformation();
        }

        xpath.walkSafely("sections");
        int sectionIdx = xpath.walkSafely("section");

        // wing[idx]/sections/section[idx] transformation
        if (xpath.isEmpty()){
            return config.GetWing(wingIdx).GetSections().GetSection(sectionIdx).GetTransformation();
        }

        xpath.walkSafely("elements");
        int elementIdx = xpath.walkSafely("element");

        // wing[idx]/sections/section[idx]/elements/element[idx] transformation
        if(xpath.isEmpty()){
            return config.GetWing(wingIdx).GetSections().GetSection(sectionIdx).GetElements().GetSectionElement(elementIdx).GetTransformation();
        }

        throw CreatorException("ConfigWriter::GetTransformationReference: Invalid xpath");
    }

    throw CreatorException("ConfigWriter::GetTransformationReference: Invalid xpath");

}


void cpcr::ConfigWriter::save(std::string newFilname) {

// The following code is not working properly because the tixi save need to reopen the document after to be able to rewrite in it
// TODO: fins a way to save the current state of the CPACSConfiguration back in the file
//    if (!isValidWithWarning()) return;
//
//    tiglSaveCPACSConfiguration(getModelUid().c_str(), tiglHandle );
//    TixiDocumentHandle tixiHandle = getConfiguration().GetTixiDocumentHandle();
//
//    int ret = tixiSaveDocument(tixiHandle, newFilname.c_str());
//    if( ret > 0){
//        throw CreatorException("ConfigWriter::save:: Impossible to save file with the name: " + newFilname );
//    }
//

}

void cpcr::ConfigWriter::save() {

    // TODO: how we can get the current file name from the current CPACSConfiguration
    // this->save(filname);
}


bool cpcr::ConfigWriter::isValidWithWarning() {

    if (isValid() ) {
        return true;
    } else {
        std::string msg = "ConfigWriter::isValidWithWarning:: The file is not valid or not open!";
        LOG(WARNING) << msg;
        return false;
    };
}





void cpcr::ConfigWriter::setTiglHandle(TiglCPACSConfigurationHandle newTiglHandle) {
    tiglHandle = newTiglHandle;
    if( ! isValid()){
        tiglHandle = -1;
        LOG(ERROR) << "ConfigWriter::open:: invalid new tiglHandle given" << std::endl;
    }
}

bool cpcr::ConfigWriter::isValid() {
    TiglBoolean isValid;
    tiglIsCPACSConfigurationHandleValid(tiglHandle, &isValid);
    if( isValid){
        return  true;
    }else{
        return false;
    }
}

std::string cpcr::ConfigWriter::getModelUid() {
    if (!isValidWithWarning()){
        return "";
    }
    tigl::CCPACSConfiguration & config = getConfiguration();
    std::string modelUID = config.GetUID();
    return modelUID;
}
