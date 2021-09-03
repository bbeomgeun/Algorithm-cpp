#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll N, M,num;
vector<int> v;
// 매개변수 탐색으로 최종 시간을 각 대기열의 사용량을 이용해서 구한다.
// 최종시간 / 사용량하면 시간 동안 그 자리에 몇 명이 앉을 수 있는지 사람 수를 구할 수 있다.
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	ll start = 1, end =v.back() * M;

	while (start <= end) {
		ll mid = (start + end) / 2;
		ll cnt = 0;

		for (int i = 0; i < v.size(); i++) {
			cnt += mid / v[i];
			if (cnt > M)
				break;
		}

		if (cnt >= M) { // 충분하므로 시간을 줄여야한다.
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << start;
}