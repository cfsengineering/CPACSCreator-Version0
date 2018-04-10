//
// Created by cfse on 3/16/18.
//

#include "AircraftTree.h"
#include "tixicpp.h"


// create an over tree from tixi



AircraftTree::AircraftTree() {

    fileName = "";
    aircraftUid = "";
    aircraftXPath = "";

    m_isBuild = false;

    CSharedPtr<CPACSOverTreeItem> m_root = nullptr;
    cpcr::CPACSFile modifier;

}


void AircraftTree::save() {
    modifier.save();
}


void AircraftTree::build(std::string file, std::string uid) {

    m_isBuild = false;
    m_root = nullptr;

    fileName = file;
    aircraftUid = uid;
    aircraftXPath = "";


    modifier.open(fileName);
    TixiDocumentHandle tixiHandle = modifier.getTixiHandle();

    // find model
    aircraftXPath = CPACS_XPATH_AIRCRAFT;
    if(aircraftUid == ""){
        aircraftXPath += "/model[1]";
    }else{
        aircraftXPath += "/model[@uID=\"" + aircraftUid + "\"]";
    }

    if( !tixi::TixiCheckElement(tixiHandle, aircraftXPath)) {
        std::cerr << "XPath: " <<  aircraftXPath << " not found in the document " << std::endl;
        aircraftXPath = "";
        return;
    } else {
        std::string uID = aircraftUid;
        if(tixi::TixiCheckAttribute(tixiHandle,aircraftXPath, "uID" ) ){
            uID = tixi::TixiGetAttribute<std::string>(tixiHandle, aircraftXPath, "uID");
        }
        if(aircraftUid != uID){
            aircraftUid = uID;    // happen's if the uID is not given
        }
    }


    // build the tree
    // create first element
    m_root =  CSharedPtr<CPACSOverTreeItem>(new CPACSOverTreeItem(0, "", "dummyRoot"));

    // recursive call to create element
    createNode(modifier.getTixiHandle(), aircraftXPath, m_root.get(), 1, "model");

    m_isBuild = true;
}




void AircraftTree::createNode(TixiDocumentHandle  tixiHandle,std::string xpath, CPACSOverTreeItem* parent, int cpacsIdx, std::string elementName) {

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

std::vector<double> AircraftTree::getPoint(std::string xpath) {

    return modifier.getPoint(xpath).toStdVector();

}

void AircraftTree::setPoint(std::string xpath, const std::vector<double> &point) {
    cpcr::Point newPoint (point);
    modifier.setPoint(xpath, newPoint);
}












