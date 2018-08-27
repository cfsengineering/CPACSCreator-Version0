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
