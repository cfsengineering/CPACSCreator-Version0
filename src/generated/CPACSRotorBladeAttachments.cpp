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
#include <CCPACSRotorBladeAttachment.h>
#include "CCPACSRotorHub.h"
#include "CPACSRotorBladeAttachments.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSRotorBladeAttachments::CPACSRotorBladeAttachments(CCPACSRotorHub* parent)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSRotorBladeAttachments::~CPACSRotorBladeAttachments() {}
        
        CCPACSRotorHub* CPACSRotorBladeAttachments::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSRotorBladeAttachments::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element rotorBladeAttachment
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotorBladeAttachment")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/rotorBladeAttachment", m_rotorBladeAttachments, reinterpret_cast<CCPACSRotorBladeAttachments*>(this));
            }
            
        }
        
        void CPACSRotorBladeAttachments::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element rotorBladeAttachment
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/rotorBladeAttachment", m_rotorBladeAttachments);
            
        }
        
        const std::vector<unique_ptr<CCPACSRotorBladeAttachment> >& CPACSRotorBladeAttachments::GetRotorBladeAttachments() const
        {
            return m_rotorBladeAttachments;
        }
        
        std::vector<unique_ptr<CCPACSRotorBladeAttachment> >& CPACSRotorBladeAttachments::GetRotorBladeAttachments()
        {
            return m_rotorBladeAttachments;
        }
        
    }
}
