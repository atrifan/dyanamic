//
// Created by trifan on 2019-06-02.
//
#include <iostream>
#include "test.h"

using namespace std;


extern "C" Generic* create()
{
    Test *test = new Test();
    return test;
}

extern "C" int onRequest(int p0)
{
    return p0 * 3;
}

int Test::onRequest(int size) {
    return size * 2;
};


