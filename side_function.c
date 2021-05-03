#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	//input data function
inline void input_random_number(int **array, FILE *fp, int len){
	int i=0;
	while(i<len){
		fscanf(fp, "%d", &array[i++][0]);
	}
}
inline void input_random_english(char **array, FILE *fp, int len){
	int i=0;
	while(i<len){
		fscanf(fp, "%s", array[i++]); 
	}
}
	//copy function
inline void copy_english_array(char **to, char **from, int len){
	int i;
	for(i=0; i<len; i++){
		strcpy(to[i], from[i]);
	}
}
inline void copy_number_array(int **to, int **from, int len){
	int i;
	for(i=0; i<len; i++){
		to[i][0] = from[i][0];
	}
}
	//compare function
inline int compare_number(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
inline int compare_english(const void *a, const void *b){
	return strcmp((char*)a, (char*)b);
}
inline void swap(void *array[], int i, int j){
	void *temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

inline void print_number_array(int **input, int len){
	for(int i=0; i<len; i++){
		printf("%d\n", *input[i]);
	}
}
inline void print_english_array(char **input, int len){
	for(int i=0; i<len; i++){
		printf("%s\n", input[i]);
	}
}

	//side function for merge sort
inline void array_copy_for_merge_sort(void **to, void **from, int head, int tail){
	int i = 0;
	while(head<=tail){
		to[i++] = from[head++];
	}
}
