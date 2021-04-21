#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct timeval Timeval;

void heapify(int *array, int root, int len);
void heap_sort(int *array, int len);
void print_result(int *array, int cnt);
void swap(int *a, int *b);

int main(){
	int idx=1;
	register int *array;
	array = (int*)calloc((int)1e7, sizeof(int));
	Timeval start;
	Timeval end;
	unsigned long diff;

	while(scanf("%d", &array[idx]) != EOF) idx++;

	gettimeofday(&start, NULL);
	heap_sort(array, idx-1);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;

	printf("sorting time:%f\n", diff/1000000.0);
	//print_result(array, idx);

	free(array);
	return 0;
}

void heap_sort(int *array, int len){
	for(int i=len/2; i>0; i--){
		heapify(array, i, len);
	}

	while(len>1){
		swap(&array[1], &array[len--]);
		heapify(array, 1, len);
	}
}
void heapify(int *array, int root, int len){
	if(root*2 > len) return;	

	int largest = root;
	int left = root*2;
	int right = root*2+1;

	if(array[left]>array[largest]){ 
		largest = left;
	}
	if(right<=len && array[right]>array[largest]){
		largest = right;
	}

	if(largest != root){
		swap(&array[root], &array[largest]);
		heapify(array, largest, len);
	}
	else return;

}
inline void print_result(int *array, int cnt){
	for(int i=1; i<cnt; i++){
		printf("%d\n", array[i]);
	}
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
