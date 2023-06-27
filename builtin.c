#include "headers/builtin.h"


int sh_cat(char *c){
    if (c == NULL)
    {
        puts(
            " /\\_/\\  \n"
            "( o.o )\n"
            " > ^ < ");
        return 1;
    }

    int count = atoi(c);
    int MAX = 5;
    if (count>MAX){
        printf("MEOOOOOOWWW !!!\n");
        return 1;
    }
    while (count>0)
    {
        printf("Meow ");
        count--;
    }
    printf("\n");
    return 1;
}

int sh_clear(){
    #ifdef __unix__
        system("clear");
    #elif __linux__
        system("clear");
    #elif _WIN32
        system.cls();
    #else
        #define PLATFORM_NAME NULL
    
    #endif
        return 1;
}

int sh_ls(){
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d){
        while ((dir = readdir(d)) != NULL){
            if(dir->d_type == DT_DIR)
                printf("%s%s%s ", BLUE, dir->d_name, NORMAL);
            else
                printf("%s ", dir->d_name);
        }
        closedir(d);
        printf("\n");
    }
    return 1;
}

int sh_cd(char *arg){
    if (arg == NULL){
        printf("psh: expected argument to \"cd\"\n");
    }else{
        if (chdir(arg) != 0){
            perror("psh: Couldn't change directory\n");
        }
    }
    return 1;
}

int sh_pwd(){
    char path[MAX_CHAR_SIZE];
    printf("%s\n", getcwd(path, MAX_CHAR_SIZE));
    return 1;
}

int sh_help(){
    puts(
        "`help` - Shows list of commands\n"
        "`cat` - A cat(args : int / number)\n"
        "`ls` - List all directories and files\n"
        "`cd<path>` - Change directory to `path`\n"
        "`pwd` - The current working directory\n"
        "`clear` - Clears the shell\n"
        "`exit` - Exit from the current shell");
    return 1;
}

int sh_exit(){
    // exit();
    return 0;
}