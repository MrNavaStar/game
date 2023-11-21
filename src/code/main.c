#include <curses.h>
#include <locale.h>
#include "../headers/screens.h"
#include "../headers/levels.h"

typedef struct{
   int x;
   int y;
   char ch;
   int level;
}Player;


int main() {
    int ch;
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
    while(1){
	    
	if(ch == 'q'){
	    quit_screen(w);
	    ch = getch();
	    if(ch == 'y')break;
	    else if(ch == 'n'){
		continue;
		//go back to original screen level
	    }
	}

	else if(ch == 'p'){
	    pause_screen(w);
	    while(1){
	    	getch();
		if(ch == 'p')break;
	    }
	    //go back to original screen level
	}
	
	else if(ch == 'w'){
	    if(p.y-1 ==' ')//player move up function;

	    
	}
        ch = getch();
    }
    endwin();
    return 0;
}
