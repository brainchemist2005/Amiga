#!/bin/bash

if [ "$#" -ne 1 ]; then
exit 1
fi 
if [ "$1" = oui ]; then
echo oui
./oui_ou_non "non"

elif [ "$1" = non ]; then
echo non
exit 2
fi
