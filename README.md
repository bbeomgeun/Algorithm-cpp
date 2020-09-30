<h2> C++ - 알고리즘 공부 </h2>

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
		return; //원소 한개일때 재귀를 종료.
	}
	
	int i = start+1;
	int j = end;
	int pivot = start;

	while (i <= j) { // 서로 엇갈릴때까지 반복 => 참 조건은 엇갈리지 않을 때까지
		while (list[pivot] >= list[i] && i<=end) { // 키값보다 큰값을 찾을때 : 즉 피봇이 계속 클 때 참값이고 작으면 중단 => list[pivot]<=list[i]이 중단조건
			i++;
		}					   // i<=end 조건은 end를 벗어나기전까지. (등호 포함)
		while (list[pivot] <= list[j] && j > start) { // 역시 피봇값보다 작은 원소를 찾을 때까지 반복 = 피봇값보다 큰 것이 참조건 =>list[pivot] >= list[j]가 중단조건
			j--;
		}					   // i>start 조건은 start 앞까지 (start는 pivot자리이므로) (등호 미포함)
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
 - while문 안의 while 두개에서 조건의 부등호를 각자 바꿔주면 내림차순으로 변경된다.
 - list[pivot] <= list[i] 와 list[pivot] >= list[j] 으로 부등호방향만 바꿔주면 된다. (그러면 왼쪽엔 큰 값, 오른쪽엔 작은 값이 정렬)
 
 ---
 
 <h4> Merge Sorting(병합정렬) </h4>
 
 1. 병합 정렬은 기본적으로 분할정복 방버을 채택한 알고리즘이다.
 2. 퀵 정렬은 피봇값을 기준으로 나누지만, 병합 정렬은 항상 반으로 나누는 특징(이것이 logN을 만든다).
 3. 리스트를 원소 단위로 모두 나눈 다음에, 병합하면서 부분집합을 만들고, 그 집합을 또 병합한다.
 4. 병합을 진행할 때, 부분 집합은 이미 정렬이 되어 있는 상태로 가정한다.
 5. 즉, 집합을 반씩 나눠서 원소 단위로 나눈 다음 합치는 순간에 정렬을 수행하며 나아간다.
 
 ~~~c++
 int sorted[8]; // 정렬된 원소를 저장할 배열은 항상 전역변수르 저장해주자.
 void merge(int* list, int start, int middle, int end) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i<=middle && j <=end) { 
	// 참조건은 두 index가 모두 도달하지 않았을때 /  i가 middle까지가거나 j가 end까지 가거나(false 조건)
		if (list[i] <= list[j]) { 
		// 블럭 인덱스끼리 비교해서 sorted array에 작은 수부터 넣어준다.
			sorted[k] = list[i];
			i++;
		} 
		else {
			sorted[k] = list[j];
			j++;
		}
		k++; //sorted array의 인덱스 k를 한칸씩 옮겨주면서 진행
	}
	// 남은 데이터 삽입
	if (i  > middle) { 
	//앞 블럭이 먼저 sorted array에 들어갈 경우 뒷 블럭의 인덱스 j를 end까지 옮겨주면서 넣어준다.
		for (int t = j; t <= end; t++) {
			sorted[k] = list[t];
			k++;
		}
	}
	else { 
	// 역시 뒷블럭이 먼저 sorted array에 들어갈 경우 앞 블럭의 인덱스 i를 middle까지 옮겨주면서 넣어준다.
		for (int t = i; t <= middle; t++) {
			sorted[k] = list[t];
			k++;
		}
	}
	for (int t = start; t <= end; t++) {
		list[t] = sorted[t];
	} // 정렬한(sorted array) 수를 다시 원래 데이터list에 넣어준다.
}

void mergeSort(int* list, int start, int end) {
	if (start < end) { // 크기가 1보다 큰 경우 mergeSort를 진행.
		int middle = (start + end) / 2;
		mergeSort(list, start, middle);
		mergeSort(list, middle + 1, end);
		merge(list, start, middle, end);
	} // 계속해서 middle을 기준으로 반으로 나누고 merge 함수를 호출하며 병합을 진행한다.
}
~~~

 - 병합 정렬의 시간 복잡도는 O(nLogn)이다.
 - 항상 반으로 나누기에 nLogn에 이미 정렬이 되어 있는 두 블럭을 합치는 것은 o(N)이기 때문이다.
 - 따라서 퀵정렬은 최악의 경우 O(N^2)이지만 병합 정렬은 항상 O(nLogn)을 보장한다.
 - 하지만 병합 정렬은 기존의 데이터를 담을 추가적인 배열 공간이 필요하다 라는 점에서 메모리 활용이 비효율적일 수 있다.
 
 ---
 
 <h4> Stack(스택) </h4>
 
  - 스택은 한쪽 입구에서 데이터를 넣고 빼는 LIFO(LAST IN FIRST OUT)의 자료구조이다.
  - 즉, 가장 최근에 추가된 데이터가 가장 먼저 제거된다.
  - C++에서는 직접 구현하거나, STL #Include <Stack>을 이용해서 사용할 수 있다.
  
  ---
  
  <h4> Queue(큐) </h4>
  
   - 큐는 양쪽에서 데이터를 넣고 뺄 수 있는 FIFO(FIRST IN FIRST OUT)의 자료구조이다.
   - 즉, 가장 먼저 넣은 데이터가 가장 먼저 제거된다. (넣은 순서대로 제거된다)
   - C++에서는 직접 구현하거나, STL #Include <Queue>를 이용해서 사용할 수 있다.
  
  ---
  
  <h3> 그래프 탐색 </h3>
  
  ---
  
  <h4> BFS(Breadth First Search) 너비 우선 탐색 </h4>
  
   - 탐색을 할 때 너비를 우선으로 하여 탐색을 수행하는 탐색 알고리즘
   - "맹목적인 탐색"을 하고자 할 때 사용할 수 있는 탐색 기법으로 "최단 경로"를 찾아준다는 점에서 최단 길이를 보장해야 할 때 많이 사용한다.
   - 일반적으로 큐(Queue) 자료구조를 이용한다.
   - 최단거리 계산에도 이용한다.
   
   ~~~ c++
   
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[1001]; 
bool check[1001]; // 방문한 노드인지 확인

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << " ";

		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];

			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {

	int n, m, start; // 노드 갯수, 간선 갯수, 시작노드
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		a[u].push_back(v); // u와 v를 입력받아서 연결해준다.
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) // 연결된 노드들을 정렬해준다 (1과 연결된 노드가 3, 5, 1이라면 1, 3, 5로)
		sort(a[i].begin(), a[i].end());

	bfs(start);

	return 0;
}

