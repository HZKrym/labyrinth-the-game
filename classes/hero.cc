#include "hero.hh"
#include "map.hh"

#include <ncurses.h>



Hero::Hero(int y, int x) {
    _y = y;
    _x = x;
}

int Hero::get_x() const {
    return _x;
}

int Hero::get_y() const {
    return _y;
}

void Hero::move(const Map& map, int vect) {
    switch (vect) {
        case KEY_UP:
            if (map.get_element(_y - 1, _x) != '$')
                --_y;
        break;
        case KEY_DOWN:
            if (map.get_element(_y + 1, _x) != '$')
                ++_y;
        break;
        case KEY_LEFT:
            if (map.get_element(_y, _x - 1) != '$' && _x != 0)
                --_x;
        break;
        case KEY_RIGHT:
            if (map.get_element(_y, _x + 1) != '$')
                ++_x;
        break;
    }
}

bool Hero::on_exit(const Map& map) const {
    return map.is_exit(_y, _x);
}