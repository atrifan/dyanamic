package test

// #include <stdio.h>
// #include <stdarg.h>
// typedef void (*cb) (int, ...);
//
// void bridge(cb f, int count, char* first, char* second)
// {
//   f(count, first, second);
// }
import "C"
import "unsafe"

type Test struct {
	Yours string
}

func (self *Test) GetYourShit(pointer unsafe.Pointer) string {
	C.bridge(C.cb(pointer), C.int(2), C.CString("abc"), C.CString("cde"))
	return self.Yours
}
