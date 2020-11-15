#include "../../include/generator/random.h"

void Random::generate(Maze& m1, double density, std::ostream& os, std::istream& in) {
    int r, c, entrada_x, entrada_y, salida_x, salida_y;
    char hasBorders, entrada_salida_random;
    os << "Numero de filas: ";
    in >> r;
    os << "Numero de columnas: ";
    in >> c;
    m1.initMaze(r, c);
    srand(time(NULL));
    int randx, randy;
    for (int i = 0; i < (m1.get_c() * m1.get_r()) * density; i++) {
        randx = rand() % m1.get_r();
        randy = rand() % m1.get_c();
        m1(randx, randy).set_type(WALL);
        m1(randx, randy).set_coste(WALL);
    }
    os << "¿Quiere que el recorrido tenga bordes completos? [Y]es | [N]o: ";
    in >> hasBorders;
    if (hasBorders == 'Y' || hasBorders == 'y') add_borders(m1);
    os << "¿Quiere que la salida y la entrada sean aleatorios? [Y]es | [N]o: ";
    in >> entrada_salida_random;
    if (entrada_salida_random == 'N' || entrada_salida_random == 'n') {
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
    } else {
        int exit_x = rand() % m1.get_r();
        int exit_y = rand() % m1.get_c();
        m1.set_exit(exit_x, exit_y);
        int start_x = rand() % m1.get_r();
        int start_y = rand() % m1.get_c();
        m1.set_start(start_x, start_y);
    }

    
    
}