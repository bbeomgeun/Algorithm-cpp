#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int N, M, a, b;
int tree[2001];
vector<pii> v;

void update(int index, int value) {
	while (index <= N) {
		tree[index] += value;
		index += (index & -index); // �ش� ������ ������Ʈ
	}
}

int query(int index) { 
	int result = 0;
	while (index) {
		result += tree[index];
		index -= (index & -index);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long answer = 0; // ���� 2�鸸��, �Ź� ��ġ�� �̹鸸*�鸸
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	for (auto k : v) {
		answer += (query(N) - query(k.second));
		update(k.second, 1);
	}
	cout << answer;
}