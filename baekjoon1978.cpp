#include <iostream>

using namespace std;

bool check[1001];
int N, num, cnt;
int main() {
	cin >> N;
	check[1] = true;
	for (int i = 2; i < 1001; i++) {
		if (!check[i]) {
			int k = i;
			while (k * i < 1001) {
				check[k * i] = true;
				k = k + 1;
			}
		}
	} 
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (!check[num])
			cnt++;
	}
	cout << cnt;
}