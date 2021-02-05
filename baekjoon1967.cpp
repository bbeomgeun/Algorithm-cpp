#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, from, to, weight, endPoint, diameter;
vector<pair<int,int>> v[10001];
bool check[10001];

void DFS(int start, int accumLength) {

	if (check[start])
		return;

	check[start] = true;

	if (diameter < accumLength) {
		diameter = accumLength;
		endPoint = start;
	}

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i].first;
		int len = v[start][i].second;
		DFS(next, accumLength + len);
	}

}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(to, weight));
		v[to].push_back(make_pair(from, weight));
	}
	DFS(1, 0);

	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}
	diameter = 0;

	DFS(endPoint, 0);

	cout << diameter;
}