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

#ifndef CPACSCREATORLIBANDTESTS_LOGGERSETUP_H
#define CPACSCREATORLIBANDTESTS_LOGGERSETUP_H


#include <string>
#include "LoggerSetUp.h"


namespace  cpcr {



    class LoggerSetUp {

    public:

        LoggerSetUp();

        static std::string configFile ;

        static bool isLoggerConfigured;

        static void run();


    };


}



#endif //CPACSCREATORLIBANDTESTS_LOGGERSETUP_H
