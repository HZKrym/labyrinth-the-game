#include "interface.hh"
#include "engine.hh"

#include <ncurses.h>



int main() {
    init();
    start_level();
    endwin();
    return 1;
}