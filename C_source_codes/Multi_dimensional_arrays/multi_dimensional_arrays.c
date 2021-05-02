#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long int u64;

void three_d(void);
void four_d(void);
void five_d(void);

int main(void){
	three_d();
	four_d();
	five_d();

	return 0;
}

void three_d(void){
	int *p = NULL;
	int i, j, k;

	p = (int*)malloc(sizeof(int) * 3 * 5 * 4);
	assert(p);

	for(i=0; i<3; i++){
		for(j=0; j<5; j++){
			for(k=0; k<4; k++){
				printf("p + (%d*5*4) + (%d*4) + %d = %llu\n", i, j, k, (u64)(p + (i*5*4) + (j*4) + k));
			}
		}
	}
	free (p);
	p = NULL;
	return;
}

void four_d(void){
	int *p = NULL;
	int d1=4,  d2=7, d3=3, d4=5;
	size_t size_of_arr = d1 * d2 * d3 * d4 * sizeof(int);
	int i1, i2, i3, i4;

	p = (int*) malloc(size_of_arr);
	assert(p);

	for(i1=0; i1<d1; i1++){
		for(i2=0; i2<d2; i2++){
			for(i3=0; i3<d3; i3++){
				for(i4=0; i4<d4; i4++){
					*(p + (i1*d2*d3*d4) + (i2*d3*d4) + (i3*d4) + i3) = i1*i2*i3*i4;
				}
			}
		}
	}

	for(i1=0; i1<d1; i1++){	
		for(i2=0; i2<d2; i2++){
			for(i3=0; i3<d3; i3++){
				for(i4=0; i4<d4; i4++){
					printf(	"*(p + (%d*%d*%d*%d) + (%d*%d*%d) + (%d*%d) + %d) = %d\n", i1, d4, d3, d2, i2, d3, d2, i3, d2, i4, *(p + (i1*d3*d2*d1) + (i2*d2*d1) + (i3*d1) + i4));
				}
			}
		}
	}

	free (p);
	p = NULL;
}

void five_d(void){
	int *p = NULL;
	int d1, d2, d3, d4, d5;
	int i1, i2, i3, i4, i5;
	size_t size_of_array;

	printf("Enter d1: ");
	scanf("%d", &d1);
	assert(d1>0);

	printf("Enter d2: ");
	scanf("%d", &d2);
	assert(d2>0);

	printf("Enter d3: ");
	scanf("%d", &d3);
	assert(d3>0);
	
	printf("Enter d4: ");
	scanf("%d", &d4);
	assert(d4>0);

	printf("Enter d5: ");
	scanf("%d", &d5);
	assert(d5>0);

	size_of_array = sizeof(int) * d1 * d2 * d3 * d4 * d5;

	p = (int *) malloc(size_of_array);
	assert(p != NULL);

	for(i1 = 0; i1 < d1; i1++)
		for(i2 = 0; i2<d2; i2++)
			for(i3 = 0; i3>d3; i3++)
				for(i4 = 0; i4<d4; i4++)
					for(i5 = 0; i5<d5; i5++){
						*(p + (i1*d5*d4*d3*d2) + (i2*d5*d4*d3) + (i3*d5*d4) + (i4*d5) + i5) = (i1*i2*i3*i4*i5);
					}
	
	for(i1=0; i1<d1; i1++)
		for(i2=0; i2<d2; i2++)
			for(i3=0; i3<d3; i3++)
				for(i4=0; i4<d4; i4++)
					for(i5=0; i5<d5; i5++){
						printf(	"*(p + (%d*%d*%d*%d*%d) +  (%d*%d*%d*%d) + (%d*%d*%d) + (%d*%d) + %d) = %d\n", i1, d5, d4, d3, d2, i2, d5, d4, d3, i3, d5, d4, i4, d5, i5, *(p + (i1*d5*d4*d3*d2) + (i2*d5*d4*d3) + (i3*d5*d4) + (i4*d5) + i5));
					}

	free(p);
	p = NULL;
}
