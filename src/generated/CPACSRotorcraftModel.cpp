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

#include "CPACSRotorcraftModel.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSRotorcraftModel::CPACSRotorcraftModel(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr) {}
        
        CPACSRotorcraftModel::~CPACSRotorcraftModel()
        {
            if (m_uidMgr) m_uidMgr->UnregisterObject(m_uID);
        }
        
        CTiglUIDManager& CPACSRotorcraftModel::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSRotorcraftModel::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSRotorcraftModel::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
            }
            
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            }
            else {
                LOG(ERROR) << "Required element name is missing at xpath " << xpath;
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            }
            
            // read element fuselages
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fuselages")) {
                m_fuselages = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
                try {
                    m_fuselages->ReadCPACS(tixiHandle, xpath + "/fuselages");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read fuselages at xpath " << xpath << ": " << e.what();
                    m_fuselages = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read fuselages at xpath " << xpath << ": " << e.getError();
                    m_fuselages = boost::none;
                }
            }
            
            // read element wings
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/wings")) {
                m_wings = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
                try {
                    m_wings->ReadCPACS(tixiHandle, xpath + "/wings");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read wings at xpath " << xpath << ": " << e.what();
                    m_wings = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read wings at xpath " << xpath << ": " << e.getError();
                    m_wings = boost::none;
                }
            }
            
            // read element rotors
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotors")) {
                m_rotors = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
                try {
                    m_rotors->ReadCPACS(tixiHandle, xpath + "/rotors");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read rotors at xpath " << xpath << ": " << e.what();
                    m_rotors = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read rotors at xpath " << xpath << ": " << e.getError();
                    m_rotors = boost::none;
                }
            }
            
            // read element rotorBlades
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotorBlades")) {
                m_rotorBlades = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
                try {
                    m_rotorBlades->ReadCPACS(tixiHandle, xpath + "/rotorBlades");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read rotorBlades at xpath " << xpath << ": " << e.what();
                    m_rotorBlades = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read rotorBlades at xpath " << xpath << ": " << e.getError();
                    m_rotorBlades = boost::none;
                }
            }
            
            if (m_uidMgr) m_uidMgr->RegisterObject(m_uID, *this);
        }
        
        void CPACSRotorcraftModel::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
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
            
            // write element fuselages
            if (m_fuselages) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fuselages");
                m_fuselages->WriteCPACS(tixiHandle, xpath + "/fuselages");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/fuselages")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/fuselages");
                }
            }
            
            // write element wings
            if (m_wings) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/wings");
                m_wings->WriteCPACS(tixiHandle, xpath + "/wings");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/wings")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/wings");
                }
            }
            
            // write element rotors
            if (m_rotors) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotors");
                m_rotors->WriteCPACS(tixiHandle, xpath + "/rotors");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotors")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/rotors");
                }
            }
            
            // write element rotorBlades
            if (m_rotorBlades) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotorBlades");
                m_rotorBlades->WriteCPACS(tixiHandle, xpath + "/rotorBlades");
            } else {
                if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotorBlades")) {
                    tixihelper::TixiRemoveElement(tixiHandle, xpath + "/rotorBlades");
                }
            }
            
        }
        
        const std::string& CPACSRotorcraftModel::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSRotorcraftModel::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                m_uidMgr->UnregisterObject(m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        const std::string& CPACSRotorcraftModel::GetName() const
        {
            return m_name;
        }
        
        void CPACSRotorcraftModel::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSRotorcraftModel::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSRotorcraftModel::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSRotorcraftModel::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const boost::optional<CCPACSFuselages>& CPACSRotorcraftModel::GetFuselages() const
        {
            return m_fuselages;
        }
        
        boost::optional<CCPACSFuselages>& CPACSRotorcraftModel::GetFuselages()
        {
            return m_fuselages;
        }
        
        const boost::optional<CCPACSWings>& CPACSRotorcraftModel::GetWings() const
        {
            return m_wings;
        }
        
        boost::optional<CCPACSWings>& CPACSRotorcraftModel::GetWings()
        {
            return m_wings;
        }
        
        const boost::optional<CCPACSRotors>& CPACSRotorcraftModel::GetRotors() const
        {
            return m_rotors;
        }
        
        boost::optional<CCPACSRotors>& CPACSRotorcraftModel::GetRotors()
        {
            return m_rotors;
        }
        
        const boost::optional<CCPACSRotorBlades>& CPACSRotorcraftModel::GetRotorBlades() const
        {
            return m_rotorBlades;
        }
        
        boost::optional<CCPACSRotorBlades>& CPACSRotorcraftModel::GetRotorBlades()
        {
            return m_rotorBlades;
        }
        
    }
}
