#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAND_LEN ((int)1e6*3)

typedef struct timeval Timeval;

void *sorted_array[RAND_LEN];


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
inline void copy_array(void** to, void **from, int len){
	int i;
	for(i=0; i<len; i++){
		to[i] = from[i];
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
	//for reduce the duplicate actions
void test_sorting_time(void **temp_array, int len,
		void (*sort)(void **, int, int, int (*)(const void*, const void*)),
		int (*compare)(const void*, const void*)){
	int k;
	double sum;
	Timeval start;
	Timeval end;
	unsigned long diff;
	
	for(int i=1; i<=12; i++){
		k = 0;
		sum = 0;
		while(k++<2){
			copy_array(sorted_array, temp_array, len*i);	//copy_array(to, from, len)
			gettimeofday(&start, NULL);
			sort(sorted_array, 0, len*i-1, compare);
			gettimeofday(&end, NULL);
			diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
			sum += diff/(1000000.0);
			//print_number_array(number_array, UNIT_LEN*i);
		}
			printf("Sorting %d data average time,%f\n", len*i, sum/(k-1));
	}
}
