#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "../lib/graph.h"



Graph::Graph(const char* file_name)
: vnum(0)
{
FILE *fptr;
fptr=fopen(file_name,"r");

char buf[1024];


while(fgets(buf,1024,fptr)) 
    this->vnum++;

std::cout<<"wierzcholkow: "<<vnum<<"\n";

rewind(fptr); //liczy wierzcholki(ile list przygotowac) i przewija plik;


for(int i=0; i<this->vnum; i++) vList.push_back(list<Vertex>());

bIt = vList.begin();

/////////////
//perser////

for(int i=0,num; i<this->vnum; i++,bIt++) //wczytuje powiazane wierzcholki
{//do kolejnych list
int where=0; //zmienna pamieta gdzie szukac w bufoze liczby
fgets(buf,1024,fptr);
    while(1)
    {                        
    while(isspace(buf[where]) && buf[where]!='\n') where++; //pomija biale znaki
    if(buf[where]=='\n') break; 

    sscanf(&buf[where],"%d",&num);
    while(isdigit(buf[where])) where++; //przechodzi za kolejna liczbe
    
    bIt->push_back(Vertex(num));
    }
where=0;
}
/////////////////
////////////////

fclose(fptr);
bIt=vList.begin();
sIt=bIt->begin();
}

//---------------------------------------------------------

Graph::~Graph()
{
std::cout<<"usuwam graf...\n";
bIt=vList.begin();

while(bIt != vList.end()) 
{ //czysci 'male listy'
    bIt->clear();
    bIt++;
}
vList.clear(); //czysci duza liste

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
if(this->has_vertex(v)) {std::cout<<"taki wierzcholek juz istnieje!\n"; return false;}
vList.push_back(list<Vertex>()); //dodaje nowa pusta liste;

bIt=vList.end();
bIt--; //ustawia na ostatni element

bIt->push_front(v);//dodaje wierzcholek na poczatek ostatniej,nowej listy
                    // teraz lista ma tylko 1 bez powiazan
vnum++;
return true;
}

void Graph::print(const char* sep)
{


for(bIt=vList.begin(); bIt != vList.end(); bIt++ )
{
    for(sIt=bIt->begin(); sIt != bIt->end(); sIt++)
    std::cout<<"("<<sIt->get_index()<<")"<<sep;

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
SmallIt tIt;

for(bIt=vList.begin(); bIt != vList.end(); bIt++)
{
sIt=bIt->begin();

if(*sIt==v)
{
tmp=*bIt; //zapamietujemy usuwana liste polaczonych wierzcholkow

this->vList.erase(bIt);
this->vnum--;

tv=*sIt; //zapamietujemy usuniety wierzcholek

    for(tIt=tmp.begin(),tIt++; tIt != tmp.end(); tIt++) //iteruje po liscie
          del_e(v,*tIt,false);      //usuwa krawedzie z listy usunietego wierzcholkow

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

return true;
}

BigIt Graph::get_vlist(Vertex v)
{
for(this->bIt=this->vList.begin(); *(bIt->begin()) != v && bIt != this->vList.end(); bIt++);
if(bIt==this->vList.end()) {std::cout<<"Brak szukanego vertexa w liscie\n"; }
return bIt;
}
