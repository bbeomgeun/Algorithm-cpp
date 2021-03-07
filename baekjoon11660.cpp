#include <iostream>

using namespace std;

int N, M,a, b, c, d;
int arr[1025][1025];
int dp[1025][1025];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin>>arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j-1] + arr[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int result = 0;
		cin >> a>> b>>c>> d;

		for (int i = a; i <= c; i++) {
			result += (dp[i][d] - dp[i][b - 1]);
		}
		cout << result << "\n";
	}

}
/////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int N,M, x, y, x2, y2;
int arr[1025][1025], dp[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N>>M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> x2 >> y2;
		int result = dp[x2][y2] - dp[x - 1][y2] - dp[x2][y - 1] + dp[x - 1][y - 1];
		cout << result << "\n";
	}
}
