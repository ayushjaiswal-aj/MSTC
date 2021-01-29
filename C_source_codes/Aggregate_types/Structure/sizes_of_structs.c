#include<stdio.h>
#include<stdlib.h>

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

struct Date d1;

struct Student s1;

int main(void) {
	printf("sizeof(d1):%u\n", sizeof(d1));
	printf("sizeof(s1):%u\n", sizeof(s1));
	return(0);
}
