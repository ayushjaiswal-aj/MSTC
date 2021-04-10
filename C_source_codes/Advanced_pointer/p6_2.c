/*
Declare a pointer to function accepting
	1. int
	2. a pointer to function accepting int and
		returning void
	returning
	a pointer to function accepting int and
	returning void

solution:
	1. Declare pointer to function 
		(*) ()

	2. Declare pointer to function accepting
		1. int
		2. a pointer to function 
	
		(*) (int, (*) ())

	3. Declare pointer to function accepting 
		1. int
		2. a pointer to function accepting int and returning void

		(*) (int, void (*) (int))

	4. Declare pointer to function accepting 
		1. int
		2. a pointer to function accepting int and returning void

		returning
		a pointer to function

		(*(*) (int, void (*) (int))) ()

	5. Declare pointer to function accepting
		1. int
		2. a pointer to function accepting int and returning void

		returning 
		a pointer to function accepting int and returning void

		void (*(*) (int, void(*) (int))) (int)

*/

#include<stdio.h>
#include<stdlib.h>

void dummy_1(int);
void dummy_2(int);
void (*my_function (int, void(*) (int))) (int);

int main(void){
	void (*pfn) (int);

	pfn = my_function (100, dummy_1);
	if(pfn == NULL){
		puts("No initial identifiner");
	}

	pfn = my_function (200, dummy_2);
	if (pfn != NULL){
		pfn (100);
	}

	pfn = my_function (300, NULL);
	if (pfn != NULL){
		pfn (200);
	}

	return 0;
}

void dummy_1(int n){
	printf("n: %d\n", n);
}

void dummy_2(int m){
	printf("m: %d\n", m);
}

void (*my_function (int k, void (*new_function) (int))) (int) {
	static void (*saved_function) (int) = NULL;
	void (*return_function) (int);

	return_function = saved_function;
	saved_function = new_function;

	return (return_function);
}
