#include <iostream>
#include <vector>
using namespace std;


class card {
public:
	int frt;
	int back;
	bool status;

	card(int front, int back) {
		this->frt = front;
		this->back = back;
		this->status = true;
	}
};

int N, M, A, B, K, score;
vector<card> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		card c(A, B);
		v.push_back(c);
	}
	for (int i = 0; i < M; i++) {
		cin >> K;
		for (int j = 0; j < v.size(); j++) {
			if (v[j].status && v[j].frt <= K)
				v[j].status = false;
			else if (!v[j].status && v[j].back <= K)
				v[j].status = true;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].status)
			score += v[i].frt;
		else if (!v[i].status)
			score += v[i].back;
	}
	cout << score;
}