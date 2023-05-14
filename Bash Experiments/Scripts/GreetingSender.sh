#!/bin/bash

temp=$(curl -s 'http://api.weatherstack.com/current?access_key=d436c7a3e9be80f697191fd02fdd65c8&query=Mohammedia' | sed -n 's/.*"temperature":\([0-9]*\).*/\1/p')
temp2=$(curl -s 'http://api.weatherstack.com/current?access_key=d436c7a3e9be80f697191fd02fdd65c8&query=Montreal,Canada' | sed -n 's/.*"temperature":\([0-9]*\).*"name":"Montreal".*/\1/p')


echo -e "This is a greeting message :) \nThe temperature in Mohammedia is $temp Celsius \n In Montreal it is $temp2 \nHave a nice day !" | mail -s "Hello Zackariae" -r zackariaeBou@outlook.com z.bouargan@aui.ma

if [[ $# == 0 ]]; then 
    echo "Succes!"
    echo "$temp2"
else
    echo "Not sent" 

fi
