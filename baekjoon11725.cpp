#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector <int> dataset[100001];
bool check[100001];
int parent[100001];
queue <int> q;

int N, a, b, par;

void findParent(int x) {
	check[x] = true;
	q.push(x);

	while (!q.empty()) {
		par = q.front();
		q.pop();

		/*for (i = 0; i < dataset[par].size(); i++) { */
		for(auto y : dataset[par]){  // ���� ��� ���鼭 ���� �湮 ���� ���� �θ����̴�(�̹� �湮�� ���� �ٸ� ����� �ڽ� ���)
			if (!check[y]) {
				parent[y] = par; // index next(�ڽ�)�� �θ� x
				check[y] = true; // �θ� ã��
				q.push(y); // �ڽ� ã����
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		dataset[a].push_back(b);
		dataset[b].push_back(a);
	}

	findParent(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;

}