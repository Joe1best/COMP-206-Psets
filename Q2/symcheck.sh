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

#Runs the ls command along with grep to filter out the files in the 
#ucrrent directory with the filename as the filter.
files=`ls $directory | grep $filename`

#If no matches, closes the script and informs the user 
if [ $? -eq 1 ]
then 
	echo "Unable to locate the file $filename in directory $directory"
	exit 2;
fi



