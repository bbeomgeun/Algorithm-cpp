#include <iostream>
#include <algorithm>

using namespace std;

void callbyRef(int &arr1, int &arr2);
 // �迭 sort���� �� callbyRef ����
 // �������� ������ ó���� �������� ���ؼ� �ּڰ� Ž�� �� ù�ڸ��� ��ȯ(1�� 2,3,4,5) -> �� ���� �ε����� 2�� 3,4,5 ���� 2�� �ּڰ� ��ȯ
// �������� �ּڰ��� �տ������� ���̰� �ȴ�.
int main() {
	const int length = 5;
	int arr[length] = { 15,85,70,60,5 };

	for (int whole = 0; whole < length - 1; whole++) { // ��ü�� ���� �ε���
		int small = whole; // �����ε����� �ּڰ��ε��� �ʱ�ȭ
		for (int compare = whole + 1; compare < length; compare++) { //��(compare index) �� ���� �ε��� �������� ����
			if (arr[small] > arr[compare]) { //�ּڰ��� �񱳰�
				small = compare; //�ּڰ� ������Ʈ
			}
		}
		callbyRef(arr[small], arr[whole]); // �迭������ �ڸ��� �ٲ�����(ó���� �ּڰ���) -> �������� ������ �ȴ�.
	}
	for (int i = 0; i < length; i++) { //�迭 ���
		cout << arr[i] << " , ";
	}
}

void callbyRef(int &arr1, int &arr2) {
	int temp = arr1;
	arr1 = arr2;
	arr2 = temp;
}