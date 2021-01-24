#include<stdio.h>
#include<stdlib.h>

int n = 10;
int *p = &n;
int *p1;
int main(void){
	p1 = &n;
	printf("value of n: %d\n", n);
	printf("addres of n: %d\n", &n);
	printf("value of p: %d\n", p);
	printf("value of *p: %d\n", *p);
	printf("value of p1: %d\n", p1);
	return(0);
}
