/* 200612 baekjoon1065��
� ���� ���� X�� �� �ڸ��� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�.
���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�. N�� �־����� ��, 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
�Է� : 1~1000;
*/

#include <iostream>

using namespace std;

int func(int inputNumber);

int main() {
	int Number = 0;
	cin >> Number;
	cout<< func(Number);
}

int func(int inputNumber) {
	int count = 0;
	int oneth, tenth, hundredth;
	if (inputNumber < 100) { //�����ڸ������� ���������� ����(1~99)
		for (int i = 0; i < inputNumber; i++)
			count++;
	}
	else { // ���� �ڸ� ������ ���
		for (inputNumber; inputNumber > 99; inputNumber--) {
			hundredth = inputNumber / 100; // �����ڸ����� 100���� ���� �� =>���� �ڸ�
			tenth = ((inputNumber) % 100) / 10; // �����ڸ����� 100���� ���� ������=>���� �ڸ��� , ���� �ڸ����� 10���� ���� ��=>���� �ڸ�
			oneth = ((inputNumber) % 100) % 10;//�����ڸ������� 10���� ���� ������ => ���� �ڸ�
			if ((hundredth - tenth) == (tenth - oneth))
				count++;
		}
		count += 99;
	}
	return count;
}