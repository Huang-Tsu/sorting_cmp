#include "sorting.h"
#include <stdio.h>
void *left_array[(int)1e6*5];
void *right_array[(int)1e6*5];
void merge_sort(void **array, int head, int tail,
		int (*compare)(const void *a, const void *b)){
	if(head >= tail) return;

	int mid = (head+tail)/2;	
	merge_sort(array, head, mid, compare);	
	merge_sort(array, mid+1, tail, compare);
	merge(array, head, mid, tail, compare);

	return;
}
inline void merge(void **array, int head, int mid, int tail,
		int (*compare)(const void *a, const void *b)){

	int i=0, j=0, array_now=head;
	int left_len = mid-head+1;
	int right_len = tail-mid;

	array_copy_for_merge_sort(left_array, array, head, mid);
	array_copy_for_merge_sort(right_array, array, mid+1, tail);
	
	while(i<left_len && j<right_len){
		if(compare(left_array[i], right_array[j]) <= 0){
			array[array_now++] = left_array[i++];
		}
		else{
			array[array_now++] = right_array[j++];
		}
	}
	while(i<left_len){
		array[array_now++] = left_array[i++];
	}
	while(j<right_len){
		array[array_now++] = right_array[j++];
	}
}
