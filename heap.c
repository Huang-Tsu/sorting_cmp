#include "sorting.h"
#include <stdio.h>
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
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
