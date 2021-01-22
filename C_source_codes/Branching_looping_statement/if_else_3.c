#include<stdio.h>
#include<stdlib.h>
	
int a, b;
unsigned int c, d;

int main(void){

	printf("Enter a: ");
	scanf("%d", &a);

	printf("Enter b: ");
	scanf("%d", &b);
		
	printf("Enter c: ");
	scanf("%u", &c);
	
	printf("Enter d: ");
	scanf("%u", &d);
	
	if (a > b || c < d){
		puts("True");
	} else {
		puts("false");
	}
	
	exit (0);

}
