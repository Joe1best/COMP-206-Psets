#!/bin/bash

#Name of the config file
file_name="a3config"


#The if statement below checks if the config file exists
#in the directory
if [ ! -f "$file_name" ]
then
	msg="Error cannot find $file_name"
	echo $msg
	exit 1
fi

#sources the config file with the variables defined there 
. $file_name

#Second condition to check if the Username and extension variables
#have been defined and set. The -z command checks if they are not set
#or not. If that is the case, print the error message and exit with 
#code 2.
if [ -z "$DIRNAME" ] || [ -z "$EXTENSION" ]
then 
	msg="Error DIRNAME and EXTENSION must be set"
	echo $msg
	exit 2
fi


#Third condition is to check if the directory name specified in a3config 
#exists. The -d command does check if it does and returns true. Therefore, 
#if it does not exist (!), then it prints the error message and exits with 
#code 3.
if [ ! -d $DIRNAME ]
then
	msg="Error directory $DIRNAME does not exist"
	echo $msg
	exit 3
fi


#Fourth condition is to check if any files within the directory name has the 
#extension specified in the config file. This is done via the -f command. If 
#it does not exist, then it prints out the error message and exits with code 0

#Finds all the files with extension ($EXTENSION). This is done through the
#ls which gives all the files in $DIRNAME and grep to filter those files with
#files that only have extension ($EXTENSION)

files=`ls $DIRNAME | grep .*\.$EXTENSION$`

echo $DIRNAME

if [ -z "$files" ]
then 
	msg="Unable to locate any files with extension $EXTENSION in $DIRNAME"
	echo $msg
	exit 0
fi

#A for loop for the files found above 
for fl in $files
do 
	echo "$DIRNAME/$fl"
	#If $SHOW is specified and is equal to true 
	#then show the content of the file. If show is true, it must also be 
	#specified so we dont have to check for that 
	if [ "$SHOW" == "true" ] 
	then 
		cat $fl
	fi
done
#exists with code 0 
exit 0





