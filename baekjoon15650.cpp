#include <iostream>
using namespace std;

int N, M, cArr[8];

void print() {
	for (int i = 0; i < M; i++) {
		cout << cArr[i] << " ";
	}
}

void Combination(int depth, int next) {
	if (depth == M) {
		print();
		cout << "\n";
	}
	for (int i = next; i <= N; i++) {
			cArr[depth] = i;
			Combination(depth + 1, i + 1);
		}
}

int main() {
	cin >> N >> M;
	Combination(0, 1);
}