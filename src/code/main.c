/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 * Date: 11/28/2023
 * Description: This code will run Cryptic Conquest in all it's parts
 ***********************/

#include <curses.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>
#include <stdlib.h>
#include "../headers/player.h"
#include "../headers/screens.h"
#include "../headers/levels.h"


int main() {
    char input;
    WINDOW *w;
    wchar_t levels[3][30][81];
    Player p;
    p.x = 54;
    p.y = 4;
    p.ch = L'@';
    p.level = 1;
    p.big_sword = 0;
    p.bow = 0;
    p.shield = 0;
    p.hourglass = 0;
    
    setlocale(LC_ALL, ""); // Set locale so special chars print correctly
    initscr();
    init_colors();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0); // Hide cursor
    w = newwin(LINES, COLS, 0, 0);
    if (LINES < 30 || COLS < 80) terminal_too_small_screen(w);

    srand(time(NULL));
    splash_screen(w);
    load_level(levels, 1);
    load_level(levels, 2);
    load_level(levels, 3);

    while (1) {
        display_level(w, levels, p.level);
        input = getch();

        // Handle quit
        if (input == 'q') {
            quit_screen(w);
            while(1) {
                input = getch();
                if (input == 'y') exit_game(w,0);
                else if (input == 'n') break;
            }
	    }
        

        // Handle pause
        else if (input == 'p') {
            pause_screen(w);
            while (1) {
                input = getch();
                if (input == 'p') break;
            }
        }

	    else if (input == 'i') {
            inventory_screen(w,&p);
            while (1) {
                input = getch();
                if (input == 'i') break;
            }
        }

        process_bad_guys(w, &p, levels, p.level);
        handle_user_input(w, &p, levels, input);
        if (p.kills >= 58) victory_screen(w);
    }
}