#!/bin/bash

div() {
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
	
	#Setting the two inputs of this function (to be always positive)
	X = abs($1)
	Y = abs($2)
	
	#Takes care of the case if one of the arguments is zero
	if [ X -eq 0 ]
	then
		return $Y
	elif [ Y -eq 0 ]
	then 
		return $X
	fi

	#Picks the value of N depending on whether X or Y is smaller 
	if [ X -le Y ]
	then
		N = $X
	elif [ Y -lt X ]
	then
		N = $Y
	fi

	while [ X%N -ne 0 ] && [ Y%N -ne 0]
	do 
		N = $N - 1
	done

	return $N

}



