
#ifndef _a2_h

#define _a2_h


#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <pthread.h>

#include <unistd.h>

#include <sys/stat.h> 

#include <sys/types.h>


int isValidCommand(int command);

void createDirectory();

void createFile();

void readFromFile();

void writeToFile();

void printFile();

void printDir();

void printMainMenu();

void printFileStatus();


#endif
