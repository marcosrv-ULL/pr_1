#include "../../include/heuristics/manhattan.h"

double hManhanttan::operator()(Nodo* current, Nodo* goal) {
    return abs(current->get_x() - goal->get_x()) + abs(current->get_y() - goal->get_y());
}

