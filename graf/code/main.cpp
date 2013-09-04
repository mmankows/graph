#include "../lib/graph.h"
#include "../lib/vertex.h"
#include <iostream>


int main()
{
Graph g1("data/plik.txt");
g1.print();
g1.contract(Vertex(4),Vertex(8));
//Graph g2("data/kargerMinCut.txt");
//g2.print();
std::cout<<"\n\n";

g1.print();

return 0;
}
