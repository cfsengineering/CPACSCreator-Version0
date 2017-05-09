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

#include "CPACSFuselageProfiles.h"
#include "CPACSProfileGeometry.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSFuselageProfiles::CPACSFuselageProfiles(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr) {}
        
        CPACSFuselageProfiles::~CPACSFuselageProfiles() {}
        
        void CPACSFuselageProfiles::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element fuselageProfile
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fuselageProfile")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/fuselageProfile", m_fuselageProfiles, m_uidMgr);
            }
            
        }
        
        void CPACSFuselageProfiles::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element fuselageProfile
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/fuselageProfile", m_fuselageProfiles);
            
        }
        
        const std::vector<unique_ptr<CPACSProfileGeometry> >& CPACSFuselageProfiles::GetFuselageProfiles() const
        {
            return m_fuselageProfiles;
        }
        
        std::vector<unique_ptr<CPACSProfileGeometry> >& CPACSFuselageProfiles::GetFuselageProfiles()
        {
            return m_fuselageProfiles;
        }
        
    }
}
