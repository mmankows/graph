#include "../lib/d_graph.h"

#include <cctype>
#include <cstdio>
#include <iostream>


dGraph::~dGraph() { std::cout<<"destruktor pochodnej(nic)\n"; }

dGraph::dGraph(const char* file_name)
{ // O(n + m)
//zaklada ze numeracja wprowadzanego grafu 1-n bez kolejno

FILE *fptr;
fptr=fopen(file_name,"r");

int last=0; //!


list<Vertex> temp;
int x1,x2;
while(fscanf(fptr,"%d%d",&x1,&x2)==2) 
{

if(last!=x1) //gdy na liscie nowy wiercholek
{


    if(temp.size()) 
    {
    vList.push_back(temp);
//
    vnum++;
    temp.clear();
    }

 
    for(last=last+1; last<x1; last++,vnum++, temp.clear()) //przypadek wiercholkow bez wychodzacych krawedzi
    {   
    temp.push_front(Vertex(last));
    vList.push_back(temp);
    }
    
   
temp.push_front(Vertex(x1)); //zainicjuj liste krawedzi nowego w nim samym
temp.push_back(Vertex(x2)); //dodaj pierwszego sasiada

}
else
{
temp.push_back(Vertex(x2));
}

}
vList.push_back(temp);
temp.clear();
vnum++;


/////////////

/////////////////
////////////////

fclose(fptr);
bIt=vList.begin();
sIt=bIt->begin();

}



bool dGraph::add_e(Vertex v1, Vertex v2, bool check)
{
if(check==true){
if(!has_vertex(v1) || !has_vertex(v2)) { 
std::cout<<"brak wierzcholka do krawedzi!\n";
std::cout<<v1.get_index()<<" "<<v2.get_index()<<"\n";
return false; 
}}

int done=1;
for(bIt=vList.begin(); bIt != vList.end() && done!=0; bIt++) 
{    
sIt=bIt->begin();
if(*sIt == v1)
{
    bIt->push_back(v2);
    done--;
}

}

return true;
}

Vertex dGraph::del_v(Vertex v)
{
Vertex t=this->Graph::del_v(v);


for(int i=1; i<=this->size(); i++)
    this->del_e(Vertex(1),Vertex(t.get_index()));
return t;
}
