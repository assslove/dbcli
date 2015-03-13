#!/bin/bash

#generate protobuf src

cd proto
ls | xargs protoc -I=./ --cpp_out=./lib 
cd ../
