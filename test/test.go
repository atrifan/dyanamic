package test

type Test struct {
	Yours string
}

func (self *Test) GetYourShit() string {
	return self.Yours
}
