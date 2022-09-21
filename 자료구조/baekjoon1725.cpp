#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> st;
int n, height[100002], answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}
	st.push(0); // stack empty ����
	for (int i = 1; i <= n + 1; i++) {
		// �ε����� ���ÿ� �������ִµ�, ���� ���� ���� �ִ� ������ ���� ���� ������ pop���ָ鼭
		// ���̸� ������ش�.
		// �� �� �ܰ��� ���̺��� pop �ϸ鼭 ���, ���� �������� n+1(0���� �ʱ�ȭ�� �޸�)�� �����ϸ鼭
		// ��� ������ pop�ϸ鼭 �������� ����ϴ� ����
		while (!st.empty() && height[st.top()] > height[i]) {
			int cur = st.top();
			st.pop();
			answer = max(answer, height[cur] * (i - st.top() - 1));
		}
		st.push(i);
	}

	cout << answer;
}