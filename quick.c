#include "sorting.h"
#include <stdio.h>
#include <string.h>
void quick_sort(void *array, int head, int tail,
		int (*compare)(const void *, const void *)){

	if(head >= tail) return;

	int pivot = partition(array, head, tail, compare);
	quick_sort(array, head, pivot-1, compare);	
	quick_sort(array, pivot+1, tail, compare);

	return;
}
inline int partition(void *array, int head, int tail,
		int (*compare)(const void *, const void *)){

		char **english;
		int *number;
	if(compare == strcmp) 
	else 

	int pivot = ptr[tail];
	int temp;
	int i, j;
	for(i=head-1, j=head; j<tail; j++){
		if(compare(ptr[i], ptr[pivot]){
			i++;
			swap(&ptr[i], &ptr[j], sizeof(ptr[0]);
		}
	}
	i++;
	temp = ptr[j];
	ptr[j] = ptr[i];
	ptr[i] = temp;

	return i;
}
