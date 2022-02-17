#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int crainN, n, x, answer;
vector<int> crain, box;

int compare(int a, int b) {
	return a > b;
}

int main() {
	cin >> crainN;
	for (int i = 0; i < crainN; i++) {
		cin >> x;
		crain.push_back(x);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		box.push_back(x);
	}

	sort(crain.begin(), crain.end(), compare);
	sort(box.begin(), box.end(), compare);

	if (crain.front() < box.front()) {
		cout << -1;
		return 0;
	}
	int flag = false;

	while (!box.empty()) {
		for (int i = 0; i < crain.size(); i++) {
			for (int j = 0; j < box.size();) {
				if (crain[i] >= box[j]) {
					box.erase(box.begin() + j);
					break; // ¥Ÿ¿Ω box
					}
				else {
					j++;
				}
			}
			if (box.empty()) {
				flag = true;
				break;
			}
		}
		answer++;
		if (flag)
			break;
	}

	cout << answer;
}