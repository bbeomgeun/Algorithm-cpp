#include <iostream>
#include <vector>
#define MAX 999999000001

using namespace std;

typedef pair<int, pair<int, int>> ppii;
typedef long long ll;

vector<ppii> v;
int n, h_atk, t, a, h;

bool progress(ll target) {
	ll max_hp = target;
	ll cur_hp = target;
	ll temp_atk = h_atk;

	for (int i = 0; i < v.size(); i++) {
		ll status = v[i].first;
		ll attack = v[i].second.first;
		ll hp = v[i].second.second;

		if (status == 1) {
			ll cnt = hp / temp_atk;
			if (hp % temp_atk == 0)
				cnt--;
			ll attackAmount = cnt * attack;
			cur_hp -= attackAmount;
			if (cur_hp <= 0) {
				return false;
			}
		}
		else {
			temp_atk += attack;
			cur_hp += hp;
			if (cur_hp > max_hp) {
				cur_hp = max_hp;
			}
		}
	}
	return true;
}

int main() {
	cin >> n >> h_atk;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> h;
		v.push_back({ t,{a, h} });
	}

	ll l = 1;
	ll r = MAX * n;
	ll answer = 0;

	while (l <= r) {
		ll mid = (l + r) / 2;
		if (progress(mid)) {
			answer = mid;
			r = mid - 1; // 최소의 체력 구하기
		}
		else {
			l = mid + 1; // 체력이 더 필요
		}
	}

	cout << answer;
}