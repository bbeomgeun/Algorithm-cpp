#include <iostream>

using namespace std;

int n, r, c;
int arr[501], record[501][501];

int multipleResult(int x, int y, int z) {
	return arr[x - 1] * arr[y] * arr[z];
}

int matrixCal(int start, int end) {
	if (start == end)
		return 0;
	if (record[start][end])
		return record[start][end];
	int result = 0;
	for (int k = start; k < end; k++) {
		if (result == 0)
			result = matrixCal(start, k) + matrixCal(k + 1, end) + multipleResult(start, k, end);
		else
			result = min(result, matrixCal(start, k) + matrixCal(k + 1, end) + multipleResult(start, k, end));
	}
	return record[start][end] = result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> r >> c;
	arr[0] = r;
	for (int i = 1; i < n-1; i++) {
		cin >> r >> c;
		arr[i] = r;
	}
	cin >> r >> c;
	arr[n - 1] = r;
	arr[n] = c;
	cout<<matrixCal(1, n);

}