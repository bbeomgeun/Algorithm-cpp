#include <iostream>
using namespace std;

int N, M, arr[8]; //1~N까지 M개 고른 수열
bool check[8];


void backTracking(int n, int m, int depth) {
	if (depth == m) {
		for (int i = 0; i <m ; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
			arr[depth] = i;
			backTracking(n, m, depth + 1);
	}
}

int main() {
	cin >> N >> M;
	backTracking(N,M,0);
}