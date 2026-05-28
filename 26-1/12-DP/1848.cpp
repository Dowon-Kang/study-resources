#include <iostream>

using namespace std;

long long dp[41];

int main() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= 40; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2]; 
    }

    int n, m, num;
    int pre = 0;
    long long res = 1;

    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        cin >> num;

        res *= dp[num - pre - 1];

        pre = num;
    }

    res *= dp[n - pre];

    cout << res;

    return 0;
}