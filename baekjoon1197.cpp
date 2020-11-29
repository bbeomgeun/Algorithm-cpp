#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];

int getParent(int a) {
	if (a == parent[a])
		return a;
	else
		return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) 
		parent[b] = a;
	else
		parent[a] = b;
}

bool find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

class Edge {
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator < (Edge &edge) {
		return this->distance < edge.distance;
	}
};

int V, E, A, B, C, sum;
vector<Edge> v;

int main() {
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		v.push_back(Edge(A, B, C));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].node[0], v[i].node[1])) {
			unionParent(v[i].node[0], v[i].node[1]);
			sum += v[i].distance;
		}
	}

	cout << sum;
}
