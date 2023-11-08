#!/bin/bash
rm -r -f tmp
rm -r -f output
mkdir tmp
cd tmp
cmake ..
make VERBOSE=1
make install
