#include "main.h"


int c; //used for flushing stdin to get a new command

int isValidCommand(int command, int options){
    if ( (command >= 1 && command <= options) ){
        return 1; //true
    }
    return 0; //false
}

void createDirectory(){
    char name[256];
    char currDir[256];
    printf("Enter the name of the directory file: ");
    while ((c = getchar()) != '\n' && c != EOF); //flush stdin
    scanf("%[^\n]s",name);
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
        switch(command)    {
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
    printf("Enter the name of the file you want to read from: ");
   while ((c = getchar()) != '\n' && c != EOF); // flush stdin
   scanf("%[^\n]s",name);
   // FILE * fd = fopen(name,"r");
   // if (fd == NULL){
     //   printf("Error opening file!\n");
    //    exit(1);
    //}
   // while(fgets(fileLine, sizeof(fileLine), fd) != NULL){
    //    printf("%s",fileLine);
    //}﻿
    //fclose(fd);
   
    
    
    
    pid_t pid1;
    get_file_name(name);
    pid1 = fork();
    if(pid1==0){
        //child1
        strcpy(s_cpy,name);
        if((fd = fopen(name,"r"))==NULL){
            perror("");
            exit(1);
        }
        if((fd = fopen(strcat(s_cpy,".bak"),"w"))!=NULL){//if the .bak file already existed.
            remove(s_cpy);            //remove old .bak file
            fclose(fd);
            fd = fopen(s_cpy,"w");    //create new .bak file
        }
        read_file_to_file(name,fd);    //read from original file to .bak file
        read_file_to_file(name,stdout);    //print to terminal
        printf("\n");
        fclose(fd);
    }else if(pid1 > 0){
        wait(NULL);
    }else{
        // fork failed
        printf("fork() failed!\n");
    }
    
    
    
    
    
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
    fprintf(fd, "%s", input);
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
    FILE * fd = fopen(name,"wb");
    if (fd == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fseek(fd, offset, SEEK_SET);
    fprintf(fd, "%s", input);
    fclose(fd);
}

void printDir(){
    DIR *dp;
    struct dirent *ep;
    
    dp = opendir ("./");
    if (dp != NULL)
    {
        while (ep = readdir (dp))
            puts (ep->d_name);
        (void) closedir (dp);
    }
    else
        perror ("Couldn't open the directory");
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
    printf("4) exit\n");
    printf("Please select an option: ");
}


void get_file_name(char str[256]){
    printf("file name: ");
    scanf("%[^\n]s", str);
    //fflush();
}
void read_file_to_file(char *name,FILE *to){
    fd=fopen(name,"r");
    if(fd==NULL)
        perror("");
    else{
        while (( c = getc(fd)) != EOF)
            putc(c,to);
        fclose(fd);
    }
}
void read_file_to_string(char *name,char *arr){
    fd=fopen(name,"r");
    if(fd==NULL)
        perror("");
    else{
        int i=0;
        while (( c = getc(fd)) != EOF){
            arr[i]=c;
            i++;
        }
        arr[i]='\0';
        fclose(fd);
    }
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
        switch(command)    {
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
                writeToFile(); //
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
