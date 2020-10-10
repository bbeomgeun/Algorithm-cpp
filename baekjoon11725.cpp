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
		for(auto y : dataset[par]){  // 벡터 요소 돌면서 아직 방문 안한 노드는 부모노드이다(이미 방문한 노드는 다른 노드의 자식 노드)
			if (!check[y]) {
				parent[y] = par; // index next(자식)의 부모가 x
				check[y] = true; // 부모 찾음
				q.push(y); // 자식 찾으러
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