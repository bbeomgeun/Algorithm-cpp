//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int T, N, g1, g2;
//
//bool compare(pair<int, int> a, pair<int, int> b) {
//	return a.first < b.first;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> T;
//	for (int t = 0; t < T; t++) {
//		vector<pair<int, int>> v;
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//			cin >> g1 >> g2;
//			v.push_back(make_pair(g1, g2));
//		}
//
//		sort(v.begin(), v.end(), compare);
//
//		int answer = 1;
//		int target = v[0].second;
//
//		for (int i = 1; i < N; i++) {
//			if (target > v[i].second) {
//				answer++;
//				target = v[i].second;
//			}
//		}
//		cout << answer << "\n";
//	}
//}