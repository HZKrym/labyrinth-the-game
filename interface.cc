#include "interface.hh"
#include "classes/map.hh"
#include "classes/hero.hh"

#include <ncurses.h>



void init() {
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    noecho();
    start_color();
    use_default_colors();
    refresh();
}

void mvputch(int y, int x, const unsigned char ch) {
    mvprintw(y, x, "%c", ch);
}

void print_all(const Map& map, const Hero& hero) {
    clear();
    
    mvputch(hero.get_y(), hero.get_x(), '0');

    mvputch(hero.get_y() - 1, hero.get_x(), map.get_element(hero.get_y() - 1, hero.get_x()));
    mvputch(hero.get_y() + 1, hero.get_x(), map.get_element(hero.get_y() + 1, hero.get_x()));
    mvputch(hero.get_y(), hero.get_x() + 1, map.get_element(hero.get_y(), hero.get_x() + 1));
    mvputch(hero.get_y(), hero.get_x() - 1, map.get_element(hero.get_y(), hero.get_x() - 1));
    mvputch(hero.get_y() - 1, hero.get_x() - 1, map.get_element(hero.get_y() - 1, hero.get_x() - 1));
    mvputch(hero.get_y() + 1, hero.get_x() + 1, map.get_element(hero.get_y() + 1, hero.get_x() + 1));
    mvputch(hero.get_y() - 1, hero.get_x() + 1, map.get_element(hero.get_y() - 1, hero.get_x() + 1));
    mvputch(hero.get_y() + 1, hero.get_x() - 1, map.get_element(hero.get_y() + 1, hero.get_x() - 1));
    
    refresh();
}

void print_win() {
    clear();
    mvprintw(9, 16, "YOU WIN!");
    refresh();
    getch();
}