// 에라토스테네스의 체

#include <iostream>
using namespace std;
int N, K, arr[1001], cnt, result;
//전역변수를 통해 0으로 초기화
int main() {
	cin >> N >> K; // n까지의 정수와 k번쨰 지워질 수(소수가 아닌 수)

	for (int i = 2; i <= N; i++) { 
		for (int j = i; j <= N; j += i) { 
			if (arr[j] == 0) {
				cnt++;
				arr[j] = 1;
			} // 2부터 진행해서 해당하는 수의 배수만큼 세며 지워준다(1로 바꾼다)
			if (cnt == K) {
				result = j;
				break;
			} // 지워지는 수의 갯수와 일치 시 반복문 break.
		}
		if (cnt == K) {
			break;
		}
	}
	cout << result;
}