/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 * Date: 11/28/2023
 ***********************/

#include <time.h>
#include <stdlib.h>
#include <wchar.h>
#include <curses.h>
#include "../headers/player.h"
#include "../headers/screens.h"

void set_char(wchar_t levels[][30][81], int level, int x, int y, wchar_t c) {
    levels[level - 1][y][x] = c;
}

void move_player(Player *p, wchar_t levels[][30][81], int level, int x, int y) {
    // Clear current pos
    set_char(levels, p->level, p->x, p->y, L' ');
    // Update pos & level
    p->y = p->y + y;
    p->x = p->x + x;
    p->level = level;
    // Move char to new pos
    levels[p->level - 1][p->y][p->x] = p->ch;
}

void item_pickup(Player *p){
    srand(time(NULL));
    int r = rand() % 5;
    if (r == 0) p->big_sword = 1;
    else if (r == 1) p->bow = 1;
    else if (r == 2) p->shield = 1;
    else if (r == 3) p->hourglass = 1;
}

int has_all_items(Player *p) {
    return p->bow && p->shield && p->hourglass;
}

void handle_user_input(WINDOW *w, Player *p, wchar_t levels[][30][81], char input) {
    // move character up
    if (input == 'w') {
        wchar_t next = levels[p->level -1][p->y-1][p->x];
        if (next == L' ') move_player(p, levels, p->level, 0, -1);

        //open chest and pickup item
        else if (next == L'C'){
            item_pickup(p);
            set_char(levels, p->level, p->x, p->y-1, L'O');
        }
        else if (next == L'E') {
            if (has_all_items(p)) {
                set_char(levels, p->level, p->x, p->y-1, L' ');
                p->kills++;
                return;
            }
            game_over_screen(w);
        }
    }

    // move character down
    else if (input == 's'){
        wchar_t next = levels[p->level -1][p->y+1][p->x];
        if (next == L' ') move_player(p, levels, p->level, 0, 1);

        //open chest and pickup item
        else if (next == L'C'){
            item_pickup(p);
            set_char(levels, p->level, p->x, p->y+1, L'O');
        }
        else if (next == L'E') {
            if (has_all_items(p)) {
                set_char(levels, p->level, p->x, p->y+1, L' ');
                p->kills++;
                return;
            }
            game_over_screen(w);
        }
    }

    // move character left
    else if (input == 'a') {
        wchar_t next = levels[p->level - 1][p->y][p->x-1];
        if (next == L' ') move_player(p, levels, p->level, -1, 0);

        // Move player to next level
        else if (next == L'2') move_player(p, levels, 2, 74, 0);
        else if (next == L'1') move_player(p, levels, 1, 73, 0);

        //open chest and pickup item
	    else if (next == L'C'){
            item_pickup(p);
            set_char(levels, p->level, p->x-1, p->y, L'O');
        }
        else if (next == L'E') {
            if (has_all_items(p)) {
                set_char(levels, p->level, p->x-1, p->y, L' ');
                p->kills++;
                return;
            }
            game_over_screen(w);
        }
    }

    // move character right
    else if (input == 'd') {
        wchar_t next = levels[p->level - 1][p->y][p->x+1];
        if (next == L' ') move_player(p, levels, p->level, 1, 0);

        // Move player to next level
        else if (next == L'3') move_player(p, levels, 3, -73, 0);
        else if (next == L'1') move_player(p, levels, 1, -74, 0);

        //open chest and pickup item
        else if (next == L'C'){
            item_pickup(p);
            set_char(levels, p->level, p->x+1, p->y, L'O');
        }
        else if (next == L'E') {
            if (has_all_items(p)) {
                set_char(levels, p->level, p->x+1, p->y, L' ');
                p->kills++;
                return;
            }
            game_over_screen(w);
        }
    }
}