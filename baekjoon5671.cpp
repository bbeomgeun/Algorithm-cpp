#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> a >> b) {
		int answer = b-a+1;
		for (int i = a; i <= b; i++) {
			int check[10] = { 0, };
			int num = i;
			while (num) {
				check[num % 10]++;
				if (check[num % 10] == 2) {
					answer--;
					break;
				}
				num = num / 10;
			}
		}
		cout <<answer<< "\n";
	}
	return 0;
}