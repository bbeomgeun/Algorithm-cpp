#include <iostream>
using namespace std;

int arr[26][2], N;
char root, Left, Right;

void preorder(int node) {
	if (node == -1)
		return;
	cout << char(node + 'A');
	preorder(arr[node][0]);
	preorder(arr[node][1]);
}

void inorder(int node) {
	if (node == -1)
		return;
	inorder(arr[node][0]);
	cout << char(node + 'A');
	inorder(arr[node][1]);
}

void postorder(int node) {
	if (node == -1)
		return;
	postorder(arr[node][0]);
	postorder(arr[node][1]);
	cout << char(node + 'A');
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> root >> Left >> Right;
		if (Left != '.')
			arr[root - 'A'][0] = Left - 'A';
		else
			arr[root - 'A'][0] = -1;
		if (Right != '.')
			arr[root - 'A'][1] = Right - 'A';
		else
			arr[root - 'A'][1] = -1;
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
}