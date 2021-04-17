#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct timeval Timeval;

void merge_sort(int *array, int head, int tail);
void merge(int *array, int head, int merge, int tail);
void array_copy(int *dest, int *src, int head, int tail);

void print_result(int *array, int cnt);

int main(){
	int input;
	register int *array;
	int cnt = 0;
	Timeval start;
	Timeval end;
	unsigned long diff;
	array = (int*)calloc((int)1e7, sizeof(int));

	while(scanf("%d", &array[cnt]) != EOF) cnt++;

	gettimeofday(&start, NULL);
	merge_sort(array, 0, cnt-1);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;

	printf("sorting time:%f\n", diff/1000000.0);
	//print_result(array, cnt);

	free(array);
	return 0;
}
void merge_sort(int *array, int head, int tail){
	if(head >= tail) return;

	int mid = (head+tail)/2;	
	merge_sort(array, head, mid);	
	merge_sort(array, mid+1, tail);
	merge(array, head, mid, tail);

	return;
}
inline void merge(int *array, int head, int mid, int tail){

	int *left_array = (int*)calloc(mid-head+1, sizeof(int));
	int *right_array = (int*)calloc(tail-mid, sizeof(int));

	int *left_ptr = left_array;
	int *right_ptr = right_array;
	
	int *left_end = left_array+mid-head+1;
	int *right_end = right_array+tail-mid;

	array_copy(left_array, array, head, mid);
	array_copy(right_array, array, mid+1, tail);
	
	while(head<=tail){
		if(right_ptr>=right_end || (left_ptr<left_end && *left_ptr<=*right_ptr)){
			array[head++] = *left_ptr++;
		}
		else{
			array[head++] = *right_ptr++;
		}
	}

	free(left_array);
	free(right_array);
}
inline void array_copy(int *dest, int *src, int head, int tail){
	int i = 0;
	while(head<=tail){
		dest[i++] = src[head++];
	}
}
inline void print_result(int *array, int cnt){
	for(int i=0; i<cnt; i++){
		printf("%d\n", array[i]);
	}
}
