#include "sorting.h"
#include <stdio.h>
#include <string.h>
void input_random_number(int *array){
		puts("Hi! I am in input_random_number.");
	int i=0;
	while(scanf("%d", &array[i++]) !=EOF)
		;
		printf("Finished read number.\n");
}
void input_random_english(char **array){
		puts("Hi! I am in input_random_english.");
	int i=0;
	while(scanf("%s", array[i++]) !=EOF)
		;
		printf("Finished read english.\n");
}
void copy_english_array(char **to, char **from, int len){
	int i;
	for(i=0; i<len; i++){
		strcpy(to[i], from[i]);
	}
		printf("Finished copy english.\n");
	
}
void copy_number_array(int *to, int *from, int len){
	int i;
	for(i=0; i<len; i++){
		to[i] = from[i];
	}
		printf("Finished copy number.\n");
}
