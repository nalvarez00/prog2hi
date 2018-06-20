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

#include <dirent.h>

int isValidCommand(int command, int options);

void getValidCommand(int * command, int options);

struct dirent *ent;
void get_file_name(char*);
void sort(void*,unsigned);
void read_file_to_file(char*,FILE*);
void read_file_to_string(char*,char *);
void write_file(char*);
void status(void);
void dir_listing(char *);

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

FILE *fd;
FILE *p_file;
DIR *dir;
char w_str[256];
char s_cpy[256];
char file_name[256];
int c;

#endif
