#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a, N, M, num;
vector<int> arr;

int binarySearch(int k) {
	int start = 0;
	int end = N - 1;
	while(start <= end){
		int m = (start + end) / 2;
		if (k == arr[m])
			return 1;
		else if (k > arr[m])
			start = m + 1;
		else
			end = m - 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		cout<<binarySearch(num)<<"\n";
	}
}