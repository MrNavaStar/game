#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "../headers/screens.h"

void load_level(wchar_t levels[][30][81], int level) {
	FILE *fptr;

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

    // Load level data from file into mem
    for (int i = 0; i < 30; i++) {
        fgetws(levels[level - 1][i], 81, fptr);
    }
	fclose(fptr);
}

void display_level(WINDOW *w, wchar_t levels[][30][81], int level) {
    clear();

    for (int i = 0; i < 30; i++) {
        wchar_t *line = levels[level - 1][i];
        render_text(line, center_text(w, line), i);
    }
}