graph_final: main.o graph.o
		g++ -Wall -ansii main.o graph.o -o graph

main.o: lib/graph.h lib/vertex.h code/main.cpp 
		g++ -Wall -ansii -c code/main.cpp

graph.o: lib/vertex.h lib/graph.h code/graph.cpp
		g++ -Wall -ansi -c code/graph.cpp

.PHONY: clean

clean:
		rm -rf *.o
