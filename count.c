#include <stdio.h>
#include <string.h>
#include "count.h"

// function uses to count the number of words in file wlist.txt 
int NumOfWord(){
	FILE *data;
	data = fopen("wlist.txt", "r"); // open file wlist.txt
	char string[10];
    int sum=0;
	fscanf(data, "%s", &string); // gets the word from file and asigns it to variable string
    while(!feof(data)){ // condition of end of file
        sum++;
		fscanf(data, "%s", &string);
    }
	fclose(data);
    return sum; 
}





