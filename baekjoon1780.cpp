#include <iostream>
#include <cmath>
using namespace std;

int N, paper[2188][2188], c1, c2, c3;

void divideSearch(int i, int j, int size) {
	int temp1 = 0;
	int temp2= 0;
	int temp3= 0;
	for (int col = i; col < i+ size; col++) {
		for (int row = j; row < j+ size; row++) {
			if (paper[col][row] == -1) {
				temp1++;
			}
			else if (paper[col][row] == 0) {
				temp2++;
			}
			else {
				temp3++;
			}
		}
	}
	if(temp1 == size*size){
		c1++;
		return;
	}
	else if (temp2 == size * size) {
		c2++;
		return;
	}
	else if(temp3 == size * size){
		c3++;
		return;
	}
	else {
		int tempSize = size / 3;
		for (int col = 0; col < size; col += tempSize) {
			for (int row = 0; row < size; row += tempSize) {
				divideSearch(i + col, j + row, tempSize);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	divideSearch(0, 0, N);
	cout << c1 << "\n" << c2 << "\n" << c3;
}