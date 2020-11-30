#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100001];

int getParent(int a) {
	if (a == parent[a])
		return a;
	else
		return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else
		parent[a] = b;
}

bool find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

class Point {
public:
	int x;
	int y;
	int z;
	int num;

	Point(int x, int y, int z, int num) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->num = num;
	}
};
bool compareX(Point & pnt1, Point& pnt2) {
	return pnt1.x < pnt2.x;
}
bool compareY(Point& pnt1, Point& pnt2) {
	return pnt1.y < pnt2.y;
}
bool compareZ(Point& pnt1, Point& pnt2) {
	return pnt1.z < pnt2.z;
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

	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};

int minDistance(Point& p1, Point& p2) {
	return min(min(abs(p1.x - p2.x), abs(p1.y - p2.y)), abs(p1.z - p2.z));
}

int N, x, y, z, tempX, tempY, tempZ, tempMin;
vector <Edge> v;
vector <Point> p;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> z;
		Point p1(x, y, z, i);
		p.push_back(p1);
	}

	// x좌표로 먼저 정렬
	sort(p.begin(), p.end(), compareX);
	int size = p.size()-1;
	for (int i = 0; i < size ; i++) {
		Point tempP1 = p[i];
		Point tempP2 = p[i + 1];
		int dis = minDistance(tempP1, tempP2);
		v.push_back(Edge(tempP1.num, tempP2.num, dis));
	}

	// y좌표로 정렬
	sort(p.begin(), p.end(), compareY);
	for (int i = 0; i < size ; i++) {
		Point tempP1 = p[i];
		Point tempP2 = p[i + 1];
		int dis = minDistance(tempP1, tempP2);
		v.push_back(Edge(tempP1.num, tempP2.num, dis));
	}

	// x좌표로 먼저 정렬
	sort(p.begin(), p.end(), compareZ);
	for (int i = 0; i < size; i++) {
		Point tempP1 = p[i];
		Point tempP2 = p[i + 1];
		int dis = minDistance(tempP1, tempP2);
		v.push_back(Edge(tempP1.num, tempP2.num, dis));
	}

	sort(v.begin(), v.end());

	int Vsize = v.size();
	int result = 0;
	for (int i = 0; i < Vsize; i++) {
		if (!find(v[i].node[0], v[i].node[1])) {
			unionParent(v[i].node[0], v[i].node[1]);
			result += v[i].distance;
		}
	}
	cout << result;
}