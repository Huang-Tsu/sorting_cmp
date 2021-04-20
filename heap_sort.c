#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct timeval Timeval;

int heap_len = 0;

void node_max(int *array, int idx);
void heap_sort(int *array, int idx);
void print_result(int *array, int cnt);

int main(){
	int input;
	register int *array;
	array = (int*)calloc((int)1e7, sizeof(int));
	Timeval start;
	Timeval end;
	unsigned long diff;

	while(scanf("%d", &array[cnt]) != EOF) cnt++;

	gettimeofday(&start, NULL);
	heap_sort(array, 0, cnt-1);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;

	//printf("sorting time:%f\n", diff/1000000.0);
	print_result(array, cnt);

	free(array);
	return 0;
}

void heap_sort(int *array, int idx){
	if(heap_len <= 1) return;

	
}
void node_max(int *array, int idx){
	
}
inline void print_result(int *array, int cnt){
	for(int i=0; i<cnt; i++){
		printf("%d\n", array[i]);
	}
}
