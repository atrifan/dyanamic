package main
import "C"
import (
	"atrifan/dyanamic/test"
	"encoding/json"
	"fmt"
)
//export onRequest
func onRequest(size C.int) C.int {
	slcD := []string{"apple", "peach", "pear"}
	slcB, _ := json.Marshal(slcD)
	fmt.Println(string(slcB))
	t := &test.Test{
		Yours: "gigiel",
	}
	fmt.Println(t.GetYourShit())
	return C.int(size * C.int(5))
}

func main() {}
