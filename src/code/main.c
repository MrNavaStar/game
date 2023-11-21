#include <curses.h>
#include <locale.h>
#include <wchar.h>
#include "../headers/screens.h"
#include "../headers/levels.h"

int main() {
    WINDOW *w;
    wchar_t levels[3][30][81];

    setlocale(LC_ALL, ""); // Set locale so special chars print correctly
    initscr();
    init_colors();
    cbreak();
    noecho();
    curs_set(0); // Hide cursor

    w = newwin(LINES, COLS, 0, 0);
    if (LINES < 30 || COLS < 80) terminal_too_small_screen(w);

    splash_screen(w);
    load_level(levels, 1);
    load_level(levels, 2);
    load_level(levels, 3);

    display_level(w, levels, 1);
    getch();

    endwin();
    return 0;
}
