//
// Created by cfse on 3/12/18.
//

#include "test.h"
#include <iostream>
// Test constructor destructor mechanism


Test::Test()
{
    i=-1;
    std::cout<<  "call::test::constructor" + std::to_string(i)  << std::endl;
}

Test::Test(Test&& ref ){
    std::cout<< "call::test::move "  + std::to_string(i)  << std::endl;
}


Test::Test(const Test& ref ){
    std::cout<< "call::test::copy "  + std::to_string(i)  << std::endl;
}


Test::~Test(){
    std::cout<< "call::test::destroy "  + std::to_string(i)  << std::endl;
}

Test& Test::operator=(const Test& ref){
    i = ref.i;
    std::cout<< "call::test::=operator "  + std::to_string(i)  << std::endl;

};