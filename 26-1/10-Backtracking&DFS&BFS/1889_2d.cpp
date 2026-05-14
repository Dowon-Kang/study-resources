#include <iostream>
#include <cmath>

using namespace std;

int board[15][15]; 
int n;
int cnt = 0;

void queen(int row) {
    if(row == n) {
        ++cnt;

        return;
    }

    for(int i = 0; i < n; ++i) {
        bool check = true;
        board[row][i] = 1;

        for(int j = 0; j < row; ++j) {
            int k = -1; // 이전 행에 배치된 퀸의 열

            for(int m = 0; m < n; ++m) {
                if(board[j][m] == 1) {
                    k = m;

                    break;
                    // 한 행에는 하나의 퀸만 존재하므로 찾으면 break;
                }
            }

            if(k == i) {
                check = false;

                break;
            }
            
            if(abs(row - j) == abs(k - i)) {
                check = false;

                break;
            }
        }

        if(check) queen(row + 1);

        board[row][i] = 0;
    }
}

int main() {
    cin >> n;

    queen(0);
    
    cout << cnt;

    return 0;
}