#include <iostream>
#include <algorithm>

using namespace std;

int N, K, answer;
int dp[101][100001], arr[101][2];

int main() {
	cin >> N >> K; // 물품의 수, 버틸 수 있는 무게
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1]; // 각 무게, 가치
	}

	for (int i = 1; i <= N; i++) { // 물품의 수 차례로(index 0번부터 n-1까지)
		for (int j = 0; j <= K; j++) { // 무게올리면서
			if (arr[i][0] <= j) { // 만약 무게가 okay
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i][0]] + arr[i][1]); // 같은 무게에서 물건을 가져오기전과, 무게만큼 더해진 값 중 최대
			}
			else { // i번째 무게 안될경우 i-1로 구성한 최적의 값 가져오기
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[N][K];
}
///////////////////////////////////////////////
#include <iostream>

using namespace std;

int dp[100001], bag[101], weight[101];
int N, K;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> weight[i] >> bag[i];

		for (int t = K; t >= weight[i]; t--) {
			dp[t] = max(dp[t - weight[i]] + bag[i], dp[t]);
		}
	}
	cout << dp[K];
}

