/** CSCI 2270-110  Data Structures
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Assignment 12
 ** Author: Aparajithan Venkateswaran
 */

#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

template<class T>
struct vertex;

template<class T>
struct adjVertex {
	vertex<T> *v;
	int weight;
};

template<class T>
struct vertex {
	T name;
	int district = -1;
	bool solved;
	int distance;
	vertex* parent;
	std::vector<adjVertex<T> > adj;
};

template<class T>
class Graph {
	public:
		Graph();
		~Graph();
		void addEdge(T v1, T v2, int weight);
		void addVertex(T name);
		void displayEdges();
		void connectGraph();
		void findShortestPath(T n1, T n2);
	protected:
	private:
		std::vector<vertex<T> > vertices;
		bool isConnected = false;
		void initialize();
};

#include "Graph.cpp"
#endif // GRAPH_H
