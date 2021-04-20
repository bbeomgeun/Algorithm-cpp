#include <iostream>

using namespace std;

pair<int, string> arr[1001][1001];
string s1, s2;

int main() {
	cin >> s1 >> s2;

	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s1[j - 1] == s2[i - 1]) {
				arr[i][j].first = arr[i - 1][j - 1].first+1;
				arr[i][j].second = arr[i - 1][j - 1].second + s1[j - 1];
			}
			else {
				if (arr[i][j - 1].first >= arr[i - 1][j].first) {
					arr[i][j].first = arr[i][j - 1].first;
					arr[i][j].second = arr[i][j - 1].second;
				}
				else {
					arr[i][j].first = arr[i - 1][j].first;
					arr[i][j].second = arr[i - 1][j].second;
				}
			}
		}
	}
	cout << arr[s2.size()][s1.size()].first << "\n";
	cout << arr[s2.size()][s1.size()].second;

}