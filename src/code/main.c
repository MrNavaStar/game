#include <curses.h>
#include <locale.h>
#include <wchar.h>
#include "../headers/screens.h"
#include "../headers/levels.h"

typedef struct Player{
   int x;
   int y;
   wchar_t ch;
   int level;
} Player;

int main() {
    int ch;
    WINDOW *w;
    wchar_t levels[3][30][81];
    Player p;
    p.x = 54;
    p.y = 4;
    p.ch = L'@';
    p.level = 1;

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

    while (1) {
        ch = getch();

        if (ch == 'q') {
            quit_screen(w);
            ch = getch();
            if (ch == 'y') break;
        }

        else if (ch == 'p') {
            pause_screen(w);
            while (1) {
                ch = getch();
                if (ch == 'p') break;
            }
        }

        //move character up function
        else if (ch == 'w' && levels[p.level][p.y-1][p.x] == L' ') {
            levels[p.level - 1][p.y][p.x] = L' ';
            levels[p.level - 1][p.y-1][p.x] = p.ch;
            p.y = p.y - 1;
        }

        //move character down function
        else if (ch == 's' && levels[p.level][p.y+1][p.x] == L' ') {
            levels[p.level - 1][p.y][p.x] = L' ';
            levels[p.level - 1][p.y+1][p.x] = p.ch;
            p.y = p.y + 1;
        }

        //move character left function
        else if (ch == 'a' && levels[p.level][p.y][p.x-1] == L' ') {
            levels[p.level - 1][p.y][p.x] = L' ';
            levels[p.level - 1][p.y][p.x-1] = p.ch;
            p.x = p.x - 1;
        }

        //move character right function
        else if (ch == 'd' && levels[p.level][p.y][p.x+1] == L' ') {
            levels[p.level - 1][p.y][p.x] = L' ';
            levels[p.level - 1][p.y][p.x+1] = p.ch;\
            p.x = p.x + 1;
        }

        display_level(w, levels, p.level);
    }

    endwin();
    return 0;
}
