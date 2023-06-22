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

int sh_exit(){
    // exit();
    return 0;
}