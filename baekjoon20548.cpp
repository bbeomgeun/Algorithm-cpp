#include <iostream>
#include <cmath>
using namespace std;

long long n, result, temp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	// 수의 구성 : 7의 제곱수로 0~2(3진수형식)만큼
	// ex : 10의 제곱수로 10진수형식은 10으로 나누면 각 자릿수가 나오고 10진수형식이므로 10을 곱해주면 복원이 가능
	// 즉 이 수는 7의 제곱수로 3진수 형식이므로 7으로 나눈 나머지를 3으로 곱해주면 복원이 가능하다.

	int digit = 1;
	while (n) {
		result += (n % 7) * digit;
		n /= 7;
		digit *= 3; // 3진수형식이므로 한 칸당 3씩 늘어난다(0,1,2)
	}

	cout << result;
}