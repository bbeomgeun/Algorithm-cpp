#include <iostream>
#include <vector>
#include <cmath>
#define mx 1000000
using namespace std;

int n;
bool arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	arr[1] = true;
	for (int i = 2; i*i <= mx; i++) {
		for (int j = i *i; j <= mx; j += i) {
			if (!arr[j])
				arr[j] = true;
		}
	}

	while (1) {
		cin >> n;
		int flag = 1;
		if (n == 0)
			return 0;

		else {
			int i = 2;
			while(1) {
				int temp = n - i;
				if (!arr[temp] && !arr[i]) {
					cout << n << " = " << i << " + " << temp << "\n";
					break;
				}
				else if (temp < 0) {
					cout << "Goldbach's conjecture is wrong." << "\n";
					break;
				}
				i++;
			}
		}
	}
}