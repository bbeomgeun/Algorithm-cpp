#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, num, arr[8001];
double total;
vector<int> v;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
		total += num;
		arr[num + 4000]++;
	}
	sort(v.begin(), v.end());

	int rnum = 0;
	int rcnt = 0;

	for (int i = 0; i <= 8000; i++) {
		if (rcnt < arr[i]) {
			rcnt = arr[i];
			rnum = i;
		}
	}

	for (int i = rnum+1; i <= 8000; i++) {
		if (rcnt == arr[i]) {
			rnum = i;
			break;
		}
	}

	cout << round(total / n) << "\n";
	cout << v[(n - 1) / 2] << "\n";
	cout << rnum - 4000<<"\n";
	cout << v.back() - v.front();
}