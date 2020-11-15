#ifndef MAXIMA_H
#define MAXIMA_H

#include "../heuristics.h"

class hMaxima : public Heuristic_function {
    public:
        double operator ()(Nodo* current, Nodo* end);
};

#endif 