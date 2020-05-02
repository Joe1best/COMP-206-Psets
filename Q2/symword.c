#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	if (argc != 2){
		fprintf(stderr, "Error, this function only takes in one argument\n");
		exit(2);
	}
	//Calculates the length of the string
	int size = strlen(argv[1]);
	
	//If the word is odd in length 
	if (size%2==1){
		int indexMid = size/2;
		
		//How many times we compared the left and right side of the indexMid
		int count = 1;
		
		//How many characters we considered 
		int updatedSize = 1;
		
		//In the odd case, to see if a word is a palindrome, we start by the middle index
		//and go count times to the left and count times to right, while comparing both 
		//if they are not equal, it just means the word is not a palindrome and we can 
		//exit with code 1 as instructed. If both are equal, we updated the size of 
		//the characters visited by doing 2*count + 1 and move on to the next pair. 	
		while (updatedSize!=size) {
			if (argv[1][indexMid-count] == argv[1][indexMid+count]){
				updatedSize = 2*count +1;
				count = count+1;
			} else {
				exit(1); 
			}
		}

		//If it survives the entire while loop, then the word is symmetric since
		//it never went in the else condition
		exit(0);

	//If the length of the string is even 
	} else {
		//Index of the left
		int leftIndex = 0; 

		//Index of the right
		int rightIndex = size - 1;

		//In the even case, we start with the leftmost character (leftIndex) and rightmost
		//character (rightIndex). We compare those two as we move both indices towards the
		//middle of the word. Keep doing this until the leftmost index is higher than the 
		//rightmost index or if when comparing, the characters at both indices are not the 
		//same.
		while (leftIndex<rightIndex){
			if (argv[1][rightIndex] == argv[1][leftIndex]){
				//Updates the indices by moving left forward and right backwards
				leftIndex = leftIndex + 1;
				rightIndex = rightIndex -1;
			} else {
				exit(1);
			}
		}
		//If it survives the while loop, it means it always went in the if condition, which 
		//means the word is symmetric
		exit(0);
	}
}
