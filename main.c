#include <stdio.h>
#include <string.h>
#include "count.h"
#include "screen.h"
#include <stdlib.h> // uses for system function

int main(){
	system("wget http://www.cc.puv.fi/~gc/wlist.txt"); // download wlist.txt file to folder
	clearScreen();
	printf("\033[0;0H");
	printf("The number of words: %d\n", NumOfWord());
	printf("Barchart1 uses to display the number of words starting from letter A to Z\n");
	printf("Barchart2 uses to display the number of letters ( A to Z) appeared in wlist.txt\n");
	setColors(CYAN, bg(BLACK));
	barChart1();
	setColors(GREEN, bg(BLACK));
	barChart2();
	system("rm wlist.txt"); // remove wlist.txt file
}

