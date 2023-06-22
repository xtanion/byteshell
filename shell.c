#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include "headers/parse.h"
#include "headers/builtin.h"

enum BUILTIN_COMMANDS
{
    NO_SUCH_BUILTIN = 0,
    EXIT
};

int execute(parseInfo* info)
{
    char* cmd = info->command;
    char *arg = info->arg;

    if (strcmp(cmd, "exit") == 0){
        int status = sh_exit();
        return status;
    }else if (strcmp(cmd, "cat")==0){
        sh_cat(arg);
        return EXIT;
    }else if (strcmp(cmd, "clear")==0){
        sh_clear();
        return EXIT;
    }
    else if (strcmp(cmd, "cd") == 0){
        sh_cd(arg);
        return EXIT;
    }else if (strcmp(cmd, "pwd")==0){
        sh_pwd();
        return EXIT;
    }else if (strcmp(cmd, "ls")==0){
        sh_ls();
        return EXIT;
    }

    printf("Not a built-in command, run `help` to see the commands list.\n");
    return EXIT;
}

int shell_launch(char *args){
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0){
        // Child process
        if (execvp(args[0], args) == -1){
            perror("shell error!");
        }
        exit(EXIT_FAILURE);
    }else if (pid < 0){
        // Error forking
        perror("Forking error");
    }else{
        // Parent process
        do{
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
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
        // TODO: Display History
        info = parse(cmdLine);
        int status;

        if (info == NULL){
            free(cmdLine);
            continue;
        }else{
            status = execute(info);
        }
        
        free_info(info);
        free(cmdLine);
        if (status==0)
            break;
    }
}
