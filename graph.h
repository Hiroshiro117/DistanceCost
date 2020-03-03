// graph.h

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdlib>
#include <queue> 

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

struct vertex;

struct edge
{
    vertex *source;
    vertex *dest;
    int cost;
    edge(vertex *a=NULL, vertex *b=NULL, int c=0)
    {
        source=a;
        dest=b;
        cost=c;
    }
};

struct vertex
{
    string name;
    vector<edge> adj;
    vertex(string s)
    {
        name=s;
    }
};

class graph
{
    public:
        typedef map<string, vertex *,less<string> > Name_map;
        Name_map work;
        void addvertex(string name);
        bool remove_vertex(string name);
        bool contain_vertex(string name);
        bool addedge(string source, string destination, int cost);
        bool remove_edge(string source, string destination);
        bool contain_edge(string source, string destination);
        void showvertex(string name);
        int Total_Edges();
        int totalVertice ();
        string Self_Edges();
        string NoInboundEdges();
        string NoOutboundEdges();
        void HeaviestWeight();
};
#endif