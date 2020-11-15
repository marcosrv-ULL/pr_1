#include "../include/maze.h"

Maze::Maze (int rows, int columns) {
    initMaze(rows, columns);
}

Maze::Maze () {
    initMaze(0,0);
}

void Maze::set_start(int x, int y) {
    at(x, y).set_type(START);
    at(x, y).set_coste(START);
    start = std::make_pair(x, y);
}

void Maze::set_exit(int x, int y) {
    at(x, y).set_type(EXIT);
    at(x, y).set_coste(EXIT);
    exit = std::make_pair(x, y);
}

Nodo& Maze::get_start() {
    return at(start.first, start.second);
}

Nodo& Maze::get_exit() {
    return at(exit.first, exit.second);
}

void Maze::initMaze(int rows, int columns) {
    m = rows;
    n = columns;
    out_of_range.set_type(WALL);
    
    maze.resize(m, vector<Nodo>(n) );
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            maze[i][j].set_coor(i, j);
            at(i, j).neigbours.insert(&at(i + 1, j));
            at(i, j).neigbours.insert(&at(i - 1, j));
            at(i, j).neigbours.insert(&at(i, j + 1));
            at(i, j).neigbours.insert(&at(i, j - 1));
        }
    }
    
}

int Maze::get_r() {
    return m;
}

int Maze::get_c() {
    return n;
}

Nodo& Maze::at(int i, int j) {
    if ((i < 0) || (j < 0) || (j > n - 1) || (i > m - 1)){
        return out_of_range;
    } 
    return maze[i][j];
    
}

Nodo& Maze::operator()(int i, int j) {
    return at(i, j);
}

std::ostream& operator<<(std::ostream& os, Maze& m1) {
    for (int i = 0; i < m1.m; i++){
        for (int j = 0; j < m1.n; j++)
            os << m1(i, j);
        os << '\n';
    }
}