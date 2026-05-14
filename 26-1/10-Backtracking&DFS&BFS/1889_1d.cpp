#include <iostream>
#include <cmath>

using namespace std;

int board[15];
int n;
int cnt = 0;

void queen(int row) {
    if(row == n) {
        ++cnt;

        return;
    }

    for(int i = 0; i < n; ++i) {
        bool check = true;
        board[row] = i;

        for(int j = 0; j < row; ++j) {
            if(board[j] == board[row]) {
                check = false;

                break;
            }
            
            if(abs(row - j) == abs(board[j] - board[row])) {
                check = false;

                break;
            }
        }

        if(check) queen(row + 1);
    }
}

int main() {
    cin >> n;

    queen(0);

    cout << cnt;

    return 0;
}