#include<stdio.h>

struct A{
	int a;
	char b;
	float c;
};

struct A get_instance_of_A(int init_a, char b, float c);

int main(void){
	struct A result;

	result = get_instance_of_A(10, 'A', 3.14f);

	printf("result.a = %d\nresult.b = %c\nresult.c = %f\n", result.a, result.b, result.c);

	return (0);
}

struct A get_instance_of_A (int init_a, char init_b, float init_c){
	struct A inA = {init_a, init_b, init_c};

	return inA;
}
