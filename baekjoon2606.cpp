//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N, T, x, y, check[101], cnt;
//vector<int> v[101];
//
//void dfs(int start) {
//	cnt += 1;
//	check[start] = true;
//
//	for (int i = 0; i < v[start].size(); i++) {
//		int tempX = v[start][i];
//		if (!check[tempX])
//			dfs(tempX);
//	}
//}
//
//int main() {
//	cin >> N;
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		cin >> x >> y;
//		v[x].push_back(y);
//		v[y].push_back(x);
//	}
//	dfs(1);
//	cout<<cnt-1;
//}