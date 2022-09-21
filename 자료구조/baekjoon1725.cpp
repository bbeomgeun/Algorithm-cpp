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
	st.push(0); // stack empty 방지
	for (int i = 1; i <= n + 1; i++) {
		// 인덱스를 스택에 저장해주는데, 만약 현재 갖고 있는 수보다 작은 수가 들어오면 pop해주면서
		// 넓이를 계산해준다.
		// 그 전 단계의 넓이부터 pop 하면서 계산, 따라서 마지막은 n+1(0으로 초기화된 메모리)를 접근하면서
		// 모든 스택을 pop하면서 나머지를 계산하는 구조
		while (!st.empty() && height[st.top()] > height[i]) {
			int cur = st.top();
			st.pop();
			answer = max(answer, height[cur] * (i - st.top() - 1));
		}
		st.push(i);
	}

	cout << answer;
}