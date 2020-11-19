#include <iostream>
#include <cmath>
using namespace std;

#define VALUE 1234567891;
int N;
long long sum;
char c;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		sum += (c - 'a' + 1) * (long long) pow(31, i);
		sum = sum % VALUE;
	}
	cout << sum % VALUE;
}