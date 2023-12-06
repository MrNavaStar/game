/***********************
 * Group: 2
 * Members: Neshko and Ethan
 * Lab: 10
 * Date: 11/28/2023
 ***********************/

#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <wchar.h>
#include<unistd.h>
#include "../headers/player.h"


// This class uses the cursed wchar_t in order to support extended ascii. If you have to modify to this file I'm sorry.
// But only a little because the ascii art is cool.

#define TEXT_GREEN COLOR_PAIR(1)
#define TEXT_RED COLOR_PAIR(2)
#define TEXT_CYAN COLOR_PAIR(3)

void init_colors() {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
}

// Render single or multiline text at the given coords
void render_text(wchar_t *text, int x, int y) {
    wchar_t *state;
    wchar_t *line;
    line = wcstok(text, L"\n", &state);
    int yOffset = 0;

    while(line != NULL) {
        move(y + yOffset, x);
        printw("%ls", line);

        line = wcstok(NULL, L"\n", &state);
        yOffset++;
    }
}

// Get the screen width of a single line or block of text
int get_width(wchar_t *text) {
    int maxLen = 0;
    int currentLen = 0;
    int totalLen = 0;

    // Find the length of the longest line without a new line
    while(text[totalLen] != '\0') {
        if (text[totalLen] == '\n') {
            if (currentLen > maxLen) maxLen = currentLen;
            currentLen = 0;
        }
        currentLen++;
        totalLen++;
    }

    if (currentLen > maxLen) maxLen = currentLen;
    return maxLen;
}

// Returns the x position that will result in the given text block being centered on the screen
int center_text(WINDOW *w, wchar_t *text) {
    return (getmaxx(w) / 2) - (get_width(text) / 2);
}

void exit_game(WINDOW *w, int wait) {
    if (wait) {
        wchar_t exiting[] = L"Exiting in 2 seconds...";
        render_text(exiting, center_text(w, exiting), 27);
        refresh();

        sleep(2);
    }
    endwin();
    exit(0);
}

void render_continue_prompt(WINDOW *w, int y) {
    wchar_t press[] = L"Press Any Key To Continue";
    render_text(press, center_text(w, press), y);
    //Wait for key press
    getch();
}

