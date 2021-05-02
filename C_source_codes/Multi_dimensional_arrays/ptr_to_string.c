#include <stdio.h>
#include <stdlib.h>

char msg[] = "hello, world!";

char *p_msg = "Hello, World!";

void test(void);

void multi_dimensional(void);

int main(void){
	int i;
	for(i=0; msg[i] != '\0'; i++){
		printf("msg[%d]: %c\n", i, msg[i]);
	}

	for(i=0; *(p_msg + i) != '\0'; i++){
		printf("*(p_msg + %d) = %c\n", i, *(p_msg+i));
	}

	printf("msg = %s\n", msg);
	for(i=0; msg[i] != '\0'; i++){
		if(msg[i] >= 97 && msg[i] <= 97+25){
			msg[i] = msg[i] - 32;
		}
	}
	printf("msg = %s\n", msg);

	multi_dimensional();

	return 0;
}

void test(void){
	char *p_str = "This is a test string";

	char t_msg[] = "This is a character array";
}

void multi_dimensional(void){
	int i, j;

	char ca[5][16];
	char *msg1 = "abc";
	char *msg2 = "pqr";
	char *msg3 = "xyz";
	char *msg4 = "lmn";

	char *msgs[4] = {
				"abc",
				"pqr",
				"xyz",
				"lmn"
			};

	char *paragraph[] = {
				"Sheldon teaches Penny a littel physics",
				"It was warm summer evening in the ancient Greece",
				"People were shopping by the nearby market, Agora",
				"And then they sae the moving bodies in the sky",
				"And named them plenetes or the moving bodies",
				(char*)NULL
			     };

	for(i=0; i<5; i++){
		for(j=0; j<16; j++){
			ca[i][j] = 97 + rand() % 26;
		}
	}

	for(i=0; i<5; i++){
		for(j=0; j<16; j++){
			printf("ca[%d][%d]: %c\n", i, j, ca[i][j]);
		}
	}

	for(i=0; paragraph[i] != NULL; i++){	
		printf("%d the statement = %s\n", i, paragraph[i]);
	}

	puts("Printing paragraph char by char");
	for(i=0; paragraph[i] != '\0'; i++){
		for(j=0; paragraph[i][j] != '\0'; j++){
			printf("Sentence %d Character %d : %c\n", i, j, paragraph[i][j]);
		}
	}
	return ;
}
