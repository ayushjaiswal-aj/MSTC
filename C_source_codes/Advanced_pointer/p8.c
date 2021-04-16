/*
Declare an array 5 of pointer to function taking 
	1. a pointer to function taking int 
		returning void
	returning pointer to array of pointer to function accepting two ints and
		returning int

Solution:

	S1. Declare an array 5
		arr[5]

	S2. Declare an array 5 of pointer
		(*arr[5])

	S3. Declare an array 5 of pointer to function
		(*arr[5]) ()

	S4. Declare an array 5 of pointer to function taking
		1. a pointer to function
		(*arr[5]) ( (*) ())

	S5. Declare an array 5 of pointer to function taking
		1. a pointer to function taking int and returning void
		(*arr[5]) (void (*) (int))

	S6. Declare an array 5 of pointer to function taking
		1. a pointer to function taking int and returning void
	returning
		pointer to array
		(*(*arr[5]) (void (*) (int))) []

	S7. Declare an array 5 of pointer to function taking
		1. a pointer to function taking int and returning void
	returning
		pointer to array of pointer to function
		(*(*(*arr[5]) (void (*) (int))) []) ()

	S8. Declare an array 5 of pointer to function taking 
		1. a pointer to function taking int and returning void
	returning 
		pointer to array of pointer to function accepting two ints
		(*(*(*arr[5]) (void (*) (int))) []) (int , int)

	S9. Declare an array 5 of pointer to function taking
		1. a pointer to function taking int and returning void
	returning
		pointer to array of pointer to function accepting two ints and
		returning
		- int
		int  (*(*(*arr[5]) (void (*) (int)))[]) (int, int)

*/

#include <stdio.h>
#include <stdlib.h>

void ip_function_1(int n);
void ip_function_2(int n);
void ip_function_3(int n);
void ip_function_4(int n);
void ip_function_5(int n);

int cpa_add(int a, int b);
int cpa_sub(int a, int b);
int cpa_mul(int a, int b);
int cpa_quotient(int a, int b);
int cpa_remainder(int a, int b);
int cpa_logical_and(int a, int b);
int cpa_logical_or(int a, int b);
int cpa_bitwise_and(int a, int b);
int cpa_bitwise_or(int a, int b);
int cpa_bitwise_xor(int a, int b);
int cpa_left_shift(int n, int k);
int cpa_right_shift(int n, int k);
int cpa_compute1(int a, int b);
int cpa_compute2(int a, int b);
int cpa_compute3(int a, int b);

int (*(*cpa_top_level_1(void (*pfn) (int)))[3]) (int, int);
int (*(*cpa_top_level_2(void (*pfn) (int)))[3]) (int, int);
int (*(*cpa_top_level_3(void (*pfn) (int)))[3]) (int, int);
int (*(*cpa_top_level_4(void (*pfn) (int)))[3]) (int, int);
int (*(*cpa_top_level_5(void (*pfn) (int)))[3]) (int, int);


int main(void){
	int i;
	int j;
	int ret;
	int (*(*pfn_ret)[3]) (int, int);
	int ap1 = 128, ap2 = 4;

	int (*(*(*pfn_arr[5])(void(*) (int)))[3]) (int , int) = {cpa_top_level_1, cpa_top_level_2, cpa_top_level_3, cpa_top_level_4, cpa_top_level_5 };

	void (*ip_arr_pfn[5])(int) = { ip_function_1, ip_function_2, ip_function_3, ip_function_4, ip_function_5};

	for (i = 0; i < 5; i++){
		pfn_ret = pfn_arr[i] (ip_arr_pfn[i]);
		for (j=0; j<3; j++){
			ret = (*pfn_ret)[j](ap1, ap2);
			printf("ret = %d\n", ret);
		}
		printf("*****************************************************************************************\n");
	}
	return (EXIT_SUCCESS);
}

void ip_function_1(int n){
	printf("power 1: n = %d\n", n);
}

void ip_function_2(int n){
	printf("power 2: n^2 = %d\n", n*n);
}

void ip_function_3(int n){
	printf("power 3: n^3 = %d\n", n*n*n);
}

void ip_function_4(int n){
	printf("power 4: n^4 = %d\n", n*n*n*n);
}
void ip_function_5(int n){
	printf("power 5: n^5 = %d\n", n*n*n*n*n);
}

int cpa_add(int a, int b){
	puts("cpa_add");
	return (a+b);
}

