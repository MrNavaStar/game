/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 ***********************/

#include <curses.h>
#include <wchar.h>

// Set up the color pairs used in the code
void init_colors();

// Show terminal too small screen - maybe adapt this into a general error screen
void terminal_too_small_screen(WINDOW *w);

// Show the quit screen
void quit_screen(WINDOW *w);

//Show the pause screen
void pause_screen(WINDOW *w);

// Show the start-up screen
void splash_screen(WINDOW *w);

// Show the failure screen
void game_over_screen(WINDOW *w);

// Show the win screen
void victory_screen(WINDOW *w);

//Show inventory screen
void inventory_screen(WINDOW *w);

// Text render utils
void render_text(wchar_t *text, int x, int y);
int center_text(WINDOW *w, wchar_t *text);
