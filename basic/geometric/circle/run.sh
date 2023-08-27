if [ -d "./build" ]; then
    rm -rf build
    echo "build is deleted!"
fi

cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=ON
cmake --build build

cd build
./main
