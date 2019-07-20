#include <iostream>
#include <dlfcn.h>
#include <stdarg.h>
#include "generic.h"

using namespace std;

void A(int count, ...)
{
    va_list list;
    int j = 0;

    va_start(list, count);
    for(j=0; j<count; j++)
    {
     printf("%s ", va_arg(list, char*));
    }

    va_end(list);

    printf("\nI am function A\n");
}

int main() {
    void *hndl = dlopen("./out.so", RTLD_LAZY);
    if (hndl == NULL) {
        cerr << dlerror() << endl;
        exit(-1);
    }
    //declare create signature
    int (*onRequest)(int, void(*)(int, ...));
    onRequest = (int (*)(int, void(*)(int, ...)))dlsym(hndl, "onRequest");
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