#!/bin/bash
THREAD=6
cmake -DTARGET_CPU:STRING=aarch64 -DCMAKE_TOOLCHAIN_FILE=../toolchains/aarch64-linux-gnu.toolchain.cmake .. 
cake --build . -j $THREAD
cmake --build . --target install