#!/bin/bash

div () {
	#div function that outputs the largest divisor between two given integers
	#This assumes that the user correctly inputs TWO INTEGERS 
	
	#If both arguments passed are 0 
	if [ $1 -eq 0 ] && [ $2 -eq 0 ] 
	then 
		echo "any number (Cannot have the largest divisor between two zeros)"
		exit 1
	fi
	
	#Setting the two inputs of this function (to be always positive), using bc to 
	#evaluate the sqrt(x^2).
	X=`echo "sqrt($1*$1)" | bc`
	Y=`echo "sqrt($2*$2)" | bc`
	N=0	

	#If conditions below take care of the case if one of the arguments is zero;
	#We just return the other number.
	if [ $X -eq 0 ]
	then
		echo $Y
		exit 0
	elif [ $Y -eq 0 ]
	then 
		echo $X
		exit 0
	fi

	#Picks the value of N depending on whether X or Y is smaller. 
	if [ $X -le $Y ]
	then
		N=$X
	elif [ $Y -lt $X ]
	then
		N=$Y
	fi
	
	#Checks whether both numbers are divisible by N. If one of them is not, then 
	#decrease N by 1, else if both are divisible, then stop the while loop.
	while [ `echo "$X%$N" | bc` -ne 0 ] || [ `echo "$Y%$N" | bc` -ne 0 ]
	do 
		N=`echo "$N-1" | bc`
	done

	#Returns the value of N 
	echo $N
}

#While loop condition keeps going if answer of the user is y
answer="y"

while [ $answer = "y" ]
do
	#Asking user for numbers
	echo "Enter first number:"
	read X 	#Reads the user input
	echo "Enter second number:"
	read Y  #Reads the user input

	#Calls in div and assigns it to N 
	N=$( div $X $Y )
	
	#Ouputs the answer
	echo "Largest divisor of $X and $Y is $N"
	#Asks the user if they want to continue and updates answer 
	echo "Do you wish to continue ?"
	read answer
done
