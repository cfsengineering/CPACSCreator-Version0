//
// Created by makem on 01/06/18.
//

#include "TIGLViewerException.h"
#include "CTiglLogging.h"


TIGLViewerException::TIGLViewerException( const std::string& msg) : std::exception() {
    message = msg;
    LOG(ERROR) << "CreatorException with message: \"" << msg << "\" was created.";

}

const char *TIGLViewerException::what() const throw() {

    return message.c_str();

}

void TIGLViewerException::addToMessage(const std::string& msg) {
    message = message + msg;
    LOG(ERROR) << "New message: " << message ;
}

