#include <iostream>

using namespace std;

int map[502][502];
int dp[502][502];

int main() {
    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(map[i][j] == 0) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else if(map[i][j] == 2) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
            else dp[i][j] = 0;
        }
    }

    cout << dp[n][m];

    return 0;
}