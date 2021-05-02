#include "sorting.h"
#include <stdio.h>
#include <string.h>
void quick_sort(void **array, int head, int tail,
		int (*compare)(const void *a, const void *b)){

	if(head >= tail) return;

	int pivot = partition(array, head, tail, compare);
	quick_sort(array, head, pivot-1, compare);	
	quick_sort(array, pivot+1, tail, compare);

	return;
}
inline int partition(void **array, int head, int tail,
		int (*compare)(const void *a, const void *b)){

	int pivot = tail;
	int i, j;
	for(i=head-1, j=head; j<tail; j++){
		if(compare(array[j], array[pivot])<=0){
			i++;
			swap(array, i, j);
		}
	}
	i++;
	swap(array, i, j);

	return i;
}
