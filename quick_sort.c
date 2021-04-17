#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *array, int head, int tail);
int partition(int *array, int head, int tail);

int main(){
	int input;
	int *array;
	array = (int*)calloc((int)1e7, sizeof(int));
	int cnt = 0;

	while(scanf("%d", &array[cnt]) != EOF) cnt++;

	quick_sort(array, 0, cnt-1);

	for(int i=0; i<cnt; i++){
		printf("%d\n", array[i]);
	}

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
