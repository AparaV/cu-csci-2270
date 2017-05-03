/*
Write a c++ function to check if a path exists in a graph.The function takes two parameters: path (array of strings), length.
It should return true if path exists. Otherwise, it should return false.

bool Graph::pathExists(string path[], int length)
*/
struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    bool visited;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        bool pathExists(string path[], int length);
    protected:
    private:
        std::vector<vertex> vertices;
};

/* Solution */

bool Graph::pathExists(string path[], int length){
    vertex* start;
    for(unsigned int i = 0; i < vertices.size(); ++i){
        if (vertices[i].name == path[0]){
            start = &vertices[i];
            break;
        }
    }
    bool found = true;
    for(int l = 1; l < length; ++l){
        bool isthere = false;
        for(unsigned int i = 0; i < start->adj.size(); ++i){
            if (start->adj[i].v->name == path[l]){
                start = start->adj[i].v;
                isthere = true;
                break;
            }
        }
        if (!isthere){
            found = false;
            break;
        }
    }
    return found;
}
