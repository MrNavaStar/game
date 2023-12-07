/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 ***********************/

#include <curses.h>
#include <wchar.h>
#include "player.h"

/**
 * Set up the color pairs used in the code
 */
void init_colors();

/**
 * Closes the ncurses screen and exits the program
 * @param w
 * @param wait
 */
void exit_game(WINDOW *w, int wait);

/**
 * Show terminal too small screen - maybe adapt this into a general error screen
 * @param w
 */
void terminal_too_small_screen(WINDOW *w);

/**
 * Show the quit screen
 * @param w
 */
void quit_screen(WINDOW *w);

/**
 * Show the pause screen
 * @param w
 */
void pause_screen(WINDOW *w);

/**
 * Show the start-up screen
 * @param w
 */
void splash_screen(WINDOW *w);

/**
 * Show the failure screen
 * @param w
 */
void game_over_screen(WINDOW *w);

/**
 * Show the win screen
 * @param w
 */
void victory_screen(WINDOW *w);

/**
 * Show inventory screen
 * @param w
 * @param p
 */
void inventory_screen(WINDOW *w, Player *p);

/**
 * Renders a block of wide chars at the give xy pos
 * @param text
 * @param x
 * @param y
 */
void render_text(wchar_t *text, int x, int y);

/**
 * Returns the x position that will result in the given text block being centered on the screen
 * @param w
 * @param text
 * @return
 */
int center_text(WINDOW *w, wchar_t *text);