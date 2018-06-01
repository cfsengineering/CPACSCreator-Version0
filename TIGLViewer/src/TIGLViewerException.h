//
// Created by makem on 01/06/18.
//

#ifndef TIGL_TIGLVIEWEREXCEPTION_H
#define TIGL_TIGLVIEWEREXCEPTION_H


#include <exception>
#include <string>


class TIGLViewerException: public std::exception  {

public:
    TIGLViewerException(  const std::string& msg);

    ~TIGLViewerException() throw() {}

    virtual const char* what() const throw(); /*override*/

    void addToMessage(const std::string& msg);

private:
    std::string message;

};

#endif //TIGL_TIGLVIEWEREXCEPTION_H
