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

#pragma once

#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSCutOutControlPoints

    // generated from /xsd:schema/xsd:complexType[241]
    class CPACSCutOutControlPoint
    {
    public:
        TIGL_EXPORT CPACSCutOutControlPoint();
        TIGL_EXPORT virtual ~CPACSCutOutControlPoint();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const double& GetRelHeight() const;
        TIGL_EXPORT virtual void SetRelHeight(const double& value);

        TIGL_EXPORT virtual const double& GetXsi() const;
        TIGL_EXPORT virtual void SetXsi(const double& value);

    protected:
        double m_relHeight;
        double m_xsi;

    private:
#ifdef HAVE_CPP11
        CPACSCutOutControlPoint(const CPACSCutOutControlPoint&) = delete;
        CPACSCutOutControlPoint& operator=(const CPACSCutOutControlPoint&) = delete;

        CPACSCutOutControlPoint(CPACSCutOutControlPoint&&) = delete;
        CPACSCutOutControlPoint& operator=(CPACSCutOutControlPoint&&) = delete;
#else
        CPACSCutOutControlPoint(const CPACSCutOutControlPoint&);
        CPACSCutOutControlPoint& operator=(const CPACSCutOutControlPoint&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSCutOutControlPoint = generated::CPACSCutOutControlPoint;
#else
typedef generated::CPACSCutOutControlPoint CCPACSCutOutControlPoint;
#endif
} // namespace tigl
