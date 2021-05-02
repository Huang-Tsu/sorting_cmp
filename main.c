#include "sorting.h"
#define RAND_LEN (int)1e6

typedef struct timeval Timeval;

int *temp_number_array[RAND_LEN];
int *number_array[RAND_LEN];
char *english_array[RAND_LEN];
char *temp_english_array[RAND_LEN];

int main(){
	FILE *fp;
	//register int *number_array = (int*)calloc((int)1e7, sizeof(int));
	//register int *temp_random_number = (int*)calloc((int)1e7, sizeof(int));
	//register char **english_array = (char**)calloc((int)1e7, sizeof(char*));
	//register char **temp_random_english = (char**)calloc((int)1e7, sizeof(char*));
	Timeval start;
	Timeval end;
	unsigned long diff;

	for(int i=0; i<RAND_LEN; i++){
		temp_number_array[i] = (int*)calloc(1, sizeof(int));
		number_array[i] = (int*)calloc(1, sizeof(int));
		temp_english_array[i] = (char*)calloc(101, sizeof(char));
		english_array[i] = (char*)calloc(101, sizeof(char));
	}

		//initialize
	fp = fopen("./test_data/dataset1.txt", "r");
	if(fp == NULL){
		fprintf(stderr, "dataset1檔案開啟失敗\n");
			exit(1);
	}
	input_random_number(temp_number_array, fp, RAND_LEN);	
	fclose(fp);

	fp = fopen("./test_data/dataset2.txt", "r");
	if(fp == NULL){
		fprintf(stderr, "dataset2檔案開啟失敗\n");
			exit(1);
	}
	input_random_english(temp_english_array, fp, RAND_LEN);
	fclose(fp);

	copy_number_array(number_array, temp_number_array, RAND_LEN);	//copy_number_array(to, from, len)
	copy_english_array(english_array, temp_english_array, RAND_LEN);
	
	gettimeofday(&start, NULL);
	quick_sort(number_array, 0, RAND_LEN-1, compare_number);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("number sorting time:%f\n", diff/1000000.0);
	//print_number_array(number_array, RAND_LEN);

	gettimeofday(&start, NULL);
	quick_sort(english_array, 0, RAND_LEN-1, compare_english);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("english sorting time:%f\n", diff/1000000.0);
	//print_english_array(english_array, RAND_LEN);
	

	for(int i=0; i<RAND_LEN; i++){
		free(temp_number_array[i]);
		free(number_array[i]);
		free(english_array[i]);
		free(temp_english_array[i]);
	}
	//free(number_array);
	//free(english_array);
	//free(temp_random_number);
	//free(temp_english_array);
	return 0;
}
