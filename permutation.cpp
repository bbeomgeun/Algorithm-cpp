//#include <iostream>
//
//using namespace std;
//
//int m, n, parr[10], check[10];
//
//void permutation(int target, int depth) {
//	if (depth == target) {
//		for (int i = 0; i < depth; i++) {
//			cout << parr[i] << " ";
//		}
//		cout << "\n";
//		return;
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			if (!check[i]) {
//				parr[depth] = i;
//				check[i] = true;
//				permutation(target, depth + 1);
//				check[i] = false;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//
//	permutation(m, 0);
//	// ������ �ִ� ��� -> 1 2�� 2 1�� �ٸ� ���
//}