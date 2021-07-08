#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, K, M, V, C;
priority_queue<int, vector<int>, greater<int>> bag;
priority_queue<pii, vector<pii>, greater<pii>> jam;
priority_queue<int> temp;
//����, ���� �������� ����
// ������ ũ������� ���鼭 ���� ũ�⿡ ���� �� �ִ� ���� ������ ������ �ֱ�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> M >> V; // ����, ��ġ
		jam.push(make_pair(M, V));
	}
	for (int i = 0; i < K; i++) {
		cin >> C;
		bag.push(C);
	}

	long long answer = 0;

	while (!bag.empty()) { // ������ ��� ����Ҷ�����
		int limit = bag.top();
		while (!jam.empty() && jam.top().first <= limit) { //���濡 ���� �� �ִ� �͵��� 
			temp.push(jam.top().second); // ������ ���� �� ��ġ ������
			jam.pop();
		}
		if (!temp.empty()) { // ���濡 ���� ������ ���� ��� ���� ��� x
			answer += temp.top(); // ��ġ ���� ���� �� pick
			temp.pop();
		}
		bag.pop();
	}
	cout << answer;
	return 0;
}