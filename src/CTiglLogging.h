/* 
 * Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
 *
 * Created: 2013-02-13 Markus Litz <Markus.Litz@dlr.de>
 * Changed: $Id$
 *
 * Version: $Revision$
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
/**
 * @file
 * @brief  Implementation of the TIGL Logger.
 */

#ifndef CTIGLLOGGING_H
#define CTIGLLOGGING_H

#include "tigl_config.h"

#include <string>
#include <stdio.h>
#ifdef GLOG_FOUND
#pragma warning( disable : 4251 4355 )
#include <glog/logging.h>
#pragma warning(disable: 4275)
#else
// dummy logger implementation
#include <iostream>
#include <sstream>
#include <cstring>
#include "TiglLoggerDefinitions.h"
#endif

namespace tigl {

#ifndef GLOG_FOUND
    //dummy implementation if glog is not available
    #ifndef LOG_MAX_LEVEL
    #define LOG_MAX_LEVEL TILOG_DEBUG4
    #endif

    //macro that extracts the filename of the current file
  #if defined _WIN32 || defined __WIN32__
    #define _CUR_FILE_ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
  #else
    #define _CUR_FILE_ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
  #endif

    /**
     * This macros can be used like streams e.g.: LOG(ERROR) << "that is an error";
     * Following log levels are supported: ERROR, WARNING, INFO, DEBUG, DEBUG1, DEBUG2, DEBUG3, DEBUG4
     */
    #define LOG(level) \
        if (TILOG_ ## level > LOG_MAX_LEVEL) ;\
    else tigl::DummyLogger_().AppendToStream(TILOG_ ## level, _CUR_FILE_, __LINE__) 

    #define DLOG LOG

    class DummyLogger_
    {
    public:
        DummyLogger_();
        virtual ~DummyLogger_();
        std::ostringstream& AppendToStream(TiglLogLevel level, const char *file, int line);
    protected:
        std::ostringstream stream;
    private:
        DummyLogger_(const DummyLogger_&);
        DummyLogger_& operator =(const DummyLogger_&);
        
        TiglLogLevel _lastLevel;
    };
#endif // not GLOG_FOUND


class CTiglLogging {

    public:
        // Returns a reference to the only instance of this class
        static CTiglLogging& Instance(void);
        
        // allows installing a custom log sink/receiver
        void SetLogger(class ITiglLogger*);
        class ITiglLogger* GetLogger();

        // Destructor
        ~CTiglLogging(void);

    private:
        // Constructor
        CTiglLogging(void);

        // Logger Initialize with defaults
        void initLogger(void);

        // Copy constructor
        CTiglLogging(const CTiglLogging& )                { /* Do nothing */ }

        // Assignment operator
        void operator=(const CTiglLogging& )             { /* Do nothing */ }
        
        class ITiglLogger* _myLogger;

};

} // end namespace tigl

#endif // CTIGLLOGGING_H
