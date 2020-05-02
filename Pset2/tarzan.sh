#!/bin/bash

################################################################
                 # Usage for tarzan.sh

#This script informs the user if a file exists within a tar folder 
#This script uses the functions tar and grep in order to explore 
#the directory tree and filter out the sought file. 
################################################################

#Below we define the inputs of the function
fileName=$1
tarFileName=$2

#Checks to see if TWO arguments are passed to the script. If not 
#throws a message and ends the script. 
if [ $# -ne 2 ]
then 
	echo "Usage $0 filename tarfile"
	exit 1
fi

#Checks to see if the tar file is in the directory 
if [ ! -f $tarFileName ]  
then 
	echo "Error cannot find tar file $tarFileName"
	exit 1
fi

#Two if conditions. The tar -tf command displays all the files 
#in the directory. 
	#t: lists all the contents of the directory 
	#f: use archive file

#Grep filters out the file in question 
#using the Eqx options. 
	#E: Interpret patterns as expressions 
	#q: Prevents it from printing the directories/folders
	#x: Selects files exactly matching the line

if tar -tf $tarFileName | grep -Eqx "(.*/)?$fileName" 
then
       	#If the file is found inside the tar file, print the 
	#following message
	echo "$fileName exists in $tarFileName"
else 
	#If the file does not exist in the tar file, print
	#the following message
      	echo "$fileName does not exist in $tarFileName"
       	exit 1       
fi
