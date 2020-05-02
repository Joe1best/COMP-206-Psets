#!/bin/bash

###########################################################
#                     Usage seeker.sh
#
#
#
#
###########################################################

content=0
matchingFile=0
while getopts ":ca" opt; 
do
	case ${opt} in 
		c ) content=1;;
		a ) matchingFile=1;;
	esac
done

#The command below makes it so the pattern argument is $1
shift $[$OPTIND - 1]
#If the argument count is less than one, it means that 
#the pattern argument was not inputted

if [ $# -lt 1 ]
then 
	echo "Error missing the pattern argument."
	echo "Usage $0 [-c] [-a] pattern [path]"
	exit 2
#If the number of arguments is 1, it means that ONLY 
#the pattern argument was inputted 
elif [ $# -eq 1 ]
then
	path=$PWD
#If the number of arguments is 2, it means that the 
#path argument was specified 
elif [ $# -eq 2 ]
then
	#-d is an operator to test if the given directory exists or not. 
	#The command below checks if the inputed path is legit or nah. 
	if [ ! -d $2 ]
	then 
		echo "Error $2 is not a valid directory"
		exit 3
	fi 
	path=$2
fi

#Filters the files that have the pattern ($1) in them
files=`ls $path | grep $1`


#If not matches, closes the script and enforces the user
if [ $? -eq 1 ]
then 
	echo "Unable to locate any files that has pattern $1 in its names in $path."
	exit 1
fi 

#Takes care of the two positional arguments

#This looks into the -a argument
if [ $matchingFile -eq 0 ]
then
	#If -a option is passed, includes the first result of the
	#match
	files=`ls $path | grep $1 | head -1`
fi
#This looks at the -c argument

#If -c is not specified, display the absolute path to the file
#(including the file name). 
if [ $content -eq 0 ]
then 
	for fil in $files
	do
		echo "$path/$fil"
	done

#If -c is specified, display the contents of the folder by using 
#the cat command. 
else 
	for fil in $files
	do 
		echo "==== Contents of: $path/$fil ===="
		cat $path/$fil
	done
fi
