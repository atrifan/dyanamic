#!/usr/bin/env bash
go build -o out.so -buildmode=c-shared -v dynamic.go
g++ -shared -o test.so test.cpp
g++ main.cpp -o out