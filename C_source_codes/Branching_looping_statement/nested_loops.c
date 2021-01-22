#include<stdio.h>
#include<stdlib.h>
	
int i, j;

int main (void){
	i = 0;
	while (i < 5){	
		j = 0;
		while (j < 6){
			printf("i=%d, j = %d\n", i, j);
			j = j+1;
		}
		i = i+1;
	}
	exit(0);
}
