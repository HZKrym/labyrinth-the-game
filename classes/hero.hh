#pragma once

#include "map.hh"

/*
Hero class
*/
class Hero {
private:
    int _x;
    int _y;
public:
    Hero(int y = 1, int x = 0);
    //get hero's x-coordinate
    int get_x() const;
    //get hero's y-coordinate
    int get_y() const;
    //move hero on map. vect is pressed key
    void move(const Map& map, int vect);
    //checks: hero on exit or not
    bool on_exit(const Map& map) const;
};