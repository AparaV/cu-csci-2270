#include <iostream>
#include <vector>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H


template<class T>
struct vertex;

template<class T>
struct adjVertex{
    vertex<T> *v;
    int weight;
};

template<class T>
struct vertex{
    T name;
    vector<adjVertex<T>> adj;
};


template<class T>
class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(T v1, T v2, int weight);
        void addVertex(T name);
        void displayEdges();
    protected:
    private:
        vector<vertex<T> > vertices;

};


// Start implementation of member objects
template<class T>
Graph<T>::Graph()
{
}

template<class T>
Graph<T>::~Graph()
{
}

template<class T>
void Graph<T>::addEdge(T v1, T v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex<T> av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}

template<class T>
void Graph<T>::addVertex(T n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex<T> v;
        v.name = n;
        vertices.push_back(v);

    }
}

template<class T>
void Graph<T>::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }

}

#endif // GRAPH_H

int main()
{

    Graph<int> g;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addEdge(1,2,30);
    g.addEdge(3,4,300);
    g.addEdge(2,4,10);
    g.displayEdges();

    return 0;
}
