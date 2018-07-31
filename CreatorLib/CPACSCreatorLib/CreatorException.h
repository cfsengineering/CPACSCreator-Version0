//
// Created by makem on 08/04/18.
//

#ifndef CPACSCREATORLIB_CPACSCREATOREXCEPTION_H
#define CPACSCREATORLIB_CPACSCREATOREXCEPTION_H


#include <exception>
#include <string>


/***
 *
 * Basic class to create Error of Creator type
 *
 * ERROR NUMBER:
 * 3 -> cst2D Airfoil not supported
 *
 *
 */


class CreatorException: public std::exception  {

public:
    CreatorException(  const std::string& msg, int errNum = -1);

    ~CreatorException() throw() {}

    virtual const char* what() const throw(); /*override*/

    void addToMessage(const std::string& msg);

    int errNumber;
private:
    std::string message;


};



#endif //CPACSCREATORLIB_CPACSCREATOREXCEPTION_H
