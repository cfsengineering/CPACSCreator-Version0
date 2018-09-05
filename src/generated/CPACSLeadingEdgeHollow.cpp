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

#include "CPACSLeadingEdgeHollow.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSLeadingEdgeHollow::CPACSLeadingEdgeHollow()
        : m_relHeightTE(0)
        , m_xsiTE(0)
    {
    }

    CPACSLeadingEdgeHollow::~CPACSLeadingEdgeHollow()
    {
    }

    void CPACSLeadingEdgeHollow::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element relHeightTE
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/relHeightTE")) {
            m_relHeightTE = tixi::TixiGetElement<double>(tixiHandle, xpath + "/relHeightTE");
        }
        else {
            LOG(ERROR) << "Required element relHeightTE is missing at xpath " << xpath;
        }

        // read element xsiTE
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/xsiTE")) {
            m_xsiTE = tixi::TixiGetElement<double>(tixiHandle, xpath + "/xsiTE");
        }
        else {
            LOG(ERROR) << "Required element xsiTE is missing at xpath " << xpath;
        }

    }

    void CPACSLeadingEdgeHollow::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element relHeightTE
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/relHeightTE");
        tixi::TixiSaveElement(tixiHandle, xpath + "/relHeightTE", m_relHeightTE);

        // write element xsiTE
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/xsiTE");
        tixi::TixiSaveElement(tixiHandle, xpath + "/xsiTE", m_xsiTE);

    }

    const double& CPACSLeadingEdgeHollow::GetRelHeightTE() const
    {
        return m_relHeightTE;
    }

    void CPACSLeadingEdgeHollow::SetRelHeightTE(const double& value)
    {
        m_relHeightTE = value;
    }

    const double& CPACSLeadingEdgeHollow::GetXsiTE() const
    {
        return m_xsiTE;
    }

    void CPACSLeadingEdgeHollow::SetXsiTE(const double& value)
    {
        m_xsiTE = value;
    }

} // namespace generated
} // namespace tigl
