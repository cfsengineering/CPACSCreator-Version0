//
// Created by cfse on 3/16/18.
//

#include "CPACSCreator.h"
#include "tixicpp.h"


// create an over tree from tixi





CSharedPtr<CPACSOverTreeItem> CPACSCreator::createRoot() {


    std::cout << "creating root from filename " << fileName << " with uid " << configUid << std::endl;
    m_root = CSharedPtr<CPACSOverTreeItem>();
    if(!isValidWithWarning())
        return m_root;


    // create first element
    m_root =  CSharedPtr<CPACSOverTreeItem>(new CPACSOverTreeItem(0, "", "dummyRoot"));

    // recursive call to create element
    createNode(tixiHandle, configXPath, m_root.get(), 1, "model");

    return m_root;

}

void CPACSCreator::createNode(TixiDocumentHandle  tixiHandle,std::string xpath, CPACSOverTreeItem* parent, int cpacsIdx, std::string elementName) {

    //
    // std::cout << xpath.c_str() << std::endl;
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

    if(tixi::TixiCheckAttribute(tixiHandle, xpath, "uID" ) ){
        uid = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
    }


    CPACSOverTreeItem* thisElement = parent->addChild(cpacsIdx,uid.c_str(),elementName.c_str(), xpath);

    char * childName = NULL;
    std::list<std::string> names ;
    for(int i = 1; i <= childrenCount; i++) {
        tixiRet = tixiGetChildNodeName(tixiHandle, xpath.c_str(), i, &childName);
        // TODO: FIND HOW TIXI SHOULD MANAGE THE NONE NODE ELEMENT LIKE TEXT
        if(childName[0] == '#' ) {
            //std::cout << childName << std::endl;
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
            createNode(tixiHandle, newXPath, thisElement, 1, currentName);    // Recursive call
        }
        else{
            for( int idx = 1; idx <= sameNamedChildrenCount; idx++){
                newXPath = xpath;
                newXPath += "/";
                newXPath += currentName;
                newXPath += "[";
                newXPath += std::to_string(idx);
                newXPath += "]";
                createNode(tixiHandle, newXPath, thisElement, idx, currentName);    // Recursive call
            }
        }
    }
    
    return ;
}



void CPACSCreator::open(std::string inFileName, std::string inConfigUid) {

    m_isValid = false;
    configXPath = "";
    tixiHandle = -1;
    fileName = inFileName;
    configUid = inConfigUid;


    // Open document
    try {
        tixiHandle = tixi::TixiOpenDocument(fileName);
        CSharedPtr<CPACSOverTreeItem> root = nullptr;
    }catch(tixi::TixiError error){
        std::cerr << error.what() << std::endl;
        tixiHandle = -1;
        return;
    }

    // find model
    configXPath = CPACS_XPATH_AIRCRAFT;
    if(configUid == ""){
        configXPath += "/model[1]";
    }else{
        configXPath += "/model[@uID=\"" + configUid + "\"]";
    }

    if( !tixi::TixiCheckElement(tixiHandle, configXPath)) {
        std::cerr << "XPath: " <<  configXPath << " not found in the document " << std::endl;
        configXPath = "";
        tixiHandle = -1;
        return;
    } else {
        std::string uID = configUid;
        if(tixi::TixiCheckAttribute(tixiHandle,configXPath, "uID" ) ){
            uID = tixi::TixiGetAttribute<std::string>(tixiHandle, configXPath, "uID");
        }
        if(configUid != uID){
            configUid = uID;    // happen's if the uID is not given
        }
        m_isValid = true;
    }

}

bool CPACSCreator::isValidWithWarning() {
    if(isValid()){
        return true;

    }else{
        std::cout << "Trying to perform operation on a invalid CPACSCreator" << std::endl;
        return false;
    };
}




std::vector<double> CPACSCreator::getPoint(std::string xpath) {

    std::vector<double> point = {-1,-1,-1};

    if ( !isValidWithWarning() ){
        return point;
    }

    if( !tixi::TixiCheckElement(tixiHandle, xpath) ){
        std::cout << "element not found" << std::endl;
    }


    std::string tempXpath = xpath + "/x";

    if ( tixi::TixiCheckElement(tixiHandle, tempXpath) ){
        point[0] = tixi::TixiGetElement<double>(tixiHandle,tempXpath);
    }else{
        std::cout << "x value not foun" << std::endl;
    }
    tempXpath = xpath + "/y";
    if ( tixi::TixiCheckElement(tixiHandle, tempXpath) ){
        point[1] = tixi::TixiGetElement<double>(tixiHandle,tempXpath);
    }else{
        std::cout << "x value not foun" << std::endl;
    }
    tempXpath = xpath + "/z";
    if ( tixi::TixiCheckElement(tixiHandle, tempXpath) ){
        point[2] = tixi::TixiGetElement<double>(tixiHandle,tempXpath);
    }else{
        std::cout << "x value not foun" << std::endl;
    }
    return point;
}



void CPACSCreator::setPoint(std::string xpath, const std::vector<double>& point) {

    if (point.size() != 3 ) {
        std::cerr << "point have not 3 values" << std::endl;
        return;
    }

    if( !tixi::TixiCheckElement(tixiHandle, xpath) ){
        std::cout << "element not found" << std::endl;
        return;
    }


    std::string tempXpath = xpath + "/x";

    if ( tixi::TixiCheckElement(tixiHandle, tempXpath) ){
        tixi::TixiSaveElement(tixiHandle,tempXpath, point[0]);
    }else{
        std::cout << "x value not foun" << std::endl;
    }
    tempXpath = xpath + "/y";
    if ( tixi::TixiCheckElement(tixiHandle, tempXpath) ){
        tixi::TixiSaveElement(tixiHandle,tempXpath, point[1]);
    }else{
        std::cout << "x value not foun" << std::endl;
    }
    tempXpath = xpath + "/z";
    if ( tixi::TixiCheckElement(tixiHandle, tempXpath) ){
        tixi::TixiSaveElement(tixiHandle,tempXpath, point[2]);
    }else{
        std::cout << "x value not foun" << std::endl;
    }

    return ;
}

void CPACSCreator::save() {
    if( tixiHandle <= 0 ){
        std::cerr << "tixi handle is not valid, we can not save the document" << std::endl;

    }
    tixiSaveDocument(tixiHandle, fileName.c_str());
    tixiCloseDocument(tixiHandle );
    tixiHandle = tixi::TixiOpenDocument(fileName);
}














