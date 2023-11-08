#include <curses.h>
#include <string.h>

// Render single or multiline text at the given coords
void renderText(char *text, int x, int y) {
    char *line;
    line = strtok(text, "\n");
    int yOffset = 0;

    while(line != NULL) {
        move(y + yOffset, x);
        printw("%s", line);

        line = strtok(NULL, "\n");
        yOffset++;
    }
}

// Get the screen width of a single line or block of text
int getWidth(char *text) {
    int len = strcspn(text, "\n");
    return len / 3;
}

// Returns the x position that will result in the given text block being centered on the screen
int centerText(WINDOW *w, char *text) {
    return (getmaxx(w) / 2) - (getWidth(text) / 2);
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void splashScreen(WINDOW *w) {
    clear();
    char cryptic[] = " ▄████▄   ██▀███ ▓██   ██▓ ██▓███  ▄▄▄█████▓ ██▓ ▄████▄  \n"
                     "▒██▀ ▀█  ▓██ ▒ ██▒▒██  ██▒▓██░  ██▒▓  ██▒ ▓▒▓██▒▒██▀ ▀█  \n"
                     "▒▓█    ▄ ▓██ ░▄█ ▒ ▒██ ██░▓██░ ██▓▒▒ ▓██░ ▒░▒██▒▒▓█    ▄ \n"
                     "▒▓▓▄ ▄██▒▒██▀▀█▄   ░ ▐██▓░▒██▄█▓▒ ▒░ ▓██▓ ░ ░██░▒▓▓▄ ▄██▒\n"
                     "▒ ▓███▀ ░░██▓ ▒██▒ ░ ██▒▓░▒██▒ ░  ░  ▒██▒ ░ ░██░▒ ▓███▀ ░\n"
                     "░ ░▒ ▒  ░░ ▒▓ ░▒▓░  ██▒▒▒ ▒▓▒░ ░  ░  ▒ ░░   ░▓  ░ ░▒ ▒  ░\n"
                     "  ░  ▒     ░▒ ░ ▒░▓██ ░▒░ ░▒ ░         ░     ▒ ░  ░  ▒   \n"
                     "░          ░░   ░ ▒ ▒ ░░  ░░         ░       ▒ ░░        \n"
                     "░ ░         ░     ░ ░                        ░  ░ ░      \n"
                     "░                 ░ ░                           ░        ";

    char conquest[] = " ▄████▄   ▒█████   ███▄    █   █████   █    ██ ▓█████   ██████ ▄▄▄█████▓\n"
                      "▒██▀ ▀█  ▒██▒  ██▒ ██ ▀█   █ ▒██▓  ██▒ ██  ▓██▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒\n"
                      "▒▓█    ▄ ▒██░  ██▒▓██  ▀█ ██▒▒██▒  ██░▓██  ▒██░▒███   ░ ▓██▄   ▒ ▓██░ ▒░\n"
                      "▒▓▓▄ ▄██▒▒██   ██░▓██▒  ▐▌██▒░██  █▀ ░▓▓█  ░██░▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ \n"
                      "▒ ▓███▀ ░░ ████▓▒░▒██░   ▓██░░▒███▒█▄ ▒▒█████▓ ░▒████▒▒██████▒▒  ▒██▒ ░ \n"
                      "░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ░░ ▒▒░ ▒ ░▒▓▒ ▒ ▒ ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   \n"
                      "  ░  ▒     ░ ▒ ▒░ ░ ░░   ░ ▒░ ░ ▒░  ░ ░░▒░ ░ ░  ░ ░  ░░ ░▒  ░ ░    ░    \n"
                      "░        ░ ░ ░ ▒     ░   ░ ░    ░   ░  ░░░ ░ ░    ░   ░  ░  ░    ░      \n"
                      "░ ░          ░ ░           ░     ░       ░        ░  ░      ░           \n"
                      "░                                                                       ";

    attron(COLOR_PAIR(1));
    printw("%d", getWidth(cryptic));
    //renderText(cryptic, centerText(w, cryptic), 2);
    //renderText(conquest, centerText(w, conquest), 12);
    attroff(COLOR_PAIR(1));

    char press[] = "Press Any Key To Continue";
    //renderText(press, centerText(w, press), 27);

    //Wait for key press
    getch();
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void gameOverScreen(WINDOW *w) {
    clear();
    char game[] = "  ▄████  ▄▄▄       ███▄ ▄███▓▓█████ \n"
                  " ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀ \n"
                  "▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███   \n"
                  "░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄ \n"
                  "░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒\n"
                  " ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░\n"
                  "  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░\n"
                  "░ ░   ░   ░   ▒   ░      ░      ░   \n"
                  "      ░       ░  ░       ░      ░  ░\n"
                  "                                    ";

    char over[] = " ▒█████   ██▒   █▓▓█████  ██▀███  \n"
                  "▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n"
                  "▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n"
                  "▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n"
                  "░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒\n"
                  "░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n"
                  "  ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n"
                  "░ ░ ░ ▒       ░░     ░     ░░   ░ \n"
                  "    ░ ░        ░     ░  ░   ░     \n"
                  "              ░                   ";

    attron(COLOR_PAIR(2));
    renderText(game, 2, 2);
    renderText(over, 2, 12);
    attroff(COLOR_PAIR(2));
    // Wait for key press
    getch();
}