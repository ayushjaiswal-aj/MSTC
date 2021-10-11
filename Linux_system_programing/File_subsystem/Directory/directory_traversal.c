#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0

typedef int flag_t;
typedef int result_t;
typedef int len_t;
typedef int bool;

result_t walk(char *path);
char* join(const char *dir_name, const char *base_name);
bool is_dir(const char *path);
void print_usage();
void print_version();
void *xcalloc(int nr_elements, int size_per_element);

int main(int argc, char *argv[]){
    int ret, i;
    char *path;
    flag_t n_flag = FALSE;
    result_t rs;

    struct option opts[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"name", required_argument, 0, 'n'},
        {0,0,0,0}
    };

    while((ret = getopt_long(argc, argv, "hvn:", opts, &i)) != -1){
        switch(ret){
            case 'h':
                print_usage();
                exit(EXIT_SUCCESS);

            case 'v':

                print_version();
                exit(EXIT_SUCCESS);
            
            case 'n':
                n_flag = TRUE;
                path = optarg;
                break;
            
            default:
                print_usage();
                exit (EXIT_FAILURE);
        }
    }

    if(n_flag == FALSE){
        print_usage();
        exit(EXIT_FAILURE);
    }

    if(is_dir(path) == FALSE){
        printf("%s\n", path);
        exit(EXIT_SUCCESS);
    }

    rs = walk(path);
    return (EXIT_SUCCESS);
}

result_t walk(char *path){
    DIR *p_dir;
    struct dirent *p_dirent;
    char *next_path;
    int i;

    p_dir = opendir(path);
    printf("%s\n", path);

    while((p_dirent = readdir(p_dir)) != NULL){
        if(((strncmp(p_dirent->d_name, ".", 1) == 0) && (strlen(p_dirent->d_name) == 1)) ||
            ((strncmp(p_dirent->d_name, "..", 2) == 0) && (strlen(p_dirent->d_name) == 2))){
            
            continue;
        }

        next_path = join(path, p_dirent->d_name);

        if(is_dir(next_path)){
            walk (next_path);
        }
        else {
            printf("%s\n", next_path);
        }
        free(next_path);
    }

    closedir(p_dir);
    printf("\n");
    return SUCCESS;
}

bool is_dir(const char *path){
    static struct stat stat_buffer;
    int ret;

    memset (&stat_buffer, (int)'\0', sizeof(struct stat));

    ret = stat(path, &stat_buffer);
    if(ret == -1){
        fprintf(stderr, "stat:%s:%s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return (S_ISDIR (stat_buffer.st_mode) ? TRUE:FALSE);
}

char* join(const char *dir_name, const char *base_name){
    char *rs_path;
    len_t len1, len2;
    int i;

    len1 = strlen(dir_name);
    len2 = strlen(base_name);

    rs_path = (char *) xcalloc((len1 + len2 + 2), sizeof(char));

    for(i = 0; i < len1; i++){
        rs_path[i] = dir_name[i];
    }

    rs_path[i] = '/';

    for(i=0; i<len2; i++){
        rs_path[len1 + 1 + i] = base_name[i];
    }

    return rs_path;
}

void print_usage(void){
    printf("directory_traversal --help/-h: prints help\n--version/-v prints version\n--name/-n: path\n");
}

void print_version(void){
    printf("1.0\n");
}

void* xcalloc(int nr, int size){
    void *ptr = NULL;
    ptr = calloc(nr, size);
    if(ptr == NULL){
        fprintf(stderr, "xcalloc: fatal out of memory\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}