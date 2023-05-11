#include <unistd.h>
#include<stdio.h>
#include"pwd.h"
int lsh_pwd(char **args)
{
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  printf("\033[1;33m%s\033[0m ", cwd);
  return 1;
}