#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <utility>
#include "nodo.h"
#include <limits>

using std::vector;
using std::pair; 

class Maze {
    private:
        int m, n; // Fila, columnas
        vector<vector<Nodo>> maze;
        pair<int,int> start, exit;
        Nodo out_of_range;
    public: 
        Maze (int rows, int columns);
        Maze ();

        int get_r();
        int get_c();

        void set_start(int x, int y);
        void set_exit(int x, int y);
        Nodo& get_start();
        Nodo& get_exit();

        void initMaze(int rows, int columns);
        friend std::ostream& operator<<(std::ostream& os, Maze& m1);
        Nodo& at(int i, int j); 
        Nodo& operator()(int i, int j);
};

#endif