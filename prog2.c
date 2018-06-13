#include <stdio.h>
#include <stdlib.h>

int isValidCommand(char command){
	//if the ascii value of the character is between A-H or between a-h 
	if ( (command >= 65 && command <= 72) || (command >= 97 && command <= 104) ){
		return 1; //true
	}
	return 0; //false
}

void createDirectory(/*char * dirName*/){
	printf("enter the name:");
	
	//validate that the input is correct (doesnt contain '/' or is an empty string)

}

void createFile(/*char * fileName*/){
	printf("enter the name:");
}

void readFromFile(){
	printf("enter the name:");
}

void writeToFile(/*char * fileName, char * mode*/){
	printf("enter the name:");
}

void printFile(){
	printf("enter the name:"); 
}

void printDir(){
	
}

int main(){
	printf("Welcome to the super multiprocessing file editron 3000\n");
	printf("A) Create a new directorry file\n");
	printf("B) Create a new regular file\n");
	printf("C) Create child process to write sorted output\n");
	printf("D) Create child process to shadow write/read regular files\n");
	printf("E) Read from a file (print out to stdout)\n");
	printf("F) Write to a file in either insert, append, or overwrite mode\n");
	printf("G) Print file status (print out to stdout)\n");
	printf("H) Print directory listing (contents of dir file) (print out to stdout)\n");
	printf("Please select an option: ");
	char command;

	// get input from the user and contine only if its valid
	command = getchar(); ///gets(command,64,stdin);
	while (!isValidCommand(command)){
		printf("please enter a character from A to H:");
		command = getchar();
	}

	// process the user command
	switch(command)
	{
		case 'a':
		case 'A': 
			createDirectory();
			break;
		case 'b':
		case 'B': 
			createFile();
			break;
		case 'c':
		case 'C': 

			break;	
		case 'd':
		case 'D': 

			break;
		case 'e':
		case 'E': 
			readFromFile();
			break;
		case 'f':
		case 'F': 
			writeToFile();
			break;
		case 'g':
		case 'G': 
			printFileStatus();
			break;
		case 'h':
		case 'H': 
			printDir();
			break;
		default:
			printf("invalid command");
	}


	return 0;
}
