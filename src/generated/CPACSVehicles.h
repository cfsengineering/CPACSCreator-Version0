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
#include <CCPACSProfiles.h>
#include <string>
#include <tixi.h>
#include "CPACSAircraft.h"
#include "CPACSMaterials.h"
#include "CPACSRotorcraft.h"
#include "tigl_internal.h"

namespace tigl
{
    class CTiglUIDManager;
    
    namespace generated
    {
        // This class is used in:
        // CPACSCpacs
        
        // generated from /xsd:schema/xsd:complexType[872]
        class CPACSVehicles
        {
        public:
            TIGL_EXPORT CPACSVehicles(CTiglUIDManager* uidMgr);
            TIGL_EXPORT virtual ~CPACSVehicles();
            
            TIGL_EXPORT CTiglUIDManager& GetUIDManager();
            TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const boost::optional<CPACSAircraft>& GetAircraft() const;
            TIGL_EXPORT virtual boost::optional<CPACSAircraft>& GetAircraft();
            
            TIGL_EXPORT virtual const boost::optional<CPACSRotorcraft>& GetRotorcraft() const;
            TIGL_EXPORT virtual boost::optional<CPACSRotorcraft>& GetRotorcraft();
            
            TIGL_EXPORT virtual const boost::optional<CCPACSProfiles>& GetProfiles() const;
            TIGL_EXPORT virtual boost::optional<CCPACSProfiles>& GetProfiles();
            
            TIGL_EXPORT virtual const boost::optional<CPACSMaterials>& GetMaterials() const;
            TIGL_EXPORT virtual boost::optional<CPACSMaterials>& GetMaterials();
            
        protected:
            CTiglUIDManager* m_uidMgr;
            
            boost::optional<CPACSAircraft>   m_aircraft;
            boost::optional<CPACSRotorcraft> m_rotorcraft;
            boost::optional<CCPACSProfiles>  m_profiles;
            boost::optional<CPACSMaterials>  m_materials;
            
        private:
            #ifdef HAVE_CPP11
            CPACSVehicles(const CPACSVehicles&) = delete;
            CPACSVehicles& operator=(const CPACSVehicles&) = delete;
            
            CPACSVehicles(CPACSVehicles&&) = delete;
            CPACSVehicles& operator=(CPACSVehicles&&) = delete;
            #else
            CPACSVehicles(const CPACSVehicles&);
            CPACSVehicles& operator=(const CPACSVehicles&);
            #endif
        };
    }
    
    // Aliases in tigl namespace
    #ifdef HAVE_CPP11
    using CCPACSVehicles = generated::CPACSVehicles;
    #else
    typedef generated::CPACSVehicles CCPACSVehicles;
    #endif
}
