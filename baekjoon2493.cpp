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
		while (!result.empty()) { // 값이 있는 경우
			if (result.top().second > height) { // 만약 입력값보다 크다면
				cout << result.top().first << " "; // index 출력
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