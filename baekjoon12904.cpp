#include <iostream>
#include <algorithm>

using namespace std;

string A, B;
int flag = false;

// 목표를 만들어가지말고 목표를 역으로 바꾸면서 시작점이 될 수 있는지 그리디하게 접근하자

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	
	while (B.size() > 0) {
		if (B.back() == 'B') {
			B.erase(B.end() - 1);
			reverse(B.begin(), B.end());
		}
		else
			B.erase(B.end() - 1);

		if (B == A) {
			flag = true;
			break;
		}
	}

	if (flag)
		cout << 1;
	else
		cout << 0;
}