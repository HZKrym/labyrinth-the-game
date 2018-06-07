#pragma once
#include "classes/map.hh"
#include "classes/hero.hh"

void init();
void mvputch(int y, int x, const unsigned char ch);
void print_all(const Map& map, const Hero& hero);
void print_win();