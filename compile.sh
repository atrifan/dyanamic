go build -o out.so -buildmode=c-shared dynamic.go
g++ -shared -o test.so test.cpp