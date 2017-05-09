// Copyright (c) 2016 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
    class CTiglUIDManager;
    
    namespace generated
    {
        class CPACSSparCell;
        
        // This class is used in:
        // CPACSSparCrossSection
        
        // generated from /xsd:schema/xsd:complexType[784]
        class CPACSSparCells
        {
        public:
            TIGL_EXPORT CPACSSparCells(CTiglUIDManager* uidMgr);
            TIGL_EXPORT virtual ~CPACSSparCells();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::vector<unique_ptr<CPACSSparCell> >& GetSparCells() const;
            TIGL_EXPORT virtual std::vector<unique_ptr<CPACSSparCell> >& GetSparCells();
            
        protected:
            CTiglUIDManager* m_uidMgr;
            
            std::vector<unique_ptr<CPACSSparCell> > m_sparCells;
            
        private:
            #ifdef HAVE_CPP11
            CPACSSparCells(const CPACSSparCells&) = delete;
            CPACSSparCells& operator=(const CPACSSparCells&) = delete;
            
            CPACSSparCells(CPACSSparCells&&) = delete;
            CPACSSparCells& operator=(CPACSSparCells&&) = delete;
            #else
            CPACSSparCells(const CPACSSparCells&);
            CPACSSparCells& operator=(const CPACSSparCells&);
            #endif
        };
    }
    
    // Aliases in tigl namespace
    #ifdef HAVE_CPP11
    using CCPACSSparCells = generated::CPACSSparCells;
    using CCPACSSparCell = generated::CPACSSparCell;
    #else
    typedef generated::CPACSSparCells CCPACSSparCells;
    typedef generated::CPACSSparCell CCPACSSparCell;
    #endif
}
