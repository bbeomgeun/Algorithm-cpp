#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* par;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		par = left = right = NULL;
	}

	void insertLeft(Node* node) {
		left = node;
	}

	void insertRight(Node* node) {
		right = node;
	}
	void setParent(Node* parent) {
		par = parent;
	}
};

class binaryTree {
private:
	Node* root;
	vector<Node*> nodelist;
public:
	binaryTree() {
		root = NULL;
		nodelist.push_back(root);
	}

	void setRoot(int data) {
		root = new Node(data);
	}

	Node* getRoot() {
		return root;
	}

	void insertNode(Node * node, int data) { // node부터 재귀 대신 inplace로 반복문
		while (node!=NULL) { // 비어있을때까지
			if (node->data > data) { // 이진탐색트리이므로 기준보다 작으면 왼쪽노드로
				if (node->left != NULL) // 왼쪽이 비어있지 않으면 왼쪽 서브트리로 이동
					node = node->left; // 왼쪽노드로 이동
				else //왼쪽이 비어있으면 삽입을 위해 종료
					break; 
			}
			else if (node->data < data) { // 이진탐색트리이므로 기준보다 크면 오른쪽노드로
				if (node->right != NULL) // 오른쪽이 비어있지 않으면 오른쪽 서브트리로
					node = node->right; // 오른쪽노드로 이동
				else // 오른쪽이 비어있으면 삽입을 위해 종료
					break;
			}
		}
		Node* newNode = new Node(data); // 삽입할 노드 생성
		if (node->data > data) { // 삽입할 위치의 노드를 찾은 상태이므로 크면 왼쪽에
			node->left = newNode; // 연결
			newNode->setParent(node); // 부모 연결
		}
		else {
			node->right = newNode; // 반대의 경우 오른쪽
			newNode->setParent(node); // 부모 연결
		}
	}

	void postOrder(Node* node) { // 후위 탐색
		if (!node)
			return;
		if (node->left != NULL) { // 왼쪽 안비어있으면 계속 왼쪽으로
			postOrder(node->left);
		}
		if (node->right != NULL) { // 왼쪽 탐색 끝났으면 오른쪽으로
			postOrder(node->right);
		}
		cout << node->data << "\n"; // postOrder
	}
};

int N, num, cnt;

int main() {
	binaryTree bt;
	while (cin >> num){
		if (num != EOF){
			if (cnt == 0) {
				bt.setRoot(num);
				cnt++;
			}
			else {
				bt.insertNode(bt.getRoot(), num); // 입력한 값대로 이진탐색트리 생성
			}
		}
	}
	bt.postOrder(bt.getRoot());
}