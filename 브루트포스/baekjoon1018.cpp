#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
string board[50];

string whiteFirst[8] = {
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" }
};

string blackFirst[8] = {
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" }
};

int blackCheck(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            if (board[i][j] != blackFirst[i - y][j - x])
                cnt++;
        }
    }
    return cnt;
}

int whiteCheck(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            if (board[i][j] != whiteFirst[i - y][j - x])
                cnt++;
        }
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    
    int minValue = 2500;

    for (int i = 0; i + 7 < N; i++) {
        for (int j = 0; j + 7 < M; j++) {
            minValue = min(minValue, min(whiteCheck(i, j), blackCheck(i, j)));
        }
    }
    cout << minValue << "\n";
	
}