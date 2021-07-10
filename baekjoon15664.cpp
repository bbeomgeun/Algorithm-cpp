#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int> v;
int buffer[8], check[8];

void recur(int depth) {
	if (depth == M) {
		for (int i = 0; i < M - 1; i++) {
			if (buffer[i] > buffer[i + 1])
				return;
		}
		for (int i = 0; i < depth; i++) {
			cout << buffer[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		int prev = 0;
		for (int i = 0; i < N; i++) {
			if (!check[i] && prev != v[i]) {
				check[i] = true;
				prev = v[i];
				buffer[depth] = v[i];
				recur(depth + 1);
				check[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	recur(0);
	
}