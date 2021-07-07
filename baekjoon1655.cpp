#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;

int n, num;

// minpq�� maxpq �ΰ��� �̿��ؼ� ��� ���� �����Ѵ�.
// �׻� top�� minpq�� top�� �� ũ�� �迭 ������ �߰��������� maxpq�� �ְ� �� �ܴ� minpq�� �ִ� ��Ŀ����
// �׷��� ���ĵ� ������ �Է¹��� ���� �ּڰ� ~ �߰����� maxpq�̹Ƿ� �� �߿��� �߰����� ���� ũ�Ƿ� maxpq�� top�� �ȴ�.
// �� ���� ������ �߰���+1 ~ �ִ��� minpq�� ���ְ� ���� minpq�� top�� maxpq���� �� ������
// 10 20 40 30 50 ���� 40�� 30�� ���� ����̹Ƿ� ���� top���� �ٲ��ش�.

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (min_pq.size() == max_pq.size()) {
			max_pq.push(num);
		}
		else {
			min_pq.push(num);
		}
		if (!max_pq.empty() && !min_pq.empty() && min_pq.top() < max_pq.top()) {
			int tempValue = min_pq.top();
			min_pq.pop();
			min_pq.push(max_pq.top());
			max_pq.pop();
			max_pq.push(tempValue);
		}
		cout << max_pq.top()<<"\n";

	}
}