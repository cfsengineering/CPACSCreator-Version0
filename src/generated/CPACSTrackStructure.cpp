// Copyright (c) 2018 RISC Software GmbH
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

#include "CPACSTrackStructure.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTrackStructure::CPACSTrackStructure()
    {
    }

    CPACSTrackStructure::~CPACSTrackStructure()
    {
    }

    void CPACSTrackStructure::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element controlSurfaceAttachment
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/controlSurfaceAttachment")) {
            m_controlSurfaceAttachment = boost::in_place();
            try {
                m_controlSurfaceAttachment->ReadCPACS(tixiHandle, xpath + "/controlSurfaceAttachment");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read controlSurfaceAttachment at xpath " << xpath << ": " << e.what();
                m_controlSurfaceAttachment = boost::none;
            }
        }

        // read element car
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/car")) {
            m_car = boost::in_place();
            try {
                m_car->ReadCPACS(tixiHandle, xpath + "/car");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read car at xpath " << xpath << ": " << e.what();
                m_car = boost::none;
            }
        }

        // read element strut1
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/strut1")) {
            m_strut1 = boost::in_place();
            try {
                m_strut1->ReadCPACS(tixiHandle, xpath + "/strut1");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read strut1 at xpath " << xpath << ": " << e.what();
                m_strut1 = boost::none;
            }
        }

        // read element strut2
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/strut2")) {
            m_strut2 = boost::in_place();
            try {
                m_strut2->ReadCPACS(tixiHandle, xpath + "/strut2");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read strut2 at xpath " << xpath << ": " << e.what();
                m_strut2 = boost::none;
            }
        }

        // read element strut3
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/strut3")) {
            m_strut3 = boost::in_place();
            try {
                m_strut3->ReadCPACS(tixiHandle, xpath + "/strut3");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read strut3 at xpath " << xpath << ": " << e.what();
                m_strut3 = boost::none;
            }
        }

        // read element sidePanels
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sidePanels")) {
            m_sidePanels = boost::in_place();
            try {
                m_sidePanels->ReadCPACS(tixiHandle, xpath + "/sidePanels");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read sidePanels at xpath " << xpath << ": " << e.what();
                m_sidePanels = boost::none;
            }
        }

        // read element upperPanel
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperPanel")) {
            m_upperPanel = boost::in_place();
            try {
                m_upperPanel->ReadCPACS(tixiHandle, xpath + "/upperPanel");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read upperPanel at xpath " << xpath << ": " << e.what();
                m_upperPanel = boost::none;
            }
        }

        // read element lowerPanel
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerPanel")) {
            m_lowerPanel = boost::in_place();
            try {
                m_lowerPanel->ReadCPACS(tixiHandle, xpath + "/lowerPanel");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read lowerPanel at xpath " << xpath << ": " << e.what();
                m_lowerPanel = boost::none;
            }
        }

        // read element rollerTrack
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rollerTrack")) {
            m_rollerTrack = boost::in_place();
            try {
                m_rollerTrack->ReadCPACS(tixiHandle, xpath + "/rollerTrack");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read rollerTrack at xpath " << xpath << ": " << e.what();
                m_rollerTrack = boost::none;
            }
        }

        // read element ribs
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribs")) {
            m_ribs = boost::in_place();
            try {
                m_ribs->ReadCPACS(tixiHandle, xpath + "/ribs");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read ribs at xpath " << xpath << ": " << e.what();
                m_ribs = boost::none;
            }
        }

        // read element fairing
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/fairing")) {
            m_fairing = boost::in_place();
            try {
                m_fairing->ReadCPACS(tixiHandle, xpath + "/fairing");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read fairing at xpath " << xpath << ": " << e.what();
                m_fairing = boost::none;
            }
        }

    }

    void CPACSTrackStructure::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element controlSurfaceAttachment
        if (m_controlSurfaceAttachment) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/controlSurfaceAttachment");
            m_controlSurfaceAttachment->WriteCPACS(tixiHandle, xpath + "/controlSurfaceAttachment");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/controlSurfaceAttachment")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/controlSurfaceAttachment");
            }
        }

        // write element car
        if (m_car) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/car");
            m_car->WriteCPACS(tixiHandle, xpath + "/car");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/car")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/car");
            }
        }

        // write element strut1
        if (m_strut1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/strut1");
            m_strut1->WriteCPACS(tixiHandle, xpath + "/strut1");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/strut1")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/strut1");
            }
        }

        // write element strut2
        if (m_strut2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/strut2");
            m_strut2->WriteCPACS(tixiHandle, xpath + "/strut2");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/strut2")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/strut2");
            }
        }

        // write element strut3
        if (m_strut3) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/strut3");
            m_strut3->WriteCPACS(tixiHandle, xpath + "/strut3");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/strut3")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/strut3");
            }
        }

        // write element sidePanels
        if (m_sidePanels) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sidePanels");
            m_sidePanels->WriteCPACS(tixiHandle, xpath + "/sidePanels");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/sidePanels")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/sidePanels");
            }
        }

        // write element upperPanel
        if (m_upperPanel) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/upperPanel");
            m_upperPanel->WriteCPACS(tixiHandle, xpath + "/upperPanel");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperPanel")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/upperPanel");
            }
        }

        // write element lowerPanel
        if (m_lowerPanel) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/lowerPanel");
            m_lowerPanel->WriteCPACS(tixiHandle, xpath + "/lowerPanel");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerPanel")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/lowerPanel");
            }
        }

        // write element rollerTrack
        if (m_rollerTrack) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rollerTrack");
            m_rollerTrack->WriteCPACS(tixiHandle, xpath + "/rollerTrack");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/rollerTrack")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/rollerTrack");
            }
        }

        // write element ribs
        if (m_ribs) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribs");
            m_ribs->WriteCPACS(tixiHandle, xpath + "/ribs");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribs")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/ribs");
            }
        }

        // write element fairing
        if (m_fairing) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fairing");
            m_fairing->WriteCPACS(tixiHandle, xpath + "/fairing");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/fairing")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/fairing");
            }
        }

    }

    const boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetControlSurfaceAttachment() const
    {
        return m_controlSurfaceAttachment;
    }

    boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetControlSurfaceAttachment()
    {
        return m_controlSurfaceAttachment;
    }

    const boost::optional<CPACSTrackCar>& CPACSTrackStructure::GetCar() const
    {
        return m_car;
    }

    boost::optional<CPACSTrackCar>& CPACSTrackStructure::GetCar()
    {
        return m_car;
    }

    const boost::optional<CPACSTrackStrut1>& CPACSTrackStructure::GetStrut1() const
    {
        return m_strut1;
    }

    boost::optional<CPACSTrackStrut1>& CPACSTrackStructure::GetStrut1()
    {
        return m_strut1;
    }

    const boost::optional<CPACSTrackStrut2>& CPACSTrackStructure::GetStrut2() const
    {
        return m_strut2;
    }

    boost::optional<CPACSTrackStrut2>& CPACSTrackStructure::GetStrut2()
    {
        return m_strut2;
    }

    const boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetStrut3() const
    {
        return m_strut3;
    }

    boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetStrut3()
    {
        return m_strut3;
    }

    const boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetSidePanels() const
    {
        return m_sidePanels;
    }

    boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetSidePanels()
    {
        return m_sidePanels;
    }

    const boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetUpperPanel() const
    {
        return m_upperPanel;
    }

    boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetUpperPanel()
    {
        return m_upperPanel;
    }

    const boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetLowerPanel() const
    {
        return m_lowerPanel;
    }

    boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetLowerPanel()
    {
        return m_lowerPanel;
    }

    const boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetRollerTrack() const
    {
        return m_rollerTrack;
    }

    boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetRollerTrack()
    {
        return m_rollerTrack;
    }

    const boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetRibs() const
    {
        return m_ribs;
    }

    boost::optional<CCPACSMaterialDefinition>& CPACSTrackStructure::GetRibs()
    {
        return m_ribs;
    }

    const boost::optional<CPACSTrackFairing>& CPACSTrackStructure::GetFairing() const
    {
        return m_fairing;
    }

    boost::optional<CPACSTrackFairing>& CPACSTrackStructure::GetFairing()
    {
        return m_fairing;
    }

    CCPACSMaterialDefinition& CPACSTrackStructure::GetControlSurfaceAttachment(CreateIfNotExistsTag)
    {
        if (!m_controlSurfaceAttachment)
            m_controlSurfaceAttachment = boost::in_place();
        return *m_controlSurfaceAttachment;
    }

    void CPACSTrackStructure::RemoveControlSurfaceAttachment()
    {
        m_controlSurfaceAttachment = boost::none;
    }

    CPACSTrackCar& CPACSTrackStructure::GetCar(CreateIfNotExistsTag)
    {
        if (!m_car)
            m_car = boost::in_place();
        return *m_car;
    }

    void CPACSTrackStructure::RemoveCar()
    {
        m_car = boost::none;
    }

    CPACSTrackStrut1& CPACSTrackStructure::GetStrut1(CreateIfNotExistsTag)
    {
        if (!m_strut1)
            m_strut1 = boost::in_place();
        return *m_strut1;
    }

    void CPACSTrackStructure::RemoveStrut1()
    {
        m_strut1 = boost::none;
    }

    CPACSTrackStrut2& CPACSTrackStructure::GetStrut2(CreateIfNotExistsTag)
    {
        if (!m_strut2)
            m_strut2 = boost::in_place();
        return *m_strut2;
    }

    void CPACSTrackStructure::RemoveStrut2()
    {
        m_strut2 = boost::none;
    }

    CCPACSMaterialDefinition& CPACSTrackStructure::GetStrut3(CreateIfNotExistsTag)
    {
        if (!m_strut3)
            m_strut3 = boost::in_place();
        return *m_strut3;
    }

    void CPACSTrackStructure::RemoveStrut3()
    {
        m_strut3 = boost::none;
    }

    CCPACSMaterialDefinition& CPACSTrackStructure::GetSidePanels(CreateIfNotExistsTag)
    {
        if (!m_sidePanels)
            m_sidePanels = boost::in_place();
        return *m_sidePanels;
    }

    void CPACSTrackStructure::RemoveSidePanels()
    {
        m_sidePanels = boost::none;
    }

    CCPACSMaterialDefinition& CPACSTrackStructure::GetUpperPanel(CreateIfNotExistsTag)
    {
        if (!m_upperPanel)
            m_upperPanel = boost::in_place();
        return *m_upperPanel;
    }

    void CPACSTrackStructure::RemoveUpperPanel()
    {
        m_upperPanel = boost::none;
    }

    CCPACSMaterialDefinition& CPACSTrackStructure::GetLowerPanel(CreateIfNotExistsTag)
    {
        if (!m_lowerPanel)
            m_lowerPanel = boost::in_place();
        return *m_lowerPanel;
    }

    void CPACSTrackStructure::RemoveLowerPanel()
    {
        m_lowerPanel = boost::none;
    }

    CCPACSMaterialDefinition& CPACSTrackStructure::GetRollerTrack(CreateIfNotExistsTag)
    {
        if (!m_rollerTrack)
            m_rollerTrack = boost::in_place();
        return *m_rollerTrack;
    }

    void CPACSTrackStructure::RemoveRollerTrack()
    {
        m_rollerTrack = boost::none;
    }

    CCPACSMaterialDefinition& CPACSTrackStructure::GetRibs(CreateIfNotExistsTag)
    {
        if (!m_ribs)
            m_ribs = boost::in_place();
        return *m_ribs;
    }

    void CPACSTrackStructure::RemoveRibs()
    {
        m_ribs = boost::none;
    }

    CPACSTrackFairing& CPACSTrackStructure::GetFairing(CreateIfNotExistsTag)
    {
        if (!m_fairing)
            m_fairing = boost::in_place();
        return *m_fairing;
    }

    void CPACSTrackStructure::RemoveFairing()
    {
        m_fairing = boost::none;
    }

} // namespace generated
} // namespace tigl
