#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

if [ $# -lt 1 ]; then
  echo "Usage: $0 <program>"
  exit 1
fi

echo "Compiling $1..."
if ! g++ -std=c++17 -o program "$1"; then
  echo "Compilation failed"
  exit 1
fi

for input_file in tests/*.in; do
  out_file="${input_file%.in}.out"
  actual="$(./program < "$input_file")"
  expected="$(cat "$out_file")"

  if [ "$actual" != "$expected" ]; then
    echo -e "${RED}WA: $input_file"
    
    echo "Expected:"
    echo "$expected"
    echo "Actual:"
    echo "$actual"
    echo

    #exit 1
  else
    echo -e "${GREEN}OK: $input_file"
    echo
  fi
done

rm program
