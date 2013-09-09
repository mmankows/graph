#ifndef D_GRAPH_H
    #define D_GRAPH_H
#include "graph.h"

class dGraph : public Graph {

public:

dGraph() : Graph() {}
dGraph(const char* plik);
~dGraph();

friend list<int> DFS(Graph &G, Vertex start,int &nr);
friend void BFS(Graph &G, Vertex start);

bool add_e(Vertex v1, Vertex v2,bool check=true);
Vertex del_v(Vertex v);


};


#endif
