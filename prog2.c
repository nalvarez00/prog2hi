
#include "a2.h"

int isValidCommand(int command, int n){
	if ( (command >= 0 && command < n ) ){
		return 1; //true
	}
	return 0; //false
}

void createDirectory(){
	char dirName[256];
	char currDir[256];
	printf("enter the name of the directory file:");
	//validate that the input is correct (doesnt contain '/' or is an empty string)
	
	fgets(dirName, sizeof(dirName), stdin);
	printf("you entered: %s ",dirName);
	//get curret directory
	getcwd(currDir, sizeof(currDir)); 	
   	//concatonate the 2 strings
	strcat(currDir, dirName);
	//pass that string to mkdir("concatonated str")
	mkdir(dirName, umask(000));
	printf("created directory: %s ",dirName);

}

void createFile(/*char * fileName*/){
	printf("enter the name:");
}

void readFromFile(){
	printf("enter the name:");
}

void getCommand(){}

void writeToFile(/*char * fileName, char * mode*/){
	printf("enter the mode in which to open the file");
	printf("\n1) Append to an exisiting file\n");
	printf("2) Overwrite an existing file\n");
	printf("3) Insert into an exisitng file\n");
	printf("0) exit\n");
	int command;
	//get input from user and continue only if its valid
	scanf("%d",&command);
	while (!isValidCommand(command,4)){
		printf("please enter a valid number:");
		scanf("%d",&command); 
	}
	//process the users command
	int flag = 1;
	while (flag == 1){
		printMainMenu();
		// get input from the user and contine only if its valid
		scanf("%d",&command);
		while (!isValidCommand(command,9)){
			printf("please enter a valid number:");
			scanf("%d",&command); 
		}
		switch(command)	{
		case 0:
			flag = 0;
			break;
		case 1:
			appendMode();
			break;
		case 2: 
			overwriteMode();
			break;
		case 3: 
			insertMode();
			break;	
		}
	}
}

void appendMode(){
	printf("appendMode\n");
}

void overwriteMode(){
	printf("overwriteMode\n");
}

void insertMode(){
	printf("insertMode\n");
}

void printFile(){
	printf("enter the name:"); 
}

void printDir(){

}

void printFileStatus(){

}

void printMainMenu(){
	printf("\n1) Create a new directory file\n");
	printf("2) Create a new regular file\n");
	printf("3) Create child process to write sorted output\n");
	printf("4) Create child process to shadow write/read regular files\n");
	printf("5) Read from a file (print out to stdout)\n");
	printf("6) Write to a file in either insert, append, or overwrite mode\n");
	printf("7) Print file status (print out to stdout)\n");
	printf("8) Print directory listing (contents of dir file) (print out to stdout)\n");
	printf("0) Exit\n");
	printf("Please select an option: ");
}

int main(){
	printf("Welcome to the super multiprocessing file editron 3000\n");
	int command;
	// process the user command
	int flag = 1;
	while (flag == 1){
		printMainMenu();
		// get input from the user and contine only if its valid
		scanf("%d",&command);
		while (!isValidCommand(command,8)){
			printf("please enter a valid number:");
			scanf("%d",&command); 
		}
		switch(command)	{
		case 0:
			flag = 0;
			break;
		case 1:
			createDirectory();
			break;
		case 2: 
			createFile();
			break;
		case 3: 

			break;	
		case 4: 

			break;
		case 5: 
 
			readFromFile();
			break;
		case 6: 
			writeToFile(); //
			break;
		case 7: 
			printFileStatus();
			break;
		case 8:
			printDir();
			break;
		default:
			printf("invalid command");
		}
	}
	return 0;
}

