#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include"rmdir.h"

int lsh_rmdir(char **args)
{
    if(args[1] == NULL)
    {
        printf("No argumets passed\n");
        return 1;
    }

    if(rmdir(args[1])!=0)
    {
        printf("Could not remove direcotory\n");
    }
    return 1;
}