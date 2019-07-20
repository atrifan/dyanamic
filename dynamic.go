package main

import "C"
import (
	"atrifan/dyanamic/test"
	"encoding/json"
	"fmt"
	"unsafe"
)
//export onRequest
func onRequest(size C.int, pointer unsafe.Pointer) C.int {
	slcD := []string{"apple", "peach", "pear"}
	slcB, _ := json.Marshal(slcD)
	fmt.Println(string(slcB))
	t := &test.Test{
		Yours: "gigiel",
	}
	fmt.Println(t.GetYourShit(pointer))
	return C.int(size * C.int(5))
}

func main() {}
