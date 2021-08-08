#include <iostream>
#include <stack>
#define MAX 1000001
using namespace std;

typedef pair<int, int> pii;
int n, num, arr[MAX], record[MAX];
stack<pii> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		record[i] = -1;
	}

	for (int i = 0; i < n -1; i++) {
		if (arr[i] < arr[i + 1]) {
			record[i] = arr[i + 1];
			while (!st.empty()) {
				if (st.top().first < arr[i + 1]) {
					record[st.top().second] = arr[i + 1];
					st.pop();
				}
				else
					break;
			}
		}
		else {
			st.push(make_pair(arr[i], i));
		}
	}

	for (int i = 0; i < n; i++)
		cout << record[i] << " ";
	
}

//#include <iostream>
//#include <stack>
//#define MAX 1000001
//using namespace std;
//
//typedef pair<int, int> pii;
//int n, num, arr[MAX];
//stack<int> st;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	for (int i = n - 1; i >= 0; i--) {
//		int a = arr[i];
//		while (!st.empty() && st.top() <= arr[i]) {
//			st.pop();
//		}
//		if (st.empty()) {
//			arr[i] = -1;
//		}
//		else {
//			arr[i] = st.top();
//		}
//		st.push(a);
//	}
//
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << " ";
//}