/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 ***********************/

#include <curses.h>
#include <wchar.h>
#include "../headers/player.h"

/**
 * Load the level from the file given a number
 * @param levels
 * @param level
 */
void load_level(wchar_t levels[][30][81], int level);

/**
 * Display the level from the array given a number
 * @param w
 * @param levels
 * @param level
 */
void display_level(WINDOW *w, wchar_t levels[][30][81], int level);

/**
 * Updates all the positions of the bad guys on the map and kills the player if it gets to close to one
 * @param w
 * @param p
 * @param levels
 * @param level
 */
void process_bad_guys(WINDOW *w, Player *p, wchar_t levels[][30][81], int level);