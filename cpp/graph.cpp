#include <iostream>
#include "../headers/graph.h"
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <queue>
//#include <tuple>
using namespace std;

Graph::Graph(){
    Vertices = {};
    Edges = {};
};

Graph::Vertex::Vertex(int n){
    this->n = n;
}

Graph::Edge::Edge(Vertex* a, Vertex* b, int n){
    this->a = a;
    this->b = b;
    this->weight = n;        
}

Graph::Vertex* Graph::addVertex(int n){
    if(getVertex(n)!=nullptr){
        cout << "Vertex already exists.\n";
        return nullptr;
    }
    Vertex* v = new Vertex(n);
    Vertices.push_back(v);
    return v;
};

Graph::Vertex* Graph::getVertex(int n){
    for(auto v : Vertices) if (v->n == n) return v;
    return nullptr;
};

bool Graph::removeVertex(int n){
    Vertex* x = getVertex(n);
    if(x == nullptr){
        cout << "Vertex does not exit.\n";
        return false;
    }
    //delete edges
    // for(auto edge : Edges) if (edge->a == x || edge->b == x) Edges.erase(edge);
    for(auto edge = Edges.begin(); edge != Edges.end();) if ((*edge)->a == x || (*edge)->b == x) Edges.erase(edge);
    //Vertices.erase(x);
    // return true;

    //delete vertex
    //for(auto vertex : Vertices) if (vertex == x) Vertices.erase(vertex);
    for(auto vertex = Vertices.begin(); vertex != Vertices.end();) if (x == (*vertex)) Vertices.erase(vertex);
    return true;
};

bool Graph::addEdge(Vertex* a, Vertex* b,int n){
    if(a == nullptr || b == nullptr){
        a==nullptr?cout<<"a is null.\n":cout <<"b is null.\n";
        return false;
    }
    if(a == b){
        cout << "Cannot have an edge from vertex to itself.\n";
        return false;
    }
    for(auto e : Edges){ 
        if(e->a == a && e->b == b){
            if(n < e->weight) return e->weight = n;
            cout <<  "Edge exists and is shorter.\n";
            return false;
        }
    }
    Edges.push_back(new Edge(a,b,n));
    return true;
};

bool Graph::removeEdge(Vertex* a, Vertex* b){
    if(a == nullptr || b == nullptr){
        a==nullptr?cout<<"a is null.\n":cout <<"b is null.\n";
        return false;
    }
    for(auto e = Edges.begin(); e != Edges.end();){
        if((*e)->a == a && (*e)->b == b) Edges.erase(e);
        return true;
    }
    return false;
};

tuple<int,map<Graph::Vertex*,Graph::Vertex*>> Graph::dijkstra(Vertex* source, Vertex* dest){
    map<Graph::Vertex*,int> dist;
    map<Graph::Vertex*,Vertex*> prev;
    auto comp = [&](Graph::Vertex* a, Graph::Vertex* b){return dist[a]>dist[b];};
    priority_queue<Graph::Vertex*, vector<Graph::Vertex*>, decltype(comp)> Q(comp);
    int tempdist;
    for( auto v : Vertices){
        dist[v] = numeric_limits<int>::max();
        prev[v] = nullptr;
        //Q.push(v);
    }
    dist[source] = 0;
    Q.push(source);
    while(!Q.empty()){
        Vertex* u = Q.top();
        Q.pop();
        //dist[u] = 0;
        //cout << u->n << "\n";
        for(auto e : Edges){
            if(e->a == u){
                tempdist = dist[u] + e->weight;
                if (tempdist < dist[e->b]){
                    Q.push(e->b);
                    dist[e->b] = tempdist;
                    prev[e->b] = u;
                }
            }
        }
        /* for_each(Edges.begin(),  // iterate from start
                    Edges.end(),    // to end
                    [&](Graph::Edge* e){
                        if(e->a == u){
                            tempdist = dist[u] + e->weight;
                            if (tempdist < dist[e->b]){
                                dist[e->b] = tempdist;
                                prev[e->b] = u;
                            }
                    ;};}); */
        }
    return {dist[dest],prev};
};

void Graph::printGraph(){
    if(Vertices.empty()){
        cout << "No Vertices.\n";
        return;
    }
    cout << "Vertices:\n\t";
    for( auto vertex : Vertices)
    cout << vertex->n << " ";
    cout << "\n";
    if(Edges.empty()){
        cout << "No edges.\n";
        return;
    }
    cout << "Edges:\n\t";
    for( auto edge : Edges)
    cout<< "Vertex " << edge->a->n << 
    " - Vertex " << edge->b->n <<
     " : " << edge->weight << ".\n\t";
};