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

#include "CPACSWingElement.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSWingElement::CPACSWingElement(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr), 
            m_transformation(m_uidMgr) {}
        
        CPACSWingElement::~CPACSWingElement()
        {
            if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        }
        
        CTiglUIDManager& CPACSWingElement::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSWingElement::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSWingElement::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
                if (m_uID.empty()) {
                    LOG(ERROR) << "Required attribute uID is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
            }
            
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
                if (m_name.empty()) {
                    LOG(ERROR) << "Required element name is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element name is missing at xpath " << xpath;
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
                if (m_description->empty()) {
                    LOG(ERROR) << "Optional element description is present but empty at xpath " << xpath;
                }
            }
            
            // read element airfoilUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/airfoilUID")) {
                m_airfoilUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/airfoilUID");
                if (m_airfoilUID.empty()) {
                    LOG(ERROR) << "Required element airfoilUID is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element airfoilUID is missing at xpath " << xpath;
            }
            
            // read element transformation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
                m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
            }
            else {
                LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
            }
            
            if (m_uidMgr) m_uidMgr->RegisterObject(m_uID, *this);
        }
        
        void CPACSWingElement::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element name
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/description");
                }
            }
            
            // write element airfoilUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/airfoilUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/airfoilUID", m_airfoilUID);
            
            // write element transformation
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
            m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");
            
        }
        
        const std::string& CPACSWingElement::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSWingElement::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                m_uidMgr->TryUnregisterObject(m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        const std::string& CPACSWingElement::GetName() const
        {
            return m_name;
        }
        
        void CPACSWingElement::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSWingElement::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSWingElement::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSWingElement::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const std::string& CPACSWingElement::GetAirfoilUID() const
        {
            return m_airfoilUID;
        }
        
        void CPACSWingElement::SetAirfoilUID(const std::string& value)
        {
            m_airfoilUID = value;
        }
        
        const CCPACSTransformation& CPACSWingElement::GetTransformation() const
        {
            return m_transformation;
        }
        
        CCPACSTransformation& CPACSWingElement::GetTransformation()
        {
            return m_transformation;
        }
        
    }
}
