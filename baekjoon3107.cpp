#include <iostream>

using namespace std;

string s, answer;
string zero[5] = { "","0", "00", "000", "0000" };
int totalClone, clone;

int main() {
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':')
			totalClone++;
	}
	string temp = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			temp = zero[4 - temp.size()] + temp;
			temp += ':';
			answer += temp;
			temp = "";
			if (s[i + 1] == ':') {
				clone = 8 - totalClone;
				for (int j = 0; j < clone; j++) {
					answer += zero[4];
					answer += ':';
				}
				i++;
			}
		}
		else {
			temp += s[i];
		}
	}
	temp = zero[4 - temp.size()] + temp;
	answer += temp;

	cout << answer;
}