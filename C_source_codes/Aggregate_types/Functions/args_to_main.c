#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[], char* envp[]){
	int i;
	
	printf("Arguments Count = %d\n", argc);

	printf("Arguments vector:\n");
		
	for (i=0; i<argc; i++){
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	printf("Enviromental arguments:\n");
	for (i=0; envp[i] != NULL; i++){
		printf("envp[%d]: %s\n", i, envp[i]);
	}
	exit(0);
}

