package test

// #include <stdio.h>
//
// typedef void (*cb) ();
//
// void bridge(cb f)
// {
//   f();
// }
import "C"
import "unsafe"

type Test struct {
	Yours string
}

func (self *Test) GetYourShit(pointer unsafe.Pointer) string {
	C.bridge(C.cb(pointer))
	return self.Yours
}
