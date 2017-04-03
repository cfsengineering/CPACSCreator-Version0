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
#include "CCPACSWingRibsDefinitions.h"
#include "CPACSWingRibsDefinition.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSWingRibsDefinition::CPACSWingRibsDefinition(CCPACSWingRibsDefinitions* parent) :
            m_ribCrossSection(reinterpret_cast<CCPACSWingRibsDefinition*>(this))
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSWingRibsDefinition::~CPACSWingRibsDefinition() {}
        
        CCPACSWingRibsDefinitions* CPACSWingRibsDefinition::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSWingRibsDefinition::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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
            
            // read element ribCrossSection
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribCrossSection")) {
                m_ribCrossSection.ReadCPACS(tixiHandle, xpath + "/ribCrossSection");
            }
            else {
                LOG(ERROR) << "Required element ribCrossSection is missing at xpath " << xpath;
            }
            
            // read element ribsPositioning
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribsPositioning")) {
                m_ribsPositioning_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibsDefinition*>(this));
                try {
                    m_ribsPositioning_choice1->ReadCPACS(tixiHandle, xpath + "/ribsPositioning");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read ribsPositioning at xpath << " << xpath << ": " << e.what();
                    m_ribsPositioning_choice1 = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read ribsPositioning at xpath << " << xpath << ": " << e.getError();
                    m_ribsPositioning_choice1 = boost::none;
                }
            }
            
            // read element ribExplicitPositioning
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribExplicitPositioning")) {
                m_ribExplicitPositioning_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibsDefinition*>(this));
                try {
                    m_ribExplicitPositioning_choice2->ReadCPACS(tixiHandle, xpath + "/ribExplicitPositioning");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read ribExplicitPositioning at xpath << " << xpath << ": " << e.what();
                    m_ribExplicitPositioning_choice2 = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read ribExplicitPositioning at xpath << " << xpath << ": " << e.getError();
                    m_ribExplicitPositioning_choice2 = boost::none;
                }
            }
            
        }
        
        void CPACSWingRibsDefinition::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element name
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            }
            
            // write element ribCrossSection
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribCrossSection");
            m_ribCrossSection.WriteCPACS(tixiHandle, xpath + "/ribCrossSection");
            
            // write element ribsPositioning
            if (m_ribsPositioning_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribsPositioning");
                m_ribsPositioning_choice1->WriteCPACS(tixiHandle, xpath + "/ribsPositioning");
            }
            
            // write element ribExplicitPositioning
            if (m_ribExplicitPositioning_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribExplicitPositioning");
                m_ribExplicitPositioning_choice2->WriteCPACS(tixiHandle, xpath + "/ribExplicitPositioning");
            }
            
        }
        
        const std::string& CPACSWingRibsDefinition::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSWingRibsDefinition::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        const std::string& CPACSWingRibsDefinition::GetName() const
        {
            return m_name;
        }
        
        void CPACSWingRibsDefinition::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        bool CPACSWingRibsDefinition::HasDescription() const
        {
            return static_cast<bool>(m_description);
        }
        
        const std::string& CPACSWingRibsDefinition::GetDescription() const
        {
            return *m_description;
        }
        
        void CPACSWingRibsDefinition::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        const CCPACSWingRibCrossSection& CPACSWingRibsDefinition::GetRibCrossSection() const
        {
            return m_ribCrossSection;
        }
        
        CCPACSWingRibCrossSection& CPACSWingRibsDefinition::GetRibCrossSection()
        {
            return m_ribCrossSection;
        }
        
        bool CPACSWingRibsDefinition::HasRibsPositioning_choice1() const
        {
            return static_cast<bool>(m_ribsPositioning_choice1);
        }
        
        const CCPACSWingRibsPositioning& CPACSWingRibsDefinition::GetRibsPositioning_choice1() const
        {
            return *m_ribsPositioning_choice1;
        }
        
        CCPACSWingRibsPositioning& CPACSWingRibsDefinition::GetRibsPositioning_choice1()
        {
            return *m_ribsPositioning_choice1;
        }
        
        bool CPACSWingRibsDefinition::HasRibExplicitPositioning_choice2() const
        {
            return static_cast<bool>(m_ribExplicitPositioning_choice2);
        }
        
        const CPACSWingRibExplicitPositioning& CPACSWingRibsDefinition::GetRibExplicitPositioning_choice2() const
        {
            return *m_ribExplicitPositioning_choice2;
        }
        
        CPACSWingRibExplicitPositioning& CPACSWingRibsDefinition::GetRibExplicitPositioning_choice2()
        {
            return *m_ribExplicitPositioning_choice2;
        }
        
    }
}
