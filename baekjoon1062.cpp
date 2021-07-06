#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K, answer;
vector<string> stringList;
string s;
int check[26];

void combination(int idx, int depth) {
	if (depth == K) {
		int tempAnswer = 0;
		for (int i = 0; i < stringList.size(); i++) {
			bool canRead = true;
			for (int j = 0; j < stringList[i].size(); j++) {
				char target = stringList[i][j];
				if (check[target - 'a'])
					continue;
				else {
					canRead = false;
					break;
				}
			}
			if (canRead)
				tempAnswer++;
		}
		answer = max(answer, tempAnswer);
	}
	else {
		for (int i = idx; i < 26; i++) {
			if (!check[i]) {
				check[i] = true;
				combination(i, depth + 1);
				check[i] = false;
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// 무조건 antic 5글자는 알려줘야 한다.
	cin >> N >> K;
	if (K < 5) {
		cout << 0;
		return 0;
	}
	else {
		K = K - 5;
		for (int i = 0; i < N; i++) {
			cin >> s;
			stringList.push_back(s);
		}

		check['a' - 'a'] = true;
		check['n' - 'a'] = true;
		check['t' - 'a'] = true;
		check['i' - 'a'] = true;
		check['c' - 'a'] = true;

		combination(0, 0);
	}
	cout << answer;
}