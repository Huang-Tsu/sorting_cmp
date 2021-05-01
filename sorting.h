	//quick sort
void quick_sort(void *array, int head, int tail,
		int (*compare)(const void *, const void *));
int partition(void *array, int head, int tail,
		int (*compare)(const void *a, const void *b));
	//merge sort
void merge_sort(int *array, int head, int tail);
void merge(int *array, int head, int merge, int tail);
void array_copy(int *dest, int *src, int head, int tail);
	//heap sort
void heapify(int *array, int root, int len);
void heap_sort(int *array, int len);
	//make_rand
void make_rand_num(int *array, int len);
	//input array
void input_random_number(int *array);
void input_random_english(char **array);
	//copy array
void copy_english_array(char **to, char **from, int len);
void copy_number_array(int *to, int *from, int len);
	//compare function
int compare_number(const void *a, const void *b);
int compare_english(const void *a, const void *b);

void swap(void *a, void *b, int width);
