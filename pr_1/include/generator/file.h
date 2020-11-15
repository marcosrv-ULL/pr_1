#ifndef FILE_H
#define FILE_H

#include "../mazegenerator.h"

using std::string;
using std::ifstream;

class File : public MazeGenerator {
    public:
        static void generate(Maze& m1, std::ostream& os, std::istream& in);
};

#endif