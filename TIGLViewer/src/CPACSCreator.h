//
// Created by cfse on 3/16/18.
//

#ifndef TIGL_CPACSCREATOR_H
#define TIGL_CPACSCREATOR_H

#include "CPACSOverTreeItem.h"
#include "tixicpp.h"




/**
 * @brief Manage one aircraft
 *
 *
 */


class CPACSCreator {

public:


    void open(std::string fileName, std::string configUid = "");

    void save();

    CSharedPtr<CPACSOverTreeItem> createRoot();

    std::vector<double> getPoint(std::string xpath);
    void setPoint(std::string xpath, const std::vector<double>& point );


    inline CSharedPtr<CPACSOverTreeItem> getRoot() const  {return m_root;}
    inline bool isValid(){return m_isValid;}


protected:
    void createNode(TixiDocumentHandle  tixiHandle, std::string xpath, CPACSOverTreeItem* parent, int cpacsIdx, std::string elementName);
    bool isValidWithWarning();



private:

    TixiDocumentHandle  tixiHandle;

    std::string fileName;
    std::string configUid;
    std::string configXPath;

    CSharedPtr<CPACSOverTreeItem> m_root;

    bool m_isValid;
};





#endif //TIGL_CPACSCREATOR_H
