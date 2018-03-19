//
// Created by cfse on 3/16/18.
//

#include "MyCPACSReader.h"
#include "CPACSOverTreeItem.h"
#include "tixicpp.h"


// create an over tree from tixi



int MyCPACSReader::openCpacsConfiguration(const QString fileName)
{
    QStringList configurations;

    tixiHandle = -1;

    char *cfileName = strdup((const char*)fileName.toLatin1());
    ReturnCode tixiRet = tixiOpenDocument(cfileName, &tixiHandle);
    if (tixiRet != SUCCESS) {
        std::cerr << QString("Error in function <u>tixiOpenDocument</u> when opening <br>file <i>"+fileName+"</i>. Error code: %1").arg(tixiRet).toStdString() << std::endl;
        tixiHandle = -1;
        return 1;
    }
    /*
    // read configuration names
    int countAircrafts = 0;

    tixiRet = tixiGetNamedChildrenCount( tixiHandle, CPACS_XPATH_AIRCRAFT, "model", &countAircrafts );
    for (int i = 0; i < countAircrafts; i++) {
        char *text;
        std::stringstream xpath;
        xpath << CPACS_XPATH_AIRCRAFT_MODEL << "[" << i+1 << "]";
        tixiRet = tixiGetTextAttribute( tixiHandle, xpath.str().c_str(), "uID", &text);
        if (tixiRet == SUCCESS) {
            configurations << text;
        }
        else {
            std::cerr << QString("Error: missing uID for aircraft model %1!").arg(i).toStdString() << std::cerr ;
            return TIGL_OPEN_FAILED;
        }
    }

    // Get configuration from user and open with TIGL
    TiglReturnCode tiglRet = TIGL_UNINITIALIZED;
    if (countAircrafts == 0) {
        // no configuration present
        std::cerr << "no aircraft present" << std::endl;
        return 1;
    }
    else if ( countAircrafts == 1) {

    }
    else {
        std::cerr << "Multiples aircrafts not supported yet" << std::endl;
    }
    */
    return 0;
}

CSharedPtr<CPACSOverTreeItem> MyCPACSReader::createRoot(const QString fileName) {

    openCpacsConfiguration(fileName);

    CSharedPtr<CPACSOverTreeItem> root = nullptr;

    if(tixiHandle < 0){
        return nullptr ;
    }

    int countAircrafts = 0;
    ReturnCode tixiRet = tixiGetNamedChildrenCount( tixiHandle, CPACS_XPATH_AIRCRAFT, "model", &countAircrafts );

    std::string xpath = CPACS_XPATH_AIRCRAFT;
    xpath += "/model[1]";

    int childrenCount = -1 ;
    int attributesCount = -1;
    std::string uid = "empty";


    tixiRet = tixiGetNumberOfChilds(tixiHandle,xpath.c_str(),&childrenCount);
    tixiRet = tixiGetNumberOfAttributes(tixiHandle, xpath.c_str(), &attributesCount);
    char* attName = NULL;
    char* attValue = NULL;
    for(int i =1; i <= attributesCount; i++) {
        tixiRet = tixiGetAttributeName(tixiHandle, xpath.c_str(), i, &attName);
        tixiRet = tixiGetTextAttribute(tixiHandle, xpath.c_str(), attName, &attValue);
        if (attName == "uID") {
            uid = attValue;
        }

    }

    root =  CSharedPtr<CPACSOverTreeItem>(new CPACSOverTreeItem(1, uid.c_str(), "model"));

    createNode(xpath, root.get(), 1, "model");

    
    return root;


}




void MyCPACSReader::createNode(std::string xpath, CPACSOverTreeItem* parent, int cpacsIdx, std::string elementName) {

    std::cout << xpath.c_str() << std::endl;
    ReturnCode tixiRet;
    
    int childrenCount = -1 ;
    int attributesCount = -1;
    std::string nodeType = "";
    std::string uid;

    char* type = NULL;
    tixiRet = tixiGetNodeType(tixiHandle, xpath.c_str(),&type);
    nodeType = type;

    tixiRet = tixiGetNumberOfChilds(tixiHandle,xpath.c_str(),&childrenCount);
    tixiRet = tixiGetNumberOfAttributes(tixiHandle, xpath.c_str(), &attributesCount);


    char* attName = NULL;
    char* attValue = NULL;
    
    for(int i =1; i <= attributesCount; i++){
        tixiRet = tixiGetAttributeName(tixiHandle,xpath.c_str(), i,&attName);
        tixiRet = tixiGetTextAttribute(tixiHandle,xpath.c_str(),attName,&attValue);
        if(attName == "uID"){
            uid = attValue;
        }    
    }


    CPACSOverTreeItem* thisElement = parent->addChild(cpacsIdx,uid.c_str(),elementName.c_str());

    char * childName = NULL;
    std::list<std::string> names ;
    for(int i = 1; i <= childrenCount; i++) {
        tixiRet = tixiGetChildNodeName(tixiHandle, xpath.c_str(), i, &childName);
        // TODO: FIND HOW TIXI SHOULD MANAGE THE NONE NODE ELEMENT LIKE TEXT
        if(childName[0] == '#' ) {
            std::cout << childName << std::endl;
        }else{
            names.push_back(childName);
        }

    }
    names.unique();

    std::string newXPath = "";
    int sameNamedChildrenCount =0;
    for(std::string currentName : names){

        tixiRet = tixiGetNamedChildrenCount(tixiHandle,xpath.c_str(),currentName.c_str(), &sameNamedChildrenCount );

        if ( sameNamedChildrenCount == 1) {
            newXPath = xpath;
            newXPath += "/";
            newXPath += currentName;
            createNode(newXPath, thisElement, 1, currentName);    // Recursive call
        }
        else{
            for( int idx = 1; idx <= sameNamedChildrenCount; idx++){
                newXPath = xpath;
                newXPath += "/";
                newXPath += currentName;
                newXPath += "[";
                newXPath += std::to_string(idx);
                newXPath += "]";
                createNode(newXPath, thisElement, idx, currentName);    // Recursive call
            }
        }
    }
    
    return ;
}



std::string MyCPACSReader::getNodeInfo(std::string xpath) {

    ReturnCode tixiRet;
    std::string summary;

    int childrenCount = -1 ;
    int attributesCount = -1;


    tixiRet = tixiGetNumberOfChilds(tixiHandle,xpath.c_str(),&childrenCount);
    summary += "numberOfChildren:";
    summary +=  std::to_string( childrenCount);
    summary +=  " ";

    tixiRet = tixiGetNumberOfAttributes(tixiHandle, xpath.c_str(), &attributesCount);
    summary += "numberOfAttributes:";
    summary +=  std::to_string(attributesCount);
    summary +=  " ";

    char* name = NULL;
    char* value = NULL;
    summary += "attributes: ";
    for(int i =1; i <= attributesCount; i++){
        tixiRet = tixiGetAttributeName(tixiHandle,xpath.c_str(), i,&name);
        summary += name;
        summary += "=";
        tixiRet = tixiGetTextAttribute(tixiHandle,xpath.c_str(),name,&value);
        summary += value;
        summary +=  " ";
    }

    return summary;
}







