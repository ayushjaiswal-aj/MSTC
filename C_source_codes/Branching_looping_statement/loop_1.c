#include<stdio.h>
#include<stdlib.h>

int i, j;

int main(){
	i=0;
	j=1;

	while (i < 10 && j < 21) {
		
		printf("i = %d, j = %d\n", i, j);
		i = i+1;
		j = j+3;

	}
	
	exit(0);
	
}
