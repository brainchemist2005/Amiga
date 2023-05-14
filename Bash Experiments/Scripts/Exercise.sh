#!/bin/bash

#Write a simple script that will check if exactly two arguments are passed. If so, print the
#arguments in reverse order. Consider this example (note: your code may look different than
#this, but should lead to the same output):
#if [ $1 == $number ]
#then
#echo "True!"
#fi


if [ $# -eq 2 ]; then
  echo "$2 $1"

else
  echo "Not enought args"

fi
