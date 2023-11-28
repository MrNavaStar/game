#include <wchar.h>
#include "../headers/player.h"

void move_player(Player *p, wchar_t levels[][30][81], int level, int x, int y) {
    // Clear current pos
    levels[p->level - 1][p->y][p->x] = L' ';
    // Update pos & level
    p->y = p->y + y;
    p->x = p->x + x;
    p->level = level;
    // Move char to new pos
    levels[p->level - 1][p->y][p->x] = p->ch;
}

void handle_user_input(Player *p, wchar_t levels[][30][81], char input) {
    // move character up
    if (input == 'w' && levels[p->level - 1][p->y-1][p->x] == L' ')
        move_player(p, levels, p->level, 0, -1);

    // move character down
    else if (input == 's' && levels[p->level - 1][p->y+1][p->x] == L' ')
        move_player(p, levels, p->level, 0, 1);

    // move character left
    else if (input == 'a') {
        wchar_t next = levels[p->level - 1][p->y][p->x-1];
        // normal translation
        if (next == L' ') move_player(p, levels, p->level, -1, 0);
            // Move player to next level
        else if (next == L'2') move_player(p, levels, 2, 74, 0);
        else if (next == L'1') move_player(p, levels, 1, 73, 0);
    }

    // move character right
    else if (input == 'd') {
        wchar_t next = levels[p->level - 1][p->y][p->x+1];
        // normal translation
        if (next == L' ') move_player(p, levels, p->level, 1, 0);
            // Move player to next level
        else if (next == L'3') move_player(p, levels, 3, -73, 0);
        else if (next == L'1') move_player(p, levels, 1, -74, 0);
    }
}
