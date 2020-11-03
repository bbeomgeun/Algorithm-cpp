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

	void insertNode(Node * node, int data) { // node���� ��� ��� inplace�� �ݺ���
		while (node!=NULL) { // �������������
			if (node->data > data) { // ����Ž��Ʈ���̹Ƿ� ���غ��� ������ ���ʳ���
				if (node->left != NULL) // ������ ������� ������ ���� ����Ʈ���� �̵�
					node = node->left; // ���ʳ��� �̵�
				else //������ ��������� ������ ���� ����
					break; 
			}
			else if (node->data < data) { // ����Ž��Ʈ���̹Ƿ� ���غ��� ũ�� �����ʳ���
				if (node->right != NULL) // �������� ������� ������ ������ ����Ʈ����
					node = node->right; // �����ʳ��� �̵�
				else // �������� ��������� ������ ���� ����
					break;
			}
		}
		Node* newNode = new Node(data); // ������ ��� ����
		if (node->data > data) { // ������ ��ġ�� ��带 ã�� �����̹Ƿ� ũ�� ���ʿ�
			node->left = newNode; // ����
			newNode->setParent(node); // �θ� ����
		}
		else {
			node->right = newNode; // �ݴ��� ��� ������
			newNode->setParent(node); // �θ� ����
		}
	}

	void postOrder(Node* node) { // ���� Ž��
		if (!node)
			return;
		if (node->left != NULL) { // ���� �Ⱥ�������� ��� ��������
			postOrder(node->left);
		}
		if (node->right != NULL) { // ���� Ž�� �������� ����������
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
				bt.insertNode(bt.getRoot(), num); // �Է��� ����� ����Ž��Ʈ�� ����
			}
		}
	}
	bt.postOrder(bt.getRoot());
}