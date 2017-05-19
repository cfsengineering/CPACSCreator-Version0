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

#include <CCPACSRotorcraftModel.h>
#include "CPACSRotorcraft.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSRotorcraft::CPACSRotorcraft(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr) {}
        
        CPACSRotorcraft::~CPACSRotorcraft() {}
        
        CTiglUIDManager& CPACSRotorcraft::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSRotorcraft::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSRotorcraft::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element model
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/model")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/model", m_models, m_uidMgr);
            }
            
        }
        
        void CPACSRotorcraft::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element model
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/model", m_models);
            
        }
        
        const std::vector<unique_ptr<CCPACSRotorcraftModel> >& CPACSRotorcraft::GetModels() const
        {
            return m_models;
        }
        
        std::vector<unique_ptr<CCPACSRotorcraftModel> >& CPACSRotorcraft::GetModels()
        {
            return m_models;
        }
        
    }
}
