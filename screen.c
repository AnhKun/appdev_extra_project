#include <stdio.h>
#include "screen.h"
#include <string.h>

// this function uses to display a barchart which shows the number of words
// starting from letter A to Z
void barChart1(){
    FILE *data;
	data = fopen("wlist.txt", "r");
    char string[10], a[2];
    int count[26]={0}, i, j;
	do{
    	fscanf(data, "%s", &string); // gets the word from file and asigns it to variable string
		count[string[0]-'A']++;
    }while(!feof(data)); // condition of end of file
    fclose(data);

	// takes the array count[] to display barchart 1
	for (i=0; i<26; i++){ // for 26 columns
		for (j=0; j<count[i]/2; j++){
			printf("\033[%d;%dH", 36-j, (2*i)+1); // j is row and i is column
#ifdef UNICODE    // conditional compilation
			printf("%s", BAR);
#else
			printf("%c", '*');
#endif
		}
		// display the values above every bar
		if (count[i]>0){
			printf("\033[%d;%dH", 36-j, (2*i)+1);
			printf("%d", count[i]);
		}
		// display A, B,... below the chart
		printf("\033[37;%dH", (2*i)+1);
		a[0]=(i+65);
		printf("%c",a[0]);
	}
	// displays the figure of chart
	setColors(RED, bg(BLACK));
	printf("\033[38;18H");
	printf("Barchart1");
	resetColors();
}




// function uses to count how many times letter 'A' ('B'..'Z') appeared in file wlist.txt
// and display them as a barchart
void barChart2(){
	FILE *data;
    data = fopen("wlist.txt", "r");
    char string[10], a[2];
    int count[26]={0}, i, j;
	do {
	    fscanf(data, "%s", &string);
		for (i=0; i<strlen(string); i++)
			count[string[i]-'A']++;
    }while (!feof(data));
	fclose(data);
    for (i=0; i<26; i++){ // for 26 columns
        for (j=0; j<count[i]/5; j++){
            printf("\033[%d;%dH", 36-j, 60+(2*i)+1); // j is row and i is column
#ifdef UNICODE    // conditional compilation
            printf("%s", BAR);
#else
            printf("%c", '*');
#endif
        }
		// displays the values above every bar
		if (count[i]>0){
			printf("\033[%d;%dH", 36-j, 60+(2*i)+1);
			printf("%d",count[i]);
		}
		// display A, B... below the chart
		printf("\033[37;%dH",60+(2*i)+1);
		a[0]=(i+65);
		printf("%c",a[0]);
    }
	// displays the figure of chart
	setColors(RED, bg(BLACK));
	printf("\033[38;80H");
	printf("Barchart2\n");
	resetColors();
}



void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);
}

void setColors(short bg, short fg){
	printf("\033[%d;%d;1m", bg, fg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}
