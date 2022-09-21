#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long init(vector<long long>& tree, vector<long long>& arr, int node, int start, int end) {
	int r = (start + end) / 2;
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = (init(tree, arr, node * 2, start, r) + init(tree, arr, node * 2 + 1, r + 1, end));
}

long long cal(vector<long long>& tree, int node, int start, int end, int left, int right) {
	int r = (start + end) / 2;
	if (left > end || right < start)
		return 0;
	else if (left <= start && end <= right)
		return tree[node];
	else
		return cal(tree, node * 2, start, r, left ,right) + cal(tree, node * 2 + 1, r + 1, end, left, right);
}

long long change(vector<long long>& tree, int node, int start, int end, int index, long long changeNum) {
	int r = (start + end) / 2;
	if (index < start || index > end)
		return tree[node];
	else if (start == end) {
		return tree[node] = changeNum;
	}
	else
		return tree[node] = (change(tree, node * 2, start, r, index, changeNum) + change(tree, node * 2 + 1, r + 1, end, index, changeNum));
}


int N, Q, x, y, a;
long long b;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> Q;
	vector<long long> arr(N);
	int h = (int)ceil(log2(N));
	vector<long long> segmentTree(1 << h + 1);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	init(segmentTree, arr, 1, 0, N - 1);
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		x--; y--;
		if (x <= y)
			cout << cal(segmentTree, 1, 0, N - 1, x, y) << "\n";
		else
			cout << cal(segmentTree, 1, 0, N - 1, y, x) << "\n";
		change(segmentTree, 1, 0, N - 1, a - 1, b);
	}
}