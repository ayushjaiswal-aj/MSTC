#include<stdio.h>
#include<stdlib.h>
	
int a, b, c, d, e, f;

int main(void){
	printf("Enter a:");
	scanf("%d", &a);

	printf("Enter b:");
	scanf("%d", &b);
	
	printf("Enter c:");
	scanf("%d", &c);
	
	printf("Enter d:");
	scanf("%d", &d);

	printf("Enter e:");
	scanf("%d", &e);
	
	printf("Enter f:");
	scanf("%d", &f);
	
	if (a <= b){
		puts("if block is executed");
	} else if (c >= d) {
	 	puts("else if 1 block is executed");
	} else if (e == f) {
		puts("else is 2 block is executed");
	} else {
		puts("all conditions are false");
	}

	exit (0);

}

