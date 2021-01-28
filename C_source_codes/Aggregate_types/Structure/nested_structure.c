#include <stdio.h>
#include <stdlib.h>

struct Date {
	int day;
	int month;
	int year;
};

struct Student {
	int st_roll_number;
	float st_marks;
	float st_attendance;
	struct Date st_date_of_birth;
};

struct Student s = {10, 78.63, 86.33, {12, 7, 2020}};

int main(void) {
	int roll; 
	float marks, attnd;
	int dd, mm, yy;

	roll = s.st_roll_number;
	marks = s.st_marks;
	attnd = s.st_attendance;
	dd = s.st_date_of_birth.day;
	mm = s.st_date_of_birth.month;
	yy = s.st_date_of_birth.year;

	printf("roll = %d marks = %.2f attnd = %.2f dd = %d mm = %d yy = %d\n", roll, marks, attnd, dd, mm, yy);
}
