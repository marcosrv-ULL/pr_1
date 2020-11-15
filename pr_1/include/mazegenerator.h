#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include "maze.h"
#include <string>
#include <time.h>
#include <fstream>

using std::string;
using std::ifstream;

class MazeGenerator {
    public:
        static void experimental(Maze& m1, int r, int c, double density, std::ostream& os, bool obstaculos);
    protected:
        static void add_start(Maze& m1, int x, int y);
        static void add_end(Maze& m1, int x, int y);
        static void add_wall(Maze& m1, int x, int y);
        static void add_borders(Maze& m1);
};

#endif