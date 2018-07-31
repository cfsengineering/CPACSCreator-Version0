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
