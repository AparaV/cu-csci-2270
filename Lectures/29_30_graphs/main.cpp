#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;


int main()
{
	Graph<string> g;
	g.addVertex("Boulder");
	g.addVertex("Denver");
	g.addVertex("New Mexico");
	g.addVertex("Texas");
	g.addVertex("New Orleans");

	//edge written to be undirected
	g.addEdge("Boulder", "Denver", 30);
	g.addEdge("Boulder", "New Mexico", 200);
	g.addEdge("Boulder", "Texas", 500);
	g.addEdge("Denver", "Texas", 300);
	g.addEdge("Texas", "New Orleans", 500);
	g.displayEdges();

	/*Graph<int> g2;
	g2.addVertex(5);
	g2.addVertex(6);
	g2.addVertex(7);
	g2.addVertex(8);
	g2.addEdge(5,6,30);
	g2.addEdge(5,7,300);
	g2.addEdge(7,8,10);
	g2.displayEdges();*/

	return 0;
}
