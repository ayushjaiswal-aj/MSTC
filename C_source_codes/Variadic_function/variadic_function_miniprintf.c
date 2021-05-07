#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void miniprintf(const char *fmt, ...);

int main(void){
	char c = 'A';
	int i = 100;
	float f = 3.14;

	miniprintf("char = %c, integer = %d, float = %f, percent = %%\n", c, i, f);
	return (0);
}

void miniprintf(const char *fmt, ...){
	va_list ap;
	int i;
	char c_data;
	int i_data;
	float f_data = 0.0;

	va_start(ap, fmt);

	i=0; 
	while(fmt[i] != '\0'){
		if(fmt[i] != '%'){
			putchar(fmt[i]);
			i++;
			continue;
		}
		i++;
		switch(fmt[i]){
			case 'c':
				c_data = va_arg(ap, int);
				printf("%c", c_data);
				break;
			case 'd':
				i_data = va_arg(ap, int);
				printf("%d", i_data);
				break;
			case 'f':
				f_data = va_arg(ap, double);
				printf("%f", f_data);
				break;
			case '%':
				putchar('%');
				break;
		}
		i++;
	}
	va_end(ap);
}
