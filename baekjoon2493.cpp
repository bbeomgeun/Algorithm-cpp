#include <iostream>
#include <stack>
using namespace std;

int N, height, top;
stack<pair<int, int>> result;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> height;
		while (!result.empty()) { // ���� �ִ� ���
			if (result.top().second > height) { // ���� �Է°����� ũ�ٸ�
				cout << result.top().first << " "; // index ���
				break;
			}
			else
				result.pop();
		}
		if (result.empty()) {
			cout << "0" << " ";
		}
		result.push(make_pair(i, height));
	}
	return 0;
}