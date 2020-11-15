#include <iostream>
#include <iomanip>
#include <chrono>
#include "../include/generator/random.h"
#include "../include/generator/file.h"
#include "../include/generator/manual.h"
#include "../include/vehicle.h"



using std::cout;
using std::cin;
using std::endl;

int maze_menu() {
    int x{};
    cout << std::setw(10) << "  [1]    Generacion Aleatoria" << endl;
    cout << std::setw(10) << "  [2]    Generacion Manual" << endl;
    cout << std::setw(10) << "  [3]    Generacion mediante fichero" << endl << endl;
    cout << std::setw(10) << "  [0]    Salir" << endl;
    
    cout << "  Elija una opcion: ";
    cin >> x;
    return x; 
}

int vehicle_menu() {
    int x{};
    cout << endl << std::setw(5) << red << " PERSONALIZACIÓN DEL VEHÍCULO" << reset << endl << endl;;
    cout << std::setw(10) << "  [1]    Usual / Euclidea" << endl;
    cout << std::setw(10) << "  [2]    Manhattan / Taxista" << endl;
    cout << std::setw(10) << "  [3]    Maxima" << endl << endl;
    cout << std::setw(10) << "  [0]    Salir" << endl;

    cout << "  Elija una función heuristica: ";
    cin >> x;
    return x; 

}

void maze_to_file(Maze& m1) {
    std::ofstream file("../resources/resultados.txt");
    for (int i = 0; i < m1.get_r(); i++) {
        for (int j = 0; j < m1.get_c(); j++) {
            file << m1(i, j);
        }
        file << endl;
    }
}

int main () {
    cout  << red  << std::setfill (' ') << std::setw(5) << " PRACTICA. ESTRATEGIAS DE BUSQUEDA" << reset << endl << endl;
    Maze m1;
    Vehicle* v1;
    switch (maze_menu()) {
        case 0: 
            cout << "bye!" << endl;
            return 0;
        break;
        case 1:
            float density;
            cout << std::setw(10) << "  Elija densidad de obstaculos [0, 0.99]: ";
            cin >> density;
            Random::generate(m1, density, cout, cin);
        break;
        case 2:
            Manual::generate(m1, cout, cin);
            break;
        case 3:
            File::generate(m1, cout, cin);
        break;
    }
    cout << yellow << "Generando laberinto... esto puede llevar unos segundos dependiendo de las dimensiones" << reset << endl;
    switch (vehicle_menu()) {
        case 0: 
            cout << "bye!" << endl;
            return 0;
        break;
        case 1:
            v1 = new Vehicle(m1, 1);
        break;
        case 2:
            v1 = new Vehicle(m1, 2);
            break;
        case 3:
            v1 = new Vehicle(m1, 3);;
        break; 
    }
    auto start = std::chrono::high_resolution_clock::now(); 
    if (v1->Explore()) {
        auto stop = std::chrono::high_resolution_clock::now();
        if (m1.get_c() + m1.get_r() > 5000) {
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            cout << green <<"Tiempo en encontrar el camino: "
                 << duration.count() / 1000 << " segundos" << endl;
            cout <<  green << "Pasando el laberinto para su visualizacion a un fichero... (resources/resultado.txt)" << endl;
            maze_to_file(m1);
        } else if (m1.get_c() + m1.get_r() > 400){
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            cout <<  green << "Tiempo en encontrar el camino: "
                 << duration.count() << " milisegundos" << endl;
            cout <<  green << "Pasando el laberinto para su visualizacion a un fichero... (resources/resultado.txt)" << endl;
            maze_to_file(m1); 
        } else {
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            cout << m1;
            cout <<  green << "Tiempo en encontrar el camino: "
                 << duration.count() << " microsegundos" << endl;
        }
        cout << green << "Nodos expandidos: " <<  v1->nodos_expandidos << endl;
        cout << green << "Longitud del camino minimo: " << v1->ruta_v.size() << endl;
        cout << reset;
    } else {
        auto stop = std::chrono::high_resolution_clock::now();
        
        if (m1.get_c() + m1.get_r() > 5000) {
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            cout << red <<  "Tiempo en Fallar: "
                 << duration.count() / 1000 << " segundos" << endl;
            cout << red << "Pasando el laberinto para su visualizacion a un fichero... (resources/resultado.txt)" << endl;
            maze_to_file(m1);
        } else if (m1.get_c() + m1.get_r() > 400){
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            cout << red << "Tiempo en Fallar: "
                 << duration.count() << " milisegundos" << endl;
            cout << red << "Pasando el laberinto para su visualizacion a un fichero... (resources/resultado.txt)" << endl;
            maze_to_file(m1); 
        } else {
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            cout << m1;
            cout  << red << "Tiempo en Fallar: "
                 << duration.count() << " microsegundos" << endl;
        }
        //cout << reset;
        cout << red << "Nodos expandidos: " <<  v1->nodos_expandidos << endl;
        cout << red << "Longitud del camino minimo: " << 0 << endl;
        cout << reset;
    } 
    cout << "END!" << endl;  
}



