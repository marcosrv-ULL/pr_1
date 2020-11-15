#include "../include/nodo.h"
#include "../include/maze.h"

Nodo::Nodo(int i, int j, int t) {
    x = i;
    y = j;
    type = t;
    set_coste(t);
}

Nodo::Nodo(int t) {
    type = t;
    set_coste(t);
}

Nodo::Nodo() {
    type = PASSAGE;
    set_coste(PASSAGE);
}

void Nodo::set_coste(int t) {
    if (t == WALL || t == 99) {
        coste = std::numeric_limits<double>::infinity();
    } else {
        coste = 1;
    }
}

int Nodo::getType() const {
    return type;
}

int Nodo::get_x() const {
    return x;
}

int Nodo::get_y() const {
    return y;
}

double Nodo::getCoste() const {
    return coste;
}

void Nodo::set_coor(int i, int j) {
    x = i;
    y = j;
}

void Nodo::set_x(int i) {
    x = i;
}

void Nodo::set_y(int j) {
    y = j;
}

void Nodo::set_type(int t) {
    type = t;
}

bool Nodo::operator==(const Nodo& n) {
    return  n.get_x() == x &&
            n.get_y() == y ;
}

bool Nodo::operator !=(const Nodo& n) {
    return  n.get_x() != x ||
            n.get_y() != y;
}

std::ostream& operator<<(std::ostream& os, Nodo& n1) {
    switch (n1.getType()) {
        case PASSAGE:
            os << "·";
            break;
        case WALL:
            os << magenta << "█" << reset;
            break;
        case VISITED:
            os << "*";
            break;
        case EXIT:
            os << red << "X" << reset;
            break;
        case START:
            os << green << ">" << reset;
            break;
        case RUTA:
            os << yellow << "#" << reset;
            break;
        default:
            os << "?";
    }
    return os;
}