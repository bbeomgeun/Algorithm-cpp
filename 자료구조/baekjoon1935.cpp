//#include <iostream>
//#include <stack>
//#include <iomanip>
//
//using namespace std;
//
//stack <double> st;
//double tempResult, value, arr[26];
//int N, cnt;
//string s;
//
//int isNum(char c) {
//	if (c >= 'A' && c <= 'Z')
//		return true;
//	else
//		return false;
//}
//
//int isOper(char c) {
//	if (c == '*' || c == '/' || c == '+' || c == '-')
//		return true;
//	else
//		return false;
//}
//
//int main() {
//	cin >> N;
//	cin >> s;
//	for (int i = 0; i < N; i++) {
//		cin >> value;
//		arr[i] = value;
//	}
//	for (int i = 0; i < s.size(); i++) {
//		if (isNum(s[i])) {
//			st.push(arr[s[i] - 'A']);
//		}
//		else if (isOper(s[i])) {
//			double temp2 = st.top();
//			st.pop();
//			double temp1 = st.top();
//			st.pop();
//			if (s[i] == '+')
//				tempResult = temp1 + temp2;
//			else if (s[i] == '-')
//				tempResult = temp1 - temp2;
//			else if (s[i] == '*')
//				tempResult = temp1 * temp2;
//			else if (s[i] == '/')
//				tempResult = temp1 / temp2;
//			st.push(tempResult);
//		}
//	}
//
//	cout << fixed << setprecision(2) << st.top();
//
//	return 0;
//}
//
