#include <stdio.h>
#include <stdlib.h>

struct Date{
	int day;
	int month;
	int year;
};

struct Date d;

int main (void){
	d.day = 10;
	d.month = 2;
	d.year = 2019;

	printf("%d-%d-%d\n", d.day, d.month, d.year);
	
	d.day = 11;
	d.month = 3; 
	d.year = 2020;
	
	printf("%d-%d-%d\n", d.day, d.month, d.year);
	
	exit(0);
}
