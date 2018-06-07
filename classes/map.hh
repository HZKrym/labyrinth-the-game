#pragma once
/*
Labyrinth map class
*/
class Map {
private:
    char **_arr;
    int _height;
    int _width;
    int _start_y;
    int _start_x;
    int _exit_y;
    int _exit_x;
    //generate path from (x1, y1) to (x2, y2)
    void _generate_path(int y1, int x1, int y2, int x2, bool exit = false);
    //generate path from (_start_x, _start_y) to (_exit_x, _exit_y)
    void _generate_exit();
public:
    Map(const int height = 10, const int width = 10);
    ~Map();
    //generate a labyrinth map
    void generate();
    //get element of _arr on coordinates
    char get_element(const int y, const int x) const;
    //get line of _arr on rows
    char* get_line(const int y) const;
    //get map height
    int get_height() const;
    //get map width
    int get_width() const;
    //set element on coordinates
    void set_element(const int y, const int x, char value);
    //checks: exit or not
    bool is_exit(const int y, const int x) const;
};