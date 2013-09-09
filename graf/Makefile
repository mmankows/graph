graph_final: main.o fun.o graph.o d_graph.o
		g++ -Wall -ansii graph.o d_graph.o main.o fun.o -o graph

main.o: lib/graph.h lib/vertex.h code/main.cpp 
		g++ -Wall -ansii -c code/main.cpp

graph.o: lib/vertex.h lib/graph.h code/graph.cpp
		g++ -Wall -ansi -c code/graph.cpp

d_graph.o: lib/vertex.h lib/graph.h lib/d_graph.h code/d_graph.cpp
		g++ -Wall -ansi -c code/d_graph.cpp

fun.o: lib/fun.h code/fun.cpp
		g++ -Wall -ansi -c code/fun.cpp

.PHONY: clean

clean:
		rm -rf *.o
