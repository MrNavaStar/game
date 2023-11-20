#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>


void display_level(int level) {
	clear();
	FILE *fptr;
	char ch;

    char level_index[2];
    sprintf(level_index, "%d", level);

    char file_name[18] = "assets/level";
    strcat(file_name, level_index);
    strcat(file_name, ".txt");

    fptr = fopen(file_name, "r");
    if (fptr == NULL) {
        endwin();
        printf("File cannot be read!\n");
        printf("%s\n", file_name);
        exit(EXIT_FAILURE);
    }

    // In the future we will load into an array, so we can move the player around. But for now just print it
    for (int i = 0; i<30; i++) {
        for (int j = 0; j<80; j++) {
            ch = fgetc(fptr);
            mvaddch(i,j,ch);
        }
    }
	fclose(fptr);
}