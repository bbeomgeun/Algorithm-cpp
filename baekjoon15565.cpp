#include <iostream>
#define INF 987654321

using namespace std;

int N, K, arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int l = 0, r = 0, cnt = 0, len = INF, sum = 0, temp = 0;

	// 투포인터
	// 조건보다 클때, 작을때, 같을때
	// 조건 미 충족시 오른쪽포인터, 충족하면 로직 처리, 과충족시 왼쪽포인터

	while (l <= r && r <= N) {
		if (cnt < K) {
			if (arr[r] == 1) {
				cnt++;
			}
			r++;
		}
		else if (cnt > K) {
			if (arr[l] == 1) {
				cnt--;
			}
			l++;
		}
		else if (cnt == K) {
			len = min(len, r - l);
			if (arr[l] == 1) {
				cnt--;
			}
			l++;
		}
	}

	if (len == INF)
		cout << -1;
	else
		cout << len;
}