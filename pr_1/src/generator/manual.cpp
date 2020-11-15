#include "../../include/generator/manual.h"

void Manual::generate(Maze& m1, std::ostream& os, std::istream& in) {
    int r, c, entrada_x, entrada_y, salida_x, salida_y, no_obstaculos, coor_y, coor_x;
    char hasBorders;
    os << "Numero de filas: ";
    in >> r;
    os << "Numero de columnas: ";
    in >> c;
    m1.initMaze(r, c);
    os << "¿Quiere que el recorrido tenga bordes? [Y]es | [N]o: ";
    in >> hasBorders;
    if (hasBorders == 'Y' || hasBorders == 'y') add_borders(m1);
    os << "¿Donde quiere que este el comienzo?" << '\n';
    os << "x: ";
    in >> entrada_x;
    os << "y: ";
    in >> entrada_y;
    add_start(m1, entrada_x, entrada_y);
    os << "¿Donde quiere la salida?" << std::endl;
    os << "x: ";
    in >> salida_x;
    os << "y: ";
    in >> salida_y;
    add_end(m1, salida_x, salida_y);
    os << "¿Cuantos obstaculos quiere poner?: ";
    in >> no_obstaculos;
    for (int i = 0; i < no_obstaculos; i++) {
        os << "x" << i << ": ";
        in >> coor_x;
        os << "y" << i << ": ";
        in >> coor_y;
        add_wall(m1, coor_x, coor_y);
    }
}