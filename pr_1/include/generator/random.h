#ifndef RANDOM_H
#define RANDOM_H

#include "../mazegenerator.h"

using std::string;
using std::ifstream;

class Random : public MazeGenerator {
    public:
        static void generate(Maze& m1, double density, std::ostream& os, std::istream& in);
};

#endif