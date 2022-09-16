#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int r, c;
string s;
vector<string> v, reverseV;

bool isDuplicate(int index) {
	unordered_set<string> record;
	for (int i = 0; i < c; i++) {
		string cur = reverseV[i].substr(index, reverseV[i].size());
		if (record.find(cur) != record.end()) {
			return true;
		}
		record.insert(cur);
	}
	return false;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < c; i++) {
		string temp = "";
		for (int j = 0; j < r; j++) {
			temp += v[j][i];
		}
		reverseV.push_back(temp);
	}

	int L = 1;
	int R = r;
	int answer = 0;

	while (L <= R) {
		int mid = (L + R) / 2;

		if (isDuplicate(mid)) { // 중복이면 위로 올라간다
			answer = mid - 1;
			R = mid - 1;
		}
		else { // 중복이 아니면 밑으로 내려간다
			L = mid + 1;
		}
	}

	cout << answer;

}