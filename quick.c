#include "sorting.h"
#include <stdio.h>
#include <string.h>
void quick_sort(void **array, int head, int tail,
		int (*compare)(void **array, int i, int j)){
				/*
					for(int i=0; i<(int)1e6; i++){
						printf("%d\n", *(int*)array[i]);
					}
					*/

	if(head >= tail) return;

	int pivot = partition(array, head, tail, compare);
	quick_sort(array, head, pivot-1, compare);	
	quick_sort(array, pivot+1, tail, compare);

	return;
}
inline int partition(void **array, int head, int tail,
		int (*compare)(void **array, int i, int j)){
			/*
					for(int i=0; i<(int)1e6; i++){
						printf("%d\n", *(int*)array[i]);
					}
				*/
				/*
					printf("compare(array, 1, 2):%d\n", compare(array, 1, 2));
					printf("compare(array, 2, 1):%d\n", compare(array, 2, 1));
					printf("compare(array, head-1, tail):%d\n", compare(array, head-1, tail));
					*/

	int pivot = tail;
	int i, j;
	for(i=head-1, j=head; j<tail; j++){
		if(compare(array, j, pivot)<=0){
			i++;
			swap(array, i, j);
		}
	}
	i++;
	swap(array, i, j);

	return i;
}
