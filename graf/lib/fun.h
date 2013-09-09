#ifndef FUN_H
    #define FUN_H
    #include "graph.h"
    #include "vertex.h"
    #include "d_graph.h"
    #include <cstdlib>

int findMinCut(Graph g,int seed);
void BFS(Graph G, Vertex s);
list<int> DFS(Graph &G, Vertex s,int &nr);
void scc(dGraph G);

#endif
