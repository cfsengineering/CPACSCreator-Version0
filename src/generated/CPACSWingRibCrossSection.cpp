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
#include "CCPACSWingRibsDefinition.h"
#include "CPACSWingRibCrossSection.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSWingRibCrossSection::CPACSWingRibCrossSection(CCPACSWingRibsDefinition* parent)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSWingRibCrossSection::~CPACSWingRibCrossSection() {}
        
        CCPACSWingRibsDefinition* CPACSWingRibCrossSection::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSWingRibCrossSection::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element material
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/material")) {
                m_material.ReadCPACS(tixiHandle, xpath + "/material");
            }
            else {
                LOG(ERROR) << "Required element material is missing at xpath " << xpath;
            }
            
            // read element ribRotation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribRotation")) {
                m_ribRotation = boost::in_place();
                try {
                    m_ribRotation->ReadCPACS(tixiHandle, xpath + "/ribRotation");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read ribRotation at xpath << " << xpath << ": " << e.what();
                    m_ribRotation = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read ribRotation at xpath << " << xpath << ": " << e.getError();
                    m_ribRotation = boost::none;
                }
            }
            
            // read element ribCell
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ribCell")) {
                m_ribCell = boost::in_place();
                try {
                    m_ribCell->ReadCPACS(tixiHandle, xpath + "/ribCell");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read ribCell at xpath << " << xpath << ": " << e.what();
                    m_ribCell = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read ribCell at xpath << " << xpath << ": " << e.getError();
                    m_ribCell = boost::none;
                }
            }
            
            // read element upperCap
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/upperCap")) {
                m_upperCap = boost::in_place();
                try {
                    m_upperCap->ReadCPACS(tixiHandle, xpath + "/upperCap");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read upperCap at xpath << " << xpath << ": " << e.what();
                    m_upperCap = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read upperCap at xpath << " << xpath << ": " << e.getError();
                    m_upperCap = boost::none;
                }
            }
            
            // read element lowerCap
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/lowerCap")) {
                m_lowerCap = boost::in_place();
                try {
                    m_lowerCap->ReadCPACS(tixiHandle, xpath + "/lowerCap");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read lowerCap at xpath << " << xpath << ": " << e.what();
                    m_lowerCap = boost::none;
                } catch(const CTiglError& e) {
                    LOG(ERROR) << "Failed to read lowerCap at xpath << " << xpath << ": " << e.getError();
                    m_lowerCap = boost::none;
                }
            }
            
        }
        
        void CPACSWingRibCrossSection::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element material
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/material");
            m_material.WriteCPACS(tixiHandle, xpath + "/material");
            
            // write element ribRotation
            if (m_ribRotation) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribRotation");
                m_ribRotation->WriteCPACS(tixiHandle, xpath + "/ribRotation");
            }
            
            // write element ribCell
            if (m_ribCell) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribCell");
                m_ribCell->WriteCPACS(tixiHandle, xpath + "/ribCell");
            }
            
            // write element upperCap
            if (m_upperCap) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/upperCap");
                m_upperCap->WriteCPACS(tixiHandle, xpath + "/upperCap");
            }
            
            // write element lowerCap
            if (m_lowerCap) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/lowerCap");
                m_lowerCap->WriteCPACS(tixiHandle, xpath + "/lowerCap");
            }
            
        }
        
        const CCPACSMaterial& CPACSWingRibCrossSection::GetMaterial() const
        {
            return m_material;
        }
        
        CCPACSMaterial& CPACSWingRibCrossSection::GetMaterial()
        {
            return m_material;
        }
        
        bool CPACSWingRibCrossSection::HasRibRotation() const
        {
            return static_cast<bool>(m_ribRotation);
        }
        
        const CPACSPointX& CPACSWingRibCrossSection::GetRibRotation() const
        {
            return *m_ribRotation;
        }
        
        CPACSPointX& CPACSWingRibCrossSection::GetRibRotation()
        {
            return *m_ribRotation;
        }
        
        bool CPACSWingRibCrossSection::HasRibCell() const
        {
            return static_cast<bool>(m_ribCell);
        }
        
        const CPACSWingRibCell& CPACSWingRibCrossSection::GetRibCell() const
        {
            return *m_ribCell;
        }
        
        CPACSWingRibCell& CPACSWingRibCrossSection::GetRibCell()
        {
            return *m_ribCell;
        }
        
        bool CPACSWingRibCrossSection::HasUpperCap() const
        {
            return static_cast<bool>(m_upperCap);
        }
        
        const CPACSCap& CPACSWingRibCrossSection::GetUpperCap() const
        {
            return *m_upperCap;
        }
        
        CPACSCap& CPACSWingRibCrossSection::GetUpperCap()
        {
            return *m_upperCap;
        }
        
        bool CPACSWingRibCrossSection::HasLowerCap() const
        {
            return static_cast<bool>(m_lowerCap);
        }
        
        const CPACSCap& CPACSWingRibCrossSection::GetLowerCap() const
        {
            return *m_lowerCap;
        }
        
        CPACSCap& CPACSWingRibCrossSection::GetLowerCap()
        {
            return *m_lowerCap;
        }
        
    }
}