int cpa_sub(int a, int b){
	puts("cpa_sub");
	return (a-b);
}

int cpa_mul(int a, int b){
	puts("cpa_mul");
	return (a*b);
}

int cpa_quotient(int a, int b){
	puts("cpa_quotient");
	return (a/b);
}

int cpa_remainder(int a, int b){
	puts("cpa_remainder");
	return (a%b);
}

int cpa_logical_and(int a, int b){
	puts("cpa_logical_and");
	return (a && b);
}

int cpa_logical_or(int a, int b){
	puts("cpa_logical_or");
	return (a || b);
}

int cpa_bitwise_and(int a, int b){
	puts("cpa_bitwise_and");
	return (a & b);
}

int cpa_bitwise_or(int a, int b){
	puts("cpa_bitwise_or");
	return (a | b);
}

int cpa_bitwise_xor(int a, int b){
	puts("cpa_bitwise_xor");
	return (a^b);
}

int cpa_right_shift(int n, int k){
	puts("cpa_right_shift");
	int ret = n >> k;
	return ret;
}

int cpa_left_shift(int n, int k){
	puts("cpa_left_shift");
	int ret = n << k;
	return ret;
}

int cpa_compute1(int a, int b){
	puts("cpa_compute1");
	return (a*a - b*b);
}

int cpa_compute2(int a, int b){
	puts("cpa_compute2");
	return (a*a - 2*a*b + b*b);
}

int cpa_compute3(int a, int b){
	puts("cpa_compute3");
	return (a*a*a - b*b*b);
}

int (*(*cpa_top_level_1(void (*pfn) (int)))[3]) (int, int){
	static int (*pfn_arr[3])(int, int);
	puts("cpa_top_level_1: calling raise to 1 function.");
	pfn(2);
	puts("cpa_top_level_1: Building array three of pointer to function accepting int, int and returning int");
	pfn_arr[0] = cpa_add;
	pfn_arr[1] = cpa_sub;
	pfn_arr[2] = cpa_mul;
	puts("********************Returning from cpa_top_level_1********************\n");
	return (&pfn_arr);
}

int (*(*cpa_top_level_2(void (*pfn) (int)))[3]) (int, int){
	static int (*pfn_arr[3])(int, int);
	puts("cpa_top_level_2: calling raise to 2 function.");
	pfn(2);
	puts("cpa_top_level_2: building array three of pointer to function accepting int, int and returning int");
	pfn_arr[0] = cpa_quotient;
	pfn_arr[1] = cpa_remainder;
	pfn_arr[2] = cpa_logical_and;
	puts("********************Returning from cpa_top_level_2********************\n");
	return (&pfn_arr);
}

int (*(*cpa_top_level_3(void(*pfn) (int)))[3]) (int, int){
	static int (*pfn_arr[3])(int, int);
	puts("cpa_top_level_3: calling raise to 3 function.");
	pfn(2);
	puts("cpa_top_level_3: building array three of pointer to function accepting int, int and returning int");
	pfn_arr[0] = cpa_logical_or;
	pfn_arr[1] = cpa_bitwise_and;
	pfn_arr[2] = cpa_bitwise_or;
	puts("********************Returning from cpa_top_level_3********************\n");
	return (&pfn_arr);
}

int (*(*cpa_top_level_4(void(*pfn)(int)))[3])(int , int){
	static int (*pfn_arr[3])(int, int);
	puts("cpa_top_level_4: calling raise to 4 function.");
	pfn(2);
	puts("cpa_top_level_4: building array three of pointer to function accepting int, int and returning int");
	pfn_arr[0] = cpa_bitwise_xor;
	pfn_arr[1] = cpa_left_shift;
	pfn_arr[2] = cpa_right_shift;
	puts("********************Returning from cpa_top_level_4********************\n");
	return (&pfn_arr);
}

int (*(*cpa_top_level_5(void(*pfn)(int)))[3])(int, int){
	static int (*pfn_arr[3])(int, int);
	puts("cpa_top_level_5: calling raise to 5 function.");
	pfn(2);
	puts("cpa_top_level_5: building array three of pointer to function accepting int, int and returning int");
	pfn_arr[0] = cpa_compute1;
	pfn_arr[1] = cpa_compute2;
	pfn_arr[2] = cpa_compute3;
	puts("********************Returning from cpa_top_level_5********************\n");
	return (&pfn_arr);
}
