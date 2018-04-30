//
// Created by cfse on 3/16/18.
//

#ifndef TIGL_CPACSCREATOR_H
#define TIGL_CPACSCREATOR_H

#include "CPACSOverTreeItem.h"
#include "tixicpp.h"


#include "CPACSCreatorLib/CPACSFile.h"
#include "CPACSCreatorLib/CPACSTransformation.h"


/**
 * @brief Manage one aircraft
 *
 *
 */


/*
class AircraftTree {

public:

    AircraftTree();

    void build(std::string file, std::string uid = "");
    inline bool isBuild(){return m_isBuild;}

    inline CSharedPtr<CPACSOverTreeItem> getRoot() const  {return m_root;}

    std::vector<double> getPoint(std::string xpath);
    void setPoint(std::string xpath, const std::vector<double>& point );

    cpcr::CPACSTransformation getTransformation(std::string xpath);
    void setTransformation(std::string xpath, const cpcr::CPACSTransformation& transformation );




    void save();


protected:
    void createNode(TixiDocumentHandle  tixiHandle, std::string xpath, CPACSOverTreeItem* parent, int cpacsIdx, std::string elementName);



private:

    std::string fileName;

    std::string aircraftUid;
    std::string aircraftXPath;

    bool m_isBuild;

    CSharedPtr<CPACSOverTreeItem> m_root;
    cpcr::CPACSFile modifier;


};




*/
#endif //TIGL_CPACSCREATOR_H
