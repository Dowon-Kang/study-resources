#include <iostream>
#include <string>

using namespace std;

bool board[10][10];
bool col[10];
int n;
int cnt = 0;

void rook(int row) {
    if(row == n) {
        ++cnt;

        return;
    }

    for(int i = 0; i < n; ++i) {
        if(col[i] == false && board[row][i] == false) {
            col[i] = true;

            rook(row + 1);

            col[i] = false;
        }
    }
}

int main() {
    string s;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> s;

        for(int j = 0; j < n; ++j) {
            if(s[j] == '#') {
                board[i][j] = true;
            }
        }
    }

    rook(0);

    cout << cnt;

    return 0;
}