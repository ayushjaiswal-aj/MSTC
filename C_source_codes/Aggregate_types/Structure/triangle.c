#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point2d {
	float x;
	float y;
};
	
struct Triangle {
	struct Point2d A;
	struct Point2d B;
	struct Point2d C;
};

struct Triangle t;

int main (void) {
	float a, b, c, s,
		perimeter, area, 
		angle_A_rad, angle_B_rad, angle_C_rad,
		angle_A_degrees, angle_B_degrees, angle_C_degrees,
		cos_of_A, cos_of_B, cos_of_C;
	int triangle_valid_flag = 1;

	printf("Enter A.x:");
	scanf("%f", &t.A.x);
	printf("Enter A.y:");
	scanf("%f", &t.A.y);
	printf("Enter B.x:");
	scanf("%f", &t.B.x);
	printf("Enter B.y:");
	scanf("%f", &t.B.y);
	printf("Enter C.x:");
	scanf("%f", &t.C.x);
	printf("Enter C.y:");
	scanf("%f", &t.C.y);

	if ((a+b <=c) || (b+c <= a) || (a+c <= b)){
		triangle_valid_flag = 0;
	}

	if(triangle_valid_flag == 0){
		puts("Points A, B, C do not form valid triangle\n");
	}

	perimeter = a + b + c;
	printf("perimeter = %.3f\n", perimeter);

	s = perimeter/2;
	area = sqrt(s * (s-a) * (s-b) * (s-c));
	printf("area = %.3f\n", s);

	cos_of_A = (pow(b,2) + pow(c,2) - pow(a,2))/(2*b*c);
	cos_of_B = (pow(c,2) + pow(a,2) - pow(b,2))/(2*c*a);
	cos_of_C = (pow(a,2) + pow(b,2) - pow(c,2))/(2*a*b);

	angle_A_rad = acos(cos_of_A);
	angle_B_rad = acos(cos_of_B);
	angle_C_rad = acos(cos_of_C);
	
	angle_A_degrees = angle_A_rad * (180.0f / 3.14159265358979323846);
	angle_B_degrees = angle_B_rad * (180.0f / 3.14159265358979323846);
	angle_C_degrees = angle_C_rad * (180.0f / 3.14159265358979323846);

	printf("measure angle A in degrees = %.3f\n", angle_A_degrees);
	printf("measure angle B in degrees = %.3f\n", angle_B_degrees);
	printf("measure angle C in degrees = %.3f\n", angle_C_degrees);

	printf("Summation of all angles of triangle = %.3f\n", angle_A_degrees + angle_B_degrees + angle_C_degrees);

	return (0);
}
