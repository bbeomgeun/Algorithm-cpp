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
	if (getAZ(N, M) < K) { // k번째보다 적은 경우의 수가 나올 경우 k번째 열람 불가
		cout << -1;
		return 0;
	}
	// 문자 만들기
	int countA = N, countZ = M;

	for (int i = 0; i < N + M; i++) { // a와 z의 갯수만큼 문자열을 만드는데
		if (countA > 0) {
			int tmp = getAZ(countA - 1, countZ); // a하나 사용하고 나머지 갯수
			if (tmp < K) { // 나는 5000번째 찾는데 a붙인 경우 1000개밖에 안나온다 1000<5000
				answer += 'z'; // a붙이면 내가 찾는 범위보다 작기 때문에 z를 붙이고 다음 단계로
				K -= tmp;
				countZ--;
			}
			else { // 범위 안에 있다면 a붙이기
				answer += 'a';
				countA--;
			}
		}
		else { // 사용할 a갯수가 없다면 for문돌면서 나머지 자리수를 모두 z로 채우기
			answer += 'z';
		}
	}
	cout << answer;
}