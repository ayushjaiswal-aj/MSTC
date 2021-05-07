#include <stdio.h>
#include <stdlib.h>

struct Date1{
	int dd, mm, yy;
};

struct Date2{
	int dd : 5;
	int mm : 4;
	int yy;
};

struct A{
	int x : 10;
	int y : 6;
	int : 0;
	short z;
};

struct B{
	int m : 2;
	int n : 2;
	int k : 2;
};

int main(void){
	printf("sizeof(struct Date1): %d\n", sizeof(struct Date1));
	printf("sizeof(struct Date2): %d\n", sizeof(struct Date2));
	printf("sizeof(struct B): %d\n", sizeof(struct B));
	struct Date2 d = {5, 12, 2020};
	d.dd = 500; 

	struct B b = {1, 3, 0};
	b.m = 5;

	return 0;
}
