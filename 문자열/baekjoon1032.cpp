#include <iostream>
#include<string>
#include <string.h>

using namespace std;

int N, status;
char list[51][51];
string result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	int input = strlen(list[0]);

	for (int i = 0; i < input; i++) {
		status = 0;
		for (int j = 0; j < N-1; j++) {
			if(list[j][i] != list[j+1][i]){
				status = 1;
				break;
			}
		}
		if (status == 0) {
			result += list[0][i];
		}
		else if (status == 1) {
			result += "?";
		}
	}
	cout << result;
}
