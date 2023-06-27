#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_CHAR_SIZE 100
#define MAX_WIDTH 80
#define MAX_HEIGHT 80
#define MAX_PIXEL_INTENSITY 255

#define NORMAL "\x1B[0m"
#define BLUE "\x1B[34m"

int sh_help();
int sh_cat(char *count);
int sh_clear();
int sh_cd(char *path);
int sh_pwd();
int sh_exit();