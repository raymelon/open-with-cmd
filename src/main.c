/**
 * main.c
 * Opens a file using command prompt
 *
 * (c) April 2015 Raymel Francisco
 *
 * Modified: Nov 2016
 */
#ifndef _WIN32
 	#define _WIN32
#endif

#include <stdio.h>
#include <time.h>
#include "convert_time.c"
/*
 * @discussion	Gets the string length of the file path
 * @param 		arg 	The file path
 * @return		The string length 
 */
const int stringLen(char *arg) {
	int len = 0;
	while(arg[len++] != 0);
	return len;
}

int main(int argc, char *args[]) {

	// exits just in case no command line arguments are present
	if (argc < 1)
		return 0;

	// redirects to Windows Command Prompt if no file supplied
	if (!args[1]) {
		system("title: Open with cmd v1.0");
		fputs("Open with cmd: No input files.\n", stdout);
		system("echo Open with cmd: You will be redirected to Command Prompt. & echo.");
		system("cmd.exe");
		return 0;
	}
	
	do {
		system("cls");
		char command[stringLen(args[1])];
		sprintf(command, "title: %s", args[1]);
		system(command);
		command[0] = 0;
		sprintf(command, "\"%s\"", args[1]);
		time_t start;
		time(&start);
		system(command);
		time_t end;
		time(&end);
		fprintf(stdout, "\nProcess ended in %s-----------------------------\nOpened by Open with cmd.\nPress any key to run again...", convert_time(difftime(end, start)));
	} while (getch());
	return 0;
}
