#include <iostream>

using namespace std;

int n, answer, carr[16];

void queen(int y) { // y�� ���� ���Ѵ�.

	if (y == n ) { //���������� n�� �ش��ϸ� ����
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) { 
		carr[y] = i; // �ش� ���� �� ������ 1~n���� �־��
		int flag = true;
		for (int j = 0; j < y; j++) { // ù��°���� y��° ������ ���غ���
			if (carr[y] == carr[j] || abs(carr[y] - carr[j]) == y - j) // ��) 3��°���̸� 1,2��° ������ ������ ���Ѵ�. 1��°�� 3��, 3��°�� 3���̸� ����
				flag = false;
		}
		if(flag) // ���� �̹� �� carr[y] = i�� �������� ���� ����� �Ȱ�ġ�� ���� ���� ����.
			queen(y + 1);
	}
}

int main() {
	cin >> n;
	queen(0);
	cout << answer;
}
