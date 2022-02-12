#include <iostream>

using namespace std;

int n, a, b, cur;

int main() {
	cin >> n;

	cur = 1;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == cur) {
			cur = b;
		}
		else if(b == cur){
			cur = a;
		}
	}
	cout << cur;
}