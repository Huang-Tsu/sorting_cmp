#include "sorting.h"
#include <stdio.h>
void quick_sort(int *array, int head, int tail){
	if(head >= tail) return;

	int pivot = partition(array, head, tail);
	quick_sort(array, head, pivot-1);	
	quick_sort(array, pivot+1, tail);

	return;
}
inline int partition(int *array, int head, int tail){

	int pivot = array[tail];
	int temp;
	int i, j;
	for(i=head-1, j=head; j<tail; j++){
		if(array[j] <= pivot){
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	i++;
	temp = array[j];
	array[j] = array[i];
	array[i] = temp;

	return i;
}
