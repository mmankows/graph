#ifndef VERTEX_H
    #define VERTEX_H

class Vertex {
protected:

int index;

public:
Vertex(int _index): index(_index) {}
Vertex(void) : index(-1) {}
~Vertex() {}
int get_index(void) {return index;}

bool operator==(Vertex v) { return this->index==v.index; }
bool operator!=(Vertex v) { return !(*this==v); }

};

#endif
