//#include <iostream>
//
//using namespace std;
//
//int n, m, carr[9];
//
//void combination(int depth, int next) {
//	if (depth == m) {
//		for (int i = 0; i < depth; i++) {
//			cout << carr[i] << " ";
//		}
//		cout << "\n";
//		return;
//	}
//	else {
//		for (int i = next; i <= n; i++) {
//			carr[depth] = i;
//			combination(depth + 1, i + 1);
//		}
//	}
//}
//
//
//int main() {
//	cin >> n >> m;
//
//	combination(0, 1);
//}