~~~

 <b> vector에 대한 이해</b>  
  - a[i].push_back(k)는 벡터요소[i]안에 추가로 [0],[1],[2]처럼 저장해준다.  
  즉 a[node].size()하면 위의 경우 3이고 그 횟수만큼 a[node][i] (a[node]안에서 index를 돌리면서 vector요소 안의 배열에 접근하는 것이다)  
  결과적으로, 그 노드에 연결된 노드들로 해석되어지며 bfs를 수행할 수 있다. 
 
 1. 시작 노드를 입력받는다.
 2. 시작 노드의 방문여부를 true로 바꾼 후, 주변 노드 검색을 위해 저장 후 queue에서 빼준다.
 3. 반복문을 통해 시작 노드에 연결된 노드들을 방문한다. (a[node].size()는 그 노드에 연결된 노드들의 갯수만큼)
 4. 각각 방문할때 방문여부를 체크 후 이미 방문했다면 다음, 방문하지 않았다면 queue에 넣어주고 방문여부를 true로 바꾼다.
 5. queue가 empty()까지 계속 반복해준다.
 
 <img src = "https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif">
   
  출처 : https://twpower.github.io/73-how-to-implement-dfs-and-bfs-in-cpp
  
  ---
  
  <h4> DFS(Depth First Search) 깊이우선탐색 </h4>
  
   - 탐색을 함에 있어 보다 깊은 것을 우선적으로 하는 탐색 알고리즘.
   - 일반적으로 스택(Stack) 알고리즘 또는 재귀함수(Recursion)을 사용한다.
   
   ~~~ c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a[1001];
bool checked[1001];
int u, v;

void dfs(int node) {
	checked[node] = true;
	cout << node << " ";

	for (int i = 0;  i < a[node].size(); i++) {
		int next = a[node][i];

		if (checked[next] == false)
			dfs(next);
	}

}

int main() {
	int n, m, start;
	cin >> n >> m >> start;

	for (int i = 0; i <m; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());

	dfs(start);

	return 0;
}
~~~

  1. 노드를 입력받은 후, 시작노드를 방문완료 후 출력해준다.
  2. 역시 a[node].size()만큼 인접노드를 탐색하되, 아직 방문하지 않았다면(false)이면 재귀호출한다. 
  3. 그렇게 깊이우선으로 탐색하다가, 어느 한점에 연결된 인접노드들이 모두 방문완료인 상태이면 재귀호출된 함수가 하나씩 종료되며 전 노드로 빠져나온다.
  4. 이런 식으로 한 노드에 대한 깊이우선으로 탐색하고 빠져 나온뒤에 다음 노드의 깊이우선으로 탐색을 반복한다.
  
  <img src = "https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif">
  
  출처 : https://twpower.github.io/73-how-to-implement-dfs-and-bfs-in-cpp
  
 ---
 
  <h4> 백 트래킹(Back Tracking) </h4>
  
   - 기본적으로 백트래킹은 '가능한 모든 방법을 탐색한다'라는 아이디어를 갖고 있다.
   - 대표적인 완전 탐색 방법으로는 DFS가 있는데 DFS는 현재 지점에서 방문할 곳이 있으면 재귀 호출을 이용해서 계속 탐색을 진행한다.
   - DFS의 장점은 무한히 깊은 곳을 찾아야 할 때 효과적인데, 모든 곳을 방문하기에 필요 없는 경로까지 탐색하므로 비효율적인 결과를 초래할 수 있다.
   - 그래서 <b> 필요 없는 경로는 차단하고 목표지점에 갈 수 있는 가능성이 있는 루트를 검사하는 방법</b>이 바로 백트래킹이다.
   
   ---
   
   <h4> 나의 공부 계획 상황 </h4>
   
    1. 자료구조 구현 및 응용 연습
    2. DP 문제와 브루트포스 (기초부터)
    3. 그래프이론(DFS, BFS) 및 백트래킹
    4. 나머지 알고리즘들(그래프 알고리즘, 이분탐색)

---
