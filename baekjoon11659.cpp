#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, arr[100001], sum[100001], from, to, temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		temp += arr[i];
		sum[i] += temp;
	}
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		cout << sum[to] - sum[from - 1] << "\n";
	}
	
}