#include "engine.hh"
#include "interface.hh"
#include "classes/map.hh"
#include "classes/hero.hh"

#include <ncurses.h>



void start_level() {
    Map map(20, 40);
    Hero hero;
    map.generate();
    print_all(map, hero);
    main_loop(map, hero);
    print_win();
}

void main_loop(const Map& map, Hero& hero) {
    while(!hero.on_exit(map)) {
        hero.move(map, getch());
        print_all(map, hero);
    }
}