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
#include "CCPACSWingSparPositions.h"
#include "CPACSSparPosition.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSSparPosition::CPACSSparPosition(CCPACSWingSparPositions* parent)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSSparPosition::~CPACSSparPosition() {}
        
        CCPACSWingSparPositions* CPACSSparPosition::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSSparPosition::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
            }
            
            // read element xsi
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/xsi")) {
                m_xsi = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/xsi");
            }
            else {
                LOG(ERROR) << "Required element xsi is missing at xpath " << xpath;
            }
            
            // read element eta
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/eta")) {
                m_eta_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/eta");
            }
            
            // read element elementUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/elementUID")) {
                m_elementUID_choice2 = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/elementUID");
            }
            
        }
        
        void CPACSSparPosition::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element xsi
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/xsi");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/xsi", m_xsi);
            
            // write element eta
            if (m_eta_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/eta");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/eta", *m_eta_choice1);
            }
            
            // write element elementUID
            if (m_elementUID_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/elementUID");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/elementUID", *m_elementUID_choice2);
            }
            
        }
        
        const std::string& CPACSSparPosition::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSSparPosition::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const double& CPACSSparPosition::GetXsi() const
        {
            return m_xsi;
        }
        
        void CPACSSparPosition::SetXsi(const double& value)
        {
            m_xsi = value;
        }
        
        bool CPACSSparPosition::HasEta_choice1() const
        {
            return static_cast<bool>(m_eta_choice1);
        }
        
        const double& CPACSSparPosition::GetEta_choice1() const
        {
            return *m_eta_choice1;
        }
        
        void CPACSSparPosition::SetEta_choice1(const double& value)
        {
            m_eta_choice1 = value;
        }
        
        bool CPACSSparPosition::HasElementUID_choice2() const
        {
            return static_cast<bool>(m_elementUID_choice2);
        }
        
        const std::string& CPACSSparPosition::GetElementUID_choice2() const
        {
            return *m_elementUID_choice2;
        }
        
        void CPACSSparPosition::SetElementUID_choice2(const std::string& value)
        {
            m_elementUID_choice2 = value;
        }
        
    }
}
