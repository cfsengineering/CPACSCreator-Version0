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
#include <typeinfo>
#include <vector>
#include "CTiglError.h"
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
    class CTiglUIDManager;
    class CCPACSWing;
    class CCPACSAircraftModel;
    class CCPACSRotorcraftModel;
    
    namespace generated
    {
        // This class is used in:
        // CPACSAircraftModel
        // CPACSRotorcraftModel
        
        // generated from /xsd:schema/xsd:complexType[937]
        class CPACSWings
        {
        public:
            TIGL_EXPORT CPACSWings(CCPACSAircraftModel* parent, CTiglUIDManager* uidMgr);
            TIGL_EXPORT CPACSWings(CCPACSRotorcraftModel* parent, CTiglUIDManager* uidMgr);
            
            TIGL_EXPORT virtual ~CPACSWings();
            
            template<typename P>
            TIGL_EXPORT bool IsParent() const
            {
                return m_parentType != NULL && *m_parentType == typeid(P);
            }
            
            template<typename P>
            TIGL_EXPORT P* GetParent() const
            {
                #ifdef HAVE_STDIS_SAME
                static_assert(std::is_same<P, CCPACSAircraftModel>::value || std::is_same<P, CCPACSRotorcraftModel>::value, "template argument for P is not a parent class of CPACSWings");
                #endif
                if (!IsParent<P>()) {
                    throw CTiglError("bad parent");
                }
                return static_cast<P*>(m_parent);
            }
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSWing> >& GetWings() const;
            TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSWing> >& GetWings();
            
        protected:
            void* m_parent;
            const std::type_info* m_parentType;
            
            CTiglUIDManager* m_uidMgr;
            
            std::vector<unique_ptr<CCPACSWing> > m_wings;
            
        private:
            #ifdef HAVE_CPP11
            CPACSWings(const CPACSWings&) = delete;
            CPACSWings& operator=(const CPACSWings&) = delete;
            
            CPACSWings(CPACSWings&&) = delete;
            CPACSWings& operator=(CPACSWings&&) = delete;
            #else
            CPACSWings(const CPACSWings&);
            CPACSWings& operator=(const CPACSWings&);
            #endif
        };
    }
    
    // CPACSWings is customized, use type CCPACSWings directly
}
