#include <iostream>
#include <ncurses.h>

int main() {

    initscr();
    printw("Try resizing your window(if possible) and then run this program again");
    refresh();
    getch();
    endwin();
    return 0;
}