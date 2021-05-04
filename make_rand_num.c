#include <stdio.h>
#include <stdlib.h>

int main(){
	int total;
	int i=0;

	scanf("%d", &total);

	while(i++<total){
		printf("%d\n", rand());
	}

	return 0;
}
