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
