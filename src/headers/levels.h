/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 ***********************/

#include <curses.h>
#include <wchar.h>

// Load the level from the file given a number
void load_level(wchar_t levels[][30][81], int level);

// Display the level from the array given a number
void display_level(WINDOW *w, wchar_t levels[][30][81], int level);
