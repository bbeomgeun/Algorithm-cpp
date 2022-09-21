#include <iostream>
#include <vector>

using namespace std;


int n, m, realnum, realman, partynum, partyman, answer;
int parent[51], check[51];
vector<int> v[51];
vector<int> tr;

int getParent(int a) {
	if (parent[a] == a)
		return a;
	else
		return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a > b) {
		parent[a] = b;
	}
	else
		parent[b] = a;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	cin >> realnum;

	for (int i = 0; i < realnum; i++) {
		cin >> realman;
		tr.push_back(realman);
	}

	for (int i = 0; i < m; i++) {
		cin >> partynum;
		
		for (int j = 0; j < partynum; j++) {
			cin >> partyman;
			v[i].push_back(partyman);
		}
		for (int j = 0; j < v[i].size()-1; j++) {
			unionParent(v[i][j], v[i][j+1]);
		}
	}
	int answer = m;

	for (int i = 0; i <m; i++) {
		int flag = true;
		for (int j = 0; j < v[i].size(); j++) {
			int now = v[i][j];
			for (int k = 0; k < tr.size(); k++) {
				if (getParent(tr[k]) == getParent(now)) {
					answer--;
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
	}
	cout << answer;
}