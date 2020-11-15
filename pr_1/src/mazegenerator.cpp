#include "../include/mazegenerator.h"

void MazeGenerator::add_borders(Maze& m1) {
    for (int i = 0; i < m1.get_c(); i++) {
        m1(0, i).set_type(WALL);
        m1(0, i).set_coste(WALL);
        m1(m1.get_r() - 1, i).set_type(WALL);
        m1(m1.get_r() - 1, i).set_coste(WALL);
    }

    for (int i = 0; i < m1.get_r(); i++) {
        m1(i, 0).set_type(WALL);
        m1(i, 0).set_coste(WALL);
        m1(i, m1.get_c() - 1).set_type(WALL);
        m1(i, m1.get_c() - 1).set_coste(WALL);
    }
}

void MazeGenerator::add_start(Maze& m1, int x, int y) {
    m1.set_start(x, y);
}

void MazeGenerator::add_end(Maze& m1, int x, int y) {
    m1.set_exit(x, y);
}

void MazeGenerator::add_wall(Maze& m1, int x, int y) {
    m1(x, y) = WALL;
}