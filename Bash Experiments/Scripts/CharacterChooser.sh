#!/bin/bash

echo "Enter a movie name and I will rate you"

read movie

case $movie in
	"Fight club")
	note=10
	;;

	"Django unchained")
	note=11
	;;

	"La La Land")
	note=5
	;;
esac

echo "Your grade is $note"
