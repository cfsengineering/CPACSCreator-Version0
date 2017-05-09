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

#include <cassert>
#include <CCPACSWingSparSegment.h>
#include "CCPACSWingSpars.h"
#include "CPACSSparSegments.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSSparSegments::CPACSSparSegments(CCPACSWingSpars* parent, CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSSparSegments::~CPACSSparSegments() {}
        
        CCPACSWingSpars* CPACSSparSegments::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSSparSegments::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element sparSegment
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/sparSegment")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/sparSegment", m_sparSegments, reinterpret_cast<CCPACSWingSparSegments*>(this), m_uidMgr);
            }
            
        }
        
        void CPACSSparSegments::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element sparSegment
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/sparSegment", m_sparSegments);
            
        }
        
        const std::vector<unique_ptr<CCPACSWingSparSegment> >& CPACSSparSegments::GetSparSegments() const
        {
            return m_sparSegments;
        }
        
        std::vector<unique_ptr<CCPACSWingSparSegment> >& CPACSSparSegments::GetSparSegments()
        {
            return m_sparSegments;
        }
        
    }
}
