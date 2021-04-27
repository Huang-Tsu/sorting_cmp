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
