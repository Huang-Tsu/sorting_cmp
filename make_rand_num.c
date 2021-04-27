#include <stdio.h>
#include <stdlib.h>

void make_rand_num(int *array, int len){
	int i=0;

	while(i<len){
		array[i] = rand();
	}
}
