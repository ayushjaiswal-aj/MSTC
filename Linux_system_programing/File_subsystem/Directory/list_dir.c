#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[]){
    DIR *dir_p;
    struct dirent *dirent_p;

    if(argc != 2){
        fprintf(stderr, "Usage error: %s <dir_name>\n", argv[0]);
        exit (EXIT_FAILURE);
    }

    dir_p = opendir(argv[1]);
    if(!dir_p){
        fprintf(stderr, "error in opening directory %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while((dirent_p = readdir(dir_p)) != NULL){
        printf("%s\n", dirent_p->d_name);
    }

    if(closedir(dir_p) == -1){
        fprintf(stderr, "error in closing directory %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    exit (EXIT_SUCCESS);
}