#include <iostream>
#include <string>
using namespace std;

long long number;
int n, digit;

int main() {
	while (cin>>n) {
		number =1;
		digit = 1;
		while (1) {
			if (number % n == 0) {
				cout << digit<<"\n";
				break;
			}
			else {
				int mod = number % n;
				number = mod * 10 + 1;
				digit++;
			}
		}
	}
	
}