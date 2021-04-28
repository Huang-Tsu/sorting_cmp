#include "sorting.h"
#include <stdio.h>
void merge_sort(int *array, int head, int tail){
	if(head >= tail) return;

	int mid = (head+tail)/2;	
	merge_sort(array, head, mid);	
	merge_sort(array, mid+1, tail);
	merge(array, head, mid, tail);

	return;
}
inline void merge(int *array, int head, int mid, int tail){

	int i=0, j=0, array_now=head;
	int left_len = mid-head+1;
	int right_len = tail-mid;
	int left_array[left_len];
	int right_array[right_len];

	array_copy(left_array, array, head, mid);
	array_copy(right_array, array, mid+1, tail);
	
	while(i<left_len && j<right_len){
		if(left_array[i] <= right_array[j]){
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
inline void array_copy(int *dest, int *src, int head, int tail){
	int i = 0;
	while(head<=tail){
		dest[i++] = src[head++];
	}
}
