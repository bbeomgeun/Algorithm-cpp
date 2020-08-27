<h2> C++공부 -  자료구조, 문제해결, 알고리즘 코드 기록 </h2>

<h4> Dynamic Programming(동적계획법) </h4>

 - 큰 문제의 해답에 그보다 작은 문제의 해답이 포함되어 있으면 <b>최적 부분 구조(Optimal SubStructure</b>를 가진다고 한다. 최적 부분 구조를 갖춘 문제의 예로 가장 대표적인 것이 피보나치 수열이다.
 - n번째 피보나치 수는 An = An-1 + An-2와 같이 구해지므로, 큰 문제 An에 작은 문제 An-2과 An-1이 포함되어 있기 때문이다.
 - 가장 간단하게 푸는 방법은 재귀함수를 이용하는 것이지만, 중복호출로 인해 매우 비효율적인 코드진행이 된다.
 - 이러한 어려움을 해결하기 위해 동적 프로그래밍을 사용하면 좋을듯 하다.
 
 1. 주어진 문제가 최적 부분 구조를 가진다.
 2. 재귀함수로 구현하기에는 비효율적이다.
 
 - 즉, An을 구할때 매번 계산하는 것이 아닌 메모리에 저장해두고, 마지막 An-1과 An-2 만을 호출해서 계산하는 것이다. 이를 <b> 메모이제이션(Memoization) </b>이라고 한다.
 
 ---
 
 <h3> 정렬 알고리즘 </h3>
 
 ---
 
 <h4> Selection Sorting(선택정렬) </h4>
 
  1. 첫번째 자리 값을 최솟값으로 지정한다.
  2. 다음 자리값과 비교하여 리스트를 순회하면서 최솟값을 갱신한다.
  3. 결과값과 첫번째 자리와 자리를 바꾼다.
  4. 그 다음 자리값을 최솟값으로 지정하고 1,2,3의 과정을 반복한다.
  
~~~c++  
  void selectionSort(int *list, const int n)
{
    int i, j, indexMin, temp;

    for (i = 0; i < n - 1; i++)
    {
        indexMin = i;
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[indexMin])
            {
                indexMin = j;
            }
        }
        temp = list[indexMin];
        list[indexMin] = list[i];
        list[i] = temp;
    }
}
~~~

 - 시간복잡도는 O(n^2)로 효율적인 정렬방법은 아니다.
 - (10개의 수일경우 비교하는 횟수는 10+9+8+...1으로 10(1+10)/2 => n(n+1)/2로 O(n^2)이다.
 
 ---
 
  <h4> Bubble Sorting(버블정렬) </h4>

  1. 선택정렬과 달리, 첫번째 원소와 두번째 원소를 비교해서 큰 수를 두번째 자리로 갱신한다.
  2. 끝 원소까지 순회하며 계속해서 옆 자리 수와 비교하며 자리를 바꿔준다.
  3. 한 바퀴 돌렸으면, 마찬가지로 첫 원소부터 시작해서 다음 원소와 비교하며 자리를 갱신한다(이번엔 n-1 까지).
  4. 계속 반복하며, 끝자리에는 차곡차곡 큰 수가 쌓이므로 반복할때마다 순회하는 자리 수를 한 자리씩 줄여준다.
  
  ~~~c++
  void bubbleSort(int* list, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
~~~

 - 시간복잡도는 O(n^2)이지만 실제로는 선택정렬보다 더 오래걸린다.
 - 선택정렬은 최솟값을 구해놓고 마지막에 위치를 바꾸지만, 버블정렬은 매번 옆 원소와 비교 후 자리를 바꿔주기 때문이다.
 
 ---
 
 <h4> Insertion Sorting(삽입정렬) </h4>
 
 1. 삽입정렬은 왼쪽 부분은 정렬되어있다고 생각하고 비교를 한다.
 2. 오른쪽 원소와 왼쪽 원소를 비교하며 왼쪽 원소가 더 크면 자리를 바꾼다.
 3. 계속 비교를 하다가 자리를 바꿀시 순회가 종료되고(이미 왼쪽은 정렬되어있기에 조건문에 의해 반복이 종료된다) 다시 다음 원소부터 비교가 시작된다.

~~~c++
void insertionSort(int* list, int N) {
	for (int i = 0; i < N-1 ; i++) {
		int j = i; // 순회하는 index j를 i로 초기화해준다.
		while (j >= 0 && list[j] > list[j + 1]) { // j >=0 : 첫번째 원소부터 정렬될시 j--가 되므로 j의 index가 -1이 되고 더미값으로 초기화된다.
			int temp = list[j];
			list[j] = list[j + 1];
			list[j + 1] = temp;
			j--; // 왼쪽으로 가면서 while 조건이 false(왼쪽<오른쪽)이 될때까지 반복
		}
	}
~~~

 - 시간복잡도는 선택, 버블정렬과 마찬가지로 O(n^2)이지만 - (반복문이 두번) 실제로는 선택정렬, 버블정렬보다 효율적일 수 있다.
 - 배열이 거의 오름차순으로 초기화되어있을 경우, 삽입정렬은 순회가 종료되는 시점을 알기에 훨신 효율적으로 정렬이 가능하다.
 - 필요할때만 삽입을 하기에 데이터가 이미 정렬되어있을 경우 어떤 알고리즘보다 빠를 수 있다.

---
<h4> Quick Sorting(퀵정렬) </h4>

1. pivot을 정해서 일반적으로 pivot 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 정렬을 해준다.
2. 왼쪽 시작원소를 start, 오른쪽 끝노드를 end로 해서 start++ . end -- 하면서 pivot보다 큰값, 작은값을 각각 찾아서 위치를 바꾼다.
3. 계속해서 위치를 바꾸다가 start와 end의 index가 서로 엇갈릴 경우, end의 값과 pivot으로 정한 값의 위치를 바꿔준다.
4. end의 index를 기준으로 왼쪽 원소들과 오른쪽 원소들을 파티션으로 나눠서 위의 과정을 반복한다. (재귀 호출)

~~~c++
void quicksort(int* list, int start, int end) {
	if (start >= end) {
		return; //원소 한개일때
	}
	
	int i = start+1;
	int j = end;
	int pivot = start;

	while (i <= j) { // 서로 엇갈릴때까지 반복 => 참 조건은 엇갈리지 않을 때까지
		while (list[pivot] >= list[i] && i<=end) { // 키값보다 큰값을 찾을때 : 즉 피봇이 계속 클 때 참값이고 작으면 중단 => list[pivot]<=list[i]이 중단조건
			i++;
		}
		while (list[pivot] <= list[j] && j > start) { // 역시 피봇값보다 작은 원소를 찾을 때까지 반복 = 피봇값보다 큰 것이 참조건 =>list[pivot] >= list[j]가 중단조건
			j--;
		}
		if (i > j) { // 엇갈렸을때 j(end)값과 pivot을 바꿔준다.
			int temp = list[j];
			list[j] = list[pivot];
			list[pivot] = temp;
		}
		else { // 아닐경우 i와 j의 값을 바꿔준다.
			int temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}
	// i와 j가 교차될때 pivot과 j와 값을 바꾸고 j를 기준으로 분할정렬된다.
	quicksort(list, start, j-1); // j기준 왼쪽 파티션
	quicksort(list, j+1, end); // j기준 오른쪽 파티션
}

~~~

 - 퀵정렬의 시간복잡도는 평균적으로 O(nLogn)이다. 
 - 분할정복+재귀호출으로 n번 탐색하며 반으로 쪼개서 깊이(logn)가 정해지므로 n * logn이다.
 - 최악은 O(n^2)로 정렬되어있는 리스트를 퀵정렬 할 경우 매번 n번 탐색 * n번 호출깊이(횟수)로 n * n이 된다. (불균형 분할이 된다.)
 - 일반적으로는 위의 선택, 버블, 삽입 정렬과 비교해서 성능이 빠르다.
 
 ---
