#include <iostream>

using namespace std;

int n, answer, carr[16];

void queen(int y) { // y는 열을 뜻한다.

	if (y == n ) { //정상적으로 n에 해당하면 정답
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) { 
		carr[y] = i; // 해당 열의 행 정보에 1~n까지 넣어본다
		int flag = true;
		for (int j = 0; j < y; j++) { // 첫번째부터 y번째 열까지 비교해본다
			if (carr[y] == carr[j] || abs(carr[y] - carr[j]) == y - j) // 예) 3번째열이면 1,2번째 열들의 정보와 비교한다. 1번째에 3열, 3번째에 3열이면 오답
				flag = false;
		}
		if(flag) // 만약 이번 열 carr[y] = i의 행정보가 위의 열들과 안겹치면 다음 열로 간다.
			queen(y + 1);
	}
}

int main() {
	cin >> n;
	queen(0);
	cout << answer;
}
