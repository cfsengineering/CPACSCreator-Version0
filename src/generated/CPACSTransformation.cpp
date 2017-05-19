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

#include "CPACSTransformation.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSTransformation::CPACSTransformation(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr) {}
        
        CPACSTransformation::~CPACSTransformation()
        {
            if (m_uidMgr && m_uID) m_uidMgr->UnregisterObject(*m_uID);
        }
        
        CTiglUIDManager& CPACSTransformation::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSTransformation::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSTransformation::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            
            // read element scaling
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/scaling")) {
                m_scaling = boost::in_place(m_uidMgr);
                try {
                    m_scaling->ReadCPACS(tixiHandle, xpath + "/scaling");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read scaling at xpath " << xpath << ": " << e.what();
                    m_scaling = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read scaling at xpath " << xpath << ": " << e.getError();
                    m_scaling = boost::none;
                }
            }
            
            // read element rotation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotation")) {
                m_rotation = boost::in_place(m_uidMgr);
                try {
                    m_rotation->ReadCPACS(tixiHandle, xpath + "/rotation");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read rotation at xpath " << xpath << ": " << e.what();
                    m_rotation = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read rotation at xpath " << xpath << ": " << e.getError();
                    m_rotation = boost::none;
                }
            }
            
            // read element translation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/translation")) {
                m_translation = boost::in_place(m_uidMgr);
                try {
                    m_translation->ReadCPACS(tixiHandle, xpath + "/translation");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read translation at xpath " << xpath << ": " << e.what();
                    m_translation = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read translation at xpath " << xpath << ": " << e.getError();
                    m_translation = boost::none;
                }
            }
            
            if (m_uidMgr && m_uID) m_uidMgr->RegisterObject(*m_uID, *this);
        }
        
        void CPACSTransformation::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            if (m_uID) {
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
            } else {
                if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                    tixihelper::TixiRemoveAttribute(tixiHandle, xpath, "uID");
                }
            }
            
            // write element scaling
            if (m_scaling) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/scaling");
                m_scaling->WriteCPACS(tixiHandle, xpath + "/scaling");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/scaling")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/scaling");
                }
            }
            
            // write element rotation
            if (m_rotation) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotation");
                m_rotation->WriteCPACS(tixiHandle, xpath + "/rotation");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotation")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/rotation");
                }
            }
            
            // write element translation
            if (m_translation) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/translation");
                m_translation->WriteCPACS(tixiHandle, xpath + "/translation");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/translation")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/translation");
                }
            }
            
        }
        
        const boost::optional<std::string>& CPACSTransformation::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSTransformation::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                if (m_uID) m_uidMgr->UnregisterObject(*m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        void CPACSTransformation::SetUID(const boost::optional<std::string>& value)
        {
            if (m_uidMgr) {
                if (m_uID) m_uidMgr->UnregisterObject(*m_uID);
                if (value) m_uidMgr->RegisterObject(*value, *this);
            }
            m_uID = value;
        }
        
        const boost::optional<CCPACSPoint>& CPACSTransformation::GetScaling() const
        {
            return m_scaling;
        }
        
        boost::optional<CCPACSPoint>& CPACSTransformation::GetScaling()
        {
            return m_scaling;
        }
        
        const boost::optional<CCPACSPoint>& CPACSTransformation::GetRotation() const
        {
            return m_rotation;
        }
        
        boost::optional<CCPACSPoint>& CPACSTransformation::GetRotation()
        {
            return m_rotation;
        }
        
        const boost::optional<CCPACSPointAbsRel>& CPACSTransformation::GetTranslation() const
        {
            return m_translation;
        }
        
        boost::optional<CCPACSPointAbsRel>& CPACSTransformation::GetTranslation()
        {
            return m_translation;
        }
        
    }
}
