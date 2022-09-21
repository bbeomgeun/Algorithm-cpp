// 숫자 내부를 오림차순으로 정렬하는 문제
// 당연히 숫자를 한자리씩 뺀 다음, 배열에 저장하고, 정렬하는 생각을 했다
// 풀면서도 훨씬 쉽게 풀수 있는 방법이 있을 것같아서 찾아보았더니 String에 저장하고 내부 sort함수를 이용해서 5줄만에 풀었다.


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

