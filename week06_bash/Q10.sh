#! /bin/bash

print_param() {

    echo "./Q10.sh"
    echo $1
    echo $2
    echo $*
    echo $#

}

print_param "Hello" "World" "!"