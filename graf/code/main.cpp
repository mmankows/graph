#include "../lib/fun.h"

#include <iostream>
#include <cstdlib>



int main()
{
//dGraph g("data/scc.txt");
dGraph g2("data/t1.txt");
//dGraph d2("data/scc.txt");

//std::cout<<"vertices: "<<g2.size()<<"\n";
//g2.print();
scc(g2);


//dGraph d("data/scc.txt");
//d.print();



/*
BFS(g,Vertex(1));
std::cout<<"\n\n";
DFS(g,Vertex(1));
std::cout<<"\n\n";
*/

/*Graph g1("data/kargerMinCut.txt");




int min=g1.size()*g1.size(),last;
for(int i=1; i<1000; ++i)
{
std::cout<<i<<". ";
last=findMinCut(g1,i);
std::cout<<last<<"\n";
if(last<min) min=last;
}

std::cout<<"mincut size found: "<<min<<"\n\n";
*/




return 0;
}
