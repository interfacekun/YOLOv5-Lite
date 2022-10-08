#!/bin/bash
THREAD=6
cmake -DTARGET_CPU:STRING=x86 --build . -j $THREAD
cmake --build . --target install