void terminal_too_small_screen(WINDOW *w) {
    clear();
    wchar_t too_small[] = L"Terminal window too small!";
    wchar_t size[] = L"Must be at least 30x80!";
    wchar_t warn[] = L"Expect visual artifacts!";
    attron(TEXT_RED);
    render_text(too_small, center_text(w, too_small), 2);
    render_text(size, center_text(w, size), 3);
    render_text(warn, center_text(w, warn), 4);
    attroff(TEXT_RED);
    render_continue_prompt(w, 5);
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void splash_screen(WINDOW *w) {
    clear();
    wchar_t cryptic[] = L" ▄████▄   ██▀███ ▓██   ██▓ ██▓███  ▄▄▄█████▓ ██▓ ▄████▄  \n"
                         "▒██▀ ▀█  ▓██ ▒ ██▒▒██  ██▒▓██░  ██▒▓  ██▒ ▓▒▓██▒▒██▀ ▀█  \n"
                         "▒▓█    ▄ ▓██ ░▄█ ▒ ▒██ ██░▓██░ ██▓▒▒ ▓██░ ▒░▒██▒▒▓█    ▄ \n"
                         "▒▓▓▄ ▄██▒▒██▀▀█▄   ░ ▐██▓░▒██▄█▓▒ ▒░ ▓██▓ ░ ░██░▒▓▓▄ ▄██▒\n"
                         "▒ ▓███▀ ░░██▓ ▒██▒ ░ ██▒▓░▒██▒ ░  ░  ▒██▒ ░ ░██░▒ ▓███▀ ░\n"
                         "░ ░▒ ▒  ░░ ▒▓ ░▒▓░  ██▒▒▒ ▒▓▒░ ░  ░  ▒ ░░   ░▓  ░ ░▒ ▒  ░\n"
                         "  ░  ▒     ░▒ ░ ▒░▓██ ░▒░ ░▒ ░         ░     ▒ ░  ░  ▒   \n"
                         "░          ░░   ░ ▒ ▒ ░░  ░░         ░       ▒ ░░        \n"
                         "░ ░         ░     ░ ░                        ░  ░ ░      \n"
                         "░                 ░ ░                           ░        ";

    wchar_t conquest[] = L" ▄████▄   ▒█████   ███▄    █   █████   █    ██ ▓█████   ██████ ▄▄▄█████▓\n"
                          "▒██▀ ▀█  ▒██▒  ██▒ ██ ▀█   █ ▒██▓  ██▒ ██  ▓██▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒\n"
                          "▒▓█    ▄ ▒██░  ██▒▓██  ▀█ ██▒▒██▒  ██░▓██  ▒██░▒███   ░ ▓██▄   ▒ ▓██░ ▒░\n"
                          "▒▓▓▄ ▄██▒▒██   ██░▓██▒  ▐▌██▒░██  █▀ ░▓▓█  ░██░▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ \n"
                          "▒ ▓███▀ ░░ ████▓▒░▒██░   ▓██░░▒███▒█▄ ▒▒█████▓ ░▒████▒▒██████▒▒  ▒██▒ ░ \n"
                          "░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ░░ ▒▒░ ▒ ░▒▓▒ ▒ ▒ ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   \n"
                          "  ░  ▒     ░ ▒ ▒░ ░ ░░   ░ ▒░ ░ ▒░  ░ ░░▒░ ░ ░  ░ ░  ░░ ░▒  ░ ░    ░    \n"
                          "░        ░ ░ ░ ▒     ░   ░ ░    ░   ░  ░░░ ░ ░    ░   ░  ░  ░    ░      \n"
                          "░ ░          ░ ░           ░     ░       ░        ░  ░      ░           \n"
                          "░                                                                       ";

    attron(TEXT_GREEN);
    render_text(cryptic, center_text(w, cryptic), 2);
    render_text(conquest, center_text(w, conquest), 13);
    attroff(TEXT_GREEN);

    wchar_t controls[] = L" - Use WASD To Move\n - I To Check Inventory\n - P To Pause\n - Q To Quit";
    render_text(controls, center_text(w, controls), 25);
    render_continue_prompt(w, 30);
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void game_over_screen(WINDOW *w) {
    clear();
    wchar_t game[] = L"  ▄████  ▄▄▄       ███▄ ▄███▓▓█████ \n"
                      " ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀ \n"
                      "▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███   \n"
                      "░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄ \n"
                      "░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒\n"
                      " ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░\n"
                      "  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░\n"
                      "░ ░   ░   ░   ▒   ░      ░      ░   \n"
                      "      ░       ░  ░       ░      ░  ░\n"
                      "                                    ";

    wchar_t over[] = L" ▒█████   ██▒   █▓▓█████  ██▀███  \n"
                      "▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n"
                      "▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n"
                      "▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n"
                      "░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒\n"
                      "░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n"
                      "  ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n"
                      "░ ░ ░ ▒       ░░     ░     ░░   ░ \n"
                      "    ░ ░        ░     ░  ░   ░     \n"
                      "              ░                   ";

    attron(TEXT_RED);
    render_text(game, center_text(w, game), 2);
    render_text(over, center_text(w, over), 13);
    attroff(TEXT_RED);
    render_continue_prompt(w, 25);
    exit_game(w, 1);
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void victory_screen(WINDOW *w) {
    clear();
    wchar_t victory[] = L" ██▒   █▓ ██▓ ▄████▄  ▄▄▄█████▓ ▒█████   ██▀███ ▓██   ██▓\n"
                         "▓██░   █▒▓██▒▒██▀ ▀█  ▓  ██▒ ▓▒▒██▒  ██▒▓██ ▒ ██▒▒██  ██▒\n"
                         " ▓██  █▒░▒██▒▒▓█    ▄ ▒ ▓██░ ▒░▒██░  ██▒▓██ ░▄█ ▒ ▒██ ██░\n"
                         "  ▒██ █░░░██░▒▓▓▄ ▄██▒░ ▓██▓ ░ ▒██   ██░▒██▀▀█▄   ░ ▐██▓░\n"
                         "   ▒▀█░  ░██░▒ ▓███▀ ░  ▒██▒ ░ ░ ████▓▒░░██▓ ▒██▒ ░ ██▒▓░\n"
                         "   ░ ▐░  ░▓  ░ ░▒ ▒  ░  ▒ ░░   ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░  ██▒▒▒ \n"
                         "   ░ ░░   ▒ ░  ░  ▒       ░      ░ ▒ ▒░   ░▒ ░ ▒░▓██ ░▒░ \n"
                         "     ░░   ▒ ░░          ░      ░ ░ ░ ▒    ░░   ░ ▒ ▒ ░░  \n"
                         "      ░   ░  ░ ░                   ░ ░     ░     ░ ░     \n"
                         "     ░       ░                                   ░ ░     ";
    attron(TEXT_GREEN);
    render_text(victory, center_text(w, victory), 10);
    attroff(TEXT_GREEN);
    render_continue_prompt(w, 25);
    exit_game(w, 1);
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void quit_screen(WINDOW *w) {
    clear();
    wchar_t quit[] = L"   █████   █    ██  ██▓▄▄▄█████▓\n"
                     " ▒██▓  ██▒ ██  ▓██▒▓██▒▓  ██▒ ▓▒\n"
                     " ▒██▒  ██░▓██  ▒██░▒██▒▒ ▓██░ ▒░\n"
                     " ░██  █▀ ░▓▓█  ░██░░██░░ ▓██▓ ░ \n"
                     " ░▒███▒█▄ ▒▒█████▓ ░██░  ▒██▒ ░ \n"
                     " ░░ ▒▒░ ▒ ░▒▓▒ ▒ ▒ ░▓    ▒ ░░   \n"
                     "  ░ ▒░  ░ ░░▒░ ░ ░  ▒ ░    ░    \n"
                     "  ░   ░  ░░░ ░ ░  ▒ ░  ░        \n"
                     "   ░       ░      ░               ";

    wchar_t game[] = L"  ▄████  ▄▄▄       ███▄ ▄███▓▓█████  \n"
                     "  ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀ \n"
                     " ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███   \n"
                     " ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄ \n"
                     " ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒\n"
                     "  ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░\n"
                     "           ▒   ▒▒ ░░  ░      ░ ░ ░  ░\n"
                     "         ░   ▒   ░      ░      ░     \n"
                     "  ░       ░  ░       ░      ░  ░       ";

    attron(TEXT_RED);
    render_text(quit, center_text(w, quit), 2);
    render_text(game, center_text(w, game), 13);
    attroff(TEXT_RED);

    wchar_t directions[] = L"Press y to quit or n to continue";
    render_text(directions, center_text(w, directions), 25);
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void pause_screen(WINDOW *w) {
    clear();
    wchar_t pause[] = L" ██▓███   ▄▄▄       █    ██   ██████ ▓█████ ▓█████▄ \n"
                      "▓██░  ██▒▒████▄     ██  ▓██▒▒██    ▒ ▓█   ▀ ▒██▀ ██▌\n"
                      "▓██░ ██▓▒▒██  ▀█▄  ▓██  ▒██░░ ▓██▄   ▒███   ░██   █▌\n"
                      "▒██▄█▓▒ ▒░██▄▄▄▄██ ▓▓█  ░██░  ▒   ██▒▒▓█  ▄ ░▓█▄   ▌\n"
                      "▒██▒ ░  ░ ▓█   ▓██▒▒▒█████▓ ▒██████▒▒░▒████▒░▒████▓ \n"
                      "▒▓▒░ ░  ░ ▒▒   ▓▒█░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░░░ ▒░ ░ ▒▒▓  ▒ \n"
                      "░▒ ░       ▒   ▒▒ ░░░▒░ ░ ░ ░ ░▒  ░ ░ ░ ░  ░ ░ ▒  ▒ \n"
                      "░░         ░   ▒    ░░░ ░ ░ ░  ░  ░     ░    ░ ░  ░ \n"
                      "░  ░   ░           ░     ░  ░   ░                   \n";


    attron(TEXT_CYAN);
    render_text(pause, center_text(w, pause), 10);
    attroff(TEXT_CYAN);

    wchar_t directions[] = L"Press p to unpause";
    render_text(directions, center_text(w, directions), 25);

}
// Text generated with https://www.asciiart.eu and https://patorjk.com/software/taag/#p=display&f=Bloody
void inventory_screen(WINDOW *w, Player *p) {
    clear();
    wchar_t inventory[] = L" ██▓ ███▄    █ ██▒   █▓▓█████  ███▄    █ ▄▄▄█████▓ ▒█████   ██▀███ ▓██   ██▓\n"
		           "▓██▒ ██ ▀█   █▓██░   █▒▓█   ▀  ██ ▀█   █ ▓  ██▒ ▓▒▒██▒  ██▒▓██ ▒ ██▒▒██  ██▒\n"
		           "▒██▒▓██  ▀█ ██▒▓██  █▒░▒███   ▓██  ▀█ ██▒▒ ▓██░ ▒░▒██░  ██▒▓██ ░▄█ ▒ ▒██ ██░\n"
			   "░██░▓██▒  ▐▌██▒ ▒██ █░░▒▓█  ▄ ▓██▒  ▐▌██▒░ ▓██▓ ░ ▒██   ██░▒██▀▀█▄   ░ ▐██▓░\n"
			   "░██░▒██░   ▓██░  ▒▀█░  ░▒████▒▒██░   ▓██░  ▒██▒ ░ ░ ████▓▒░░██▓ ▒██▒ ░ ██▒▓░\n"
			   "░▓  ░ ▒░   ▒ ▒   ░ ▐░  ░░ ▒░ ░░ ▒░   ▒ ▒   ▒ ░░   ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░  ██▒▒▒ \n"
			   " ▒ ░░ ░░   ░ ▒░  ░ ░░   ░ ░  ░░ ░░   ░ ▒░    ░      ░ ▒ ▒░   ░▒ ░ ▒░▓██ ░▒░ \n"
			   " ▒ ░   ░   ░ ░     ░░     ░      ░   ░ ░   ░      ░ ░ ░ ▒    ░░   ░ ▒ ▒ ░░  \n"
			   " ░           ░      ░     ░  ░         ░              ░ ░     ░     ░ ░     \n";

    wchar_t small_sword[] = L"    |                     \n"
	                     "O===[====================-\n"
                             "    |                     \n"; 
    
    
    wchar_t big_sword[] = L"              />                                                           \n"
    			   "  ()         //---------------------------------------------------------(  \n"
    			   "(*)OXOXOXOXO(*>                                                          \\ \n"
    			   "  ()        \\\\-----------------------------------------------------------)\n"
			   "              \\>                                                           \n"; 
    
    
    wchar_t bow[] = L"    (      \n"
                     "     \\     \n"
                     "      )    \n"
                     "##-------->\n"
                     "      )    \n"
                     "     /     \n"
                     "    (      \n";
    


    wchar_t shield[] = L"|`-._/\\_.-`|\n"
  			"|    ||    |\n"
  			"|___o()o___|\n"
  			"|__((<>))__|\n"
  			"\\   o\\/o   /\n"
   			" \\   ||   / \n"
    			"  \\  ||  /  \n"
  			"   '.||.'   \n";
    wchar_t hourglass[] = L"+====+\n"
			   "|(::)|\n"
			   "| )( |\n"
			   "|(..)|\n"
			   "+====+\n";
    attron(TEXT_CYAN);
    render_text(inventory, center_text(w, inventory), 1);
    attroff(TEXT_CYAN);
    if (p->big_sword == 0) render_text(small_sword, center_text(w, small_sword), 10);
    else if (p->big_sword == 1)render_text(big_sword, center_text(w, big_sword), 10);
    if (p->bow == 1) render_text(bow, center_text(w,bow)+5, 14);
    if (p->shield == 1) render_text(shield,center_text(w,shield)-7 ,20 );
    if (p->hourglass == 1) render_text(hourglass, center_text(w,hourglass)+7, 25);

} 
