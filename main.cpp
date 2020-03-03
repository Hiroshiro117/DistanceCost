/*

Aung Lin Htet

Object : To calculate the distance of different positions
In this program I used < main.cpp , graph.h , graph.cpp > and < curCuontent.txt > is input csv file

*/

//     main .cpp

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdlib>
#include <fstream>

#include "graph.h"
using namespace std;

// how would you like for output file
// is input file is rigth 

int main(int argc, char *argv[])
{
    graph g;
    string name;
    string source,destination;
    string inputfile;
    int cost;

    // calling input csv file

     if (argc == 2)
      inputfile = argv[1];
     ifstream ip(inputfile.c_str());

    
    if(!ip.is_open())
    cout << "Error\n\n";

    string first;
    string second;
    string weight;

    // while element is still not empty, keep print it out in my own map order
    while (ip.good())  
    {
      getline(ip,first,',');
      getline(ip,second,',');
      getline(ip,weight,'\n');

      int myint = stoi(weight); 
      
      // implement into map graph
      g.addvertex(first);
      g.addvertex(second);
      g.addedge(first, second, myint);
    }

    ip.close();

    g.addvertex("zoo");

    cout << "\n\n----------- Show vertexs before removed -----------\n";
    g.showvertex(name);

    cout << "\n\n----------- Remove vertex -----------\n";
    g.remove_vertex("zoo");

    cout << "\n\n----------- Show vertexs after removed -----------\n";
    g.showvertex(name);

    cout << "\n\n----------- Total vertexs -----------\n";
    g.totalVertice ();
    
    cout << "\n\n----------- Vertexs with Self_Edge -----------\n";
    g.Self_Edges();

    cout << "\n\n----------- Total Edges -----------\n";
    g.Total_Edges();

    cout << "\n\n----------- No inbound edges -----------\n";
    g.NoInboundEdges();

    cout << "\n\n----------- No Out bound edges -----------\n";
    g.NoOutboundEdges();

    cout << "\n\n----------- HeaviestWeight -----------\n";
     g.HeaviestWeight(); 

    
    return 0;
}
