#ifndef USUAL_H
#define USUAL_H

#include "../heuristics.h"
#include <cmath>

class hUsual : public Heuristic_function { // a.k.a distancia euclidea
    public:
        double operator ()(Nodo* current, Nodo* end);
};

#endif 