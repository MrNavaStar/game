/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 * Date: 11/28/2023
 ***********************/

#include <time.h>
#include <stdlib.h>
#include <wchar.h>
#include "../headers/player.h"

void move_player(Player *p, wchar_t levels[][30][81], int level, int x, int y) {
    // Clear current pos
    levels[p->level - 1][p->y][p->x] = L' ';
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

void handle_user_input(Player *p, wchar_t levels[][30][81], char input) {
    // move character up
    if (input == 'w'){
	wchar_t next = levels[p->level -1][p->y-1][p->x];    
        if (next == L' ') move_player(p, levels, p->level, 0, -1);
        //open chest and pickup item
	else if (next == L'C'){
           item_pickup(p);
	   levels[p->level -1][p->y-1][p->x] = L'O';
	}
    }
    // move character down
    else if (input == 's'){
        wchar_t next = levels[p->level -1][p->y+1][p->x];
        if (next == L' ') move_player(p, levels, p->level, 0, 1);
        //open chest and pickup item
	else if (next == L'C'){
           item_pickup(p);
           levels[p->level -1][p->y+1][p->x] = L'O';
	}
    }
    // move character left
    else if (input == 'a') {
        wchar_t next = levels[p->level - 1][p->y][p->x-1];
        // normal translation
        if (next == L' ') move_player(p, levels, p->level, -1, 0);
            // Move player to next level
        else if (next == L'2') move_player(p, levels, 2, 74, 0);
        else if (next == L'1') move_player(p, levels, 1, 73, 0);
        //open chest and pickup item
	else if (next == L'C'){
           item_pickup(p);
           levels[p->level -1][p->y][p->x-1] = L'O';
        }

    }

    // move character right
    else if (input == 'd') {
        wchar_t next = levels[p->level - 1][p->y][p->x+1];
        // normal translation
        if (next == L' ') move_player(p, levels, p->level, 1, 0);
            // Move player to next level
        else if (next == L'3') move_player(p, levels, 3, -73, 0);
        else if (next == L'1') move_player(p, levels, 1, -74, 0);
        //open chest and pickup item
	else if (next == L'C'){
           item_pickup(p);
           levels[p->level -1][p->y][p->x+1] = L'O';
        }

    }
}
