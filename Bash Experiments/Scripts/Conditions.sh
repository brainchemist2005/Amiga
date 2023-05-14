#!/bin/bash

#This is a if else bash script 


if [ $# -eq 2 ];
then 
  username1=$1
  username2=$2

  echo "There are two usernames $username1 and $username2"

else 
  echo "We need two arguments"

fi

echo "Bye"
