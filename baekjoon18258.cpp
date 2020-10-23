//�迭 ��� ����ť ���ǻ���
//1. �׻� front�� rear�� 0���� �ʱ�ȭ / front�� �׻� �� ���� ����Ű�� �ִٴ� ����(dequeue�Ҷ� front+1���ְ� �װ� null����� ����Ű�� ����)
//2. enqueue�Ҷ��� rear+1���ְ� �� �ε����� �����͸� �־��ش�.
//3. ����ť �����Ҷ��� max_size�� �Է°� +1��ŭ ���ش�( Full �Ǻ��� �ε��� �ϳ� ���ܳ��� ����) (rear+1)%max == front full����
//4. �׷��� �迭class ©�� add(i,x)�� ũ�⺸�� i�� ������ ũ���ε����� �־��ִ� �ڵ� �����ؾ��Ѵ�. + �迭 �ڷ� �̷�°͵� ����
//(�̰� �迭 ������ �������� ����ϰ�)
//���� add�� �� �ε����� ������ �ִ°� �����ϱ�.

#include <iostream>
using namespace std;

class Array {
public:
	int arr_size = 2000001;
	int* arr;
	int n;

	Array() {
		arr = new int[arr_size];
		for (int i = 0; i < arr_size; i++) {
			arr[i] = 0;
		}
		this->n = 0;
	}

	int at(int i) {
		return arr[i];
	}
	void set(int i, int x) {
		if (arr[i] == 0) {
			cout << "0" << "\n";
		}
		else {
			arr[i] = x;
		}
	}

	void add(int i, int X) {
		arr[i] = X;
		n++;
	}
};

class arrQueue {
public:
	Array* arr;
	int max_size;
	int front;
	int rear;
	int n;

	arrQueue(int size) {
		arr = new Array();
		max_size = size;
		front = 0;
		rear = 0;
		n = 0;
	}
	int size() {
		return n;
	}
	bool isEmpty() {
		return front == rear;
	}

	bool isFull() {
		return (rear + 1) % max_size == front;
	}

	void enqueue(int x) {
		if (isFull())
			cout << "Full" << "\n";
		else {
			rear = (rear + 1) % max_size;
			arr->add(rear, x);
			n++;
		}
	}

	void dequeue() {
		if (isEmpty()) {
			cout << -1 << "\n";
		}
		else {
			front = (front + 1) % max_size;
			cout << arr->at(front)<< "\n";
			arr->set(front, 0);
			n--;
		}
	}
	void Front() {
		if (isEmpty())
			cout << -1 << "\n";
		else {
			cout << arr->at(front+1) << "\n";
		}
	}
	void Rear() {
		if (isEmpty())
			cout << -1 << "\n";
		else {
			cout << arr->at(rear) << "\n";
		}
	}
};

int N, S, x;
string input;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	arrQueue q(2000001);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "empty") {
			cout << q.isEmpty()<< "\n";
		}
		else if (input == "push") {
			cin >> x;
			q.enqueue(x);
		}
		else if (input == "pop") {
			q.dequeue();
		}
		else if (input == "size") {
			cout<<q.size()<<"\n";
		}
		else if (input == "front") {
			q.Front();
		}
		else if (input == "back") {
			q.Rear();
		}
	}
	return 0;
}