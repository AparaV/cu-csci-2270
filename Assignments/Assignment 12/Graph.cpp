/** CSCI 2270-110  Data Structures
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Assignment 12
 ** Author: Aparajithan Venkateswaran
 */

#include "Graph.h"
#include <vector>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

// ctor
template<class T>
Graph<T>::Graph() {

}

// dtor
template<class T>
Graph<T>::~Graph() {

}

// add edge
template<class T>
void Graph<T>::addEdge(T v1, T v2, int weight) {

	// find first vertex
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].name == v1) {

			// check if vertex already exists
			bool exists = false;
			for (int k = 0; k < vertices[i].adj.size(); ++k) {
				if (vertices[i].adj[k].v->name == v2) {
					exists = true;
					break;
				}
			}
			if (exists) {
				break;
			}

			// find second vertex
			for (int j = 0; j < vertices.size(); j++) {
				if (vertices[j].name == v2 && i != j) {
					// add element to first vertex adjacent
					adjVertex<T> av;
					av.v = &vertices[j];
					av.weight = weight;
					vertices[i].adj.push_back(av);

					// another vertex for edge in other direction
					adjVertex<T> av2;
					av2.v = &vertices[i];
					av2.weight = weight;
					vertices[j].adj.push_back(av2);
				}
			}
		}
	}
}

// add vertex
template<class T>
void Graph<T>::addVertex(T n) {
	bool found = false;
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].name == n) {
			found = true;
			cout << vertices[i].name << " found." << endl;
		}
	}
	if (found == false) {
		vertex<T> v;
		v.name = n;
		vertices.push_back(v);
	}
}

// print graph
template<class T>
void Graph<T>::displayEdges() {
	//loop through all vertices and adjacent vertices
	for (int i = 0; i < vertices.size(); i++) {
		cout << vertices[i].district << ":" << vertices[i].name << "-->";
		for (int j = 0; j < vertices[i].adj.size(); j++) {
			cout << vertices[i].adj[j].v->name;
			if (j != vertices[i].adj.size() - 1) {
				cout << "***";
			}
		}
		cout << endl;
	}
}

// connect graph
template<class T>
void Graph<T>::connectGraph() {
	int district = 1;
	for (int i = 0; i < vertices.size(); ++i) {
		queue<vertex<T>* > q;
		q.push(&vertices[i]);
		if (vertices[i].district != -1) {
			continue;
		}

		while (!q.empty()) {
			vertex<T>* start = q.front();
			q.pop();
			start->district = district;
			// all adjacent cities
			for (int j = 0; j < start->adj.size(); ++j) {
				if (start->adj[j].v->district == -1) {
					start->adj[j].v->district = district;
					q.push(start->adj[j].v);
				}
			}
		}
		district++;
	}
	isConnected = true;
}

template<class T>
void Graph<T>::findShortestPath(T n1, T n2) {
	vertex<T> *v1, *v2;
	bool found1 = false, found2 = false;
	// find vertex
	for (int i = 0; i < vertices.size(); ++i) {
		if (vertices[i].name == n1) {
			v1 = &vertices[i];
			found1 = true;
		}
		if (vertices[i].name == n2) {
			v2 = &vertices[i];
			found2 = true;
		}
	}

	if (!found1 || !found2){
		cout << "One or more cities doesn't exist" << endl;
		return;
	}
	if (v1->district == -1 || v2->district == -1) {
		cout << "Please identify the districts before checking distances" << endl;
		return;
	}
	if (v1->district != v2->district) {
		cout << "No safe path between cities" << endl;
		return;
	}

	// Dijkstra's algorithm
	initialize();
	v1->solved = true;
	v1->distance = 0;
	vector<vertex<T>* > solved;
	solved.push_back(v1);
	vertex<T>* solvedVertex;
	vertex<T>* parent;
	while (!v2->solved) {
		int minDistance = INT32_MAX;
		solvedVertex = NULL;
		for (int i = 0; i < solved.size(); ++i) {
			vertex<T>* s = solved[i];
			for (int j = 0; j < s->adj.size(); ++j) {
				if (!s->adj[j].v->solved) {
					int dist = s->distance + s->adj[j].weight;
					if (dist < minDistance) {
						solvedVertex = s->adj[j].v;
						minDistance = dist;
						parent = s;
					}
				}
			}
		}
		solvedVertex->distance = minDistance;
		solvedVertex->parent = parent;
		solvedVertex->solved = true;
		solved.push_back(solvedVertex);
	}

	// retrace path
	vector<vertex<T>* > path;
	vertex<T>* temp = v2;
	while (temp->parent != NULL) {
		path.push_back(temp);
		temp = temp->parent;
	}

	// print the path
	cout << path.size();
	path.push_back(temp);
	for (int i = path.size() - 1; i >= 0; --i) {
		cout << "," << path[i]->name;
	}
	cout << endl;
}

template<class T>
void Graph<T>::initialize() {
	for (int i = 0; i < vertices.size(); ++i) {
		vertices[i].distance = 0;
		vertices[i].solved = false;
		vertices[i].parent = NULL;
	}
}
