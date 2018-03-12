//
// Created by cfse on 3/12/18.
//

#ifndef TIGL_TEST_H
#define TIGL_TEST_H


class Test {

public:
    Test();
    Test(Test&& ref);
    Test(const Test& ref);
    ~Test();
    Test& operator=(const Test& ref);

    int i;
};


#endif //TIGL_TEST_H
