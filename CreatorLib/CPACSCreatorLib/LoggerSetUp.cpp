/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
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
//
// Created by makem on 11/04/18.
//

#include "LoggerSetUp.h"
#include "easylogging++.h"


INITIALIZE_EASYLOGGINGPP

bool cpcr::LoggerSetUp::isLoggerConfigured = false;
std::string cpcr::LoggerSetUp::configFile = "logger.conf";


// Tricks to get the run call once by the constructor when the lib is used
// Run is call in the constructor and the following statement will be call before main()
static cpcr::LoggerSetUp logger;


void cpcr::LoggerSetUp::run() {

    if(! isLoggerConfigured ) {
        // Load configuration from file
        el::Configurations conf();
        // Reconfigure the loggers will use configuration from file
        el::Loggers::reconfigureAllLoggers(configFile);

        LOG(INFO) << "Now logging is configured with the file:  " + configFile;

        isLoggerConfigured = true;
    }

}

cpcr::LoggerSetUp::LoggerSetUp() {
    run();

}
