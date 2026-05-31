#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int board[26][26];
bool visit[26][26];
int n;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visit[row][col] = true;

    int cnt = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if (board[nr][nc] == 1 && !visit[nr][nc]) {
                    visit[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') board[i][j] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1 && !visit[i][j]) {
                v.push_back(bfs(i, j));
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for (int i : v) {
        cout << i << "\n";
    }

    return 0;
}