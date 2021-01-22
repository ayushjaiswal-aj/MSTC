#include<stdio.h>
#include<stdlib.h>

int n1;
int n2;

int main(void){
        printf("U: Enter n1: ");
        scanf("%d", &n1);
        printf("U: Enter n2: ");
        scanf("%d", &n2);

        if (n1 <= n2){
                puts("C: n1 is less than or equal to n2");
        }
 
        puts("U: End of program");
        exit(0);
}

