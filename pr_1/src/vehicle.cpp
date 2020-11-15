#include "../include/vehicle.h"

Vehicle::Vehicle() {
    start = nullptr;
    goal = nullptr;
    reached = false;
    current_loc = nullptr;
    nodos_expandidos = 0;
}

Vehicle::Vehicle(Maze& m1, int heuristics) {
    m = m1;
    start = &m1.get_start();
    goal = &m1.get_exit();
    switch (heuristics) {
        case 1:
            astar.h = new hUsual();
            break;
        case 2:
            astar.h = new hManhanttan();
            break;
        case 3:
            astar.h = new hMaxima();
    }
    nodos_expandidos = 0;
    reached = false;
}

vector<Nodo*> Vehicle::showPath(map<Nodo*, Nodo*> cameFrom, Nodo* current) {
    vector<Nodo*> camino_final;
    Nodo* n_transition;
    while (cameFrom.find(current) != cameFrom.end()) {
        camino_final.push_back(current);
        n_transition = current;
        current->set_type(RUTA);
        current = cameFrom[current];
        cameFrom.erase(n_transition);
    }
    current->set_type(START);
    return camino_final;
}

bool Vehicle::Explore() {
     map<Nodo*, Nodo*> camino_final = astar.search(m, *start, *goal, reached, nodos_expandidos);
     if (reached) {
         ruta_v = showPath(camino_final, goal);
         goal->set_type(EXIT);
         return true;
     } else {
         return false;
     }
}

std::ostream& Vehicle::showRuta(std::ostream& os) {
    os << "EL RECORRIDO EN COORDENADAS ES: " << std::endl;
    
    for (size_t i = 0; i < ruta_v.size() - 1; i++)
    {
        os << " (" << ruta_v[i]->get_x() << ", " << ruta_v[i]->get_y() << ")" << "<--" << "(" << ruta_v[i + 1]->get_x() << ", " << ruta_v[i + 1]->get_y() << ") ";
    }
    os << std::endl;
    return os;
}