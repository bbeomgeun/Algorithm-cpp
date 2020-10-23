//배열 기반 원형큐 주의사항
//1. 항상 front와 rear은 0으로 초기화 / front는 항상 빈 곳을 가리키고 있다는 개념(dequeue할때 front+1해주고 그곳 null만들고 가리키고 있음)
//2. enqueue할때도 rear+1해주고 그 인덱스에 데이터를 넣어준다.
//3. 원형큐 선언할때도 max_size는 입력값 +1만큼 해준다( Full 판별용 인덱스 하나 남겨놓기 때문) (rear+1)%max == front full조건
//4. 그래서 배열class 짤때 add(i,x)에 크기보다 i가 작으면 크기인덱스에 넣어주는 코드 삭제해야한다. + 배열 뒤로 미루는것도 삭제
//(이건 배열 조건이 있을때나 사용하고)
//원래 add는 그 인덱스에 데이터 넣는게 맞으니까.

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