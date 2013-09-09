#ifndef GRAPH_H
    #define GRAPH_H
    #include "vertex.h"
    #include <list>
    #include <vector>
    #include <iostream>
using namespace std;
typedef typename vector<list<Vertex> >::iterator BigIt;
typedef typename list<Vertex>::iterator SmallIt;

class Graph {
protected:

int vnum; //liczba wierzcholkow
vector<list<Vertex> > vList; 

BigIt bIt;
SmallIt sIt;


public:

friend list<int> DFS(Graph &G, Vertex start,int &nr);
friend void BFS(Graph &G, Vertex start);    
Graph() : vnum(0) {}
Graph(const char* file_name);
virtual ~Graph();

void show_order(void);
void print(const char* sep=" ");

int size(void) { return vnum;}
int degree(Vertex v) { return get_vlist(v)->size()-1; }

bool add_v(Vertex v,bool check=true);
bool add_e(Vertex v1, Vertex v2,bool check=true);

int& explored(Vertex v){ return vList[v.get_index()-1].begin()->inspected();}//this->eTab[v.get_index()-1];}
bool has_vertex(Vertex v);
bool has_edge(Vertex v1,Vertex v2);

Vertex del_v(Vertex v,bool check=true);
bool del_e(Vertex v1, Vertex v2,bool check=true);

BigIt contract(Vertex v1,Vertex v2);
BigIt get_vlist(Vertex v); //zwraca iterator do listy powiazanej z v
BigIt begin(void) { return vList.begin();}

};

#endif
