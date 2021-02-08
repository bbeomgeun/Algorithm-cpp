//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int T, n, x, y, r;
//
//class Point {
//public:
//	int x;
//	int y;
//	double r;
//
//	Point(int x, int y, double r) {
//		this->x = x;
//		this->y = y;
//		this->r = r;
//	}
//};
//vector<Point> v;
//int parent[3001];
//
//int find_parent(int x) {
//	if (parent[x] == x) {
//		return x;
//	}
//	else
//		return parent[x] = find_parent(parent[x]);
//}
//
//void union_parent(int x, int y) {
//	x = find_parent(x);
//	y = find_parent(y);
//
//	if (x <= y) {
//		parent[y] = x;
//	}
//	else
//		parent[x] = y;
//}
//
//bool checkDistance(int i, int j) {
//	double distance = sqrt(pow((v[i].x - v[j].x), 2) + pow((v[i].y - v[j].y), 2));
//	if (distance <= v[i].r + v[j].r) {
//		return true;
//	}
//	else
//		return false;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> T;
//	for (int t = 0; t < T; t++) {
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			parent[i] = i;
//		}
//		int count = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> x >> y >> r;
//			Point p(x, y, r);
//			v.push_back(p);
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = i+1; j < n; j++) {
//				if (checkDistance(i, j)) {
//					union_parent(i, j);
//				}
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			if (parent[i] == i) {
//				count++;
//			}
//		}
//		cout << count<<"\n";
//		v.clear();
//	}
//}