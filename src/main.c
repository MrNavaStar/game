#include <curses.h>
#include <locale.h>
#include "screens.h"

int main() {
    WINDOW *w;
    setlocale(LC_ALL, ""); // Set locale so utf8 chars print correctly
    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(0); // Hide cursor
    w = newwin(30, 80, 0, 0);
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    splashScreen(w);
    //gameOverScreen(w);

    endwin();
    return 0;
}
