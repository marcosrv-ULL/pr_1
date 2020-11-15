all: pr_1

clean:
	rm ../bin/*.o ../bin/pr_1_estrategias_busqueda
pr_1: nodo.o maze.o mazegenerator.o vehicle.o astar.o manhattan.o usual.o maxima.o main.o file.o random.o manual.o
	g++ --std=c++11 -g -o ../bin/pr_1_estrategias_busqueda ../bin/*.o
	rm ../bin/*.o
main.o: ../src/main.cpp 
	g++ --std=c++11 -c -g ../src/main.cpp -o ../bin/main.o
nodo.o: ../src/nodo.cpp 
	g++ --std=c++11 -c -g ../src/nodo.cpp -o ../bin/nodo.o
maze.o: ../src/maze.cpp
	g++ --std=c++11 -c -g ../src/maze.cpp -o ../bin/maze.o
mazegenerator.o: ../src/mazegenerator.cpp
	g++ --std=c++11 -c -g ../src/mazegenerator.cpp -o ../bin/mazegenerator.o
vehicle.o: ../src/vehicle.cpp
	g++ --std=c++11 -c -g ../src/vehicle.cpp -o ../bin/vehicle.o
astar.o: ../src/search_strat/astar.cpp
	g++ --std=c++11 -c -g ../src/search_strat/astar.cpp -o ../bin/astar.o
manhattan.o: ../src/heuristics/manhattan.cpp
	g++ --std=c++11 -c -g ../src/heuristics/manhattan.cpp -o ../bin/manhattan.o
usual.o: ../src/heuristics/usual.cpp
	g++ --std=c++11 -c -g ../src/heuristics/usual.cpp -o ../bin/usual.o
maxima.o: ../src/heuristics/maxima.cpp
	g++ --std=c++11 -c -g ../src/heuristics/maxima.cpp -o ../bin/maxima.o
file.o: ../src/generator/file.cpp
	g++ --std=c++11 -c -g ../src/generator/file.cpp -o ../bin/file.o
random.o: ../src/generator/random.cpp
	g++ --std=c++11 -c -g ../src/generator/random.cpp -o ../bin/random.o
manual.o: ../src/generator/manual.cpp
	g++ --std=c++11 -c -g ../src/generator/manual.cpp -o ../bin/manual.o