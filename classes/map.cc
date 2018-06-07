#include "map.hh"

#include <ctime>
#include <cstdlib>
#include <cmath>



double length(int y1, int x1, int y2, int x2) {
    return sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
}

Map::Map(const int height, const int width) {
    _height = height;
    _width = width;
    _start_x = 0;
    _start_y = 1;
    _exit_x = _width - 1;
    _exit_y = rand() % (_height - 2) + 1;
    _arr = new char* [_height];
    for (int i = 0; i < _height; ++i)
        _arr[i] = new char [_width];
    srand(unsigned(time(NULL)));
}

Map::~Map() {
    for (int i = 0; i < _height; ++i)
        delete [] _arr[i];
}

void Map::generate() {
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
            _arr[i][j] = '$';
    _arr[_start_y][_start_x] = ' ';
    
    _generate_exit();
    
    //generate random path
    for (int i = 0; i < 100; ++i) {
        int y{rand() % (_height - 2) + 1};
        int x{rand() % (_width - 2) + 1};
        //generate coordinates until they are on the path
        while( _arr[y][x] != ' ' ) {
            x = rand() % (_width - 2) + 1;
            y = rand() % (_height - 2) + 1;
        }
        int _y{rand() % (_height - 2) + 1};
        int _x{rand() % (_width - 2) + 1};
        //generate coordinates until they are not 1st coordinates
        while (length(_y, _x, y, x) > 10 || _y == y || _x == x) {
            _y = rand() % (_height - 2) + 1;
            _x = rand() % (_width - 2) + 1;
        }
        _generate_path(y, x, _y, _x);
    }
    
    _arr[_exit_y][_exit_x] = '?';
}

char Map::get_element(const int y, const int x) const {
    char ch;
    if (x < 0) ch = '$'; //crutch :)
    else ch = _arr[y][x];
    return ch;
}

char* Map::get_line(const int y) const {
    return _arr[y];
}

int Map::get_height() const {
    return _height;
}

int Map::get_width() const {
    return _width;
}

void Map::set_element(const int y, const int x, const char value) {
    _arr[y][x] = value;
}

void Map::_generate_path(int y1, int x1, int y2, int x2, bool exit) {
    if (exit) {
        int x{x1};
        int y{y1};
        int dx = x2 > x1 ? 1 : -1;
        int dy = y2 > y1 ? 1 : -1;
        while (x != x2) {
            x += dx;
            _arr[y][x] = ' ';
        };
        while (y != y2) {
            y += dy;
            _arr[y][x] = ' ';
        }
    } else {
        int x{x1};
        int y{y1};
        int dx = x2 > x1 ? 1 : -1;
        int dy = y2 > y1 ? 1 : -1;
        while (x != x2) {
            x += dx;
            //so that the width of the path is 1
            if (_arr[y + 1][x] == '$' && _arr[y - 1][x] == '$' && _arr[y][x] != ' ')
            _arr[y][x] = ' ';
            else
            break;
        };
        while (y != y2) {
            y += dy;
            //so that the width of the path is 1
            if (_arr[y][x + 1] == '$' && _arr[y][x - 1] == '$' && _arr[y][x] != ' ')
            _arr[y][x] = ' ';
            else
            break;
        }
    }
}

void Map::_generate_exit() {
    int y{_exit_y};
    int x{_exit_x};

    //ganarete more little path ^-^
    for (int i = 0; i < 20; ++i) {
        int _y{rand() % (_height - 2) + 1};
        int _x{rand() % (_width - 2) + 1};
        while (length(_y, _x, y, x) > 6 || _y == y || _x == x) {
            _y = rand() % (_height - 2) + 1;
            _x = rand() % (_width - 2) + 1;
        }
        _generate_path(y, x, _y, _x, true);
        y = _y;
        x = _x;
    }
    _generate_path(_start_y, _start_x, y, x, true);
}

bool Map::is_exit(const int y, const int x) const {
    return y == _exit_y && x == _exit_x;
}