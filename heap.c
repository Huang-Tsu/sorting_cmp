#include "sorting.h"
#include <stdio.h>
void heap_sort(void **array, int end_idx,
		int (*compare)(const void *a, const void *b)){
	for(int i=(end_idx-1)/2; i>=0; i--){
		heapify(array, i, end_idx, compare);
	}

	while(end_idx>0){
		swap(array, 0, end_idx--);
		heapify(array, 0, end_idx, compare);
	}
}
void heapify(void **array, int root, int end_idx,
		int (*compare)(const void *a, const void *b)){
	if(root*2+1 > end_idx) return;	

	int largest = root;
	int left = root*2+1;
	int right = root*2+2;

	if(compare(array[left], array[largest]) >= 0){ 
		largest = left;
	}
	if(right<=end_idx && compare(array[right], array[largest]) >= 0){
		largest = right;
	}

	if(largest != root){
		swap(array, root, largest);
		heapify(array, largest, end_idx, compare);
	}

	return;

}
