#!/bin/bash

if [ -d "./build" ]; then
    rm -rf build
    echo "the build is deleted successfully!"
fi

cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
