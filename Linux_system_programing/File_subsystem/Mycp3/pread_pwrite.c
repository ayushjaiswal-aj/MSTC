#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/uio.h>

#define STR_EQ 0
#define LONG_OPT 0
#define FALSE 0
#define TRUE 1
#define BUFFER_SIZE 4096

void print_usage(void);
void print_version(void);
void* xcalloc(int, int);
off_t get_curr_offset(char*, int);

char buffer[BUFFER_SIZE];

int main(int argc, char *argv[]){
    int ret, i;
    off_t off;
    char* f_name;
    int fd, rb, wb;
    int name_flag = FALSE, p_flag = FALSE;
    int len;

    struct option opts[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"name", required_argument, 0, 'n'},
        {"p", no_argument, 0, 'p'},
        {0, 0, 0, 0}
    };

    if(argc == 1){
        print_usage();
        exit(EXIT_SUCCESS);
    }
    
    while((ret = getopt_long(argc, argv, "hvn:p", opts, &i)) != -1){
        switch(ret){
            case 'h':
                print_usage();
                exit(EXIT_SUCCESS);
            
            case 'v':
                print_version();
                exit(EXIT_SUCCESS);
            
            case 'n':
                name_flag = TRUE;
                f_name = optarg;
                break;
            
            case 'p':
                p_flag = TRUE;
                break;
            
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }

    fd = open(f_name, O_RDWR | O_APPEND | O_TRUNC);
    if(fd < 0){
        fprintf(stderr, "open:%s:%s\n", f_name, strerror(errno));
        exit(EXIT_FAILURE);
    }

    off = get_curr_offset(f_name, fd);
    printf("offset before reading: %ld\n", off);

    memset(buffer, 'C', BUFFER_SIZE);

    if(p_flag == TRUE){
        rb = pread(fd, buffer, BUFFER_SIZE, SEEK_CUR);
        if(rb < 0){
            fprintf(stderr, "pread:%s:%s\n", f_name, strerror(errno));
            exit(EXIT_FAILURE);
        }
        off = get_curr_offset(f_name, fd);
        printf("offset after pread = %ld\n", off);

        wb = pwrite(fd, buffer, BUFFER_SIZE, off);
        if(wb != BUFFER_SIZE){
            fprintf(stderr, "pwrite:%s:%s\n", f_name, strerror(errno));
            exit(EXIT_FAILURE);
        }
        off = get_curr_offset(f_name, fd);
        printf("offset after pwrite: %ld\n", off);
    }
    else {
        rb = read(fd, buffer, BUFFER_SIZE);
        if(rb == -1){
            fprintf(stderr, "read:%s:%s\n", f_name, strerror(errno));
            exit(EXIT_FAILURE);
        }
        printf("after pread contains of buffer:\n%s\n", buffer);
        off = get_curr_offset(f_name, fd);
        printf("offset after read = %ld\n", off);

        memset(buffer, 'B', BUFFER_SIZE);

        wb = write(fd, buffer, BUFFER_SIZE);
        if(wb != BUFFER_SIZE){
            fprintf(stderr, "write:%s:%s\n", f_name, strerror(errno));
            exit(EXIT_FAILURE);
        }
        off = get_curr_offset(f_name, fd);
        printf("offset after write: %ld\n", off);
    }

    if(close(fd) < 0){
        fprintf(stderr, "close:%s:%s\n", f_name, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

void print_usage(void){
    printf("[option]\n--help/-h: prints help\n--version/-v: prints version/n--name/-n: file name\n--p/-p: p_flag\n");
}

void print_version(void){
    printf("0.1\n");
}

void* xcalloc(int nr, int size){
    void *ptr = NULL;
    ptr = calloc(nr, size);
    if(ptr == NULL){
        printf("calloc: fatal out of memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

off_t get_curr_offset(char *f_name, int fd){
    off_t off;
    off = lseek(fd, 0, SEEK_CUR);
    if(off == -1){
        fprintf(stderr, "get_curr_offset:lseek:%s:%s\n", f_name, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return off;
}