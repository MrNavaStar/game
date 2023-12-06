/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 ***********************/

#ifndef PLAYER_H
#define PLAYER_H
#include <wchar.h>
#include <curses.h>

typedef struct Player {
    int x;
    int y;
    wchar_t ch;
    int level;
    int kills;
    int big_sword;
    int bow;
    int shield;
    int hourglass;
} Player;

// translates the player from its current position & can be used to change the players current level if the passed
// in level does not match p.level
void move_player(Player *p, wchar_t levels[][30][81], int level, int x, int y);

// simple code that will gnenerate a random number and allow the player to add this random item to their inventory
void item_pickup(Player *p);

int has_all_items(Player *p);

// Must be called every game loop to process keyboard inputs for the player
void handle_user_input(WINDOW *w, Player *p, wchar_t levels[][30][81], char input);

#endif
