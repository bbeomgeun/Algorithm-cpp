// ���� ���θ� ������������ �����ϴ� ����
// �翬�� ���ڸ� ���ڸ��� �� ����, �迭�� �����ϰ�, �����ϴ� ������ �ߴ�
// Ǯ�鼭�� �ξ� ���� Ǯ�� �ִ� ����� ���� �Ͱ��Ƽ� ã�ƺ��Ҵ��� String�� �����ϰ� ���� sort�Լ��� �̿��ؼ� 5�ٸ��� Ǯ����.


#include <iostream>
using namespace std;

int N, result, arr[10], cnt;

int main() {
	cin >> N;
	for (int i = N; i > 0; ) {
		result = i % 10;
		i = i / 10;
		arr[cnt] = result;
		cnt += 1;
	}

	for (int i = 0; i < cnt; i++) {
		int max = i;
		for (int j = i; j < cnt; j++) {
			if (arr[max] < arr[j])
				max = j ;
		}
		int temp = arr[max];
		arr[max] = arr[ i ];
		arr[i] = temp;
	}

	for (int i = 0; i < cnt; i++)
		cout << arr[i];
}
////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string N;
	cin >> N;

	sort(N.begin(), N.end());
	reverse(N.begin(), N.end());
	cout << N;
}

