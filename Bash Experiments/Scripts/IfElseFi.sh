#!/bin/bash

#If else fi

age=$2
name=$1

if [ $age -eq 20 ] && [ $name = "Zack" ]
then
	echo "Hello $name"
else
	echo "You are not the right person"
fi

echo "The number of args are $#"


