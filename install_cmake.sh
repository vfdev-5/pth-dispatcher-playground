#!/bin/bash

set -ex

apt update && apt install -y wget

cd /tmp

version=3.13
build=1
wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
tar -xzvf cmake-$version.$build.tar.gz && cd cmake-$version.$build/
./bootstrap && make -j8 && make install

cd /cpp
