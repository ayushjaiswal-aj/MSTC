#include<stdio.h>
#include<stdlib.h>
	
int a[10] = {23,345,76,3,535,34,22,34,9,333};
int N = 10;
int i, k;
int min_index;
int tmp, cnt;

int main() {
	puts ("Before sorting:");
	for (cnt =0; cnt < N; cnt++){
		printf("a[%d]: %d\n", cnt, a[cnt]);
	}

	for (i=0; i<N-1; i++) {
		min_index = i;
		for (k=i; k<N-1; k++){
			if(a[k] < a[min_index]){
				min_index = k;
			}
		}

		tmp = a[i];
		a[i] = a[min_index];
		a[min_index] = tmp;
	}
	puts("After sorting:");
	for (cnt = 0; cnt < N; cnt++){
		printf("a[%d]: %d\n", cnt, a[cnt]);
	}
	return (0);
}
