#include <curses.h>
#include <locale.h>
#include "../headers/screens.h"
#include "../headers/levels.h"

int main() {
    WINDOW *w;
    setlocale(LC_ALL, ""); // Set locale so special chars print correctly
    initscr();
    init_colors();
    cbreak();
    noecho();
    curs_set(0); // Hide cursor

    w = newwin(LINES, COLS, 0, 0);
    if (LINES < 30 || COLS < 80) terminal_too_small_screen(w);

    splash_screen(w);
    //game_over_screen(w);
    //victory_screen(w);
    display_level(w, 1);
    getch();
    display_level(w, 2);
    getch();
    display_level(w, 3);
    getch();
    endwin();
    return 0;
}
