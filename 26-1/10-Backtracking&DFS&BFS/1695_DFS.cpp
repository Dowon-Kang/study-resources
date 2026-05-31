#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int board[26][26];
bool visit[26][26];
int n;
// 방향성 : 상, 하, 좌, 우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dfs(int row, int col) {
    visit[row][col] = true;

    int cnt = 1;

    for(int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
            if(board[nr][nc] == 1 && visit[nr][nc] == false) cnt += dfs(nr, nc); 
        }
    }

    return cnt;
}

int main() {
    string s;
    vector<int> v;
    
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> s;

        for(int j = 0; j < n; ++j) {
            if(s[j] == '1') board[i][j] = 1;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(board[i][j] == 1 && visit[i][j] == false) {
                v.push_back(dfs(i, j));
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";

    for(int i : v) {
        cout << i << "\n";
    }

    return 0;
}