#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct name {
	string parent;
	vector<string> sonList;

	name(string _parent) {
		parent = _parent;
	}
};

bool compare(name n1, name n2) {
	return n1.parent < n2.parent;
}

int n, e, inDegree[1001];
string s,x,y;
unordered_map<string, int> m;
unordered_map<int, string> mInt;
vector<int> v[1001];
vector<string> ancestorList;
vector<int> answerTree[1001];
vector<name> nameList;

void topologicalSort(int startX) {
	queue<int> q;
	q.push(startX);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			inDegree[nx]--;
			if (inDegree[nx] == 0) {
				answerTree[x].push_back(nx);
				q.push(nx);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s] = i;
		mInt[i] = s;
	}
	cin >> e;

	for (int i = 0; i < e; i++) {
		cin >> x >> y; // x 조상 중 y가 있다.
		int son = m[x];
		int ancestor = m[y];
		v[ancestor].push_back(son);
		inDegree[son]++;
	}

	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			ancestorList.push_back(mInt[i]);
		}
	}

	sort(ancestorList.begin(), ancestorList.end());

	cout << ancestorList.size() << "\n";

	for (auto k : ancestorList) {
		cout << k << " ";
		int start = m[k];
		topologicalSort(start);
	}
	cout << "\n";

	for (int i = 0; i < n; i++) {
		string p = mInt[i];
		name n1(p);
		for (int j = 0; j < answerTree[i].size(); j++) {
			string son = mInt[answerTree[i][j]];
			n1.sonList.push_back(son);
		}
		sort(n1.sonList.begin(), n1.sonList.end());
		nameList.push_back(n1);
	}

	sort(nameList.begin(), nameList.end(), compare);

	for (int i = 0; i < nameList.size(); i++) {
		name temp = nameList[i];
		cout << temp.parent << " " << temp.sonList.size() << " ";
		for (int j = 0; j < temp.sonList.size(); j++) {
			cout << temp.sonList[j] << " ";
		}
		cout << "\n";
	}
}