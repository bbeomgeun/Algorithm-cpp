#include <iostream>
using namespace std;

int position[100001];
int inorder[100001];
int postorder[100001], n, le, rt;

void binaryTree(int ins, int ine, int pos, int poe) {
	if (ins > ine || pos > poe)
		return;
	int root = postorder[poe];
	cout << root << " ";

	int ie = position[root];
	int left = ie - ins;
	binaryTree(ins, ie-1, pos, pos+left-1);
	// 왼쪽 subTree = 1부터 root 전까지, 1부터 inorder크기만큼
	binaryTree(ie + 1, ine, pos + left, poe - 1);
	// 오른쪽 subTree = root후부터 끝까지, 루트위치부터 끝-1(postorder은 끝이 제외된다.)
	//inorder은 중간index의 root이용, postorder은 뒤에 root가 있다.
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> postorder[i];
	}
	for (int i = 1; i <= n; i++) {
		position[inorder[i]] = i;
		// inorder에 해당하는 인덱스를 저장한다
		// postorder의 끝이 root이므로 그 루트숫자기준 앞에 몇개있는지
	}

	binaryTree(1, n, 1, n);

}
