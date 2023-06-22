// Parser's job is to break each command from shell's input

#include "headers/parse.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TOKEN_DELIM " \t"
#define TOKEN_BUFSIZE 64


parseInfo *parse (char *cmdline) {
	parseInfo *Result;
	char command[81];
	int com_pos = -1;
    if (cmdline[0] == '\n' || cmdline[0] == '\0')
        return NULL;

    Result = malloc(sizeof(parseInfo));

    int bufsize = TOKEN_BUFSIZE, position = 0;
    char *token;

    token = strtok(cmdline, TOKEN_DELIM);
    if (token!=NULL)
        Result->command = token;
    token = strtok(0, cmdline);
    if (token!=NULL)
        Result->arg = token;

    com_pos = 0;

    command[com_pos]='\0';
	
	return Result;
}

void free_info(parseInfo *info)
{
    free(info);
}