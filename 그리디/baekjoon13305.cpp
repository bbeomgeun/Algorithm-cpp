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
			// 이 가격으로 계속 주유해야함
			tempNeed += needList[i];
		}
		else { // 다음 것보다 비싸면 이제까지 밀린거 다 구입 & 지금 필요한 것만 삼
			answer += tempMinPrice * (tempNeed);
			tempMinPrice = priceList[i];
			tempNeed = needList[i];
		}
	}
	answer += tempMinPrice * tempNeed;

	cout << answer;
}