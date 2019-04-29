#include <stdio.h>
#include <string.h>
#include "count.h"
#include "screen.h"

int main(){
    FILE *data;
	clearScreen();
	printf("\033[0;0H");
    printf("The number of words: %d\n", NumOfWord(data));
	printf("Barchart1 uses to display the number of words starting from letter A to Z\n");
	printf("Barchart2 uses to display the number of letters ( A to Z) appeared in wlist.txt\n");
	setColors(CYAN, bg(BLACK));
	barChart1(data);
	setColors(GREEN, bg(BLACK));
	barChart2(data);
}

