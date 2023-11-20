#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "../headers/screens.h"


void display_level(WINDOW *w, int level) {
	clear();
	FILE *fptr;
	wchar_t levelStr[2400]; // 30*80 chars = 2400

    char file_name[18] = "assets/level";
    char level_index[2];
    sprintf(level_index, "%d", level);
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
        fgetws(levelStr, 2400, fptr);
        printw("%ls", levelStr);
    }
	fclose(fptr);
}