#ifndef HEURISTICS_H
#define HEURISTICS_H

#include "nodo.h"

class Heuristic_function {
    public:
        virtual double operator()(Nodo* current, Nodo* end) = 0;
};

#endif