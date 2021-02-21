#include <iostream>
#include <cmath>
using namespace std;

long long n, result, temp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	// ���� ���� : 7�� �������� 0~2(3��������)��ŭ
	// ex : 10�� �������� 10���������� 10���� ������ �� �ڸ����� ������ 10���������̹Ƿ� 10�� �����ָ� ������ ����
	// �� �� ���� 7�� �������� 3���� �����̹Ƿ� 7���� ���� �������� 3���� �����ָ� ������ �����ϴ�.

	int digit = 1;
	while (n) {
		result += (n % 7) * digit;
		n /= 7;
		digit *= 3; // 3���������̹Ƿ� �� ĭ�� 3�� �þ��(0,1,2)
	}

	cout << result;
}