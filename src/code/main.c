#include <curses.h>
#include <locale.h>
#include <wchar.h>
#include "../headers/screens.h"
#include "../headers/levels.h"

typedef struct Player{
   int x;
   int y;
   char ch;
   int level;
}Player;


int main() {
    int ch;
    WINDOW *w;
    wchar_t levels[3][30][81];
    Player p;
    p.x = 51;
    p.y = 4;
    p.ch = '@';
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

    //game_over_screen(w);
    //victory_screen(w);
    display_level(w, levels, p.level);
    mvaddch(p.y,p.x,p.ch);
    while(1){
	    
	if(ch == 'q'){
	    quit_screen(w);
	    ch = getch();
	    if(ch == 'y')break;

	    else if(ch == 'n'){
	        display_level(w, levels, p.level);
	        mvaddch(p.y,p.x,p.ch);  
	    }
	}

	else if(ch == 'p'){
	    pause_screen(w);
	    while(1){
	    	getch();
		if(ch == 'p')break;
	    }
	    display_level(w, levels, p.level);
	    mvaddch(p.y,p.x,p.ch);
	}
	    
	else if(ch == 'w'){
	    if(mvinch(p.y-1,p.x) == L' '){
		//move character up function
	    }
	}
	else if(ch == 'a'){
            if(mvinch(p.y,p.x-1) == L' '){
                //move character left function
            }
        }
	else if(ch == 's'){
            if(mvinch(p.y+1,p.x) == L' '){
                //move character down function
            }
        }
	else if(ch == 'd'){
            if(mvinch(p.y,p.x+1) == L' '){
                //move character right function
            }
        }


        ch = getch();
    }

    endwin();
    return 0;
}
