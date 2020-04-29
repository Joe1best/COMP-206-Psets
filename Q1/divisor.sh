#!/bin/bash

div () {
	#Checks whether the correct number of arguments is passed in the div() function
	if [ $# -ne 2 ]
	then
		echo "Incorrect number of arguments given to $0"
		exit 1
	elif [ $1 -eq 0 ] && [ $2 -eq 0 ] 
	then 
		echo "Cannot have the largest divisor between two zeros"
		exit 1
	fi
	
	#Setting the two inputs of this function (to be always positive
	X=`echo "sqrt($1*$1)" | bc`
	Y=`echo "sqrt($2*$2)" | bc`
	N=0	
	#Takes care of the case if one of the arguments is zero
	if [ $X -eq 0 ]
	then
		return $Y
	elif [ $Y -eq 0 ]
	then 
		return $X
	fi

	#Picks the value of N depending on whether X or Y is smaller 
	if [ $X -le $Y ]
	then
		N=$X
	elif [ $Y -lt $X ]
	then
		N=$Y
	fi
	

	while [ `echo "$X%$N" | bc` -ne 0 ] && [ `echo "$Y%$N" | bc` -ne 0 ]
	do 
		N=`echo "$N-1" | bc`
		echo "$N"
	done

	return $N
}

answer="y"

while [ $answer = "y" ]
do

	echo "Enter first number:"
	read X
	echo "Enter second number:"
	read Y

	N=$( div $X $Y )

	echo "Largest divisor of $X and $Y is $N"
	echo "Do you wish to continue ?"
	read $answer
done




