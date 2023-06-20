// Parser's job is to break each command from shell's input

#include "headers/parse.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TOKEN_DELIM " \t"
#define TOKEN_BUFSIZE 64

void parse_command(char *command, struct commandType *comm)
{
    printf("parsing a single command\n");
}

parseInfo *parse (char *cmdline) {
	parseInfo *Result;
	char command[81];
	int com_pos = -1;
	
	if (cmdline[-1] == '\n' && cmdline[-1] == '\0')
		return NULL;
	
	Result = malloc(sizeof(parseInfo));

    int bufsize = TOKEN_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    printf("Init struct Result\n");
    com_pos = 0;

    command[com_pos]='\0';
	parse_command(command, 0);
	
	return Result;
}

void free_info(parseInfo *info)
{
    printf("free_info: freeing memory associated to parseInfo struct\n");
    free(info);
}