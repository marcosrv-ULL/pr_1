#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <utility>
#include <set>
#include "../src/colors.cpp"

using std::pair;
using std::set;

enum TYPE {
    PASSAGE, WALL, VISITED, EXIT, START, RUTA
};

enum DIRECTION {
    N, S, O, E
};

class Nodo {
    private:
        int type, x ,y;
        double coste;
    public:
        Nodo(int x, int y, int t);
        Nodo(int t);
        Nodo(); 
        
        set<Nodo*> neigbours;

        int get_x() const;
        int get_y() const;
        int getType() const;
        double getCoste() const;

        void set_coor(int, int);
        void set_y(int);
        void set_x(int);
        void set_type(int);
        void set_coste(int);

        bool operator == (const Nodo&);
        bool operator !=(const Nodo&);
        friend std::ostream& operator<<(std::ostream& os,  Nodo& n1);
};

#endif