#include <iostream>
#include <unordered_map>

#define MAX 200001

using namespace std;

int F, T, parent[MAX], child[MAX];
string name1, name2;
unordered_map<string, int> m;

int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

int unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) // ��ġ�� �ʴ� ���̽�
		return child[a];

	else if (a > b) { // a�� �θ� b�� �Ǵ� ���̽�
		parent[a] = b;
		child[b] += child[a];
		return child[b];
	}
	else { // b�� �θ� a�� �Ǵ� ���̽�
		parent[b] = a;
		child[a] += child[b];
		return child[a];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> F;
	for (int f = 0; f < F; f++) {
		cin >> T;
		for (int i = 0; i < MAX; i++) {
			parent[i] = i;
			child[i] = 1;
		} // unionFind �ʱ�ȭ
		int count = 1;
		m.clear();
		for (int t = 0; t < T; t++) {
			cin >> name1 >> name2;
			if (m[name1] == 0) {
				m[name1] = count;
				count++;
			}
			if (m[name2] == 0) {
				m[name2] = count;
				count++;
			}
			cout << unionParent(m[name1], m[name2]) << "\n";
		}
	}
}