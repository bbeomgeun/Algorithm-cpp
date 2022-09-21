#include <iostream>
#include <string>

using namespace std;

string input, key;

int main() {
	getline(cin, input);
	getline(cin, key);

	int keylen = key.size();
	for (int i = 0; i < keylen; i++) {
		key[i] = key[i] - 96; // 아스키코드에서 96만큼 빼서 실제 알파벳순서
	}

	for (int i = 0; i<input.size() ; i++) {
			if (input[i] >= 97 && input[i] <= 123) { // 공백 제외
				if (input[i] - key[i % keylen] >= 97) { // 알파벳을 벗어나지않는 경우
					input[i] = input[i] - key[i % keylen];
				}
				else { // 벗어날 경우 26만큼 알파벳 한 사이클 더해주기
					input[i] = input[i] - key[i % keylen] + 26;
				}
			}
			else {
				input[i] = 32; // 공백
			}
		}
	for (int i = 0; i<input.size() ; i++) {
			cout <<input[i];
	}
}