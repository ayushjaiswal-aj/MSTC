#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct A{
	int a;
	char b;
	float c;
};

struct A* get_instance_of_A(int , char , float);

int main(void){
	struct A* p1 = get_instance_of_A(10, 'A', 3.14f);
	
	printf("a: %d, b: %c, c: %f\n", p1->a, p1->b, p1->c);

	return (0);
}

struct A* get_instance_of_A(int init_a, char init_b, float init_c){
	static struct A return_instance;
	
	memset(&return_instance, 0, sizeof(struct A));
	
	return_instance.a = init_a;
	return_instance.b = init_b;
	return_instance.c = init_c;

	return &return_instance;
}	
