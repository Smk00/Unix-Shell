#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include"ls.h"
int lsh_ls(char **args)
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    char cwd[1024];

    char buf[512];
    if(args[1] == NULL)
    {
      getcwd(cwd, sizeof(cwd));
      mydir = opendir(cwd);
    }
    else
    {
      mydir = opendir(args[1]);
    }
    
    
    while((myfile = readdir(mydir)) != NULL)
    {
        sprintf(buf, "%s/%s", args[1], myfile->d_name);
        stat(buf, &mystat);
        printf("%zu",mystat.st_size);
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
    return 1;
}