#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int initMin(vector<int>& v, vector<int>& arr,  int node, int start, int end) {
	int r = (start + end) / 2;
	if (start == end)
		return v[node] = arr[start];
	else
		return v[node] = min(initMin(v, arr, node * 2, start, r), initMin(v, arr, node * 2 + 1, r + 1, end));
}

int resultMin(vector<int>& v, int node, int start, int end, int left, int right) {
	int r = (start + end) / 2;
	if (left > end || right < start)
		return 1000000001;
	else if (left <= start && end <= right)
		return v[node];
	else
		return min(resultMin(v, node * 2, start, r, left, right), resultMin(v, node * 2 + 1, r + 1, end, left, right));
}

int N, M, X, a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	vector<int> arr(N);
	int h = (int)ceil(log2(N));
	vector<int> segmentTree(1 << h + 1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	initMin(segmentTree, arr, 1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << resultMin(segmentTree, 1, 0, N - 1, a - 1, b - 1) << "\n";
	}
}