#include <curses.h>
#include <locale.h>
#include "screens.h"

int main() {
    WINDOW *w;
    setlocale(LC_ALL, ""); // Set locale so special chars print correctly
    initscr();
    initColors();
    cbreak();
    noecho();
    curs_set(0); // Hide cursor

    w = newwin(30, 80, 0, 0);
    refresh();

    splashScreen(w);
    //gameOverScreen(w);
    //victoryScreen(w);

    endwin();
    return 0;
}