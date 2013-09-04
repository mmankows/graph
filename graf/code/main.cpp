#include "../lib/graph.h"
#include "../lib/vertex.h"
#include <iostream>
#include <cstdlib>


int findMinCut(Graph g,int seed)
{
Vertex v1,v2;
BigIt bIt;
SmallIt sIt;


int s;
srand(seed);

while(g.size()!=2)
{
//random pierwszego wiercholka
s = g.size();
s=rand()%s; 
for(bIt=g.begin(); s>0; s--,bIt++);
v1 = *(bIt->begin());
//random drugiego wiercholka
s=bIt->size();
s=rand()%(s-1)+1;
for(sIt=bIt->begin(); s>0;  s--,sIt++);
v2 = *sIt;


g.contract(v1,v2);

}
return g.degree(v1);
}




int main()
{
Graph g1("data/kargerMinCut.txt");
/*int a,b;

while(1){
g1.print();
std::cout<<"\n ktore wierzcholki polaczyc?\n";
std::cin>>a;
std::cin>>b;
g1.contract(Vertex(a),Vertex(b));
//g1.contract(Vertex(4),Vertex(8));
//Graph g2("data/kargerMinCut.txt");
//g2.print();
}
*/

int min=g1.size()*g1.size(),last;
for(int i=1; i<1000; ++i)
{
std::cout<<i<<". ";
last=findMinCut(g1,i);
std::cout<<last<<"\n";
if(last<min) min=last;
}

std::cout<<"mincut size found: "<<min<<"\n\n";
//g1.print();

return 0;
}
