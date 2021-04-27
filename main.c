#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define RAND_LEN (int)1e7

typedef struct timeval Timeval;

int main(){
	register int *array_num = (int*)calloc((int)1e7, sizeof(int));
	int *temp_rand_num = (int*)calloc((int)1e7, sizeof(int));
	register char **array_eng = (char**)calloc((int)1e7, sizeof(char*));
	char **temp_rand_eng = (char**)calloc((int)1e7, sizeof(char*));
	int cnt = 0;
	Timeval start;
	Timeval end;
	unsigned long diff;
	for(int i=0; i<RAND_LEN; i++){
		array_eng[i] = (char*)calloc(101, sizeof(char);
	}

	read_rand(temp_rand_num);	


	gettimeofday(&start, NULL);
	//quick_sort(array_num, 0, cnt-1);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;

	printf("sorting time:%f\n", diff/1000000.0);
	//print_result(array_num, cnt);

	free(array_num);

	for(int i=0; i<RAND_LEN; i++){
		free(array_eng[i]);
	}
	free(array_eng);
	return 0;
}
