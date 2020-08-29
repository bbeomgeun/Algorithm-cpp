#include <iostream>
#include <algorithm>

using namespace std;

int N, input, arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}

// ���������� for�� ������ Ǯ�� ���� �����ؾ� �� ���� �ִ�. ����� ����� ������ ���� ���� �Է¹ްų� ����� �� �ð��ʰ��� �� �� �ִٴ� ���̴�.
// C++�� ����ϰ� �ְ� cin / cout�� ����ϰ��� �Ѵٸ�, cin.tie(NULL)�� sync_with_stdio(false)�� �� �� ������ �ְ�,
// endl ��� ���๮��(\n)�� ����.��, �̷��� �ϸ� �� �̻� scanf / printf / puts / getchar / putchar �� C�� ����� ����� ����ϸ� �� �ȴ�.