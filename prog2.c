#include "a2.h"

int isValidCommand(int command, int options){
	if ((command >= 1 && command <= options)){
		return 1; //true
	}
	return 0; //false
}

void createDirectory(){
	char name[256];
	char currDir[256];
	printf("Enter the name of the directory file: ");
	while ((c = getchar()) != '\n' && c != EOF); //flush stdin
	scanf("%[^\n]s", name);
	//get curret directory
	getcwd(currDir, sizeof(currDir));
	//add a slash then the name of the new directory
   	strcat(currDir, "/");
	strcat(currDir, name);
	//pass that string to mkdir()
	if(mkdir(currDir, 0777) == -1){
		printf("Error creating directory you want to create\n");
		return;
	}
	printf("created directory: %s", currDir);
}

void createFile(){
	char name[256];
	char currDir[256];
	printf("Enter the name of the file: ");
	while ((c = getchar()) != '\n' && c != EOF); 
	scanf("%[^\n]s",name);
	//store the curret directory in currDir
	getcwd(currDir, sizeof(currDir)); 	
	//add a slash then the name of the new directory
   	strcat(currDir, "/");
	strcat(currDir, name);
	//pass that string to creat()
	if (creat(currDir,S_IRWXU|S_IRWXG|S_IRWXO) == -1){
		printf("Error creating file\n");
		return;
	}
	printf("created file: %s\n", currDir);
}

void getValidCommand(int * command, int options){
	//read in command and if its not valid prompt again
	while (scanf("%d",command) && !isValidCommand(*command, options)){
		//flush stdin to get new command
		while ((c = getchar()) != '\n' && c != EOF); 
		printf("please enter a valid number: "); 
	}
}

void writeToFile(/*char * fileName, char * mode*/){
	int command;
	int flag = 1;
	while (flag == 1){
		printMenu6();
		// get input from the user and contine only if its valid
		getValidCommand(&command,4); 
		// process the users command
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
		default:
			//flush stdin to get new command
			while ((c = getchar()) != '\n' && c != EOF); 
			printf("Invalid command\n");
			break;
		}
	}
}

void readFromFile(){
	char name[256];
    char fileLine[256];
    char copyName[256];
    FILE * fd;
    getFileName(name);
    pid1 = fork();
    if(pid1 == 0){ //child process
        strcpy(copyName,name);
        if((fd = fopen(name,"r")) == NULL){
            perror("Error opening file!\n");
            exit(1);
        }
        //if the copy already existed.
        if((fd = fopen(strcat(copyName,".bak"),"w"))!= NULL){
            remove(copyName); //remove old .bak file
            fclose(fd);
            fd = fopen(copyName,"w"); //create new copy file
        }
        copyFile(name, fd); //write contents from original file to copy file
        printFile(name, stdout); //print to terminal
        fclose(fd);
    } else if (pid1 > 0) { //parent process
        wait(NULL); 
    } else {
        printf("fork() fail\n");
    }
}

void copyFile(char * name, FILE * dest){
	FILE * fd;
    if ((fd = fopen(name,"r")) == NULL){
        perror("Error opening file!\n");
        exit(1);
    } 
    while ((c = getc(fd)) != EOF){
        putc(c, dest);
	}
    fclose(fd);
    
}

void printFile(char * name, char * str){
	int i = 0;
	FILE * fd;
	if ((fd = fopen(name,"r")) == NULL){
        perror("Error opening file!\n");
        exit(1);
    } 
    while ((c = getc(fd)) != EOF){
        printf("%c", c);
    }
    fclose(fd);
    printf("\n");
}

void appendMode(){
	char name[256];
	char input[256];
	printf("Enter the name of the file you want to append to: ");
	while ((c = getchar()) != '\n' && c != EOF); // flush stdin
	scanf("%[^\n]s",name);
	printf("Enter what you want to write: ");
	while ((c = getchar()) != '\n' && c != EOF); // flush stdin
	fgets(input, sizeof(input), stdin);
	FILE * fd = fopen(name,"a"); 
	if (fd == NULL){
	    printf("Error opening file!\n");
	    exit(1);
	}
	fprintf(fd, "%s\n", input);
	fclose(fd);
}

