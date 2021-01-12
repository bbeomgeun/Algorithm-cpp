#include <iostream>
#include <bitset>

using namespace std;

string s;
int n, x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned int data = 0x00000;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			x = x - 1;
			data = data | (1 << x);
		}
		else if (s == "remove") {
			cin >> x;
			x = x - 1;
			data = data & ~(1 << x);
		}
		else if (s == "check") {
			cin >> x;
			x = x - 1;
			if ((data & (1 << x)))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> x;
			x = x - 1;
			if (!(data & (1 << x))) {
				data = data | (1 << x);
			}
			else
				data = data & ~(1 << x);
		}
		else if (s == "all") {
			data = 0xFFFFF;
		}
		else if (s == "empty") {
			data = 0x00000;
		}
	}
}