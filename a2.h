
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

#include <fcntl.h>

int isInt(char *str);

int isValidCommand(int command, int options);

void getValidCommand(int * command, int options);

void createDirectory();

void createFile();

void readFromFile();

void writeToFile();

void printFile();

void printDir();

void printMainMenu();

void printMenu6();

void printFileStatus();

void appendMode();

void overwriteMode();

void insertMode();


#endif
