#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char* replace(char* str, char* str1, char* str2){
	int comp = strcmp(str,str1);
	if (comp==0){
		return str2;
	} else {
		return str;
	}
}
