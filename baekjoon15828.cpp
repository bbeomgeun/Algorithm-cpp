#include <iostream>
#include <queue>

using namespace std;

int bufferSize, packet;
queue<int> router;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> bufferSize;
	while (1) {
		cin >> packet;
		if (packet == -1)
			break;

		if (packet == 0) {
			router.pop();
			continue;
		}

		if (router.size() < bufferSize) {
			router.push(packet);
		}
	}

	if (router.empty())
		cout << "empty";
	else
		while (!router.empty()) {
			cout << router.front() << " ";
			router.pop();
		}
}