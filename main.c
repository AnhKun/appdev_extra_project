#include <stdio.h>
#include <string.h>
int main(){
	FILE *data = fopen("wlist.txt", "r");
	char string[10];
	int count[26]={0}, numOfWords=0;
	fscanf(data, "%s", &string);
	while(!feof(data)){
		numOfWords++;
		for (int i=65; i<=90; i++){
			char a[2];
			a[0]=i;
			if (string[0]==a[0]){
				count[i-65]++;
			}
		}
		fscanf(data, "%s", &string);
	}
	fclose(data);
	printf("The number of words: %d\n", numOfWords);
	for (int i=65; i<=90; i++){
		char a[2];
    	a[0]=i;
		printf("The number of words that are starting with %c: %d\n", a[0], count[i-65]);
	}
}
