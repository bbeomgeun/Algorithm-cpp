// �����佺�׳׽��� ü

#include <iostream>
using namespace std;
int N, K, arr[1001], cnt, result;
//���������� ���� 0���� �ʱ�ȭ
int main() {
	cin >> N >> K; // n������ ������ k���� ������ ��(�Ҽ��� �ƴ� ��)

	for (int i = 2; i <= N; i++) { 
		for (int j = i; j <= N; j += i) { 
			if (arr[j] == 0) {
				cnt++;
				arr[j] = 1;
			} // 2���� �����ؼ� �ش��ϴ� ���� �����ŭ ���� �����ش�(1�� �ٲ۴�)
			if (cnt == K) {
				result = j;
				break;
			} // �������� ���� ������ ��ġ �� �ݺ��� break.
		}
		if (cnt == K) {
			break;
		}
	}
	cout << result;
}