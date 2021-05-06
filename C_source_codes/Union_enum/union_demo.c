#include <stdio.h>
#include <stdlib.h>

union builtin{
	char c;
	int n;
	float f;
	double d;
};

struct A{
	int a;
	char b;
	float c;
};

struct B{
	int a[5];
	double d[5];
};

union demo{
	struct A inA;
	struct B inB;
};

struct thread_info{
	char __pad[54];
};

union kernel_stack{
	struct thread_info ti;
	long int arr[2048];
};

int main(void){
	union builtin instance_of_builtin;
	printf("sizeof(instance_of_builtin): %zu\n", sizeof(instance_of_builtin));

	instance_of_builtin.c = 'A';
	printf("CHAR= %c\n", instance_of_builtin.c);
	instance_of_builtin.d = 5648611.6518498;
	printf("DOUBLE= %lf\n", instance_of_builtin.d);
	instance_of_builtin.f = 4564.346f;
	printf("FLOAT= %f\n", instance_of_builtin.f);
	instance_of_builtin.n = 50004;
	printf("INT= %d\n", instance_of_builtin.n);

	printf("&instance_of_builtin.c = %p\n", &instance_of_builtin.c);
	printf("&instance_of_builtin.n = %p\n", &instance_of_builtin.n);
	printf("&instance_of_builtin.f = %p\n", &instance_of_builtin.f);
	printf("&instance_of_builtin.d = %p\n", &instance_of_builtin.d);

	union demo X;
	X.inA.a;
	X.inA.b;
	X.inA.c;

	X.inB.a[0];
	X.inB.d[0];

	return 0;
}
