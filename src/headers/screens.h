#include <curses.h>

// Set up the color pairs used in the code
void init_colors();

// Show terminal too small screen - maybe adapt this into a general error screen
void terminal_too_small_screen(WINDOW *w);

// Show the start-up screen
void splash_screen(WINDOW *w);

// Show the failure screen
void game_over_screen(WINDOW *w);

// Show the win screen
void victory_screen(WINDOW *w);