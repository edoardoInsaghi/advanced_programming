#!/bin/bash

echo "yo I'm the second file, and now I'm calling a variable from the last script"

echo $a

echo "now I'm declaring a function (can't see it at runtime)"

my_fun(){

	echo "this was printed by a function, now I'm printing the function arguments"
	echo $1 $2
}

my_fun arg1 arg2




