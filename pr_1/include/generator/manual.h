#ifndef MANUAL_H
#define MANUAL_H

#include "../mazegenerator.h"

using std::string;
using std::ifstream;

class Manual : public MazeGenerator {
    public:
        static void generate(Maze& m1, std::ostream& os, std::istream& in);
};

#endif