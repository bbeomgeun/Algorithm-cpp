#include <iostream>
#include <algorithm>

using namespace std;

string A, B;
int flag = false;

// ��ǥ�� ���������� ��ǥ�� ������ �ٲٸ鼭 �������� �� �� �ִ��� �׸����ϰ� ��������

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