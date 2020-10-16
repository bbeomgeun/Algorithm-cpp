#include <iostream>
using namespace std;


int N, cnt;

int main() {
	cin >> N;
	while (N > 0) {
		if (N % 5 == 0) {
			N -= 5;
			cnt += 1;
		}
		else if (N % 3 == 0) {
			N -= 3;
			cnt += 1;
		}
		else if (N > 5) {
			N -= 5;
			cnt += 1;
		}
		else {
			cnt = -1;
			break;
		}
	}
	cout << cnt;
}
