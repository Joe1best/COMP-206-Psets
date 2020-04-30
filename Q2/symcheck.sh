#!/bin/bash

#Checks if the number of arguments is valid or not
if [ $# -ne 1 ]
then 
	echo "This script expects only one argument of type .txt"
	exit 1;
fi

#filename argument
filename=$1
#current directory
directory=$PWD


#Checks whether filename variable exists in the current directory 
if [ ! -f "$filename" ]
then 
	echo "Unable to locate the file $filename in directory $directory"
	exit 2;
fi

#while that reads the $filename line by line and executes the c file. THIS ASSUMES
#THAT THE OUT FILE IS CALLED symword AND IS IN THE SAME DIRECTORY AS THIS BASH SCRIPT
`gcc -o symword symword.c` #compiles the C file 
while read line
do 
	`./symword $line`
	c=`echo $?`#saves the value of the exit code
       	#If exit code is equal to 1, then the word is not symmetric as defined 
	#in the symword.c file. If it is equal to 0, then is symmetric	
	if [ $c -eq 1 ]
	then 
		echo "$line is not symmetric"
	elif [ $c -eq 0 ]
	then 
		echo "$line is symmetric"
	fi
done < $filename
