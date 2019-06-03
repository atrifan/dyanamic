#include <iostream>
#include <dlfcn.h>
#include "generic.h"

using namespace std;
int main() {
    void *hndl = dlopen("/usr/local/Cellar/go/1.12.5/src/dynamicLib/dynamic.so", RTLD_LAZY);
    if (hndl == NULL) {
        cerr << dlerror() << endl;
        exit(-1);
    }
    //declare create signature
    int (*onRequest)(int);
    onRequest = (int (*)(int))dlsym(hndl, "onRequest");
    int result = onRequest(4);
    cout << result << endl;
    hndl = dlopen("/Users/trifan/DEVELOPMENT/dynamic/test.so", RTLD_LAZY);
    if (hndl == NULL) {
        cerr << dlerror() << endl;
        exit(-1);
    }
    Generic* (*create)();
    create = (Generic* (*)())dlsym(hndl, "create");
    Generic *clazz = create();

    int sz = clazz->onRequest(23);
    cout<<"--> "<<sz;
}