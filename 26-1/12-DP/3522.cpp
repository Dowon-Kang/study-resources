#include <iostream>

using namespace std;

long long dp[100001];

int main() {
    
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= 100000; ++i) {
        dp[i] = (dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007) % 1000000007;
    }

    int n;

    cin >> n;   

    cout << dp[n];

    return 0;
}