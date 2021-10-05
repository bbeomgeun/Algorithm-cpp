#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

int N, M, tag;
string from, to, route;
unordered_map<string, int> name2int;
bool isFile[2001];
vector<int> v[2001];
vector<unordered_map<int, int>> resultMap[2001];

unordered_map<int, int> DFS(int x) {
	unordered_map<int, int> result;
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		if (isFile[nx]) {
			result[nx]++;
			continue;
		}
		unordered_map<int, int> temp = DFS(nx);
		// temp 비면 for문 안돌아가나?
		for (auto k : temp) {
			result[k.first] += k.second;
		}
	}
	resultMap[x].push_back(result);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int cnt = 1;
	for (int i = 0; i < N + M; i++) {
		cin >> from >> to >> tag;
		if (name2int.find(from) == name2int.end()) {
			name2int[from] = cnt;
			cnt++;
		}
		if (name2int.find(to) == name2int.end()) {
			name2int[to] = cnt;
			cnt++;
		}
		v[name2int[from]].push_back(name2int[to]);
		if (tag == 0) { // folder to folder
			isFile[name2int[to]] = true;
		}
	}

	DFS(name2int["main"]);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> route;
		string buffer;
		istringstream ss(route);

		while (getline(ss, buffer, '/')) {
		}
		unordered_map<int, int> temp = resultMap[name2int[buffer]][0];
		if (temp.size() == 0) {
			cout << 0 << " " << 0 << "\n";
			continue;
		}
		else {
			int cnt = 0;
			for (auto k : temp) {
				cnt += k.second;
			}
			cout << temp.size() << " " << cnt << "\n";
		}
	}
}