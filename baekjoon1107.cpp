#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX 1000000

using namespace std;

int check[10], target, n, num, arr[10], answer;
vector<int> possible;

void backTracking(int depth, int limit) {
	if (depth == limit+2)
		return;
	if (depth > 0) {
		int temp = 0;
		for (int i = 0; i < depth; i++) {
			temp = temp * 10 + arr[i];
		}
		string k = to_string(temp);
		int result = abs(target - temp) + k.size();
		answer = min(answer, result);
	}

	for (int i = 0; i < possible.size(); i++) {
		int p = possible[i];
		arr[depth] = p;
		backTracking(depth + 1, limit);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> target >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		check[num] = true;
	}
	for (int i = 0; i < 10; i++) {
		if (!check[i])
			possible.push_back(i);
	}

	int t = target;
	int cnt = 0;
	while (t) {
		cnt++;
		t /= 10;
	}

	answer = abs(target - 100);

	backTracking(0, cnt);
	
	cout << answer;
}