
#!/bin/bash
fruit1=Apples
fruit2=Oranges
if [ $1 -lt $# ];
then
echo "This is like comparing $fruit1 and $fruit2!"
elif [ $1 -gt $2 ];
then
echo "$fruit1 win!"
else
echo "$fruit2 win!"
fi
