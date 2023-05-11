#include<stdio.h>
#include <sys/stat.h>
#include"mkdir.h"

int lsh_mkdir(char **args)
{
  int index = 1;
  if(args[1]== NULL)
  {
      printf("No name argument passed\n");
      return 1;
  }

  while(args[index]!= NULL)
  {
    if(mkdir(args[index],0777) == -1)
    {
      printf("Directory with name %s already exists\n",args[index]);
    }
    index++;

  }

  return 1;
}