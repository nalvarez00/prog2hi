#include "a2.h"

int c;

int isValidCommand(int command, int options){
	if ( (command >= 1 && command <= options ) ){
		return 1; //true
	}
	return 0; //false
}

void createDirectory(){
	char name[256];
	char currDir[256];
	printf("enter the name of the directory file: ");
	while ((c = getchar()) != '\n' && c != EOF); 
	fgets(name, sizeof(name), stdin);
	//get curret directory
	getcwd(currDir, sizeof(currDir)); 	
	//add a slash then the name of the new directory
   	strcat(currDir, "/");
	strcat(currDir, name);
	//pass that string to mkdir()
	mkdir(currDir, umask(0000));
	printf("created directory: %s \n", currDir);
}

void createFile(){
	char name[256];
	char currDir[256];
	printf("enter the name of the file: ");
	while ((c = getchar()) != '\n' && c != EOF); 
	fgets(name, sizeof(name), stdin);
	//store the curret directory in currDir
	getcwd(currDir, sizeof(currDir)); 	
	//add a slash then the name of the new directory
   	strcat(currDir, "/");
	strcat(currDir, name);
	//pass that string to mkdir()
	creat(currDir, umask(0000));
	printf("created file: %s \n", currDir);
}

void readFromFile(){
	printf("enter the name:");
}

void getValidCommand(int * command, int options){
	while (scanf("%d",command) && !isValidCommand(*command, options)){
		// get rid of newline/EOF characters in stdin
		while ((c = getchar()) != '\n' && c != EOF); 
		printf("please enter a valid number:"); 
	}
}

void writeToFile(/*char * fileName, char * mode*/){
	int command;
	int flag = 1;
	while (flag == 1){
		printMenu6();
		// get input from the user and contine only if its valid
		getValidCommand(&command,4); 
		//process the users command
		switch(command)	{
		case 1:
			appendMode();
			break;
		case 2: 
			overwriteMode();
			break;
		case 3: 
			insertMode();
			break;	
		case 4:
			flag = 0;
			break;
		}
		while ((c = getchar()) != '\n' && c != EOF); 
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
	printf("9) Exit\n");
	printf("Please select an option: ");
}

//print the menu for option 6 in the main menu
void printMenu6(){
	printf("\n1) Append to an exisiting file\n");
	printf("2) Overwrite an existing file\n");
	printf("3) Insert into an exisitng file\n");
	printf("4) exit\n");
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
		getValidCommand(&command,9);
		switch(command)	{
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
		case 9:
			flag = 0;
			break;
		default:
			while ((c = getchar()) != '\n' && c != EOF);
			printf("invalid command");
		} 
	}
	return 0;
}
