#include<iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int check[1000001], record[1000001];

void BFS(int from, int to) {
	queue<int> q;
	q.push(from);
	check[from] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		if (temp == to)
			return;

		int up = temp + U;
		if (up <= F && !check[up]) {
			q.push(up);
			record[up] = record[temp] + 1;
			check[up] = true;
		}
		int down = temp - D;
		if (down >= 1 && !check[down]) {
			q.push(down);
			record[down] = record[temp] + 1;
			check[down] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> F >> S >> G >> U >> D;
	if (S == G) {
		cout << "0";
		return 0;
	}

	BFS(S, G);

	if (record[G] == 0) {
		cout << "use the stairs";
	}
	else
		cout << record[G];
}