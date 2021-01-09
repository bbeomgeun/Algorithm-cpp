#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, num;
vector<int> v, results;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		v.push_back(num);
	}
	results.push_back(v[0]);
	results.push_back(N - v[v.size()-1]);

	for (int i = 1; i < v.size(); i++) {
		int height = v[i] - v[i - 1];
		if (height % 2 == 0) {
			results.push_back(height/2);
		}
		else
			results.push_back(height /2+ 1);
	}

	sort(results.begin(), results.end());
	cout << results[results.size() - 1];
}