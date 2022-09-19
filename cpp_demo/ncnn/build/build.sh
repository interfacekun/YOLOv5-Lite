#!/bin/bash
THREAD=6
cmake --build . -j $THREAD
cmake --build . --target install
