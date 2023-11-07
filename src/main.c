#include <curses.h>
#include <locale.h>

void drawSplashScreen(WINDOW *w) {
    char cryptic[] = "\n\n            ▄████▄   ██▀███ ▓██   ██▓ ██▓███  ▄▄▄█████▓ ██▓ ▄████▄  \n"
                         "           ▒██▀ ▀█  ▓██ ▒ ██▒▒██  ██▒▓██░  ██▒▓  ██▒ ▓▒▓██▒▒██▀ ▀█  \n"
                         "           ▒▓█    ▄ ▓██ ░▄█ ▒ ▒██ ██░▓██░ ██▓▒▒ ▓██░ ▒░▒██▒▒▓█    ▄ \n"
                         "           ▒▓▓▄ ▄██▒▒██▀▀█▄   ░ ▐██▓░▒██▄█▓▒ ▒░ ▓██▓ ░ ░██░▒▓▓▄ ▄██▒\n"
                         "           ▒ ▓███▀ ░░██▓ ▒██▒ ░ ██▒▓░▒██▒ ░  ░  ▒██▒ ░ ░██░▒ ▓███▀ ░\n"
                         "           ░ ░▒ ▒  ░░ ▒▓ ░▒▓░  ██▒▒▒ ▒▓▒░ ░  ░  ▒ ░░   ░▓  ░ ░▒ ▒  ░\n"
                         "             ░  ▒     ░▒ ░ ▒░▓██ ░▒░ ░▒ ░         ░     ▒ ░  ░  ▒   \n"
                         "           ░          ░░   ░ ▒ ▒ ░░  ░░         ░       ▒ ░░        \n"
                         "           ░ ░         ░     ░ ░                        ░  ░ ░      \n"
                         "           ░                 ░ ░                           ░        \n";
                     
    char conquest[] = "\n     ▄████▄   ▒█████   ███▄    █   █████   █    ██ ▓█████   ██████ ▄▄▄█████▓\n"
                        "    ▒██▀ ▀█  ▒██▒  ██▒ ██ ▀█   █ ▒██▓  ██▒ ██  ▓██▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒\n"
                        "    ▒▓█    ▄ ▒██░  ██▒▓██  ▀█ ██▒▒██▒  ██░▓██  ▒██░▒███   ░ ▓██▄   ▒ ▓██░ ▒░\n"
                        "    ▒▓▓▄ ▄██▒▒██   ██░▓██▒  ▐▌██▒░██  █▀ ░▓▓█  ░██░▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ \n"
                        "    ▒ ▓███▀ ░░ ████▓▒░▒██░   ▓██░░▒███▒█▄ ▒▒█████▓ ░▒████▒▒██████▒▒  ▒██▒ ░ \n"
                        "    ░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ░░ ▒▒░ ▒ ░▒▓▒ ▒ ▒ ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   \n"
                        "      ░  ▒     ░ ▒ ▒░ ░ ░░   ░ ▒░ ░ ▒░  ░ ░░▒░ ░ ░  ░ ░  ░░ ░▒  ░ ░    ░    \n"
                        "    ░        ░ ░ ░ ▒     ░   ░ ░    ░   ░  ░░░ ░ ░    ░   ░  ░  ░    ░      \n"
                        "    ░ ░          ░ ░           ░     ░       ░        ░  ░      ░           \n"
                        "    ░                                                                       \n";
                      
    attron(COLOR_PAIR(1));
    printw("%s", cryptic);
    printw("%s", conquest);
    wrefresh(w);
    attroff(COLOR_PAIR(1));
    move(25, 27);
    printw("Press Any Key To Continue");
    wrefresh(w);
}

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

    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Define a color pair with cyan text on a black background

    drawSplashScreen(w);

    // Wait for key press
    getch();
    
    endwin();
    return 0;
}
