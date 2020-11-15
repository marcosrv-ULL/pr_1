#include "../../include/heuristics/maxima.h"

double hMaxima::operator()(Nodo* current, Nodo* goal) {
    return (current->get_x() - goal->get_x() < current->get_y() - current->get_y())? current->get_y() - current->get_y() : current->get_x();
}

