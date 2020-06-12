/* 200612 baekjoon1065번
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
입력 : 1~1000;
*/

#include <iostream>

using namespace std;

int func(int inputNumber);

int main() {
	int Number = 0;
	cin >> Number;
	cout<< func(Number);
}

int func(int inputNumber) {
	int count = 0;
	int oneth, tenth, hundredth;
	if (inputNumber < 100) { //십의자리까지는 등차수열이 성립(1~99)
		for (int i = 0; i < inputNumber; i++)
			count++;
	}
	else { // 백의 자리 숫자의 경우
		for (inputNumber; inputNumber > 99; inputNumber--) {
			hundredth = inputNumber / 100; // 백의자리수를 100으로 나눈 몫 =>백의 자리
			tenth = ((inputNumber) % 100) / 10; // 백의자리수를 100으로 나눈 나머지=>십의 자리수 , 십의 자리수를 10으로 나눈 몫=>십의 자리
			oneth = ((inputNumber) % 100) % 10;//십의자리수에서 10으로 나눈 나머지 => 일의 자리
			if ((hundredth - tenth) == (tenth - oneth))
				count++;
		}
		count += 99;
	}
	return count;
}