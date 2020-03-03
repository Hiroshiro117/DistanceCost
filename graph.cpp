// graph.cpp

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdlib>
#include <queue> 

#include "graph.h"
using namespace std;

graph g;
queue <string> q;
queue <int> w;

// funtion for adding vertex 
void graph::addvertex(string name)
{
    Name_map::iterator itr=work.begin();
    itr=work.find(name);
    if(itr==work.end()) 
    {
        vertex *v;
        v= new vertex(name);
        work[name]=v;
        return;
    }
}

// funtion for removing targeted vertex
bool graph::remove_vertex(string name)
{
    Name_map::iterator itr=work.begin();
    itr = work.find(name);

    for(itr=work.begin();itr!=work.end();itr++)
    {
          if ( itr->first == name )
          {
            cout << name << " is removed";
            work.erase(name);
            return true ;
          } 
    }
   return false;    
}

// additional funtion help to check existing vertex and print out vertexs 
void graph::showvertex(string name) 
{
    Name_map::iterator itr=work.begin();
    for(itr=work.begin();itr!=work.end();itr++)
    {
          cout << itr->first << " , " ;
    }
}

// funtion for checking specific target vertexs are contained
bool graph::contain_vertex(string name) 
{
    Name_map::iterator itr=work.begin();
    
    // check the input name is similar to one of the vertex list
    for(itr=work.begin();itr!=work.end();itr++)
    {
          if ( itr->first == name )
          return true;
    }
   return false;
}

// add edges function
bool graph::addedge(string source,  string destination, int cost)
{
    Name_map::iterator itr=work.begin();
    vertex *f=(work.find(source)->second);
    vertex *t=(work.find(destination)->second);
    edge added(f,t,cost);
    
    f->adj.push_back(added);
    
    itr=work.find(source);
    if(itr==work.end())
    {
        vertex *so;
        so= new vertex(source);
        work[source]=so; 
    }

    itr=work.find(destination);
    if(itr==work.end())
    {
        vertex *de;
        de= new vertex(destination);
        work[destination]=de;
    }

    // check if the source and destination are locating in the list,
    // if doesn't we can not add any edge
    if ( !g.contain_vertex(source) || !g.contain_vertex(destination) )
    {
        return false;
    }
    
    return true;
}

// remove edge funtion 
bool graph::remove_edge(string source, string destination)
{
    Name_map::iterator itr=work.find(source); 
    
    vector<edge> v = (itr->second)->adj;
    vector<edge>::iterator itr1=v.begin();

    
    // used <vector> erase to remove edge from specifice targeted lsit
    for(itr1=v.begin();itr1!=v.end();itr1++)
    {   
        if( ((*itr1).dest)->name==destination )
        {
            cout<<"\nThe removed cost is:"<<(*itr1).cost;
            v.erase((itr1));
            return true;
        } 
    }
    return false;   
}

// funtion for checking edges for targeted vertexs are contained
bool graph::contain_edge( string source,  string destination)
{
    Name_map::iterator itr=work.find(source);
    vector<edge> v=(itr->second)->adj;

    vector<edge>::iterator itr1=v.begin();
    for(itr1=v.begin();itr1!=v.end();itr1++)
    {
        if(((*itr1).dest)->name==destination)
        {
            cout<<"\nThe cost for '"<< source << "' to '" << destination <<"' is:"<<(*itr1).cost;
        return true;
        }
    }
    cout << " it is empty\n";
    return false;
}

// funtion for showing total vertices 
int graph::totalVertice ()
{
    int total_V=0;
    Name_map::iterator itr=work.begin();
    
    for(itr=work.begin() ;itr!=work.end();itr++)
          total_V++;
    
    cout <<"Total vertexs are : " << total_V;

    return total_V;
}

// self edges vertex list
string graph::Self_Edges()
{
    Name_map::iterator itr=work.begin();
    string target ;

    
      for(itr=work.begin() ;itr!=work.end();itr++)  // source from "begin" to "end"
      {
        itr->first;

        vector<edge> v=(itr->second)->adj;
        vector<edge>::iterator itr1=v.begin();  // only pointed to "begin" and "end" only
        
        // check all destnations in each source ( are they similar )
        while (itr1 != v.end()) 
        {
            if ( itr->first == ((*itr1).dest)->name)
                cout  << "\nSelf edges vertex : " << ((*itr1).dest)->name  ;
            itr1++;
        }
      }
    return target;
}

