/*
	Standard Template Library
	-------------------------
		Collection of template classes on commonly used algorithms and data structures
*/

#include <iostream>
#include <vector>

using namespace std;

struct vertex {
	int key;
	vertex* adjacent;
};

struct vertex2;

struct adjacent {
	vertex2* v;
};

struct vertex2 {
	int key;
	vector<adjacent> adj;
};


int main() {

	/*
	vector<int> v;
	v.push_back(5);
	cout << v.size() << endl;

	vector<int> v2(10); // initial size = 10
	vector<int> v3(10, 5); // initial size = 10, values = 5
	for (int i = 0; i < v2.size(); ++i) {
		v2[i] = i; // treat vector like array
	}

	for (vector<int>::iterator it = v2.begin(); it < v2.end(); ++it) {
		cout << (*it) << endl; // vector style
	}

	vector<vertex> vertices(10);
	for (int i = 0; i < 10; ++i) {
		vertices[i].key = i + 1;
	}
	for (vector<vertex>::iterator it = vertices.begin(); it < vertices.end(); ++it) {
		cout << it->key << " ";
	}
	cout << endl;

	vertices[0].adjacent = &vertices[1];
	vertices[2].adjacent = &vertices[8];
	cout << vertices[0].adjacent->key << endl;
	cout << vertices[2].adjacent->key << endl;
	*/

	vector<vertex2> ve(10);
	for (int i = 0; i < 10; ++i) {
		ve[i].key = (i + 1) * 10;
	}
	adjacent a; // has a pointer to a vertex2, not initialized
	a.v = &ve[1];
	ve[0].adj.push_back(a);
	a.v = &ve[2];
	ve[0].adj.push_back(a);
	cout << ve[0].adj[0].v->key << endl;
	cout << ve[0].adj[1].v->key << endl;

	return 0;
}