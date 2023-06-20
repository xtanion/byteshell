#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <readline/readline.h>
#include "headers/parse.h" //include declarations for parse-related structs

enum BUILTIN_COMMANDS
{
    NO_SUCH_BUILTIN = 0,
    EXIT,
    JOBS
};

int isBuiltInCommand(char *cmd)
{

    if (strncmp(cmd, "exit", strlen("exit")) == 0)
    {
        return EXIT;
    }
    return NO_SUCH_BUILTIN;
}

int main(int argc, char **argv)
{

    char *cmdLine;
    parseInfo *info;         // info stores all the information returned by parser.
    struct commandType *com; // com stores command name and Arg list for one command.
    fprintf(stderr, "press ctrl-c to exit\n");

    while (1)
    {
        cmdLine = readline("bruh > ");
        printf("Enterinng loop %s\n", cmdLine);
        // TODO: Display History
        
        info = parse(cmdLine);

        // If command exist, execute

        if (info == NULL)
        {
            free(cmdLine);
            continue;
        }

        free_info(info);
        free(cmdLine);
    }
}
