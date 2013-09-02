#include "../lib/graph.h"
#include "../lib/vertex.h"
#include <iostream>


int main()
{
Graph g1("plik.txt");
g1.print();


//test1:
g1.add_v(Vertex(9));
g1.add_v(2);

//test2:
g1.add_e(Vertex(1),Vertex(8));
g1.add_e(Vertex(1),Vertex(2));
g1.add_e(Vertex(3),Vertex(4));
g1.add_e(Vertex(3),Vertex(6));
g1.add_e(Vertex(4),Vertex(5));
g1.add_e(Vertex(4),Vertex(8));
g1.add_e(Vertex(4),Vertex(9));
g1.add_e(Vertex(6),Vertex(5));
g1.add_e(Vertex(7),Vertex(2));
g1.add_e(Vertex(2),Vertex(9));

g1.print();
std::cout<<"\n\n";

//test3:
g1.del_e(Vertex(4),Vertex(8));
g1.del_e(Vertex(1),Vertex(9));
g1.print();
std::cout<<"\n\n";

//test4:
//g1.del_v(Vertex(2));
//g1.print();
//std::cout<<"\n\n";

}
