#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//a : 배열 a , tree : 세그먼트 트리, node : 세그먼트 트리노드 번호, start~end : node가 갖고 있는 합의 범위
long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = a[start];
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

//start~end : node가 갖고 있는 합의 범위 , left~right : 구해야 하는 합의 범위
long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0; // node가 나타내는 구간 합에 구하고자 하는 합의 범위가 해당하지 않는 경우
	if (left <= start && end<=right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end)
		return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int N, M, K;
long long X;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	vector<long long> arr(N);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1)); // *2
	vector<long long> segmentTree(tree_size);

	for (int i = 0; i < N; i++) {
		cin >> X;
		arr[i] = X;
	}
	init(arr, segmentTree, 1, 0, N - 1); // node 1번부터 시작 (node*2, node*2+1 필요하기 때문)

	for (int i = 0; i < M + K; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			//b번재 수를 c로 바꾸기
			int b;
			long long c;
			cin >> b >> c;
			long long diff = c - arr[b - 1];//5번째 index는 4
			arr[b - 1] = c;
			update(segmentTree, 1, 0, N - 1, b-1, diff);
		}
		else if(a == 2) {
			//b~c의 합을 출력
			int b, c;
			cin >> b >> c;
			cout << sum(segmentTree, 1, 0, N - 1, b - 1, c - 1)<<"\n";
		}
	}
}