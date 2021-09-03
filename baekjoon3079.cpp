#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll N, M,num;
vector<int> v;
// �Ű����� Ž������ ���� �ð��� �� ��⿭�� ��뷮�� �̿��ؼ� ���Ѵ�.
// �����ð� / ��뷮�ϸ� �ð� ���� �� �ڸ��� �� ���� ���� �� �ִ��� ��� ���� ���� �� �ִ�.
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

		if (cnt >= M) { // ����ϹǷ� �ð��� �ٿ����Ѵ�.
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << start;
}