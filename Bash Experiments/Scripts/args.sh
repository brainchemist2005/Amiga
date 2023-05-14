#!/bin/bash

#using args in this script

if [ $# -eq 0 ]; then
echo "Enter the first argument: "
read variable
echo "Enter the second argument: "
read variable1

else
variable=$1
variable1=$2

fi

echo "Here are the arguments you presented: $variable and $variable1" 
echo "The number of args u passed are $#"
