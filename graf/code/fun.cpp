#include "../lib/fun.h"
#include <list>
#include <iostream>

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


//0000000000000000000000000000000000000000000000000000

void BFS(Graph G, Vertex start)
{
//najkrotsza droga bfs: nalezy pamietac odleglosc od wiercholka
//startowego w wiercholkach ktore odwiedzamy
//kazdy wiercholek v odwiedzony z wiercholka w ma odleglosc o 1 wieksza
//od startu

    
SmallIt sIt;
BigIt bIt;


G.explored(start) = 1;

std::list<Vertex> quee; //tylko push_back() i pop_front() /!!!

quee.push_back(start);

while(!quee.empty())
{
Vertex v = *(quee.begin()); //tworzy kolejke sasiadow odwiedzonego wezla
std::cout<<v.get_index()<<" ";
quee.pop_front();


    for(bIt=G.get_vlist(v), sIt=bIt->begin(); sIt!=bIt->end(); sIt++ )
    {
    if(!G.explored(*sIt)) 
    {
    G.explored(*sIt) = 1;
    quee.push_back(*sIt);
    }
    }

}
}

list<int> DFS(Graph &G, Vertex start,int &nr)
{
//wrzuca na stos sasiadow wezla, ale bierze do odwiedzenia ostatnio wrzucony
static int t=1;


SmallIt sIt;
BigIt bIt;


std::list<Vertex> stack; //tylko push_front() i pop_front() /!!!
std::list<int> temp;
stack.clear();

stack.push_front(start);

while(!stack.empty())

    
Vertex v = *(stack.begin()); 
stack.pop_front();


G.explored(v) = nr;

temp.push_front(v.get_index());
std::cout<<v.get_index()<<", ";


bool flag=false;

    for(SmallIt eIt=G.vList[v.get_index()-1].end(),
        sIt=G.vList[v.get_index()-1].begin(); sIt!=eIt; sIt++ )
    {
    //
    if( G.explored(*sIt)==0 ) 
    { 
//    G.explored(*sIt) = nr;
    flag=true;
    stack.push_front(*sIt);
   
    }
    }

}


std::cout<<"|  ";
return temp;
}

//------------------------------------------------------------------

void scc(dGraph G)
{
//int nr=G.size();
dGraph temp = G;
    
int nr=-12345;
list<int> l,t;

for(int i=G.size(); i>0; i--)
{ 
if( G.explored(Vertex(i))==0)
{
    t=DFS(temp,Vertex(i),nr);
   
}
}
temp.show_order();

}


