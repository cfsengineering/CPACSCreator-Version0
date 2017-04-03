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

#include "CPACSPointAbsRel.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSPointAbsRel::CPACSPointAbsRel(){}
        CPACSPointAbsRel::~CPACSPointAbsRel() {}
        
        void CPACSPointAbsRel::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            
            // read attribute refType
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "refType")) {
                m_refType = stringToECPACSTranslationType(tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "refType"));
            }
            
            // read element x
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/x")) {
                m_x = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/x");
            }
            
            // read element y
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/y")) {
                m_y = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/y");
            }
            
            // read element z
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/z")) {
                m_z = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/z");
            }
            
        }
        
        void CPACSPointAbsRel::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            if (m_uID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
            }
            
            // write attribute refType
            if (m_refType) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/refType");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "refType", ECPACSTranslationTypeToString(*m_refType));
            }
            
            // write element x
            if (m_x) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/x");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/x", *m_x);
            }
            
            // write element y
            if (m_y) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/y");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/y", *m_y);
            }
            
            // write element z
            if (m_z) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/z");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/z", *m_z);
            }
            
        }
        
        bool CPACSPointAbsRel::HasUID() const
        {
            return static_cast<bool>(m_uID);
        }
        
        const std::string& CPACSPointAbsRel::GetUID() const
        {
            return *m_uID;
        }
        
        void CPACSPointAbsRel::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        bool CPACSPointAbsRel::HasRefType() const
        {
            return static_cast<bool>(m_refType);
        }
        
        const ECPACSTranslationType& CPACSPointAbsRel::GetRefType() const
        {
            return *m_refType;
        }
        
        void CPACSPointAbsRel::SetRefType(const ECPACSTranslationType& value)
        {
            m_refType = value;
        }
        
        bool CPACSPointAbsRel::HasX() const
        {
            return static_cast<bool>(m_x);
        }
        
        const double& CPACSPointAbsRel::GetX() const
        {
            return *m_x;
        }
        
        void CPACSPointAbsRel::SetX(const double& value)
        {
            m_x = value;
        }
        
        bool CPACSPointAbsRel::HasY() const
        {
            return static_cast<bool>(m_y);
        }
        
        const double& CPACSPointAbsRel::GetY() const
        {
            return *m_y;
        }
        
        void CPACSPointAbsRel::SetY(const double& value)
        {
            m_y = value;
        }
        
        bool CPACSPointAbsRel::HasZ() const
        {
            return static_cast<bool>(m_z);
        }
        
        const double& CPACSPointAbsRel::GetZ() const
        {
            return *m_z;
        }
        
        void CPACSPointAbsRel::SetZ(const double& value)
        {
            m_z = value;
        }
        
    }
}
