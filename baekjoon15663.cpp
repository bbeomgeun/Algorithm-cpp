#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int> v;
int buffer[8], check[8];

void recur(int depth) {
	if (depth == M) {
		for (int i = 0; i < depth; i++) {
			cout << buffer[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		int prev = 0; // 이번 depth를 채우는 과정에서 중복된 숫자를 또 생성하지 않는다
		// 정렬되어있으므로 두번째 자리에 9를 채웠는데 다음에 또 9가 나오면 그냥 pass
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