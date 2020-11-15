#include "../../include/heuristics/usual.h"

double hUsual::operator()(Nodo* current, Nodo* goal) {
    return sqrt(pow(current->get_x() - goal->get_x(), 2) + pow(current->get_y() - goal->get_y(), 2) );
}
