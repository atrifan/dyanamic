//
// Created by trifan on 2019-06-02.
//

#ifndef DYNAMIC_TEST_H
#define DYNAMIC_TEST_H

#include "generic.h"

class Test : public Generic {
public:
    int onRequest(int size);
};

#endif //DYNAMIC_TEST_H
