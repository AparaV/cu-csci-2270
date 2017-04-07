#include <iostream>
#include <queue>

using namespace std;

int main() {

	queue<int> q;
	cout << "Size: " << q.size() << endl;

	q.push(3);
	q.push(6);
	q.push(5);

	cout << "Size after inserting: " << q.size() << endl;

	while (!q.empty()) {
		q.pop();
	}

	cout << "Size after deleting: " << q.size() << endl;


	return 0;
}