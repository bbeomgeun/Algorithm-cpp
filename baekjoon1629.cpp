#include <iostream>

using namespace std;

int a, b, c;

long long pow(int a, int b, int c) {
	if (b == 0) {
		return 1;
	}
	long long n = pow(a, b / 2, c);
	long long temp = n * n % c;

	if (b % 2 == 0) {
		return temp;
	}
	else {
		return a * temp % c;
	}
}

int main() {
	cin >> a >> b >> c;
	cout << pow(a, b, c);

}