void overwriteMode(){
	char name[256];
	char input[256];
	printf("Enter the name of the file you want to overwrite: ");
	while ((c = getchar()) != '\n' && c != EOF); // flush stdin
	scanf("%[^\n]s",name);
	printf("Enter what you want to write: ");
	while ((c = getchar()) != '\n' && c != EOF); // flush stdin
	fgets(input, sizeof(input), stdin);
	FILE * fd = fopen(name,"w"); 
	if (fd == NULL){
	    printf("Error opening file!\n");
	    exit(1);
	}
	fprintf(fd, "%s", input);
	fclose(fd);
}

void insertMode(){
	char name[256];
	char input[256];
	int offset;
	printf("Enter the name of the file you want to insert to: ");
	while ((c = getchar()) != '\n' && c != EOF); // flush stdin
	scanf("%[^\n]s", name);
	printf("Enter the position where you want to insert: ");
	scanf("%d", &offset);
	printf("Enter what you want to write: ");
	while ((c = getchar()) != '\n' && c != EOF); // flush stdin
	scanf("%[^\n]s",input);

	FILE * fd = fopen(name,"r+"); 
	if (fd == NULL){
	    printf("Error opening file!\n");
	    exit(1);
	}
	fseek(fd, offset, SEEK_SET);
	fprintf(fd, "%s", input);
	fclose(fd);
}

void printDir(){
	char currDir[254];
	DIR * d;
	struct dirent *dir;
	printf("Printing the files in the current directory:\n");
	d = opendir("./");
	if (d != NULL) {
        while (dir = readdir(d))
            puts(dir->d_name);
        (void) closedir (d);
    } else {
        perror("Couldn't open the directory\n");
    }
}

void printFileStatus(){
	struct stat info;
	char name[256];
	char currDir[256];
	printf("Enter the name of the file: ");
	while ((c = getchar()) != '\n' && c != EOF); 
	scanf("%[^\n]s",name);
	//store the curret directory in currDir
	getcwd(currDir, sizeof(currDir)); 	
	//add a slash then the name of the new directory
   	strcat(currDir, "/");
	strcat(currDir, name);
	if (stat(currDir, &info) == -1){
		printf("Error opening file!\n");
	    exit(1);
	}
	printf("  inode: %d\n", (int)info.st_ino);
	printf(" dev id: %d\n", (int)info.st_dev);
	printf("   mode: %08x\n", (int)info.st_mode);
	printf("  links: %d\n", (int)info.st_nlink);
	printf("    uid: %d\n", (int)info.st_uid);
	printf("    gid: %d\n", (int)info.st_gid);
	printf("   size: %d bytes\n", (int)info.st_size);
}

void printMainMenu(){
	printf("\n1) Create a new directory file\n");
	printf("2) Create a new regular file\n");
	//printf("3) Create child process to write sorted output\n");
	//printf("4) Create child process to shadow write/read regular files\n");
	printf("3) Read from a file (print out to stdout)\n");
	printf("4) Write to a file in either insert, append, or overwrite mode\n");
	printf("5) Print file status (print out to stdout)\n");
	printf("6) Print directory listing (contents of dir file) (print out to stdout)\n");
	printf("7) Exit\n");
	printf("Please select an option: ");
}

//print the menu for option 6 in the main menu
void printMenu6(){
	printf("\n1) Append to a file\n");
	printf("2) Overwrite a file\n");
	printf("3) Insert into a file\n");
	printf("4) Go back to main menu\n");
	printf("Please select an option: ");
}

void getFileName(char name[256]){
	while ((c = getchar()) != '\n' && c != EOF);
    printf("file name: ");
    scanf("%[^\n]s",name);
    while ((c = getchar()) != '\n' && c != EOF);
 }

int main(){
	printf("Welcome to the super multiprocessing file editron 3000\n");
	int command;
	int flag = 1;
	// display the menu until the user exits
	while (flag == 1){
		printMainMenu();
		// get input from the user and contine only if its valid
		getValidCommand(&command,7);
		// process the user command
		switch(command)	{
		case 1:
			createDirectory();
			break;
		case 2: 
			createFile();
			break;
		case 3: 
			readFromFile();
			break;
		case 4: 
			writeToFile(); 
			break;
		case 5: 
			printFileStatus();
			break;
		case 6:
			printDir();
			break;
		case 7:
			flag = 0; //exit
			break;
		default:
			//flush the buffer 
			while ((c = getchar()) != '\n' && c != EOF);
			printf("Invalid command\n");
		} 
	}
	return 0;
}
