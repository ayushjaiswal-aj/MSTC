/* 
 * Declare a pointer to function accepting
 * 	1. an int
 * 	2. a pointer to function to accepting int and returning void
 * 	
 *	returning
 * 	a pointer to function accepting int and returning void
 *
 */

/* 
solution:
	S11: pointer to a function
		(*) ()

	S12: pointer to function  accepting int
		(*) (int)

	S13: pointer to function accepting int and returning void
		void (*) (int)
--------------------------------------------------------------------------------
	
	S21: my_function is a function
		my_function()

	S22: my_function is a function accepting 
		1. int
		2. pointer to a function accepting int and returning void

		my_function (int, void (*) (int))

	S23: my_function is a function accepting
		1. int
		2. pointer to a fuction accepting int and returning void

		returning 
		pointer

		*my_function (int, void (*) (int))

	S24: my_function is a function accepting
		1. int
		2. pointer to a function accepting int and returning void
	
		returning
		pointer to function

		( *my_function(int, void (*)(int))) ()

	S25: my_function is a function accepting
		1. int
		2. pointer to a fucntion accepting int and returning void

		returning 
		pointer to function accepting int and returning void

		void (*my_function (int, void (*) (int))) (int);

---------------------------------------------------------------------------------

	S31: A pointer to a function accepting
		1. integer
		2. a pointer to a function accepting int and returning void

		returning 
		a pointer to a function accepting int and returning void

		void (*(*pfn) (int, void (*) (int))) (int);

---------------------------------------------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>

void first_handler (int);
void second_handler (int);
void (*exchange(int, void (*)(int))) (int);

int main(void){
	void (*pfn) (int);

	pfn = exchange(10, first_handler);
	if (pfn == NULL){
		puts("main: no previously registered handler");
	}

	pfn = exchange(20, second_handler);
	if (pfn != NULL){
		pfn(100);
	}

	pfn = exchange(30, NULL);
	if (pfn != NULL){
		pfn(200);
	}

	return (0);
}

void first_handler(int n){
	printf("first_handler: n = %d\n", n);
}

void second_handler (int m){
	printf("second_handler: m = %d\n", m);
}

void (*exchange(int k, void(*pfn_new)(int) )) (int){
	static void (*pfn_saved)(int) = NULL;
	void (*return_pfn) (int);

	return_pfn = pfn_saved;
	pfn_saved = pfn_new;
	return (return_pfn);
}
