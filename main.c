#include <stdio.h>
#include <string.h>
#include "count.h"
#include "screen.h"

int main(){
    FILE *data;
    printf("The number of words: %d\n", NumOfWord(data));
//    WordStartingLetter(data);
	setColors(CYAN, bg(BLACK));
	barChart1(data);
	setColors(GREEN, bg(BLACK));
	barChart2(data);
//	FindWordDuplicate(data);
}

