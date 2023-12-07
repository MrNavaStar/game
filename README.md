Group: 2
Members: Neshko, Ethan

# Cryptic Conquest
A simple terminal game written in c using the ncurses library.

# Game Plan
The Goal of the game is to explore the dungeon and defeat all the enemies.
In order to do so, you will need to collect all 4 items (bow,shield,hourglass, and a big sword).
These weapons can be found inside Chests throughout the dungeon. However, the
dungeon is guarded by enemies, so you will have to evade them in order to
loot the chests. Once you have all the items, you will be able 
defeat all the enemies and win! The levels will be viewed from the top down and will
be made up of fancy ascii characters.

# Playing the game
To play this project, simply run:
```bash
git clone https://github.com/MrNavaStar/game.git
make
./game
```

# How To Win
- Start by moving around (Using the WASD Keys) the map collecting items from the chests (They are the C's on the map) Run into the chest to open it
- Make sure to avoid the bad guys (They are the E's on the map). If they touch you, you will lose.
- You can move between levels by running into the numbers on the map (Often at the end of a corridor). Be careful when going into level 3. If you don't have all the items, the enemies might block you way out, and you'll be stuck!
- You can check your inventory by pressing "i". Once you have collected all 4 items, you will be able to kill the bad guys. Kill them by running into them. It helps to try and corner them if you can.
- Once you kill all the bad guys on all three levels, you win!
- The game takes roughly 5 - 10 min to complete. If you want to end the game sooner for testing purposes, modify the if check at the bottom of `src/code/main.c` from `if (p.kills >= 58) victory_screen(w);` to something like `if (p.kills >= 5) victory_screen(w);`. This will let you win by killing only 5 enemies.