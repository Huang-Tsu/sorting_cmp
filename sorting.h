	//quick sort
void quick_sort(int *array, int head, int tail);
int partition(int *array, int head, int tail);
	//merge sort
void merge_sort(int *array, int head, int tail);
void merge(int *array, int head, int merge, int tail);
void array_copy(int *dest, int *src, int head, int tail);
	//heap sort
void heapify(int *array, int root, int len);
void heap_sort(int *array, int len);
void swap(int *a, int *b);
	//make_rand
void make_rand_num(int *array, int len);
