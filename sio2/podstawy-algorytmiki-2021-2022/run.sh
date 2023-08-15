#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Usage: $0 <program>"
  exit 1
fi

echo "Compiling $1..."
if ! g++ -std=c++17 -o program "$1"; then
  echo "Compilation failed"
  exit 1
fi

./program < in
