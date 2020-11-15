#include "../../include/search_estrat/astar.h"


struct coste_map {
    double val = std::numeric_limits<double>::infinity();
};

Nodo* search_min(set<Nodo*> open, map<Nodo*, coste_map>& fScore) {
    double min = std::numeric_limits<double>::infinity();
    Nodo* current;
    for (auto f: open) {
        if (fScore[f].val < min) {
            
            min = fScore[f].val;
            current = f;
        }
    }
    return current;
}

 map<Nodo*, Nodo*> Astar::search(Maze& m1, Nodo& start, Nodo& exit, bool& reached, int& nodos_expandidos){
    set<Nodo*> Open;
    set<Nodo*> Closed;
    Nodo* current;
    Open.insert(&start);
    map<Nodo*, Nodo*> cameFrom;
    map<Nodo*, coste_map> gScore;
    gScore[&start].val = 0;
    map<Nodo*, coste_map> fScore;
    fScore[&start].val = (*h)(&start, &exit);
    while(!Open.empty()) {
        current = search_min(Open, fScore);
        if (*current == exit) {
            reached = true;
            return cameFrom;
        }
        Open.erase(current);
        Closed.insert(current);
        for (auto f: current->neigbours) {
            if (Closed.find(f) != Closed.end()) continue;
            double tentativeScore = gScore[current].val + f->getCoste() ;
            if (tentativeScore < gScore[f].val && tentativeScore != std::numeric_limits<double>::infinity()) {
                cameFrom[f] = current;
                gScore[f].val = tentativeScore;
                fScore[f].val = (*h)(f, &exit);
                if (Open.find(f) == Open.end()){
                    nodos_expandidos++;
                    f->set_type(VISITED);
                    Open.insert(f);
                } 
            }
        }
    }
 }