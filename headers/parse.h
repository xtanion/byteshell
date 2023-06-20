#define MAX_VAR_NUM 10
#define ARG_MAX_SIZE 40

typedef struct
{
    char *command;
    char *arg[ARG_MAX_SIZE];
} parseInfo;

parseInfo *parse(char *);
void free_info(parseInfo *);
void print_info(parseInfo *);
