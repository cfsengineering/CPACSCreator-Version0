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
#include "CCPACSRotors.h"
#include "CPACSRotor.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSRotor::CPACSRotor(CCPACSRotors* parent, CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr), 
            m_transformation(m_uidMgr), 
            m_rotorHub(reinterpret_cast<CCPACSRotor*>(this), m_uidMgr)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSRotor::~CPACSRotor()
        {
            if (m_uidMgr) m_uidMgr->UnregisterObject(m_uID);
        }
        
        CCPACSRotors* CPACSRotor::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSRotor::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
            }
            
            // read attribute symmetry
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
                m_symmetry = stringToTiglSymmetryAxis(tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "symmetry"));
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
            
            // read element parentUID
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
                m_parentUID = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/parentUID");
            }
            
            // read element type
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/type")) {
                m_type = stringToCPACSRotor_type(tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/type"));
            }
            
            // read element nominalRotationsPerMinute
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/nominalRotationsPerMinute")) {
                m_nominalRotationsPerMinute = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/nominalRotationsPerMinute");
            }
            
            // read element transformation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
                m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
            }
            else {
                LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
            }
            
            // read element rotorHub
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotorHub")) {
                m_rotorHub.ReadCPACS(tixiHandle, xpath + "/rotorHub");
            }
            else {
                LOG(ERROR) << "Required element rotorHub is missing at xpath " << xpath;
            }
            
            if (m_uidMgr) m_uidMgr->RegisterObject(m_uID, *this);
        }
        
        void CPACSRotor::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write attribute symmetry
            if (m_symmetry) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/symmetry");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "symmetry", TiglSymmetryAxisToString(*m_symmetry));
            }
            
            // write element name
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            }
            
            // write element parentUID
            if (m_parentUID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/parentUID");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/parentUID", *m_parentUID);
            }
            
            // write element type
            if (m_type) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/type");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/type", CPACSRotor_typeToString(*m_type));
            }
            
            // write element nominalRotationsPerMinute
            if (m_nominalRotationsPerMinute) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/nominalRotationsPerMinute");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/nominalRotationsPerMinute", *m_nominalRotationsPerMinute);
            }
            
            // write element transformation
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
            m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");
            
            // write element rotorHub
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotorHub");
            m_rotorHub.WriteCPACS(tixiHandle, xpath + "/rotorHub");
            
        }
        
        const std::string& CPACSRotor::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSRotor::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                m_uidMgr->UnregisterObject(m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        const boost::optional<TiglSymmetryAxis>& CPACSRotor::GetSymmetry() const
        {
            return m_symmetry;
        }
        
        void CPACSRotor::SetSymmetry(const TiglSymmetryAxis& value)
        {
            m_symmetry = value;
        }
        
        void CPACSRotor::SetSymmetry(const boost::optional<TiglSymmetryAxis>& value)
        {
            m_symmetry = value;
        }
        
        const std::string& CPACSRotor::GetName() const
        {
            return m_name;
        }
        
        void CPACSRotor::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSRotor::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSRotor::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSRotor::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const boost::optional<std::string>& CPACSRotor::GetParentUID() const
        {
            return m_parentUID;
        }
        
        void CPACSRotor::SetParentUID(const std::string& value)
        {
            m_parentUID = value;
        }
        
        void CPACSRotor::SetParentUID(const boost::optional<std::string>& value)
        {
            m_parentUID = value;
        }
        
        const boost::optional<CPACSRotor_type>& CPACSRotor::GetType() const
        {
            return m_type;
        }
        
        void CPACSRotor::SetType(const CPACSRotor_type& value)
        {
            m_type = value;
        }
        
        void CPACSRotor::SetType(const boost::optional<CPACSRotor_type>& value)
        {
            m_type = value;
        }
        
        const boost::optional<double>& CPACSRotor::GetNominalRotationsPerMinute() const
        {
            return m_nominalRotationsPerMinute;
        }
        
        void CPACSRotor::SetNominalRotationsPerMinute(const double& value)
        {
            m_nominalRotationsPerMinute = value;
        }
        
        void CPACSRotor::SetNominalRotationsPerMinute(const boost::optional<double>& value)
        {
            m_nominalRotationsPerMinute = value;
        }
        
        const CCPACSTransformation& CPACSRotor::GetTransformation() const
        {
            return m_transformation;
        }
        
        CCPACSTransformation& CPACSRotor::GetTransformation()
        {
            return m_transformation;
        }
        
        const CCPACSRotorHub& CPACSRotor::GetRotorHub() const
        {
            return m_rotorHub;
        }
        
        CCPACSRotorHub& CPACSRotor::GetRotorHub()
        {
            return m_rotorHub;
        }
        
    }
}
