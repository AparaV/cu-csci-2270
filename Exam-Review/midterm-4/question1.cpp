/*
Write a C++ function to determine if the distance to any vertex is less than the edge weight to the next adjacent vertex visited in a BFS.
If such a vertex is found, the function returns true (1), otherwise, the function returns false (0).
You must use the BFSfind() method in the class to search for the startVertex.

bool BFSWithDistance(std::string startVertex) //write the function definition for this function
*/

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
	bool visited;
    std::vector<adjVertex> adj;
    int distance;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
		bool BFSWithDistance(std::string startVertex);
		int BFSFind(std::string startVertex);
    protected:
    private:
        std::vector<vertex> vertices;

};


Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);

                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
		v.visited = false;
		v.distance = 0;
        vertices.push_back(v);

    }
}

int Graph::BFSFind(std::string startVertex)
{
   bool foundStartVertex=false;
   for (int i=0;i<vertices.size(); i++){
        if (vertices[i].name == startVertex){
            return i;
        }
   }
   cout<<"starting vertex does not exist"<<endl;
   return -1;
}}

/* Solution */
bool Graph::BFSWithDistance(std::string startVertex){

    int start = BFSFind(startVertex);
    if (start == -1){
        return false;
    }
    vertex curr = vertices[start];
    // loop through all adjacent vertices
    for(unsigned int i = 0; i < curr.adj.size(); ++i){
        int weight = curr.adj[i].weight;
        vertex* nextAdj = curr.adj[i].v;
        //loop through adjacent vertices of that vertex
        //it doesn't matter if we look at starting vertex again
        //because we want weight1 < weight2
        for(unsigned int j = 0; j < nextAdj->adj.size(); ++j){
            if (weight < nextAdj->adj[j].weight){
                return true;
            }
        }
    }
    return false;
}
