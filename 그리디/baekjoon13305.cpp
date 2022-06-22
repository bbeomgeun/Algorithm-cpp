#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000

using namespace std;

typedef long long ll;

ll n, need, price, totalNeed;
ll answer;
vector<ll> priceList, needList;

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> need;
		needList.push_back(need);
		totalNeed += need;
	}
	for (int i = 0; i < n; i++) {
		cin >> price;
		priceList.push_back(price);
	}

	ll tempNeed = needList[0];
	ll tempMinPrice = priceList[0];
	for (int i = 1; i < n - 1; i++) {
		if (tempMinPrice <= priceList[i]) {
			// �� �������� ��� �����ؾ���
			tempNeed += needList[i];
		}
		else { // ���� �ͺ��� ��θ� �������� �и��� �� ���� & ���� �ʿ��� �͸� ��
			answer += tempMinPrice * (tempNeed);
			tempMinPrice = priceList[i];
			tempNeed = needList[i];
		}
	}
	answer += tempMinPrice * tempNeed;

	cout << answer;
}