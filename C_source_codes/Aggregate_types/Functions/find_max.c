#include<stdio.h>
#include<stdlib.h>

int q, p, r;

int main(void){
	int max_element;

	printf("Enter p:");
	scanf("%d", &p);
	printf("Enter q:");
	scanf("%d", &q);
	printf("Enter r:");
	scanf("%d", &r);

	max_element = find_max(p, q, r);
	printf("max_element = %d\n", max_element);
	
	exit(0);
}

int find_max(int n1, int n2, int n3){
	int max_element;
	if (n1>n2){
		max_element = n1;
	} else {
		max_element = n2;
	}
	if (n3 > n2){
		max_element = n3;
	}

	return max_element;
}
