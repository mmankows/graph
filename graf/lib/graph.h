#ifndef GRAPH_H
    #define GRAPH_H
    #include "vertex.h"
    #include <list>
using namespace std;
typedef typename list<list<Vertex> >::iterator BigIt;
typedef typename list<Vertex>::iterator SmallIt;

class Graph {
protected:

int vnum; //liczba wierzcholkow
list<list<Vertex> > vList; 

BigIt bIt;
SmallIt sIt;


public:
Graph(const char* file_name);
~Graph();
void print(const char* sep=" ");

bool add_v(Vertex v,bool check=true);
bool add_e(Vertex v1, Vertex v2,bool check=true);


bool has_vertex(Vertex v);
bool has_edge(Vertex v1,Vertex v2);

Vertex del_v(Vertex v,bool check=true);
bool del_e(Vertex v1, Vertex v2,bool check=true);


};


#endif