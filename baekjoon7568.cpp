#include <iostream>
using namespace std;

int N, arr[51][2], cnt[51];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < N; i++) {
		int count = 1;
		for (int j = 0; j < N ; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				count++;
		}
		cnt[i] = count;
	}
	
	for (int i = 0; i < N; i++)
		cout << cnt[i] << " ";
}