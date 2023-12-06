/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 * Date: 11/28/2023
 ***********************/

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "../headers/screens.h"

typedef struct BadGuy {
    int x;
    int y;
} BadGuy;

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

int get_bad_guys(BadGuy *badGuys, wchar_t levels[][30][81], int level) {
    int size = 0;

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 80; j++) {
            if (levels[level - 1][i][j] == L'E') {
                BadGuy badGuy;
                badGuy.x = j;
                badGuy.y = i;
                badGuys[size] = badGuy;

                size++;
            };
        }
    }
    return size;
}

void process_bad_guys(WINDOW *w, Player *p, wchar_t levels[][30][81], int level) {
    BadGuy *badGuys = calloc(1, 400); // Make this more dynamic lol
    int size = get_bad_guys(badGuys, levels, level);

    for (int i = 0; i < size; i++) {
        BadGuy badGuy = badGuys[i];

        int r = rand() % 4;
        if (r == 0 && (levels[level - 1][badGuy.y - 1][badGuy.x] == L' ' || levels[level - 1][badGuy.y - 1][badGuy.x] == L'@')) {
            if (levels[level - 1][badGuy.y - 1][badGuy.x] == L'@') {
                if (!has_all_items(p)) game_over_screen(w);
            } else {
                levels[level - 1][badGuy.y][badGuy.x] = L' ';
                levels[level - 1][badGuy.y - 1][badGuy.x] = L'E';
            }
        }

        if (r == 1 && (levels[level - 1][badGuy.y + 1][badGuy.x] == L' ' || levels[level - 1][badGuy.y + 1][badGuy.x] == L'@')) {
            if (levels[level - 1][badGuy.y + 1][badGuy.x] == L'@') {
                if (!has_all_items(p)) game_over_screen(w);
            } else {
                levels[level - 1][badGuy.y][badGuy.x] = L' ';
                levels[level - 1][badGuy.y + 1][badGuy.x] = L'E';
            }
        }

        if (r == 2 && (levels[level - 1][badGuy.y][badGuy.x - 1] == L' ' || levels[level - 1][badGuy.y][badGuy.x - 1] == L'@')) {
            if (levels[level - 1][badGuy.y][badGuy.x - 1] == L'@') {
                if (!has_all_items(p)) game_over_screen(w);
            } else {
                levels[level - 1][badGuy.y][badGuy.x] = L' ';
                levels[level - 1][badGuy.y][badGuy.x - 1] = L'E';
            }
        }

        if (r == 3 && (levels[level - 1][badGuy.y][badGuy.x + 1] == L' ' || levels[level - 1][badGuy.y][badGuy.x + 1] == L'@')) {
            if (levels[level - 1][badGuy.y][badGuy.x + 1] == L'@') {
                if (!has_all_items(p)) game_over_screen(w);
            } else {
                levels[level - 1][badGuy.y][badGuy.x] = L' ';
                levels[level - 1][badGuy.y][badGuy.x + 1] = L'E';
            }
        }
    }

    free(badGuys);
}