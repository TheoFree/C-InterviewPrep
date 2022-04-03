#include <vector>
#include <map> 
//#include <tuple>
class Graph{
    struct Vertex{
        int n;
        Vertex(int n);
    };
    struct Edge{
        Vertex* a;
        Vertex* b;
        int weight;
        Edge(Vertex* a, Vertex* b, int n);
    };

    vector<Vertex*> Vertices;
    vector<Edge*> Edges;
    
    public:
        Graph();
        Vertex* addVertex(int n);
        Vertex* getVertex(int n);
        bool removeVertex(int n);
        bool addEdge(Vertex* a, Vertex* b,int n);
        bool removeEdge(Vertex* a, Vertex* b);
        void printGraph();
        tuple<int,map<Graph::Vertex*,Graph::Vertex*>> dijkstra(Vertex* source, Vertex* dest);
        ~Graph();

};