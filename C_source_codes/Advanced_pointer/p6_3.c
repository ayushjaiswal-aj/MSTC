/*
Declare a pointer to function accepting
	1. int
	2. a pointer to function accepting int and 
		returning void
	returning 
		a pointer to function accepting int and
		returning void

solution: 
S1. pointer to function
	(*) ()

S2. pointer to function accepting
	1. int
	2. a pointer to function

	(*) (int, (*) ())

S3. pointer to function accepting
	1. int
	2. a pointer to function accepting int 

	(*) (int, (*) (int))

S4. pointer to function accepting 
	1. int
	2. a pointer to function accepting int and
		returning void

	(*) (int, void (*) (int))

S5. pointer to function accepting
	1. int
	2. a pointer to function accepting int and 
		returning void
	returning 
	a pointer to function

	(*(*) (int, void (*) (int))) ()

S6. pointer to function accepting
	1. int
	2. a pointer to function accepting int and
		returning void
	returning 
	a pointer to function accepting int and
		returning void

	void (*(*) (int, void (*) (int))) (int)

*/

#include <stdio.h>
#include <stdlib.h>

void handler_1(int);
void (*my_function (int, void (*) (int))) (int);

int main(void){
	void (*pfn) (int);
	int number = 100;

	pfn = my_function (number, handler_1);
	if (pfn != NULL){
		pfn (10);
	}

	pfn = my_function (number, handler_1);
	if (pfn != NULL){
		pfn (20);
	}

	pfn = my_function (number, handler_1);
	if (pfn != NULL){
		pfn (30);
	}

	return 0;
}

void handler_1 (int n){
	static int call_count = 0;
	call_count++;
	printf("n = %d, call_count = %d\n", n, call_count);
}

void (*my_function (int k, void (*new_function) (int))) (int){
	static void (*static_function) (int) = NULL;
	//void (*returning_function) (int);
	static int number;
	number = number + k;

	//returning_function = static_function;
	static_function = new_function;

	printf("k: %d\n", k);
	printf("number: %d\n", number);

	return static_function;
}
