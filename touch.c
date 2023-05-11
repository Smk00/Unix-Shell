#include<stdio.h>
#include"touch.h"

int lsh_touch(char **args)
{
    FILE *fp;
    if(args[1]==NULL)
    {
        printf("No argumets passed\n");
        return 1;
    }


    fp = fopen(args[1],"w");
    if(fp==NULL)
    {
        printf("Could not create file\n");
        return 1;
    }
    
    fclose(fp);
    return 1;
}