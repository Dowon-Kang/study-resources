#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q, lc, lr, rc, rr;

    cin >> n;

    vector<vector<long long>> v(n + 1, vector<long long>(n + 1));
    vector<vector<long long>> s(n + 1, vector<long long>(n + 1));

    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            cin >> v[i][j];

            s[i][j] = v[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
        }
    }

    cin >> q;

    for(long long i = 0; i < q; ++i) {
        cin >> lc >> lr >> rc >> rr;

        cout << s[rc][rr] - s[lc - 1][rr] - s[rc][lr - 1] + s[lc - 1][lr - 1] << "\n";
    }

    return 0;
}