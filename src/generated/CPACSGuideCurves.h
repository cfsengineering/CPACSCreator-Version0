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
#include "CTiglError.h"
#include <typeinfo>
#include "tigl_internal.h"

namespace tigl
{
    class CCPACSGuideCurve;
    
    namespace generated
    {
        // This class is used in:
        // CPACSFuselageSegment
        // CPACSWingSegment
        
        // generated from /xsd:schema/xsd:complexType[422]
        class CPACSGuideCurves
        {
        public:
            TIGL_EXPORT CPACSGuideCurves();
            TIGL_EXPORT virtual ~CPACSGuideCurves();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::vector<unique_ptr<CCPACSGuideCurve> >& GetGuideCurves() const;
            TIGL_EXPORT std::vector<unique_ptr<CCPACSGuideCurve> >& GetGuideCurves();
            
        protected:
            std::vector<unique_ptr<CCPACSGuideCurve> > m_guideCurves;
            
        private:
            #ifdef HAVE_CPP11
            CPACSGuideCurves(const CPACSGuideCurves&) = delete;
            CPACSGuideCurves& operator=(const CPACSGuideCurves&) = delete;
            
            CPACSGuideCurves(CPACSGuideCurves&&) = delete;
            CPACSGuideCurves& operator=(CPACSGuideCurves&&) = delete;
            #else
            CPACSGuideCurves(const CPACSGuideCurves&);
            CPACSGuideCurves& operator=(const CPACSGuideCurves&);
            #endif
        };
    }
    
    // Aliases in tigl namespace
    // CPACSGuideCurves is customized, use type CCPACSGuideCurves directly
}
