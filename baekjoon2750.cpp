#include <iostream>

using namespace std;

int main() {
	int num = 0, input = 0, min = 0;

	cin >> num;

	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> input;
		*(arr + i) = input;
	}

	for (int i = 0; i < num; i++) {
		min = i;
		for (int j = i; j < num; j++) {
			if (*(arr + min) > * (arr + j))
				min = j;
		}
		int temp = *(arr + min);
		*(arr + min) = *(arr + i);
		*(arr + i) = temp;
	}

	for (int i = 0; i < num; i++) {
		cout << *(arr + i) << endl;
	}


	delete[] arr;
	arr = NULL;
}