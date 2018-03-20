//
// Created by cfse on 3/16/18.
//

#ifndef TIGL_MYCPACSREADER_H
#define TIGL_MYCPACSREADER_H

#include "CPACSOverTreeItem.h"
#include "tixicpp.h"

class MyCPACSReader {

public:
    CSharedPtr<CPACSOverTreeItem> createRoot(QString fileName, QString configUid);

private:

    int openCpacsConfiguration(const QString fileName);


    void createNode(std::string xpath, CPACSOverTreeItem* parent, int cpacsIdx, std::string elementName);
    std::string getNodeInfo(std::string xpath);


    TixiDocumentHandle tixiHandle;

};


#endif //TIGL_MYCPACSREADER_H
