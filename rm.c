#include<stdio.h>
#include"rm.h"

int lsh_rm(char **args)
{
    if(args[1]==NULL)
    {
        printf("No parametars passed\n");
        return 1;
    }
    if(remove(args[1])!=0)
    {
        printf("Could not remove the file\n");
    }
    return 1;
}