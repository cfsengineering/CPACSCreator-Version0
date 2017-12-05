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

#include <CCPACSWingCellPositionChordwise.h>
#include <CCPACSWingCellPositionSpanwise.h>
#include <string>
#include <tixi.h>
#include "CPACSWingSkin.h"
#include "tigl_internal.h"

namespace tigl
{
    class CTiglUIDManager;
    class CCPACSWingCells;
    
    namespace generated
    {
        // This class is used in:
        // CPACSWingCells
        
        // generated from /xsd:schema/xsd:complexType[925]
        class CPACSWingCell
        {
        public:
            TIGL_EXPORT CPACSWingCell(CCPACSWingCells* parent, CTiglUIDManager* uidMgr);
            
            TIGL_EXPORT virtual ~CPACSWingCell();
            
            TIGL_EXPORT CCPACSWingCells* GetParent() const;
            
            TIGL_EXPORT CTiglUIDManager& GetUIDManager();
            TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::string& GetUID() const;
            TIGL_EXPORT virtual void SetUID(const std::string& value);
            
            TIGL_EXPORT virtual const CPACSWingSkin& GetSkin() const;
            TIGL_EXPORT virtual CPACSWingSkin& GetSkin();
            
            TIGL_EXPORT virtual const CCPACSWingCellPositionChordwise& GetPositioningLeadingEdge() const;
            TIGL_EXPORT virtual CCPACSWingCellPositionChordwise& GetPositioningLeadingEdge();
            
            TIGL_EXPORT virtual const CCPACSWingCellPositionChordwise& GetPositioningTrailingEdge() const;
            TIGL_EXPORT virtual CCPACSWingCellPositionChordwise& GetPositioningTrailingEdge();
            
            TIGL_EXPORT virtual const CCPACSWingCellPositionSpanwise& GetPositioningInnerBorder() const;
            TIGL_EXPORT virtual CCPACSWingCellPositionSpanwise& GetPositioningInnerBorder();
            
            TIGL_EXPORT virtual const CCPACSWingCellPositionSpanwise& GetPositioningOuterBorder() const;
            TIGL_EXPORT virtual CCPACSWingCellPositionSpanwise& GetPositioningOuterBorder();
            
        protected:
            CCPACSWingCells* m_parent;
            
            CTiglUIDManager* m_uidMgr;
            
            std::string                     m_uID;
            CPACSWingSkin                   m_skin;
            CCPACSWingCellPositionChordwise m_positioningLeadingEdge;
            CCPACSWingCellPositionChordwise m_positioningTrailingEdge;
            CCPACSWingCellPositionSpanwise  m_positioningInnerBorder;
            CCPACSWingCellPositionSpanwise  m_positioningOuterBorder;
            
        private:
            #ifdef HAVE_CPP11
            CPACSWingCell(const CPACSWingCell&) = delete;
            CPACSWingCell& operator=(const CPACSWingCell&) = delete;
            
            CPACSWingCell(CPACSWingCell&&) = delete;
            CPACSWingCell& operator=(CPACSWingCell&&) = delete;
            #else
            CPACSWingCell(const CPACSWingCell&);
            CPACSWingCell& operator=(const CPACSWingCell&);
            #endif
        };
    }
    
    // CPACSWingCell is customized, use type CCPACSWingCell directly
}
