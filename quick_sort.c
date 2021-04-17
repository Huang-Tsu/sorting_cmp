#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct timeval Timeval;

void quick_sort(int *array, int head, int tail);
int partition(int *array, int head, int tail);
void print_result(int *array, int cnt);

int main(){
	int input;
	register int *array;
	array = (int*)calloc((int)1e7, sizeof(int));
	int cnt = 0;
	Timeval start;
	Timeval end;
	unsigned long diff;

	while(scanf("%d", &array[cnt]) != EOF) cnt++;

	gettimeofday(&start, NULL);
	quick_sort(array, 0, cnt-1);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;

	//printf("sorting time:%f\n", diff/1000000.0);
	print_result(array, cnt);

	free(array);
	return 0;
}
void quick_sort(int *array, int head, int tail){
	if(head >= tail) return;

	int pivot = partition(array, head, tail);
	quick_sort(array, head, pivot-1);	
	quick_sort(array, pivot+1, tail);

	return;
}
int partition(int *array, int head, int tail){

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
void print_result(int *array, int cnt){
	for(int i=0; i<cnt; i++){
		printf("%d\n", array[i]);
	}
}
