#include <iostream>
#include <string>

using namespace std;

string vowels = "aiyeou";
string bigVowels = "AIYEOU";
string nonVowels = "bkxznhdcwgpvjqtsrlmf";

string s, answer;


int main() {
	while(getline(cin, s)){
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				if (vowels.find(s[i]) != string::npos) {
					if (vowels.find(s[i])  < 3)
						answer += vowels[vowels.find(s[i]) - 3 + vowels.size()];
					else
						answer += vowels[vowels.find(s[i]) - 3];
				}
				else if (nonVowels.find(s[i]) != string::npos) {
					if (nonVowels.find(s[i]) < 10)
						answer += nonVowels[nonVowels.find(s[i]) - 10 + nonVowels.size()];
					else
						answer += nonVowels[nonVowels.find(s[i]) - 10];
				}
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				if (bigVowels.find(s[i]) != string::npos) {
					if (bigVowels.find(s[i])< 3)
						answer += bigVowels[bigVowels.find(s[i]) - 3 + bigVowels.size()];
					else
						answer += bigVowels[bigVowels.find(s[i]) - 3];
				}
				else {
					if (nonVowels.find(s[i]+32)  < 10)
						answer += nonVowels[nonVowels.find(s[i]) - 10 + nonVowels.size()] - 32;
					else
						answer += nonVowels[nonVowels.find(s[i]) - 10] - 32;
				}
			}
			else {
				answer += s[i];
			}
		}
		answer += '\n';
	}
	cout << answer;
}