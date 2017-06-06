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

#include "CPACSPositioning.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSPositioning::CPACSPositioning(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr), 
            m_length(0), 
            m_sweepAngle(0), 
            m_dihedralAngle(0) {}
        
        CPACSPositioning::~CPACSPositioning()
        {
            if (m_uidMgr && m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
        }
        
        CTiglUIDManager& CPACSPositioning::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSPositioning::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSPositioning::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
                if (m_uID->empty()) {
                    LOG(ERROR) << "Optional attribute uID is present but empty at xpath " << xpath;
                }
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
            
            // read element length
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/length")) {
                m_length = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/length");
            }
            else {
                LOG(ERROR) << "Required element length is missing at xpath " << xpath;
            }
            
            // read element sweepAngle
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/sweepAngle")) {
                m_sweepAngle = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/sweepAngle");
            }
            else {
                LOG(ERROR) << "Required element sweepAngle is missing at xpath " << xpath;
            }
            
            // read element dihedralAngle
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/dihedralAngle")) {
                m_dihedralAngle = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/dihedralAngle");
            }
            else {
                LOG(ERROR) << "Required element dihedralAngle is missing at xpath " << xpath;
            }
            
            // read element fromSectionUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fromSectionUID")) {
                m_fromSectionUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/fromSectionUID");
                if (m_fromSectionUID->empty()) {
                    LOG(ERROR) << "Optional element fromSectionUID is present but empty at xpath " << xpath;
                }
            }
            
            // read element toSectionUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/toSectionUID")) {
                m_toSectionUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/toSectionUID");
                if (m_toSectionUID.empty()) {
                    LOG(ERROR) << "Required element toSectionUID is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element toSectionUID is missing at xpath " << xpath;
            }
            
            if (m_uidMgr && m_uID) m_uidMgr->RegisterObject(*m_uID, *this);
        }
        
        void CPACSPositioning::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
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
            
            // write element length
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/length");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/length", m_length);
            
            // write element sweepAngle
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sweepAngle");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/sweepAngle", m_sweepAngle);
            
            // write element dihedralAngle
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/dihedralAngle");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/dihedralAngle", m_dihedralAngle);
            
            // write element fromSectionUID
            if (m_fromSectionUID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fromSectionUID");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/fromSectionUID", *m_fromSectionUID);
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fromSectionUID")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/fromSectionUID");
                }
            }
            
            // write element toSectionUID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/toSectionUID");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/toSectionUID", m_toSectionUID);
            
        }
        
        const boost::optional<std::string>& CPACSPositioning::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSPositioning::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                if (m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        void CPACSPositioning::SetUID(const boost::optional<std::string>& value)
        {
            if (m_uidMgr) {
                if (m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
                if (value) m_uidMgr->RegisterObject(*value, *this);
            }
            m_uID = value;
        }
        
        const std::string& CPACSPositioning::GetName() const
        {
            return m_name;
        }
        
        void CPACSPositioning::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSPositioning::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSPositioning::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSPositioning::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const double& CPACSPositioning::GetLength() const
        {
            return m_length;
        }
        
        void CPACSPositioning::SetLength(const double& value)
        {
            m_length = value;
        }
        
        const double& CPACSPositioning::GetSweepAngle() const
        {
            return m_sweepAngle;
        }
        
        void CPACSPositioning::SetSweepAngle(const double& value)
        {
            m_sweepAngle = value;
        }
        
        const double& CPACSPositioning::GetDihedralAngle() const
        {
            return m_dihedralAngle;
        }
        
        void CPACSPositioning::SetDihedralAngle(const double& value)
        {
            m_dihedralAngle = value;
        }
        
        const boost::optional<std::string>& CPACSPositioning::GetFromSectionUID() const
        {
            return m_fromSectionUID;
        }
        
        void CPACSPositioning::SetFromSectionUID(const std::string& value)
        {
            m_fromSectionUID = value;
        }
        
        void CPACSPositioning::SetFromSectionUID(const boost::optional<std::string>& value)
        {
            m_fromSectionUID = value;
        }
        
        const std::string& CPACSPositioning::GetToSectionUID() const
        {
            return m_toSectionUID;
        }
        
        void CPACSPositioning::SetToSectionUID(const std::string& value)
        {
            m_toSectionUID = value;
        }
        
    }
}
