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

#include <tixi.h>
#include <string>
#include <vector>
#include "UniquePtr.h"
#include "tigl_internal.h"

namespace tigl
{
    class CCPACSFuselageSectionElement;
    
    namespace generated
    {
        // This class is used in:
        // CPACSFuselageSection
        
        // generated from /xsd:schema/xsd:complexType[362]
        class CPACSFuselageElements
        {
        public:
            TIGL_EXPORT CPACSFuselageElements();
            TIGL_EXPORT virtual ~CPACSFuselageElements();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSFuselageSectionElement> >& GetElements() const;
            TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSFuselageSectionElement> >& GetElements();
            
        protected:
            std::vector<unique_ptr<CCPACSFuselageSectionElement> > m_elements;
            
        private:
            #ifdef HAVE_CPP11
            CPACSFuselageElements(const CPACSFuselageElements&) = delete;
            CPACSFuselageElements& operator=(const CPACSFuselageElements&) = delete;
            
            CPACSFuselageElements(CPACSFuselageElements&&) = delete;
            CPACSFuselageElements& operator=(CPACSFuselageElements&&) = delete;
            #else
            CPACSFuselageElements(const CPACSFuselageElements&);
            CPACSFuselageElements& operator=(const CPACSFuselageElements&);
            #endif
        };
    }
    
    // CPACSFuselageElements is customized, use type CCPACSFuselageSectionElements directly
}
