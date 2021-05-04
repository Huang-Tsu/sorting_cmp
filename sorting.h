#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
	//quick sort
void quick_sort(void **array, int head, int tail,
		int (*compare)(const void *a, const void *b));
int partition(void **array, int head, int tail,
		int (*compare)(const void *a, const void *b));
	//merge sort
void merge_sort(void **array, int head, int tail,
		int (*compare)(const void *a, const void *b));
void merge(void **array, int head, int merge, int tail,
		int (*compare)(const void *a, const void *b));
void array_copy_for_merge_sort(void **dest, void **src, int head, int tail);
	//heap sort
void heapify(void **array, int root, int len,
		int (*compare)(const void *a, const void *b));
void heap_sort(void **array, int end_idx,
		int (*compare)(const void *a, const void *b));
	//make_rand
void make_rand_num(int *array, int len);
	//input array
void input_random_number(int **array, FILE *fp, int len);
void input_random_english(char **array, FILE *fp, int len );
	//copy array
void copy_english_array(char **to, char **from, int len);
void copy_number_array(int **to, int **from, int len);
void copy_array(void** to, void **from, int len);
	//compare function
int compare_number(const void *a, const void *b);
int compare_english(const void *a, const void *b);
	//swap function
void swap(void **array, int i, int j);
	//print function
void print_number_array(int **input, int len);
void print_english_array(char **input, int len);
