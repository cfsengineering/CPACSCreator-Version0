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

#pragma once

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSFuselageSectionElements.h>
#include <CCPACSTransformation.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
    class CTiglUIDManager;
    
    namespace generated
    {
        // This class is used in:
        // CPACSFuselageSections
        
        // generated from /xsd:schema/xsd:complexType[366]
        class CPACSFuselageSection
        {
        public:
            TIGL_EXPORT CPACSFuselageSection(CTiglUIDManager* uidMgr);
            TIGL_EXPORT virtual ~CPACSFuselageSection();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::string& GetUID() const;
            TIGL_EXPORT virtual void SetUID(const std::string& value);
            
            TIGL_EXPORT virtual const std::string& GetName() const;
            TIGL_EXPORT virtual void SetName(const std::string& value);
            
            TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
            TIGL_EXPORT virtual void SetDescription(const std::string& value);
            TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);
            
            TIGL_EXPORT virtual const CCPACSTransformation& GetTransformation() const;
            TIGL_EXPORT virtual CCPACSTransformation& GetTransformation();
            
            TIGL_EXPORT virtual const CCPACSFuselageSectionElements& GetElements() const;
            TIGL_EXPORT virtual CCPACSFuselageSectionElements& GetElements();
            
        protected:
            CTiglUIDManager* m_uidMgr;
            
            std::string                   m_uID;
            std::string                   m_name;
            boost::optional<std::string>  m_description;
            CCPACSTransformation          m_transformation;
            CCPACSFuselageSectionElements m_elements;
            
        private:
            #ifdef HAVE_CPP11
            CPACSFuselageSection(const CPACSFuselageSection&) = delete;
            CPACSFuselageSection& operator=(const CPACSFuselageSection&) = delete;
            
            CPACSFuselageSection(CPACSFuselageSection&&) = delete;
            CPACSFuselageSection& operator=(CPACSFuselageSection&&) = delete;
            #else
            CPACSFuselageSection(const CPACSFuselageSection&);
            CPACSFuselageSection& operator=(const CPACSFuselageSection&);
            #endif
        };
    }
    
    // CPACSFuselageSection is customized, use type CCPACSFuselageSection directly
}
