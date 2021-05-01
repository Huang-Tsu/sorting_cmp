#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sorting.h"
#define RAND_LEN (int)1e6

typedef struct timeval Timeval;

int main(){
	register int *number_array = (int*)calloc((int)1e7, sizeof(int));
	register int *temp_random_number = (int*)calloc((int)1e7, sizeof(int));
	//register char **english_array = (char**)calloc((int)1e7, sizeof(char*));
	//register char **temp_random_english = (char**)calloc((int)1e7, sizeof(char*));
	Timeval start;
	Timeval end;
	unsigned long diff;

	/*
	for(int i=0; i<RAND_LEN; i++){
		english_array[i] = (char*)calloc(101, sizeof(char));
		temp_random_english[i] = (char*)calloc(101, sizeof(char));
	}
	*/
		printf("Finished allocation.\n");

		//initialize
	input_random_number(temp_random_number);	
	//input_random_english(temp_random_english);


	copy_number_array(number_array, temp_random_number, RAND_LEN);	//copy_number_array(to, from, len)
	//copy_english_array(temp_random_english, english_array, RAND_LEN);
	gettimeofday(&start, NULL);
	quick_sort(number_array, 0, RAND_LEN-1, compare_number);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("sorting time:%f\n", diff/1000000.0);
	//print_result(number_array, cnt);

	/*
	for(int i=0; i<RAND_LEN; i++){
		free(english_array[i]);
		free(temp_random_english[i]);
	}
	*/
	free(number_array);
	//free(english_array);
	free(temp_random_number);
	//free(temp_random_english);
	return 0;
}
