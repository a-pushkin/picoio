#!/bin/bash
cd "$(dirname "$0")"
mkdir build
cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cp compile_commands.json ../..
make -j$(nproc)
./picoio_tests
