//
// Created by cfse on 3/13/18.
//

/**
 * @brief Structure element to hold the CPACS tree
 * @author Malo Drougard
 */



#ifndef TIGL_CPACSTREEITEM_H
#define TIGL_CPACSTREEITEM_H

#include <vector>
#include <string>
#include "Eigen/Dense"

#include "CPACSFile.h"
#include "CPACSTransformation.h"
#include "UniqueXPath.h"


namespace cpcr {

    class CPACSTree;
    class CPACSTreeItem {

    public:
        // should be only used to create the root
        CPACSTreeItem(CPACSTree* tree, UniqueXPath xpath, std::string cpacsType, int tixiIndex, std::string uid );
        CPACSTreeItem();

        ~CPACSTreeItem();

        // this should be the only way to add children
        CPACSTreeItem* addChild(UniqueXPath xpath, std::string cpacsType, int tixiIndex, std::string uid);

        CPACSTreeItem* getParent() const;

        std::vector<CPACSTreeItem *> getChildren() const;

        // Return the child with respect to the given xpath
        // IF the child was not find nullptr is returned
        // The xpath expression is evaluated from the current item
        // if the xpath has multiple possibility the element with tixi index 1 is returned
        CPACSTreeItem * getChild(UniqueXPath xpath, bool warnings = true);
        CPACSTreeItem * getChild(std::string xpathString, bool warnings = true);
        CPACSTreeItem * getChildByUid(std::string uid);

        CPACSTreeItem * getParentOfType(std::string type);

        
        std::vector<CPACSTreeItem *> findAllChildrenOfTypeRecursively(std::string type);



        // Return its position in the children list of its parent.
        // If there is no parent or the item is not found in parent list, its return -1.
        int positionRelativelyToParent() const;


        int getTixiIndex() const;

        std::string getType() const;

        UniqueXPath getXPath() const;

        inline std::string getUid() const {return uid;};

        CPACSTree* getTree() const ;


        bool hasChildOfType(std::string name);


        // Todo: change place of this function put in tree
        // Return all the Transform in the path from the target to this node
        // If the target as transform child this will also be in the path
        std::vector<CPACSTransformation> composeTransformRecursively(UniqueXPath target);




    private:

        std::string type;
        UniqueXPath xpath;
        int tixiIdx;
        std::string uid;

        CPACSTreeItem *parent;
        std::vector<CPACSTreeItem *> children;

        // tree that the item belong
        CPACSTree* tree;

    };

}   // end namespace cpcr



#endif //TIGL_CPACSTREEITEM_H
