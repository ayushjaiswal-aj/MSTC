#include <stdio.h>
#include <stdlib.h>

struct A{
	int a;
	char b;
	float c;
} inA;

typedef unsigned long long int off_tt;

int main(void){
	off_tt offset_a, offset_b, offset_c;
	
	offset_a = (off_tt)&inA.a - (off_tt)&inA;
	offset_b = (off_tt)&inA.b - (off_tt)&inA;
	offset_c = (off_tt)&inA.c - (off_tt)&inA;

	printf("offset_a = %llu\noffset_b = %llu\noffset_c = %llu\n", offset_a, offset_b, offset_c);
	
	struct A* p = NULL;
	offset_a = offset_b = offset_c = 100;

	offset_a = (off_tt)(&p->a);
	offset_b = (off_tt)(&p->b);
	offset_c = (off_tt)(&p->c);

	printf("without creating instace\n");
	printf("offset_a: %llu\noffset_b: %llu\noffset_c: %llu\n", offset_a, offset_b, offset_c);

	offset_a = (unsigned long long int)(&((struct A*)0)->a);
	offset_b = (unsigned long long int)(&((struct A*)0)->b);
	offset_c = (unsigned long long int)(&((struct A*)0)->c);

	printf("third solution:\n");
	printf("offset_a: %llu\noffset_b: %llu\noffset_c: %llu\n", offset_a, offset_b, offset_c);

	return 0;
}