// funtion for total_edges number for additional supporting 
int graph::Total_Edges()
{
    int  total=0;
    Name_map::iterator itr=work.begin();

    for(itr=work.begin() ;itr!=work.end();itr++)  // source from "begin" to "end"
    {
        itr->first;

        vector<edge> v=(itr->second)->adj;
        vector<edge>::iterator itr1=v.begin();  // only pointed to "begin" and "end" only
 
        while (itr1 != v.end())
        {
            // if ( itr->first == ((*itr1).dest)->name)
            ((*itr1).dest)->name;
            itr1++;
            total++;
        }  
    }
    cout << "\nTotal edges are : " << total;

  return total;
}

// Vertex lsit with Exactly zero inbound Edges
string graph::NoInboundEdges()
{
    string target;
    
    Name_map::iterator itr=work.begin();
    
    for(itr=work.begin() ;itr!=work.end();itr++)  // source from "begin" to "end" 
    {
        itr->first;

        vector<edge> v=(itr->second)->adj;
        vector<edge>::iterator itr1=v.begin();  

        // use queue to push costs into queue patthen 
        while (itr1 != v.end())
        {
            q.push(((*itr1).dest)->name);
            itr1++;
        }
    }
    string arr[q.size()];

    // use queue to store data for using later comparison 
    // store those data into array list
    int size = q.size();
    while (!q.empty())
    {   
      for(int i=0; i<q.size(); i++)
        arr[i] = q.front();
        q.pop();
    }
    
    // compare the source and destination to search there is any vertex is not destination 
    for (itr = work.begin(); itr!=work.end(); itr++)
    {
        int inbound = 0;
        for(int i=0; i<size; i++)
        {
            if ( itr->first != arr[i] )
            {
               inbound += 1;
            }
        }
        if ( size == inbound )
            cout << endl << itr->first << " is Zero inbound\n" ;
    }

    return target;
}

// Vertex lsit with Exactly zero outbound Edges
string graph::NoOutboundEdges()
{
    string target;
    int inbound = 0;
    
    Name_map::iterator itr=work.begin();
    
    for(itr=work.begin() ;itr!=work.end();itr++)  // source from "begin" to "end" 
    {
        itr->first;

        vector<edge> v=(itr->second)->adj;
        vector<edge>::iterator itr1=v.begin();  
        
        // use queue to push costs into queue patthen 
        while (itr1 != v.end())
        {
            q.push(((*itr1).dest)->name);
            itr1++;
        }
    }
    string arr[q.size()];
    
    // use queue to store data for using later comparison 
    // store those data into array list
    int size = q.size();
    while (!q.empty())
    {   
      for(int i=0; i<q.size(); i++)
        arr[i] = q.front();
        q.pop();
    }

    // compare source and destination to search there is any vertex is destination, but not source
    for (itr = work.begin(); itr!=work.end(); itr++)
    {
        for(int i=0; i<size; i++)
        {
            if ( itr->first != arr[i] )
               inbound = -1;
            
            else 
                inbound = 1;
                break;
        }
        if (inbound == 1)
            cout << endl << itr->first << " is Zero outbound\n" ;
    }
 
    return target;
}

// the heaviest weight or cost  funtion 
void graph::HeaviestWeight()
{
     Name_map::iterator itr=work.begin();
    
    for(itr=work.begin() ;itr!=work.end();itr++)  
    {
        itr->first;

        vector<edge> v=(itr->second)->adj;
        vector<edge>::iterator itr1=v.begin();  

        while (itr1 != v.end())
        {
            w.push((*itr1).cost);
            itr1++;
        }
    }

    int co[w.size()];
    int size = w.size();

    while (!w.empty())
    {   
      for(int i=0; i<w.size(); i++)
        co[i] = w.front();
        w.pop();
    }

    int temp =0 ;
     for(int i=0; i<size; i++)
        if (co[i] >= temp)
            temp = co[i];
            
      cout << "\nThe Heaviest weight is : "<< temp;
    
}
