/*
* Copyright (C) 2015 German Aerospace Center (DLR/SC)
*
* Created: 2015-05-27 Martin Siggel <Martin.Siggel@dlr.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef CCPACSEXTERNALOBJECT_H
#define CCPACSEXTERNALOBJECT_H

#include "generated/CPACSGenericGeometricComponent.h"
#include "CTiglRelativelyPositionedComponent.h"

namespace tigl
{

class CCPACSConfiguration;

class CCPACSExternalObject : public generated::CPACSGenericGeometricComponent, public CTiglRelativelyPositionedComponent
{
public:
    TIGL_EXPORT CCPACSExternalObject(CCPACSExternalObjects* parent);
    
    TIGL_EXPORT virtual const std::string& GetUID() const OVERRIDE;

    TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& objectXPath) OVERRIDE;
    
    TIGL_EXPORT const std::string& GetFilePath() const;
    
    TIGL_EXPORT TiglGeometricComponentType GetComponentType() const;

private:
    /// reads in the CAD file
    virtual PNamedShape BuildLoft() OVERRIDE;

    std::string _filePath;
};

} // namespace tigl

#endif // CCPACSEXTERNALOBJECT_H
