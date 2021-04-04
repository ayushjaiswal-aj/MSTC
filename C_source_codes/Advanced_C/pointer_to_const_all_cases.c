#include <stdio.h>
#include <stdlib.h>

int g_rw_int = 100;
const int g_ro_int = 1000;

int* ptr_to_nonconst_int;
const int* ptr_to_const_int;

void f(const int* ptr_to_const_int);

int main(void){
	int loc_rw_int = 200;
	const int loc_ro_int = 2000;

	ptr_to_nonconst_int = &g_rw_int;
	printf("address of g_rw_int (ptr_nonconst_int): %p\n", ptr_to_nonconst_int);
	printf("value of g_rw_int (ptr_nonconst_int): %d\n", *ptr_to_nonconst_int);

	ptr_to_nonconst_int = &loc_rw_int;
	printf("address of loc_rw_int (ptr_nonconst_int): %p\n", ptr_to_nonconst_int);
	printf("value of loc_rw_int (*ptr_nonconst_int): %d\n", *ptr_to_nonconst_int);

	ptr_to_nonconst_int = &g_ro_int;
	printf("address of g_ro_int (ptr_nonconst_int): %p\n", ptr_to_nonconst_int);
	printf("value of g_ro_int (*ptr_nonconst_int): %d\n", *ptr_to_nonconst_int);

	printf("After changing value of const int g_ro_int\n");
	//*ptr_to_nonconst_int = -100;			/* compile time error */
	printf("value of g_ro_int (*ptr_noncosnt_int): %d\n", *ptr_to_nonconst_int);

	ptr_to_nonconst_int = &loc_ro_int;
	*ptr_to_nonconst_int = -200;
	printf("value of loc_ro_int (*ptr_nonconst_int): %d\n", *ptr_to_nonconst_int);

	ptr_to_const_int = &g_rw_int;
	printf("address of g_rw_int (ptr_to_const_int): %p\n", ptr_to_const_int);
	printf("value of g_rw_int (*ptr_to_const_int): %d\n", *ptr_to_const_int);

	//*ptr_to_const_int = -1000;			/* compile time error */
	printf("After changing g_rw_int value\n");
	printf("value of g_rw_int (*ptr_to_const_int): %d\n", *ptr_to_const_int);

	ptr_to_const_int = &loc_rw_int;
	printf("address of loc_rw_int (ptr_to_const_int): %p\n", ptr_to_const_int);
	printf("value of loc_rw_int (*ptr_to_const_int): %d\n", *ptr_to_const_int);
	
	//*ptr_to_const_int = -2000;			/* compile time error */
	printf("After changing value of loc_rw_int\n");
	printf("value of loc_rw_int (*ptr_to_const_int): %d\n", *ptr_to_const_int);

	ptr_to_const_int = &g_ro_int;
	printf("address of g_ro_int (ptr_to_cosnt_int): %p\n", ptr_to_const_int);
	printf("value of g_ro_int (*ptr_to_cosnt_int): %d\n", *ptr_to_const_int);

	//*ptr_to_const_int = -2000;			/* compile time error */
	printf("After changing g_ro_int\n");
	printf("value of g_ro_int (*ptr_to_const_int): %d\n", *ptr_to_const_int);

	ptr_to_const_int = &loc_ro_int;
	printf("address of loc_ro_int (ptr_to_const_int): %p\n", ptr_to_const_int);
	printf("value of loc_ro_int (*ptr_to_const_int): %d\n", *ptr_to_const_int);

	//*ptr_to_const_int -2000;			/* compile time error */
	printf("value of loc_ro_int (*ptr_to_const_int): %d\n", *ptr_to_const_int);
}
