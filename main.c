#include "sorting.h"
#define RAND_LEN ((int)1e6*3)
#define UNIT_LEN ((int)1e4*25)

typedef void (*Sorting)(void **, int, int, 
		int (*)(const void *, const void*));

int *temp_number_array[RAND_LEN];
char *temp_english_array[RAND_LEN];
int main(){
	FILE *fp;
	Sorting sorts[3] = {quick_sort, merge_sort, heap_sort};		//宣告函式紙標陣列
	char *sorting_name[3] = {"\033[3m\033[1mQuick sort:\033[m",	//奇怪的符號是讓print出來時變斜體還有粗體
							"\033[3m\033[1mMerge sort:\033[m",
							"\033[3m\033[1mHeap sort:\033[m"}; //用陣列紀錄sorting的名字


	puts("Memory allocation...");
	for(int i=0; i<RAND_LEN; i++){
		temp_number_array[i] = (int*)calloc(1, sizeof(int));
		temp_english_array[i] = (char*)calloc(101, sizeof(char));
	}
	puts("Done!\n");


	puts("Read data...");
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
	puts("Done!\n");


	puts("Sorting start!\n");
	for(int i=0; i<3; i++){
		puts(sorting_name[i]);
		puts("\tnumber...");
		test_sorting_time((void**)temp_number_array, UNIT_LEN, sorts[i], compare_number);

		puts("----------------------------------");

		puts("\tenglish...");
		test_sorting_time((void**)temp_english_array, UNIT_LEN, sorts[i], compare_english);
		puts("___________________________________\n");
	}
					
	printf("Sorting completed.\n");
		//free allocated memory
	for(int i=1; i<RAND_LEN; i++){
		free(temp_number_array[i]);
		free(temp_english_array[i]);
	}

	return 0;
}
