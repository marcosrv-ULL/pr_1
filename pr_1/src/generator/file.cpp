#include "../../include/generator/file.h"

int Maze_node_parser (char node) {
    switch (node) {
        case '+':
            return WALL;
            break;
        case 'X':
            return EXIT;
            break;
        case ' ': 
            return PASSAGE;
            break;
        case '>':
            return START;
            break;
        case '*':
            return VISITED;
        default:
            return 99;
    }
}

void File::generate(Maze& m1, std::ostream& os, std::istream& in) {
    int r, c;
    string filename, line;
    os << "Escriba la direccion del fichero: ";
    in >> filename;
    ifstream myMaze;
    myMaze.open(filename);
    myMaze >> r;
    myMaze >> c;
    os << r << ", " << c << '\n';
    m1.initMaze(r, c);
    r = 0;
    std::getline(myMaze, line);
    while(std::getline(myMaze, line)){
        c = 0; 
        for (const char ch : line){
            if (c < (m1.get_c()) && r < (m1.get_r())) {
                m1(r, c).set_type(Maze_node_parser(ch));
                if (m1(r,c).getType() == EXIT) add_end(m1, r, c);
                if (m1(r,c).getType() == START) add_start(m1, r, c);
                m1(r, c).set_coor(r, c);
                m1(r, c).set_coste(Maze_node_parser(ch));
                c++;
            }
        }
        r++;
    } 
}