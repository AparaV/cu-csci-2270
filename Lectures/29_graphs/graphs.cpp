/*
	Graphs
	======
		No root
		Multiple edges
		No hierarchy

	Example - Road map
		Edges between 2 cities means that they are adjacent
		In traversing graph, can only go to adjacent city from a city

	Definition:
		Graph G defined as G = {V, E} ; V = vertices, E = edges
			V = {v1, v2, v3, .. vn}
			E = {e1, e2, e3, .. em}

	Representations:
		1. Adjacency matrix
		2. Adjacency list

	Weighted and unweighted graphs
		Unweighted - all edges have uniform weight of 1
		Weighted   - each edge has a value that is the weight of that edge

	Adjacency Matrix
	----------------
		2d matrix - all vertices listed on horizontal and vertical axes
		Vertical - starting
		Horizontal - ending
		1 => there is an edge (unweighted)
		0 => there is no edge

		If weighted, replace edge with weight
		Use 0 for vk to vk
		Use -1 for no edge

	Adjacency List
	--------------
		Only stores information about the adjacent edges
		Doesn't store edges that don't exist

		For each vertex, store list of adjacent vertices including weight of edge in a weighted graph

	class Graph { // adjacency list
		private:
			vector<vertex> vertices; // include adjacency list; vertex type exists
		public:
			Graph();
			void insertVertex(value);
			void insertEdge(startVal, endVal, weight);
			void deleteVertex(value);
			void deleteEdge(starVal, endVal);
			void printGraph();
			bool search(value);
	};

	// pre condition - value is valid
	// post condition - vertex is added to vertices if it doesn't already exist
	void insertVertex(value) {
		bool found = false;
		for (int i = 0; i < vertices.size(); ++i) {
			if (vertices[i].key == value){
				found = true;
				break;
			}
		}
		// value not in vertices
		if (!found) {
			vertex v; // vertex type exists
			v.key = value;
			vertices.push_back(v);
		}
	}
		

*/