#include<stdio.h>
#include<stdlib.h>

int n1, n2;
int sum;

int main(void){
	puts("This is a start of the program");
	
	printf("Enter n1: ");
	scanf("%d", &n1);
	
	printf("Enter n2: ");
	scanf("%d", &n2);
	
	if (n1 > n2){
		sum = n1 -n2;
	} else {
		sum = n1 + n2;
	}

	printf("sum = %d\n" ,sum);
	puts("This is the end of the program");
	exit(0);
}
