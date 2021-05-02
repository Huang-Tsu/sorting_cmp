#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	//input data function
void input_random_number(int **array, FILE *fp, int len){
	int i=0;
	while(i<len){
		fscanf(fp, "%d", &array[i++][0]);
	}
}
void input_random_english(char **array, FILE *fp, int len){
	int i=0;
	while(i<len){
		fscanf(fp, "%s", array[i++]); 
	}
}
	//copy function
void copy_english_array(char **to, char **from, int len){
	int i;
	for(i=0; i<len; i++){
		strcpy(to[i], from[i]);
	}
}
void copy_number_array(int **to, int **from, int len){
	int i;
	for(i=0; i<len; i++){
		to[i][0] = from[i][0];
	}
}
	//compare function
int compare_number(void **array, int i, int j){
	return *(int*)array[i] - *(int*)array[j];
}
int compare_english(void **array, int i, int j){
	return strcmp((char*)array[i], (char*)array[j]);
}
void swap(void *array[], int i, int j){
	void *temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void print_number_array(int **input, int len){
	for(int i=0; i<len; i++){
		printf("%d\n", *input[i]);
	}
}
void print_english_array(char **input, int len){
	for(int i=0; i<len; i++){
		printf("%s\n", input[i]);
	}
}
