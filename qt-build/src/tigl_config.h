/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2013-04-23 Martin Siggel <Martin.Siggel@dlr.de>
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

#ifndef CONFIG_H
#define CONFIG_H

// include files and other standard functionality
#define HAVE_CPP11
#define HAVE_STDSHARED_PTR
#define HAVE_STDUNIQUE_PTR
/* #undef HAVE_STDMAKE_UNIQUE */
#define HAVE_STDIS_SAME

// optional libraries
/* #undef GLOG_FOUND */

// Default off: Activate, if OpenCASCADE is patched to provide the C2 coons algorithm
/* #undef TIGL_OCE_COONS_PATCHED */

#endif // CONFIG_H
