//
// Created by makem on 08/04/18.
//

#include "CreatorException.h"
#include "easylogging++.h"

CreatorException::CreatorException( const std::string& msg, int errNum) : std::exception() {
    message = msg;
    errNumber = errNum;
    LOG(ERROR) << "CreatorException with message: \"" << msg << "\" was created.";

}

const char *CreatorException::what() const throw() {

    return message.c_str();

}

void CreatorException::addToMessage(const std::string& msg) {
    message = message + msg;
    LOG(ERROR) << "New message: " << message ;
}

