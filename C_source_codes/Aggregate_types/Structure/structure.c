#include<stdio.h>
#include<stdlib.h>

struct Student {
	int roll_no;
	char div;
	float marks;
};

int main(void) {
	/* creating instance of structure student */
	struct Student s1 = {32, 'A', 83.60};

	/* reading data from structure instance s1*/
	printf("roll_no: %d\ndiv: %c\nmarks: %f\n",s1.roll_no, s1.div, s1.marks);
	/* writing new data into stucture instance s1 */
	s1.div = 'B';
	s1.roll_no = 34;
	s1.marks = 87.88;
	
	/* reading newly added data into instance s1 */
	printf("roll_no: %d\ndiv: %c\nmarks: %f\n",s1.roll_no, s1.div, s1.marks); 
	return (0);
}
