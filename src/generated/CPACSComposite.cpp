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

#include "CPACSComposite.h"
#include "CPACSCompositeLayer.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSComposite::CPACSComposite(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr) {}
        
        CPACSComposite::~CPACSComposite()
        {
            if (m_uidMgr && m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
        }
        
        CTiglUIDManager& CPACSComposite::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSComposite::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSComposite::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
                if (m_uID->empty()) {
                    LOG(WARNING) << "Optional attribute uID is present but empty at xpath " << xpath;
                }
            }
            
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
                if (m_name.empty()) {
                    LOG(WARNING) << "Required element name is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element name is missing at xpath " << xpath;
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
                if (m_description->empty()) {
                    LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
                }
            }
            
            // read element offset
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/offset")) {
                m_offset = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/offset");
            }
            
            // read element compositeLayer
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/compositeLayer")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/compositeLayer", m_compositeLayers);
            }
            
            if (m_uidMgr && m_uID) m_uidMgr->RegisterObject(*m_uID, *this);
        }
        
        void CPACSComposite::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            if (m_uID) {
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
            } else {
                if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                    tixihelper::TixiRemoveAttribute(tixiHandle, xpath, "uID");
                }
            }
            
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
            
            // write element offset
            if (m_offset) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/offset");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/offset", *m_offset);
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/offset")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/offset");
                }
            }
            
            // write element compositeLayer
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/compositeLayer", m_compositeLayers);
            
        }
        
        const boost::optional<std::string>& CPACSComposite::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSComposite::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                if (m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        void CPACSComposite::SetUID(const boost::optional<std::string>& value)
        {
            if (m_uidMgr) {
                if (m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
                if (value) m_uidMgr->RegisterObject(*value, *this);
            }
            m_uID = value;
        }
        
        const std::string& CPACSComposite::GetName() const
        {
            return m_name;
        }
        
        void CPACSComposite::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSComposite::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSComposite::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSComposite::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const boost::optional<double>& CPACSComposite::GetOffset() const
        {
            return m_offset;
        }
        
        void CPACSComposite::SetOffset(const double& value)
        {
            m_offset = value;
        }
        
        void CPACSComposite::SetOffset(const boost::optional<double>& value)
        {
            m_offset = value;
        }
        
        const std::vector<unique_ptr<CPACSCompositeLayer> >& CPACSComposite::GetCompositeLayers() const
        {
            return m_compositeLayers;
        }
        
        std::vector<unique_ptr<CPACSCompositeLayer> >& CPACSComposite::GetCompositeLayers()
        {
            return m_compositeLayers;
        }
        
    }
}
