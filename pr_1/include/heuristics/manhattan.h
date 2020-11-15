#ifndef MANHANTTAN_H
#define MANHANTTAN_H

#include "../heuristics.h"

class hManhanttan : public Heuristic_function {
    public:
        double operator ()(Nodo* current, Nodo* end);
};

#endif 