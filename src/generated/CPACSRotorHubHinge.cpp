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
#include "CCPACSRotorHinges.h"
#include "CPACSRotorHubHinge.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSRotorHubHinge::CPACSRotorHubHinge(CCPACSRotorHinges* parent, CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr), 
            m_transformation(m_uidMgr)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSRotorHubHinge::~CPACSRotorHubHinge()
        {
            if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        }
        
        CCPACSRotorHinges* CPACSRotorHubHinge::GetParent() const
        {
            return m_parent;
        }
        
        CTiglUIDManager& CPACSRotorHubHinge::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSRotorHubHinge::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSRotorHubHinge::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
                if (m_uID.empty()) {
                    LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
            }
            
            // read element name
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
                if (m_name->empty()) {
                    LOG(WARNING) << "Optional element name is present but empty at xpath " << xpath;
                }
            }
            
            // read element description
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
                if (m_description->empty()) {
                    LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
                }
            }
            
            // read element transformation
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
                m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
            }
            else {
                LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
            }
            
            // read element type
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/type")) {
                m_type = stringToCPACSRotorHubHinge_type(tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/type"));
            }
            else {
                LOG(ERROR) << "Required element type is missing at xpath " << xpath;
            }
            
            // read element neutralPosition
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/neutralPosition")) {
                m_neutralPosition = tixi::TixiGetElement<double>(tixiHandle, xpath + "/neutralPosition");
            }
            
            // read element staticStiffness
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/staticStiffness")) {
                m_staticStiffness = tixi::TixiGetElement<double>(tixiHandle, xpath + "/staticStiffness");
            }
            
            // read element dynamicStiffness
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/dynamicStiffness")) {
                m_dynamicStiffness = tixi::TixiGetElement<double>(tixiHandle, xpath + "/dynamicStiffness");
            }
            
            // read element damping
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/damping")) {
                m_damping = tixi::TixiGetElement<double>(tixiHandle, xpath + "/damping");
            }
            
            if (m_uidMgr) m_uidMgr->RegisterObject(m_uID, *this);
        }
        
        void CPACSRotorHubHinge::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element name
            if (m_name) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
                tixi::TixiSaveElement(tixiHandle, xpath + "/name", *m_name);
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/name");
                }
            }
            
            // write element description
            if (m_description) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
                }
            }
            
            // write element transformation
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
            m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");
            
            // write element type
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/type");
            tixi::TixiSaveElement(tixiHandle, xpath + "/type", CPACSRotorHubHinge_typeToString(m_type));
            
            // write element neutralPosition
            if (m_neutralPosition) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/neutralPosition");
                tixi::TixiSaveElement(tixiHandle, xpath + "/neutralPosition", *m_neutralPosition);
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/neutralPosition")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/neutralPosition");
                }
            }
            
            // write element staticStiffness
            if (m_staticStiffness) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/staticStiffness");
                tixi::TixiSaveElement(tixiHandle, xpath + "/staticStiffness", *m_staticStiffness);
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/staticStiffness")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/staticStiffness");
                }
            }
            
            // write element dynamicStiffness
            if (m_dynamicStiffness) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/dynamicStiffness");
                tixi::TixiSaveElement(tixiHandle, xpath + "/dynamicStiffness", *m_dynamicStiffness);
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/dynamicStiffness")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/dynamicStiffness");
                }
            }
            
            // write element damping
            if (m_damping) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/damping");
                tixi::TixiSaveElement(tixiHandle, xpath + "/damping", *m_damping);
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/damping")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/damping");
                }
            }
            
        }
        
        const std::string& CPACSRotorHubHinge::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSRotorHubHinge::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                m_uidMgr->TryUnregisterObject(m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        const boost::optional<std::string>& CPACSRotorHubHinge::GetName() const
        {
            return m_name;
        }
        
        void CPACSRotorHubHinge::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        void CPACSRotorHubHinge::SetName(const boost::optional<std::string>& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSRotorHubHinge::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSRotorHubHinge::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSRotorHubHinge::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const CCPACSTransformation& CPACSRotorHubHinge::GetTransformation() const
        {
            return m_transformation;
        }
        
        CCPACSTransformation& CPACSRotorHubHinge::GetTransformation()
        {
            return m_transformation;
        }
        
        const CPACSRotorHubHinge_type& CPACSRotorHubHinge::GetType() const
        {
            return m_type;
        }
        
        void CPACSRotorHubHinge::SetType(const CPACSRotorHubHinge_type& value)
        {
            m_type = value;
        }
        
        const boost::optional<double>& CPACSRotorHubHinge::GetNeutralPosition() const
        {
            return m_neutralPosition;
        }
        
        void CPACSRotorHubHinge::SetNeutralPosition(const double& value)
        {
            m_neutralPosition = value;
        }
        
        void CPACSRotorHubHinge::SetNeutralPosition(const boost::optional<double>& value)
        {
            m_neutralPosition = value;
        }
        
        const boost::optional<double>& CPACSRotorHubHinge::GetStaticStiffness() const
        {
            return m_staticStiffness;
        }
        
        void CPACSRotorHubHinge::SetStaticStiffness(const double& value)
        {
            m_staticStiffness = value;
        }
        
        void CPACSRotorHubHinge::SetStaticStiffness(const boost::optional<double>& value)
        {
            m_staticStiffness = value;
        }
        
        const boost::optional<double>& CPACSRotorHubHinge::GetDynamicStiffness() const
        {
            return m_dynamicStiffness;
        }
        
        void CPACSRotorHubHinge::SetDynamicStiffness(const double& value)
        {
            m_dynamicStiffness = value;
        }
        
        void CPACSRotorHubHinge::SetDynamicStiffness(const boost::optional<double>& value)
        {
            m_dynamicStiffness = value;
        }
        
        const boost::optional<double>& CPACSRotorHubHinge::GetDamping() const
        {
            return m_damping;
        }
        
        void CPACSRotorHubHinge::SetDamping(const double& value)
        {
            m_damping = value;
        }
        
        void CPACSRotorHubHinge::SetDamping(const boost::optional<double>& value)
        {
            m_damping = value;
        }
        
    }
}
