#include <iostream>

using namespace std;

int N, M, win, lose;

int arr[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> win >> lose;
        arr[win][lose] = 1;
        arr[lose][win] = -1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][k] == 1 && arr[k][j] == 1 && arr[i][j] == 0) {
                    arr[i][j] = 1;
                    arr[j][i] = -1;
                }
                if (arr[i][k] == -1 && arr[k][j] == -1 && arr[i][j] == 0) {
                    arr[i][j] = -1;
                    arr[j][i] = 1;
                }
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        int result = 0;
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] != 0) {
                result++;
            }
        }
        if (result == N - 1)
            answer++;
    }
	cout << answer;
}
