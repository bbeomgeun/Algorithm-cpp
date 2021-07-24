#include <iostream>
#define INF 987654321
using namespace std;

int T1, N, M, W, S, E;
long long arr[501][501], T;

int main() {
	// 음수간선까지 받은 후 플로이드 와샬을 돌리고, arr[i][i] (자기자신)으로 돌아오는 가중치값이
	// 음수이면 yes 아님 no
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T1;
	for (int t = 0; t < T1; t++) {
		cin >> N >> M >> W;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = INF;
			}
		}

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			arr[S][E] = min(arr[S][E], T);
			arr[E][S] = min(arr[S][E], T);
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			arr[S][E] = min(arr[S][E], -T);
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
		int flag = false;

		for (int i = 1; i <= N; i++) {
			if (arr[i][i] < 0) { // 자기자신으로 돌아오는 값이 음수인지 체크
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}