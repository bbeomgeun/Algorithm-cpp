#include <iostream>
#include <vector>
#define MAX 2000000000

using namespace std;

typedef long long ll;

int n, k, num;
vector<int> v;

bool isOk(ll target) {
	int total = k;
	for (int i = 0; i < v.size(); i++) {
		int cur = v[i];
		if (cur < target) {
			total -= (target - cur);
		}
		if (total < 0)
			return false;
	}
	return true;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	ll l = 0;
	ll r = MAX;
	int answer = 0;

	while (l <= r) {
		ll mid = (l + r) / 2;

		if (isOk(mid)) {
			answer = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << answer;
}