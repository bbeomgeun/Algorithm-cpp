#include <iostream>

using namespace std;

int arr[129][129];
int N, value, blueCnt, whiteCnt;
//1 = blue, 0 white
void square(int i, int j, int size) {
	int whiteflag = false;
	int blueflag = false;
	for (int row = i; row < i + size; row++) {
		for (int col = j; col < j + size; col++) {
			if (arr[row][col])
				blueflag = true;
			else if (!arr[row][col])
				whiteflag = true;
		}
	}
	if (blueflag && !whiteflag) {
		blueCnt++;
		return;
	}
	else if (!blueflag && whiteflag) {
		whiteCnt++;
		return;
	}
	else {
		square(i, j, size / 2);
		square(i + size / 2, j, size / 2);
		square(i, j + size / 2, size / 2);
		square(i+ size / 2, j+ size / 2, size / 2);
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	square(0, 0, N);

	cout << whiteCnt << "\n" << blueCnt;
}