#include <iostream>
#include <algorithm>

using namespace std;

int N, K, answer;
int dp[101][100001], arr[101][2];

int main() {
	cin >> N >> K; // ��ǰ�� ��, ��ƿ �� �ִ� ����
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1]; // �� ����, ��ġ
	}

	for (int i = 1; i <= N; i++) { // ��ǰ�� �� ���ʷ�(index 0������ n-1����)
		for (int j = 0; j <= K; j++) { // ���Կø��鼭
			if (arr[i][0] <= j) { // ���� ���԰� okay
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i][0]] + arr[i][1]); // ���� ���Կ��� ������ ������������, ���Ը�ŭ ������ �� �� �ִ�
			}
			else { // i��° ���� �ȵɰ�� i-1�� ������ ������ �� ��������
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

