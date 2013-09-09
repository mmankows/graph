#ifndef VERTEX_H
    #define VERTEX_H

class Vertex {
protected:

int index;
int seen;

public:
Vertex(int _index): index(_index), seen(false){}
Vertex(void) : index(-1), seen(false) {}
~Vertex() {}
int get_index(void) {return index;}

void mins() { this->seen = true;} //marks v as inspected
void muins() { this->seen = false;} //marks v as uninspected
int& inspected() { return seen; } //shows if the vertex has been inspected
bool operator==(Vertex v) { return this->index==v.index; }
bool operator!=(Vertex v) { return !(*this==v); }

};

#endif
