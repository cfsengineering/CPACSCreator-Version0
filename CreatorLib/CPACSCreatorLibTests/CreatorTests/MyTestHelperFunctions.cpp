//
// Created by makem on 07/06/18.
//

#include "MyTestHelperFunctions.h"

double mthf::EPSILON = 0.01;

bool mthf::CompareDoubleEpsilon(double a, double b, double e){
        double diff = a - b;
        return (diff <= e ) && ( diff >= -e) ;
};


