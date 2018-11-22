/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
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

        virtual void writeToFile();

        virtual void writeToFile(std::string fileName) ;

        inline CPACSTreeItem * getRoot() const  {return m_root;}

        inline std::string getFilename() const {return fileName; };

        inline CPACSFile* getModifier() {return &modifier;};



        /**
         * Check if the UID exist in the tree.
         * If not throw an Exception with the optional prefix.
         *
         * @param uid
         * @param prefixErr The first part of the error message
         */
        void checkUID(UID uid, std::string prefixErr = "");

        /**
         *
         * Check if the UID exist in the tree and is of the given type.
         * If not throw an Exception with the optional prefix.
         *
         * @param uid
         * @param type
         * @param prefixErr The first part of the error message
         * @return
         */
        void checkUIDAndType(UID uid, std::string type, std::string prefixErr = "");

        /**
         * Check if the UID exist in the tree and is of the given type and has a parent of the given type.
         * If not throw an Exception with the optional prefix.
         *
         * @param uid
         * @param elementType
         * @param parentType
         * @param prefixErr The first part of the error message
         * @return
         */
        void checkUIDAndTypeAndParentType(UID uid, std::string elementType, std::string parentType, std::string prefixErr = "");




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
