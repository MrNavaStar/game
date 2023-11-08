#include <curses.h>
#include <string.h>
#include <wchar.h>

// This class uses the cursed wchar_t in order to support extended ascii. If you have to modify to this file I'm sorry.
// But only a little because the ascii art is cool.

#define TEXT_GREEN COLOR_PAIR(1)
#define TEXT_RED COLOR_PAIR(2)

void initColors() {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
}

// Render single or multiline text at the given coords
void renderText(wchar_t *text, int x, int y) {
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
int getWidth(wchar_t *text) {
    int len = 0;
    while(text[len] != '\n' && text[len] != '\0') len++;
    return len;
}

// Returns the x position that will result in the given text block being centered on the screen
int centerText(WINDOW *w, wchar_t *text) {
    return (getmaxx(w) / 2) - (getWidth(text) / 2);
}

void renderContinuePrompt(WINDOW *w) {
    wchar_t press[] = L"Press Any Key To Continue";
    renderText(press, centerText(w, press), 25);
    //Wait for key press
    getch();
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void splashScreen(WINDOW *w) {
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
    renderText(cryptic, centerText(w, cryptic), 2);
    renderText(conquest, centerText(w, conquest), 13);
    attroff(TEXT_GREEN);
    renderContinuePrompt(w);
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void gameOverScreen(WINDOW *w) {
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
    renderText(game, centerText(w, game), 2);
    renderText(over, centerText(w, over), 13);
    attroff(TEXT_RED);
    renderContinuePrompt(w);
}

// Text generated with https://patorjk.com/software/taag/#p=display&f=Bloody
void victoryScreen(WINDOW *w) {
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
    renderText(victory, centerText(w, victory), 10);
    attroff(TEXT_GREEN);
    renderContinuePrompt(w);
}