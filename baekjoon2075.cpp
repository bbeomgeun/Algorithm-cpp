#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
// greater -> �������� = �ּ���
int N, num;

// �޸� ������ 4MB�̴�. ���� ��� ���� �Է¹޾� �����ϴ� ����� �޸� �ʰ��� �� ���̰�
// �켱����ť�� �̿��Ͽ� NlogN���� �Է¹ް� n�� �̿��� ���� pop�ϴ� ������� �����Ѵ�.
// pq���� �׻� N���� ���� ����Ǿ� �ְ� ��� ���� ��ġ�� ���� �ּ����� front�� n��° ū ���� �ȴ�.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			pq.push(num);
		}
		while (pq.size() != N) {
			pq.pop();
		}
	}
	cout << pq.top();
}
