#include <iostream>
#define INF 1000000010
using namespace std;

int N, M, K;
int cache[101][101];
string answer;

int getAZ(int a, int z) {
	if (a == 0 || z == 0)
		return 1;
	if (cache[a][z] != -1)
		return cache[a][z];
	else {
		cache[a][z] = getAZ(a - 1, z) + getAZ(a, z - 1);
		if (cache[a][z] >= INF)
			cache[a][z] = INF;
		return cache[a][z];
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			cache[i][j] = -1;
		}
	}
	if (getAZ(N, M) < K) { // k��°���� ���� ����� ���� ���� ��� k��° ���� �Ұ�
		cout << -1;
		return 0;
	}
	// ���� �����
	int countA = N, countZ = M;

	for (int i = 0; i < N + M; i++) { // a�� z�� ������ŭ ���ڿ��� ����µ�
		if (countA > 0) {
			int tmp = getAZ(countA - 1, countZ); // a�ϳ� ����ϰ� ������ ����
			if (tmp < K) { // ���� 5000��° ã�µ� a���� ��� 1000���ۿ� �ȳ��´� 1000<5000
				answer += 'z'; // a���̸� ���� ã�� �������� �۱� ������ z�� ���̰� ���� �ܰ��
				K -= tmp;
				countZ--;
			}
			else { // ���� �ȿ� �ִٸ� a���̱�
				answer += 'a';
				countA--;
			}
		}
		else { // ����� a������ ���ٸ� for�����鼭 ������ �ڸ����� ��� z�� ä���
			answer += 'z';
		}
	}
	cout << answer;
}