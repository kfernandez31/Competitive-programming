#!/bin/bash 

N = 100000

for i in {1..$N} {   
    echo $i 
    ./gen > gen.out
    ./brut < gen.out > expected.out
    ./my < gen.out > actual.out
    if diff actual.out expected.out > /dev/null; then
        echo $"OK"
    else 
        echo $"WA"
        exit 0
    fi
}