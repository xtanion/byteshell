#include<stdio.h>
#include<string.h>
#include <unistd.h>

int sh_cat(int *count){
    int MAX = 5;
    if (count>MAX){
        printf("MEOOOOOOWWW !!!");
        return 1;
    }
    while (count)
    {
        printf("Meow ");
        count--;
    }
    printf("\n");
    return 1;
}