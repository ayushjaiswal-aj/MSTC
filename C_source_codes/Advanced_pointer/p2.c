/* Declare a pointer to array 5 of integer */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i;
	int m;

	pA = &a;

	for (i = 0; i < 5; i++){
		m = (*pA)[i];
		printf("m = %d\n", m);
	}

	return 0;
}
