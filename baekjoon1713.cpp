#include <iostream>

using namespace std;

int n;  // 사진틀의 갯수  
int pic_frame[20]; // 사진틀(자료구조) 0 ~ 19 index를 갖는다 
int num_cc; // 추천갯수  
int ord_cc[1000]; // 추천 순서
int cand_like[101]; //후보 추천 횟수
int cand_where[101]; // 후보가 어떤 사진틀에 걸려있는 지 
int cand_when[101]; // 언제 올라갔는지


int get_pic_frame() {
    // 빈 자리가 있다면 포지션 리턴
    for (int i = 1; i <= n; i++) {
        if (pic_frame[i] == 0)
            return i;
    }

    int min_like = 1000;
    int old_when = 1000; // 수가 작을수록 오래된 것
    int res = 0;
    for (int i = 0; i < n; i++) {
        int cur = pic_frame[i];
        if (min_like > cand_like[cur]) {
            min_like = cand_like[cur];
            old_when = cand_when[cur];
            res = i;
        }
        else if (min_like == cand_like[cur] && old_when > cand_when[cur]) {
            old_when = cand_when[cur];
            res = i;
        }
    }
    return res;
    
}

int main() {
    cin >> n >> num_cc;

    for (int i = 0; i < num_cc; i++) {
        cin >> ord_cc[i]; // 2 1 4 3 5 6 2 7 2 순서로 배열에 저장
    }

    // 초기화 
    for (int i = 1; i <= 100; i++) {
        cand_where[i] = -1;
        cand_when[i] = -1;
    }

    // 추천을 수행한다 .... num_cc만큼
    for (int i = 0; i < num_cc; i++) {
        int cur = ord_cc[i]; // 입력받은 순서
        // 후보가 사진틀에 올라가 있을까?
        if (cand_where[cur] != -1) { // 있다면
            // 좋아요만 올려줌 
            cand_like[cur]++;
        }
        else {
            // 비어있는 또는 후보를 넣을 사진틀을 얻는다. 
            int pos = get_pic_frame();
            int delete_cand = pic_frame[pos];
            // delete_cand는 사진틀에서 내리면서, 좋아요도 초기화한다
            if (delete_cand != 0) {
                cand_where[delete_cand] = -1;
                cand_like[delete_cand] = 0;
            }
            cand_where[cur] = pos;
            cand_like[cur] = 1;
            cand_when[cur] = i;
            pic_frame[pos] = cur;
        }
    }

    // 정답을 출력한다
  // pic_frame을 조사해서, 누가 사진틀에 있는지확인하고,
  // 후보들을 모아서 번호가 증가하는 순서대로 출력한다.. 
    for (int i = 1; i <= 100; i++) {
        if (cand_where[i] != -1) {
            cout << i << " ";
        }
    }
}