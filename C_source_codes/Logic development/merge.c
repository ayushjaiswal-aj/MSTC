#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

void merge(int* pa, int p, int q, int r);
void merge2(int* pa, int p, int q, int r);

int main(void){
	int a[] = {10, 20, 30, 40, 50, 15, 25, 35, 45, 55, 65};
	int size_a = sizeof(a)/sizeof(a[0]);
	int p = 0, q = 4, r = size_a - 1;
	int i;

	puts("Before merge:");
	for (i = 0; i < size_a; i++){
		printf("a[%d]: %d\n", i, a[i]);
	}

	merge(a, p, q, r);

	puts("After merge:");
	for (i = 0; i < size_a; i++){
		printf("a[%d]: %d\n", i, a[i]);
	}

	return (EXIT_SUCCESS);
}

void merge(int* pa, int p, int q, int r){
	int n1, n2;

	int* pa1 = NULL;
	int* pa2 = NULL;

	n1 = q - p + 1;
	n2 = r - q;

	int i, j, k;

	pa1 = (int*) malloc(n1 * sizeof(int));
	if(pa1 == NULL){
		puts("fatal: not enough memory");
		exit (EXIT_FAILURE);
	}

	pa2 = (int*) malloc(n2 * sizeof(int));
	if (pa2 == NULL){
		puts("fatal: not enough memory");
		exit (EXIT_FAILURE);
	}

	for (i = 0; i < n1; i++){
		pa1[i] = pa[p+i];
	}

	for (i = 0; i < n2; i++){
		pa2[i] = pa[q+i+1];
	}

	i = 0;
	j = 0;
	k = 0;

	while (TRUE){
		if (pa1[i] <= pa2[j]){
			pa[p+k] = pa1[i];
			i++;
			k++;
			if (i == n1){
				while (j<n2){
					pa[p+k] = pa2[j];
					j++;
					k++;
				}
				break;
			}
		}
		else {
			pa[p+k] = pa2[j];
			j++;
			k++;
			if (j == n2){
				while (i < n1){
					pa[p+k] = pa1[i];
					i++;
					k++;
				}
				break;
			}
		}
	}
	free (pa1);
	pa1 = NULL;
	free (pa2);
	pa2 = NULL;

}
