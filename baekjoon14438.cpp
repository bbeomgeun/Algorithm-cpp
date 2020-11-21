#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Init(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
	int r = (start + end) / 2;
	if (start == end) {
		return tree[node] = arr[start];
	}
	else
		return tree[node] = min(Init(arr, tree, node * 2, start, r), Init(arr, tree, node * 2 + 1, r + 1, end));
}

int minTree(vector<int>& tree, int node, int start, int end, int left, int right) {
	int r = (start + end) / 2;
	
	if (left > end || right < start) {
		return 1000000001;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	else
		return min(minTree(tree, node * 2, start, r, left, right), minTree(tree, node * 2 + 1, r + 1, end, left, right));
}

int updateTree(vector<int>& tree, int node, int start, int end, int target, int updateNum) {
	int r = (start + end) / 2;
	if (target < start || target > end) { // 1차적으로 범위를 거르자
			return tree[node];
	}
	else if (start == end) { // 이 경우를 if문 먼저했더니 target index와 다른 경우에도 update가 되어서 다른 노드의 값도 update되어버렸다.
		return tree[node] = updateNum;
	}
	else
		return tree[node] = min(updateTree(tree, node * 2, start, r, target, updateNum), updateTree(tree, node * 2 + 1, r + 1, end, target, updateNum));
}

int N, M, a, b, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector <int> arr(N);
	int h = (int)ceil(log2(N));
	int size = 1 << (1 + h);
	vector <int> segmentTree(size);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	Init(arr, segmentTree, 1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			updateTree(segmentTree, 1, 0, N - 1, b-1, c);
		}
		else {
			cout << minTree(segmentTree, 1, 0, N - 1, b-1, c-1) << "\n";
		}
	}
}