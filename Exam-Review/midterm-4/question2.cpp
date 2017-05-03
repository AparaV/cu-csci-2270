/*
Write a c++ function to check if the unweighted shortest path between two vertices passes through the third vertex.
The function takes three parameters: source vertex, destination vertex and intermediate vertex.
It should check if the unweighted shortest path between source and destination vertices passes through the intermediate vertex.
It should display "Yes" if the path passes through intermediate vertex. Otherwise, it should display "No".

void Graph::shortestPath(string source, string destination, string intermediate)
*/

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    bool visited;
    vertex *prev;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void shortestPath(string source, string destination, string intermediate);
    protected:
    private:
        std::vector<vertex> vertices;
};

/* Solution */
void Graph::shortestPath(string source, string destination, string intermediate){
    vertex *v1, *v2, *v3;
	// find vertex
	for (unsigned int i = 0; i < vertices.size(); ++i) {
		if (vertices[i].name == source) {
			v1 = &vertices[i];
		}
		if (vertices[i].name == destination) {
			v2 = &vertices[i];
		}
		if (vertices[i].name == intermediate) {
			v3 = &vertices[i];
		}
	}
	queue<vertex*> q;
	bool reached = false;
	v1->visited = true;
	v1->prev = NULL;
	q.push(v1);
	while(!q.empty() || !reached){
	    vertex* curr = q.front();
	    q.pop();
	    for(unsigned int i = 0; i < curr->adj.size(); ++i){
	        if (!curr->adj[i].v->visited){
	            curr->adj[i].v->visited = true;
	            curr->adj[i].v->prev = curr;
	            if(curr->adj[i].v == v2){
	                reached = true;
	            }
	            q.push(curr->adj[i].v);
	        }
	    }
	}
	vertex* curr = v2;
	bool found = false;
	while(curr->prev != NULL){
	    if (curr->prev == v3){
	        cout << "Yes" << endl;
	        found = true;
	        break;
	    }
	    curr = curr->prev;
	}
	if (!found){
	    cout << "No" << endl;
	}
}
