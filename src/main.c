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
    setlocale(LC_ALL, "");
    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(0);
    w = newwin(30, 80, 0, 0);
    refresh();

    init_pair(1, COLOR_RED, COLOR_BLACK); // Define a color pair with red text on a black background

    drawSplashScreen(w);

    int ch = getch();
    
    endwin();
    return 0;
}
