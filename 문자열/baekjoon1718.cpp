#include <iostream>
#include <string>

using namespace std;

string input, key;

int main() {
	getline(cin, input);
	getline(cin, key);

	int keylen = key.size();
	for (int i = 0; i < keylen; i++) {
		key[i] = key[i] - 96; // �ƽ�Ű�ڵ忡�� 96��ŭ ���� ���� ���ĺ�����
	}

	for (int i = 0; i<input.size() ; i++) {
			if (input[i] >= 97 && input[i] <= 123) { // ���� ����
				if (input[i] - key[i % keylen] >= 97) { // ���ĺ��� ������ʴ� ���
					input[i] = input[i] - key[i % keylen];
				}
				else { // ��� ��� 26��ŭ ���ĺ� �� ����Ŭ �����ֱ�
					input[i] = input[i] - key[i % keylen] + 26;
				}
			}
			else {
				input[i] = 32; // ����
			}
		}
	for (int i = 0; i<input.size() ; i++) {
			cout <<input[i];
	}
}