#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int initMin(vector<int>& v, vector<int> & arr,  int node, int start, int end) {
	int r = (start + end) / 2;
	
	if (start == end) {
		return v[node] = arr[start];
	}
	else
		return v[node] = min(initMin(v, arr, node * 2, start, r), initMin(v, arr, node * 2 + 1, r + 1, end));
}

int initMax(vector<int>& v, vector<int>& arr, int node, int start, int end) {
	int r = (start + end) / 2;

	if (start == end) {
		return v[node] = arr[start];
	}
	else
		return v[node] = max(initMax(v, arr, node * 2, start, r), initMax(v, arr, node * 2 + 1, r + 1, end));
}

int resultMin(vector<int>& v,int node, int start, int end, int left, int right) {
	int r = (start + end) / 2;
	if (left > end || right < start)
		return 1000000001;
	else if (left <= start && end <= right) {
		return v[node];
	}
	else {
		return min(resultMin(v, node * 2, start, r, left, right), resultMin(v, node * 2 + 1, r + 1, end, left, right));
	}
}

int resultMax(vector<int>& v, int node, int start, int end, int left, int right) {
	int r = (start + end) / 2;
	if (left > end || right < start)
		return 0;
	else if (left <= start && end <= right) {
		return v[node];
	}
	else {
		return max(resultMax(v, node * 2, start, r, left, right), resultMax(v, node * 2 + 1, r + 1, end, left, right));
	}
}

int N, M, a, b, X;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	vector<int> arr(N);
	int h = (int)ceil(log2(N));
	vector<int> segmentMax(1 << h+1);
	vector<int> segmentMin(1 << h+1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	initMin(segmentMin, arr, 1, 0, N - 1);
	initMax(segmentMax, arr, 1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		cout << resultMin(segmentMin, 1, 0, N - 1, a, b)<<" "<<resultMax(segmentMax, 1, 0, N-1, a, b)<<"\n";
	}
}