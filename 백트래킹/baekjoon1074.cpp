#include <iostream>
#include <cmath>
using namespace std;

int N,r, c, answer;

void recursive(int h, int x, int y) {
	if (x == r && y == c) {
		cout << answer << "\n";
		return;
	}

	if (r > x + h - 1 || c > y + h - 1 || r < x || c < y){
		answer += h * h;
		return;
	}

	recursive(h / 2, x, y);
	recursive(h / 2, x, y + h / 2);
	recursive(h / 2, x + h / 2, y);
	recursive(h / 2, x + h / 2, y + h / 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> r >> c;
	recursive(pow(2,N), 0, 0);
}