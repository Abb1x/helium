#!/bin/sh
ROOT=${1:-'sudo'}


CC=clang meson setup build/
ninja -j$(nproc) -C build/

$ROOT cp build/libhelium.so /usr/lib64/
$ROOT mkdir /usr/include/helium
$ROOT cp -r include/* /usr/include/helium

echo "Done"
