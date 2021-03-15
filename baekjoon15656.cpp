#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int n, m, num;
vector<int> arr;
int carr[8];

void func(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << carr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		carr[depth] = arr[i];
		func(depth + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	
	func(0);

	
}