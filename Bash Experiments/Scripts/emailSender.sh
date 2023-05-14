#!/bin/bash

for i in {0..9};do
    (echo "Hello Zack this is an email test #$i I hope you like it!" | mail -s "Script Tester" -r zackariaeBou@outlook.com z.bouargan@aui.ma)

if [[ $# != 0 ]]; then
echo "Error"

else
echo "Sent"
fi
done
