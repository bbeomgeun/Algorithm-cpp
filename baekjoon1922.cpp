#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[1001];

int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
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
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};
vector<Edge> v;
int N, M, a, b, c, sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].node[0], v[i].node[1])) {
			unionParent(v[i].node[0], v[i].node[1]);
			sum += v[i].distance;
		}
	}
	cout << sum;
}