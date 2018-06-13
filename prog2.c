
#include "a2.h"

mode_t getumask(void); 

int isValidCommand(int command){
	//if the ascii value of the character is between A-H or between a-h 
	if ( (command >= 0 && command <= 8 ) ){
		return 1; //true
	}
	return 0; //false
}

void createDirectory(){
	char dirName[256];
	char currDir[256];
	//char * fullDir[256];
	printf("enter the name of the directory file:");
	//validate that the input is correct (doesnt contain '/' or is an empty string)
	fgets(dirName, sizeof(dirName), stdin);
	//get curret directory
	getcwd(currDir, sizeof(currDir)); 	
   	//concatonate the 2 strings
	strcat(currDir, dirName);
	//pass that string to mkdir("concatonated str")
	mkdir(dirName, umask(0));
	printf("created directory: %s ",dirName);

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

void printFileStatus(){

}

void printMainMenu(){
	printf("\n1) Create a new directorry file\n");
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
		scanf("%d",&command); ///gets(command,64,stdin);
		while (!isValidCommand(command)){
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

