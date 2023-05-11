#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// POSIX dependencies
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include"rmr.h"


int lsh_rmr(char *args[1])
{
    size_t path_len;
    char *full_path;
    DIR *dir;
    struct stat stat_path, stat_entry;
    struct dirent *entry;

    // stat for the path
    stat(args[1], &stat_path);

    // if path does not exists or is not dir - exit with status -1
    if (S_ISDIR(stat_path.st_mode) == 0) {
        fprintf(stderr, "%s: %s\n", "Is not directory", args[1]);
        exit(-1);
    }

    // if not possible to read the directory for this user
    if ((dir = opendir(args[1])) == NULL) {
        fprintf(stderr, "%s: %s\n", "Can`t open directory", args[1]);
        exit(-1);
    }

    // the length of the path
    path_len = strlen(args[1]);

    // iteration through entries in the directory
    while ((entry = readdir(dir)) != NULL) {

        // skip entries "." and ".."
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;

        // determinate a full path of an entry
        full_path = calloc(path_len + strlen(entry->d_name) + 1, sizeof(char));
        strcpy(full_path, args[1]);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);

        // stat for the entry
        stat(full_path, &stat_entry);

        // recursively remove a nested directory
        if (S_ISDIR(stat_entry.st_mode) != 0) {
            lsh_rmr(&full_path);
            continue;
        }

        // remove a file object
        if (unlink(full_path) == 0)
            printf("Removed a file: %s\n", full_path);
        else
            printf("Can`t remove a file: %s\n", full_path);
        free(full_path);
    }

    // remove the devastated directory and close the object of it
    if (rmdir(args[1]) == 0)
        printf("Removed a directory: %s\n", args[1]);
    else
        printf("Can`t remove a directory: %s\n", args[1]);

    closedir(dir);
    
    return 1;
}