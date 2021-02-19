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
	// ���� subTree = 1���� root ������, 1���� inorderũ�⸸ŭ
	binaryTree(ie + 1, ine, pos + left, poe - 1);
	// ������ subTree = root�ĺ��� ������, ��Ʈ��ġ���� ��-1(postorder�� ���� ���ܵȴ�.)
	//inorder�� �߰�index�� root�̿�, postorder�� �ڿ� root�� �ִ�.
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
		// inorder�� �ش��ϴ� �ε����� �����Ѵ�
		// postorder�� ���� root�̹Ƿ� �� ��Ʈ���ڱ��� �տ� ��ִ���
	}

	binaryTree(1, n, 1, n);

}
