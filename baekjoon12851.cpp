#include <iostream>
#include <queue>

using namespace std;

int tm, n, k, answer;
bool check[100002];

queue<int> q;

void BFS(int start) {
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front();
			q.pop();
			if (x == k)
				answer++;
			check[x] = true;

			if (x + 1 <= 100000 && !check[x + 1]) 
				q.push(x + 1);
			if (x - 1 >= 0 && !check[x - 1])
				q.push(x - 1);
			if(x*2 <= 100000 && !check[2*x])
				q.push(x * 2);
		}
		if (answer)
			return;
		tm++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	if (n == k) {
		cout << 0 << " " << 1;
		return 0;
	}

	BFS(n);
	
	cout <<tm<< " " << answer;
}