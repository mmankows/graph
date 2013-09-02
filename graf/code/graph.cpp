#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../lib/graph.h"

//#include <sstream>


Graph::Graph(const char* file_name)
: vnum(0)
{
FILE *fptr;
fptr=fopen(file_name,"r");

char ch,buf[1024];
int num;

while(fgets(buf,1024,fptr)) 
    this->vnum++;

rewind(fptr); //liczy wierzcholki(ile list przygotowac) i przewija plik;


for(int i=0; i<this->vnum; i++)
{
vList.push_back(list<Vertex>());
num--;
}

bIt = vList.begin(); //ustawia iterator list na pierwsza pusta liste

for(int i=0; i<this->vnum; i++,bIt++) //wczytuje powiazane wierzcholki
do{                                   //do kolejnych list

fscanf(fptr,"%d%c",&num,&ch);
bIt->push_back(Vertex(num));

}while(ch!='\n');

fclose(fptr);
bIt=vList.begin();
sIt=bIt->begin();
}

//---------------------------------------------------------

Graph::~Graph()
{
bIt=vList.begin();

while(bIt != vList.end()) 
{ //czysci 'male listy'
    bIt->clear();
    bIt++;
    std::cout<<"usunałem mała liste!\n";
}
vList.clear(); //czysci duza liste
std::cout<<"usunalem duza liste. koniec\n";

}

//-----------------------------------------------------------------

bool Graph::has_vertex(Vertex v)
{
for(bIt=vList.begin(); bIt!=vList.end(); bIt++) //sprawdza czy nie ma 
{                                                //juz takiego wierzcholka
sIt=bIt->begin();
if(*sIt==v) return true;
}
return false;
}

//-----------------------------------------------------------

bool Graph::add_v(Vertex v,bool check)
{
if(check==true)
if(this->has_vertex(v)) {std::cout<<"taki wierzcholek juz istnieje!"; return false;}
vList.push_back(list<Vertex>()); //dodaje nowa pusta liste;

bIt=vList.end();
bIt--; //ustawia na ostatni element

bIt->push_front(v);//dodaje wierzcholek na poczatek ostatniej,nowej listy
                    // teraz lista ma tylko 1 bez powiazan
std::cout<<bIt->size()<<"size\n";
return true;
}

void Graph::print(const char* sep)
{


for(bIt=vList.begin(); bIt != vList.end(); bIt++ )
{
    for(sIt=bIt->begin(); sIt != bIt->end(); sIt++)
    std::cout<<sIt->get_index()<<sep;

std::cout<<std::endl;
}

}

//--------------------------------------------------------

bool Graph::add_e(Vertex v1, Vertex v2,bool check)
{
if(check==true){
if(has_edge(v1,v2)) {
    std::cout<<"jest juz taka krawedz!\n"; return false; 
}
if(!has_vertex(v1) || !has_vertex(v2)) { 
std::cout<<"brak wierzcholka do krawedzi!\n";
return false; 
}}

int done=2;
for(bIt=vList.begin(); bIt != vList.end() && done!=0; bIt++) 
{    //poki nie dojdziemy do konca listy lub nie zrealizujemy obu
sIt=bIt->begin();
if(*sIt == v1)
    bIt->push_back(v2);
else if(*sIt == v2)
    bIt->push_back(v1);

}

return true;
}

//------------------------------------------------------------------------

bool Graph::has_edge(Vertex v1,Vertex v2)
{
for(bIt=vList.begin(),sIt=bIt->begin(); bIt!=vList.end() ; bIt++)
{ 
sIt=bIt->begin();
    if(*sIt == v1) 
    {
        for(; sIt != bIt->end(); sIt++)
            if(*sIt == v2)  return true;
       
    }
    else if(*sIt == v2)
    {
        for(; sIt != bIt->end(); sIt++)
            if(*sIt == v1) return true;
        
    }

}
 return false;

}

//------------------------------------------------------------------------

Vertex Graph::del_v(Vertex v,bool check)
{
if(check==true)
if(!(this->has_vertex(v))) {std::cout<<"nie ma takiego wierzcholka!";return Vertex(-1);}

list<Vertex> tmp;
Vertex tv(0);

for(bIt=vList.begin(); bIt != vList.end(); bIt++)
{
sIt=bIt->begin();

if(*sIt==v)
{
tmp=*bIt; //zapamietujemy usuwana liste polaczonych wierzcholkow

this->vList.erase(bIt);
this->vnum--;

tv=*sIt; //zapamietujemy usuniety wierzcholek

    for(sIt=tmp.begin(); sIt != tmp.end(); sIt++) //iteruje po liscie
          del_e(*sIt,v,false);      //usuwa krawedzie z listy usunietego wierzcholka
                

return tv;
}

}
return Vertex(-2); //niespodziewane zakonczenie
}

//--------------------------------------------------------------------

bool Graph::del_e(Vertex v1, Vertex v2,bool check)
{
if(check==true)
if(!(this->has_edge(v1,v2))) {std::cout<<"nie ma takiej krawedzi!\n"; return false;}

int done=2;
for(bIt=vList.begin(); bIt!=vList.end() && done!=0; bIt++ )
    {
    if( *(bIt->begin()) == v1)
        for(sIt=bIt->begin(); sIt != bIt->end(); sIt++){
            if(*sIt == v2)
            {
            sIt=bIt->erase(sIt);
            sIt--;
            done--;
           // break; //moze byc kilka krawedzi z punktu  a do b!!
            }} //klamra niezbedna zeby ify sie nie gryzly
    
    else if( *(bIt->begin()) == v2)
        for(sIt=bIt->begin(); sIt != bIt->end(); sIt++){
            if(*sIt == v1)
            {
            sIt=bIt->erase(sIt);
            sIt--;
            done--;
            //break; //  patrz wyzej 
            }}
    
    }


}

