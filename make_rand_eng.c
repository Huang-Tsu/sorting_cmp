#include <stdio.h>
#include <stdlib.h>

int main(){
	int total;
	char word;
	int remain;
	int i=0;

	scanf("%d", &total);

	while(i++<total){
		for(int i=0; i<100; i++){
			remain = rand()%52;
			if(remain<=25) word = 'a'+ remain;
			else word = 'A' + remain-26;
			printf("%c", word);
		}
		puts("");
	}

	return 0;
}
