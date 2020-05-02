
//Name: Youssef Bestavros
//Department: Physics 
//Description: This code implements a bank application that has three capabilities. 
//		i) Add an account number
//		ii) Make a deposit
//		iii) Make a withdrawal 
//Everything is stored in a CSV file called bankdata.csv. 
//
//History: 11 March: Started the assignment. Implemented the scan and totalbalance function. 
//		     Coded up the cases where the user gives in the optional input of -a
//		     -d.  
//         12 March: Added the -w options. Was giving segmentation fault. Gave up for today 
//         13 March: fixed the issue. Had to do with type casting in the total balance.  


//Importing packages 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Function that returns 1 if the user exits in the bankdata.csv and 0 else. 
int scan(char *filename, int accountNum){
	//Starts with a pointer, and opens it
	FILE *fPointer;
	fPointer = fopen(filename, "r");
	char line[38];
	
	while (fgets(line,sizeof(line),fPointer)){
		//if the first character of the line begins with an A, it 
		//means that it is the line that contains AX and hence
		//an account
		if (line[0]=='A'){
			//Extracts AC but we do not want that 
			char * splits = strtok(line,",");
			//Split again to extract the account number
			splits = strtok(NULL,",");
			char * bank_num = splits;
			//If the name and the account number is the same 	
			int acc = atoi(bank_num);
			if (acc==accountNum){
				return 1;
			}
		}		
	} 
	fclose(fPointer);
	//Returns 0 if the code survives the while loop. 
	return 0;

}


//Function that calculates the total balance of a bank account given the account
//number and filename. 
float totalBalance(char *filename,int num_account){
	FILE *fPointer;
	fPointer = fopen(filename, "r");
	char line[100];

	//Initializing some variables 
	float balance=0; 
	float trans=0;
	int acc = 0;
	while (fgets(line,sizeof(line),fPointer)){
		
		//If a line begins with T, it means that it is TX which is a 
		//transcation. 
		if (line[0] == 'T'){
			//Extracts TX 
			char * splits = strtok(line,",");
			char * account;
			//This for loop keeps extracting the strings seperated 
			//by , until the very last one which is the amount. This 
			//is done whilst keeping the string from the last iteration 
			for (int i=0;i<2;i++){
				account = splits;
				splits = strtok(NULL,",");
			}
			splits = strtok(NULL,",");
			trans= atof(splits);
			//Compare to see if the same bank number 
			acc = atoi(account);
			if (num_account==acc){
				balance = balance + trans; //updates balance
			}
		}
	}
	fclose(fPointer);
	return balance;
}

//Main Method 
int main(int argc,char *argv[])
{
	//Need to checks whether the csv file exists in the directory 
	//If not, we terminate with exit code 100 
	FILE *file;
	if (!(file= fopen("bankdata.csv","r"))){
		fprintf(stderr, "%s","Error, unable to locate the data file bankdata.csv\n");
		exit(100);	
	}
	//If there are no arguments given
	if (argc == 1){
		fprintf(stderr, "Error, incorrect usage!\n-a ACCTNUM NAME\n-d ACCTNUM DATE AMOUNT\n-w ACCTNUM DATE AMOUNT\n");
		exit(1);
	}
	//If we give the command line the option of -a. Need to check whether the number of 
	//inputs equals 4 or not. If it is, we scan the file to see whether this account 
	//already exists or not using the scan function defined above 	
	file = fopen("bankdata.csv","a");

	if (strcmp(argv[1],"-a")==0) {
		if ( argc !=4 ) {
			fprintf(stderr,"%s","Error, incorrect usage!\n-a ACCTNUM NAME\n");
			exit(1);
		}

		// If the account does not exist, append it.
		if (scan("bankdata.csv",atoi(argv[2]))==0) {
			char line[38];
			strcpy(line,"AC,");
			strcat(line,argv[2]);
			strcat(line,",");
			strcat(line,argv[3]);
			strcat(line,"\n");	
			fputs(line,file);		
			exit(0);
		//If the account number exists, print an error message with exit code 50
		} else {		
			fprintf(stderr, "Error, account number %s already exists\n", argv[2]);
			exit(50);
		}

	//The deposit option implemented here 
	} else if (strcmp(argv[1],"-d")==0){
		// If the number of arguments are not the number expected whivh is 4+1 
		if ( argc !=5 ) {
			fprintf(stderr, "%s", "Error, incorrect usage!\n-d ACCTNUM DATE AMOUNT\n");
			exit(1);
		} 	
		//Sacn method to see whether the bank account already exists or not
		int cond = scan("bankdata.csv", atoi(argv[2]));
		if (cond==0) { 
			fprintf(stderr,"Error, account number %s does not exist\n", argv[2]);
			exit(50);
		}
		//If the bank account does not exist, append it.
		char line[50];
		strcpy(line,"TX,");
		strcat(line,argv[2]);
		strcat(line,",");
		strcat(line,argv[3]);
		strcat(line,",");
		strcat(line,argv[4]);
		strcat(line, "\n");
		fputs(line,file);
		exit(0);

	//The withdraw option
	} else if (strcmp(argv[1],"-w")==0){
		//Checking whether inputs are used correctly 
		if ( argc != 5 ) { 
			fprintf(stderr, "%s", "Error, incorrect usage!\n-w ACCTNUM DATE AMOUNT\n");
			exit(1);
		//If the bank account that we are trying to withdraw money from does not exist 
		//then print an error message 
		} else if (scan("bankdata.csv",atoi(argv[2]))==0) { 
			fprintf(stderr, "Error, account number %s does not exist\n", argv[2]);
			exit(50);
		//If we are trying to withdraw negative money, you cant do that 
		} else if (atof(argv[4])<0) {
			fprintf(stderr, "%s", "Cannot withdraw negative money homie!\n");
			exit(420);
		}
		//Get the total balance using the bank number
		float b = totalBalance("bankdata.csv",atoi(argv[2]));
		float input = atof(argv[4]);
		
		//If the amount withdrew is bigger than what you have in your bank account. You cant
		//do that 
		if (input > b) {
			fprintf(stderr,"Error, account number %s has only %.2f\n",argv[2] ,b);
			exit(60);
		} else {
			//Append the withdraw transaction
			char line[100];
		 	strcpy(line,"TX,");
	                strcat(line,argv[2]);	
			strcat(line,",");
			strcat(line,argv[3]);
			strcat(line,",-");
			strcat(line,argv[4]);
			strcat(line,"\n");
	                fputs(line,file);
			exit(0);		
		}
	}
	fclose(file);	
}

