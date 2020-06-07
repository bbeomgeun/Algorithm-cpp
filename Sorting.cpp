#include <iostream>
#include <algorithm>

using namespace std;

void callbyRef(int &arr1, int &arr2);
 // 배열 sort연습 및 callbyRef 연습
 // 오름차순 정렬은 처음과 나머지를 비교해서 최솟값 탐색 후 첫자리와 교환(1과 2,3,4,5) -> 그 다음 인덱스인 2와 3,4,5 비교후 2와 최솟값 교환
// 차곡차곡 최솟값이 앞에서부터 쌓이게 된다.
int main() {
	const int length = 5;
	int arr[length] = { 15,85,70,60,5 };

	for (int whole = 0; whole < length - 1; whole++) { // 전체를 도는 인덱스
		int small = whole; // 시작인덱스로 최솟값인덱스 초기화
		for (int compare = whole + 1; compare < length; compare++) { //비교(compare index) 는 시작 인덱스 다음부터 돈다
			if (arr[small] > arr[compare]) { //최솟값과 비교값
				small = compare; //최솟값 업데이트
			}
		}
		callbyRef(arr[small], arr[whole]); // 배열내에서 자리를 바꿔주자(처음과 최솟값을) -> 오름차순 정렬이 된다.
	}
	for (int i = 0; i < length; i++) { //배열 출력
		cout << arr[i] << " , ";
	}
}

void callbyRef(int &arr1, int &arr2) {
	int temp = arr1;
	arr1 = arr2;
	arr2 = temp;
}