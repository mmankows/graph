#include "../lib/graph.h"
#include "../lib/vertex.h"
#include <iostream>


int main()
{
Graph g1("data/plik.txt");
g1.print();
Graph g2("data/kargerMinCut.txt");
g2.print();

return 0;
}
