//
// Created by makem on 18/04/18.
//

#ifndef CPACSCREATORLIBANDTESTS_CPACSTREE_H
#define CPACSCREATORLIBANDTESTS_CPACSTREE_H


#include <string>
#include <vector>
#include <memory>

#include "CPACSFile.h"
#include "CPACSTreeItem.h"





namespace  cpcr {

    typedef std::string UID;


    /**
     * @brief Construct and manage a tree structure over CPACS file.
     *
     * The xml CPACS format can be represented as a tree. This class create for each xml node starting from the given
     * root a CPACSTreeItem. The access to the underlying file is managed by the TIXI library. So basically, this class
     * is a a tree structure that represent the a given xml file from a given root. Remark, that the root need not to
     * be the first element of the CPACS, but can be every where, typically the the "modelType" of CPACS can be chosen.
     */
    class CPACSTree {

    public:

        CPACSTree();
        ~CPACSTree();

        virtual void build(std::string file, UniqueXPath root);
        inline bool isBuild(){return m_isBuild;}

        inline CPACSTreeItem * getRoot() const  {return m_root;}

        inline std::string getFilename() const {return fileName; };

        inline CPACSFile* getModifier() {return &modifier;};


    protected:

        void createChildrenRecursively(CPACSTreeItem& parent);

        void clean();

        CPACSFile modifier;

        // cpacs file we will extract the tree
        std::string fileName;
        // The xpath in cpacs file of the root element
        // We can start the tree where ever we want
        UniqueXPath rootXPath;

        CPACSTreeItem*  m_root;

        bool m_isBuild;
    };
}

#endif //CPACSCREATORLIBANDTESTS_CPACSTREE_H
