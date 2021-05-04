#include "sorting.h"
#define RAND_LEN ((int)1e6*3)
#define UNIT_LEN ((int)1e5*5)

typedef struct timeval Timeval;

int *temp_number_array[RAND_LEN];
int *number_array[RAND_LEN];
char *english_array[RAND_LEN];
char *temp_english_array[RAND_LEN];
int main(){
	FILE *fp;
	double sum;
	int k;
	Timeval start;
	Timeval end;
	unsigned long diff;

	for(int i=0; i<RAND_LEN; i++){
		temp_number_array[i] = (int*)calloc(1, sizeof(int));
		temp_english_array[i] = (char*)calloc(101, sizeof(char));
	}

		//initialize
	fp = fopen("./test_data/dataset_num.txt", "r");
		if(fp == NULL){
			fprintf(stderr, "dataset_num.txt檔案開啟失敗\n");
				exit(1);
		}
	input_random_number(temp_number_array, fp, RAND_LEN);	
	fclose(fp);

	fp = fopen("./test_data/dataset_eng.txt", "r");
		if(fp == NULL){
			fprintf(stderr, "dataset_eng.txt檔案開啟失敗\n");
				exit(1);
		}
	input_random_english(temp_english_array, fp, RAND_LEN);
	fclose(fp);

		//quick sort
			//Number
	printf("Quick sort start!\n");
	for(int i=1; i<=6; i++){
		k = 0;
		sum = 0;
		while(k++<3){
			copy_array((void**)number_array, (void**)temp_number_array, UNIT_LEN*i);	//copy_array(to, from, len)
			gettimeofday(&start, NULL);
			quick_sort((void**)number_array, 0, UNIT_LEN*i-1, compare_number);
			gettimeofday(&end, NULL);
			diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
			sum += diff/(1000000.0);
			//print_number_array(number_array, UNIT_LEN*i);
		}
			printf("Sorting %d number average time,%f\n", UNIT_LEN*i, sum/3);
	}
				printf("------------------------------------------\n");

			//English
	for(int i=1; i<=6; i++){
		k = 0;
		sum = 0;
		while(k++<3){
			copy_array((void**)english_array, (void**)temp_english_array, UNIT_LEN*i);
			gettimeofday(&start, NULL);
			quick_sort((void**)english_array, 0, UNIT_LEN*i-1, compare_english);
			gettimeofday(&end, NULL);
			diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
			sum += diff/(1000000.0);
			//print_english_array(english_array, UNIT_LEN*i);
		}
			printf("Sorting %d english average time,%f\n", UNIT_LEN*i, sum/3);
	}
				printf("___________________________________________\n\n");

		//merge sort
			//Number
	printf("Merge sort start!\n");
	for(int i=1; i<=6; i++){
		k = 0;
		sum = 0;
		while(k++<3){
			copy_array((void**)number_array, (void**)temp_number_array, UNIT_LEN*i);	//copy_array(to, from, len)
			gettimeofday(&start, NULL);
			merge_sort((void**)number_array, 0, UNIT_LEN*i-1, compare_number);
			gettimeofday(&end, NULL);
			diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
			sum += diff/(1000000.0);
			//print_number_array(number_array, UNIT_LEN*i);
		}
			printf("Sorting %d number average time,%f\n", UNIT_LEN*i, sum/3);
	}
				printf("------------------------------------------\n");

			//English
	for(int i=1; i<=6; i++){
		k = 0;
		sum = 0;
		while(k++<3){
			copy_array((void**)english_array, (void**)temp_english_array, UNIT_LEN*i);
			gettimeofday(&start, NULL);
			merge_sort((void**)english_array, 0, UNIT_LEN*i-1, compare_english);
			gettimeofday(&end, NULL);
			diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
			sum += diff/(1000000.0);
			//print_english_array(english_array, UNIT_LEN*i);
		}
			printf("Sorting %d english average time,%f\n", UNIT_LEN*i, sum/3);
	}
				printf("___________________________________________\n\n");
		//heap sort
			//Number
	printf("Heap sort start!\n");
	for(int i=1; i<=6; i++){
		k = 0;
		sum = 0;
		while(k++<3){
			copy_array((void**)number_array, (void**)temp_number_array, UNIT_LEN*i);	//copy_array(to, from, len)
			gettimeofday(&start, NULL);
			heap_sort((void**)number_array, UNIT_LEN*i-1, compare_number);
			gettimeofday(&end, NULL);
			diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
			sum += diff/(1000000.0);
			//print_number_array(number_array, UNIT_LEN*i);
		}
			printf("Sorting %d number average time,%f\n", UNIT_LEN*i, sum/3);
	}
				printf("------------------------------------------\n");

			//English
	for(int i=1; i<=6; i++){
		k = 0;
		sum = 0;
		while(k++<3){
			copy_array((void**)english_array, (void**)temp_english_array, UNIT_LEN*i);
			gettimeofday(&start, NULL);
			heap_sort((void**)english_array, UNIT_LEN*i-1, compare_english);
			gettimeofday(&end, NULL);
			diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
			sum += diff/(1000000.0);
			//print_english_array(english_array, UNIT_LEN*i);
		}
			printf("Sorting %d english average time,%f\n", UNIT_LEN*i, sum/3);
	}
				printf("___________________________________________\n\n");
	printf("Sorting completed.\n");
		//free allocated memory
	for(int i=1; i<RAND_LEN; i++){
		free(temp_number_array[i]);
		free(temp_english_array[i]);
	}
	return 0;
}
