#include <curses.h>

void init_colors();

void terminal_too_small_screen(WINDOW *w);

void splash_screen(WINDOW *w);

void game_over_screen(WINDOW *w);

void victory_screen(WINDOW *w);