#ifndef VEHICLE_H
#define VEHICLE_H

#include <set>
#include "maze.h"
#include "search_estrat/astar.h"
#include "heuristics/manhattan.h"
#include "heuristics/usual.h"
#include "heuristics/maxima.h"

using std::set;

class Vehicle {  
    private:
      Nodo* current_loc, *start, *goal;
      Maze m;
      set<Nodo*> s_percepcion;
      Astar astar;
      bool reached; 

    public:
      Vehicle();
      Vehicle(Maze& m1, int heuristics);
      int nodos_expandidos;
      vector<Nodo*> ruta_v;
      
      bool Explore();

      vector<Nodo*> showPath(map<Nodo*, Nodo*> cameFrom, Nodo* end);
      std::ostream& showRuta(std::ostream& os);
};

#endif