/*
Print all adjacent vertices in a graph whose value is greater than the value of the parent vertex in a breadth-first search (BFS).
You need to fill in the appropriate code in the following function, which has already been defined for you.
Copy the code provided into the coding window as the starting point for your answer.

void Graph::findAdjacentWithGreaterValue(int startVertex);

The function should print the starting vertex and its adjacent vertices whose value is greater than the value of the parent vertex.
Do not visit a vertex that has already been visited.
The vertex structure includes a "visited" variable, set to false by default.
You can use this variable in the findAdjacentWithGreaterValue function.
*/

struct adjVertex{
    vertex *v;
};

struct vertex{
    int value;
    bool visited;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(int v1, int v2);
        void addVertex(int name);
        void displayEdges();
	void findAdjacentWithGreaterValue(int startVertex);
    private:
        std::vector<vertex> vertices;
};

void Graph::findAdjacentWithGreaterValue(int startVertex) {
	vertex *start;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].value == startVertex) {
			start = &vertices[i];
		}
	}

	queue<vertex*> Q;
	Q.push(start);
	start->visited = true;
	cout << start->value << " ";
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
		for (int i = 0; i < (int)node->adj.size(); i++) {
		    //Students have to fill in this part of the code
		    if (!node->adj[i].v->visited){
                if (node->adj[i].v->value > node->value){
                    cout << node->adj[i].v->value << " ";
                }
                node->adj[i].v->visited = true;
                Q.push(node->adj[i].v);
		    }
		}
	}
}
