#ifndef ASTAR_H
#define ASTAR_H

#include "../heuristics.h"
#include "../maze.h"
#include <map>

using std::map;

class Astar {  
    public:
        Heuristic_function* h;
        map<Nodo*, Nodo*> search(Maze& m1, Nodo& start, Nodo& exit, bool& reached, int& nodos_expandidos);
};

#endif