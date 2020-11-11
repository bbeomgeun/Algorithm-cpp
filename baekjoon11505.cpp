#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, K;
long long divNum = 1000000007;

long long init(vector<long long>& v, vector<long long>& arr, int node, int start, int end) {
	int r = (start + end) / 2;
	if (start == end) {
		return v[node] = arr[start];
	}
	else
		return v[node] = (init(v, arr, node * 2, start, r) * init(v, arr, node * 2 + 1, r + 1, end)) % divNum;
}

long long multiple(vector<long long>& v, int node, int start, int end, int left, int right) {
	int r = (start + end) / 2;
	if (right < start || end < left)
		return 1;
	else if (left <= start && end <= right) {
		return v[node];
	}
	else
		return (multiple(v, node * 2, start, r, left, right) % divNum) *(multiple(v, node * 2 + 1, r + 1, end, left, right) % divNum);
}

long long change(vector<long long>& v, int node, int start, int end, int index, int changeNum) {
	int r = (start + end) / 2;
	if (index < start || index > end) {
		return v[node];
	}
	else if (start == end)
		return v[node] = changeNum;
	else 
		return v[node] = (change(v, node * 2, start, r, index, changeNum) % divNum) * (change(v, node * 2 + 1, r + 1, end, index, changeNum) % divNum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	vector<long long> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int h = (int)ceil(log2(N));
	vector<long long> segmentTree(1 << h + 1);
	init(segmentTree, arr, 1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		int a;
		cin >> a;
		if (a == 1) { // b번째 c로 바꾸기
			int b; long long c;
			cin >>b >> c;
			b--;
			change(segmentTree, 1, 0, N - 1, b,c);
			arr[b] = c;
		}
		else { // b~c 곱
			int b; int c;
			cin >> b >> c;
			cout << multiple(segmentTree, 1, 0, N - 1, b - 1, c - 1) % divNum << "\n";
		}
	}
}