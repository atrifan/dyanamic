#include <iostream>
#include <dlfcn.h>
#include "generic.h"

using namespace std;

void A()
{
    printf("I am function A\n");
}

int main() {
    void *hndl = dlopen("./out.so", RTLD_LAZY);
    if (hndl == NULL) {
        cerr << dlerror() << endl;
        exit(-1);
    }
    //declare create signature
    int (*onRequest)(int, void(*)());
    onRequest = (int (*)(int, void(*)()))dlsym(hndl, "onRequest");
    int result = onRequest(4, &A);
    cout << result << endl;
    hndl = dlopen("./test.so", RTLD_LAZY);
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