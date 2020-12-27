#include <iostream>
#include <vector>
using namespace std;

string name1, name2, sumName;
int size1, size2;
vector<int> num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arr[26] = { 3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
	cin >> size1 >> size2;
	cin >> name1 >> name2;

	int minSize = size1 >= size2 ? size2 : size1;
	int maxSize = size1 >= size2 ? size1 : size2;
	string maxString = size1 >= size2 ? name1: name2;
	for (int i = 0; i < minSize; i++) {
		sumName += name1[i];
		sumName += name2[i];
	}
	for (int i = minSize; i < maxSize; i++) {
		sumName += maxString[i];
	}

	for (int i = 0; i < size1 + size2; i++) {
		int idx = sumName[i] - 'A';
		num.push_back(arr[idx]);
	}

	while (num.size() != 2) {
		vector<int> temp;
		for (int i = 0; i < num.size() - 1; i++) {
			int tempNum = num[i] + num[i + 1];
			temp.push_back(tempNum > 9 ? tempNum - 10 : tempNum);
		}
		num = temp;
	}
	if(num[0] == 0)
		cout << num[1] << "%";
	else
		cout << num[0] <<num[1]<< "%";
}