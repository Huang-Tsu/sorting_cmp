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
	//input array
void input_random_number(int *array);
void input_random_english(char **array);
	//copy array
void copy_english_array(char **to, char **from, int len);
void copy_number_array(int *to, int *from, int len);
