#include <iostream>

using namespace std;

int n;  // ����Ʋ�� ����  
int pic_frame[20]; // ����Ʋ(�ڷᱸ��) 0 ~ 19 index�� ���´� 
int num_cc; // ��õ����  
int ord_cc[1000]; // ��õ ����
int cand_like[101]; //�ĺ� ��õ Ƚ��
int cand_where[101]; // �ĺ��� � ����Ʋ�� �ɷ��ִ� �� 
int cand_when[101]; // ���� �ö󰬴���


int get_pic_frame() {
    // �� �ڸ��� �ִٸ� ������ ����
    for (int i = 1; i <= n; i++) {
        if (pic_frame[i] == 0)
            return i;
    }

    int min_like = 1000;
    int old_when = 1000; // ���� �������� ������ ��
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
        cin >> ord_cc[i]; // 2 1 4 3 5 6 2 7 2 ������ �迭�� ����
    }

    // �ʱ�ȭ 
    for (int i = 1; i <= 100; i++) {
        cand_where[i] = -1;
        cand_when[i] = -1;
    }

    // ��õ�� �����Ѵ� .... num_cc��ŭ
    for (int i = 0; i < num_cc; i++) {
        int cur = ord_cc[i]; // �Է¹��� ����
        // �ĺ��� ����Ʋ�� �ö� ������?
        if (cand_where[cur] != -1) { // �ִٸ�
            // ���ƿ丸 �÷��� 
            cand_like[cur]++;
        }
        else {
            // ����ִ� �Ǵ� �ĺ��� ���� ����Ʋ�� ��´�. 
            int pos = get_pic_frame();
            int delete_cand = pic_frame[pos];
            // delete_cand�� ����Ʋ���� �����鼭, ���ƿ䵵 �ʱ�ȭ�Ѵ�
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

    // ������ ����Ѵ�
  // pic_frame�� �����ؼ�, ���� ����Ʋ�� �ִ���Ȯ���ϰ�,
  // �ĺ����� ��Ƽ� ��ȣ�� �����ϴ� ������� ����Ѵ�.. 
    for (int i = 1; i <= 100; i++) {
        if (cand_where[i] != -1) {
            cout << i << " ";
        }
    }
}