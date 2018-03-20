//
// Created by cfse on 3/13/18.
//

/**
 * @brief Structure element to hold the CPACS tree
 * @author Malo Drougard
 */



#ifndef TIGL_CPACSOVERTREEITEM_H
#define TIGL_CPACSOVERTREEITEM_H

#include <QList>
#include <QVariant>
#include "TIGLViewerDocument.h"

class CPACSOverTreeItem {

public:

    // should be only used to create the root
    CPACSOverTreeItem(int cpacsIndex, std::string cpacsUid, std::string cpacsType);
    ~CPACSOverTreeItem();

    // this should be the only way to add children
    CPACSOverTreeItem*  addChild(int cpacsIndex, std::string cpacsUid, std::string cpacsType);

    CPACSOverTreeItem* getParent() const;
    QList<CPACSOverTreeItem*> getChildren() const;


    int getChildrenCount() const;

    // Return its position in the children list of its parent.
    // If there is no parent or the item is not found in parent list, its return -1.
    int positionRelativelyToParent() const;


    // DATA
    // functions to fetch data
    int getCpacsIndex() const;
    std::string getCpacsType() const;
    std::string getCpacsUid() const;
    // return how many different data the structure hold
    inline int getDataCount() {return 3;}
    // get the Name associated with the data index
    std::string getDataName(int i);


private:

    int cpacsIndex;
    std::string cpacsUid;
    std::string cpacsType;
    std::string xPath;

    CPACSOverTreeItem* parent;
    QList<CPACSOverTreeItem*> children;

};





#endif //TIGL_CPACSOVERTREEITEM_H
