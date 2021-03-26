#include <stdio.h>
#include <stdlib.h>

int a[10];

int main(void){
	int i, n, ans;

	int* a = NULL;
	unsigned int size = 0;
	
	while(1){
		printf("Do you want to enter one more integer. YES- 1 | NO- 0\n");
		scanf("%d", &ans);
		if (ans != 1){
			break;
		}
		
		printf("Enter an integer:");
		scanf("%d", &n);

		size = size +1;
		a = realloc(a, size * sizeof(int));
		a[size-1] = n;
	}

	for (i=0; i<size; i++){
		printf("a[%d]: %d\n", i, a[i]);
	}

	free(a);
	a = NULL;

	return (0);
}
