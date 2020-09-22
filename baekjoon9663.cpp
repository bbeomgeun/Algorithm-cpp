#include <iostream>
using namespace std;

int pArr[8], N,M;
bool check[9];

void permutation(int depth) {
	if (depth == M) {				//depth�� �ڸ��� �迭 ��ĭ�� �÷�����
		for (int i = 0; i < M; i++) {
			cout << pArr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) { // 1~N���� ���ư��鼭 ���� check
		if (!check[i]) {
			check[i] = true;
			pArr[depth] = i;
			permutation(depth + 1);
			check[i] = false;
		}
	}
}


int main() {
	cin >> N >> M;
	permutation(0);
	return 0;
}