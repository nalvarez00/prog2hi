
#ifndef _a2_h

#define _a2_h


#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <string.h>

#include <pthread.h>

#include <unistd.h>

#include <sys/stat.h> 

#include <sys/types.h>

#include <sys/wait.h>

#include <fcntl.h>

#include <dirent.h>

int c; //used for flushing stdin to get a new command
pid_t pid1, pid2, pid3; // pid for the processes that will be created when reading writing



void copyFile(char * name, FILE * dest);

void printFile(char * name, char * str);

int isValidCommand(int command, int options);

void getValidCommand(int * command, int options);

void getFileName(char * name);

void createDirectory();

void createFile();

void readFromFile();

void writeToFile();

void printDir();

void printMainMenu();

void printMenu6();

void printFileStatus();

void appendMode();

void overwriteMode();

void insertMode();

#endif
