#include <wchar.h>

typedef struct Player {
    int x;
    int y;
    wchar_t ch;
    int level;
} Player;

// translates the player from its current position & can be used to change the players current level if the passed
// in level does not match p.level
void move_player(Player *p, wchar_t levels[][30][81], int level, int x, int y);

// Must be called every game loop to process keyboard inputs for the player
void handle_user_input(Player *p, wchar_t levels[][30][81], char input);