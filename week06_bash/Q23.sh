#! /bin/bash

factorial(){
    
    result=1

    if [ $NUM -le 0 ]; then
        echo 1
        return 0
    fi

    for n in $(seq 1 $NUM); do
        
        result=$((result * n))
    done

    echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM