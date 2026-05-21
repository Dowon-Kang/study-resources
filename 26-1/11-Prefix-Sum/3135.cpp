#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q, l, r;

    cin >> n;

    vector<long long> v(n + 1);
    vector<long long> s(n + 1);

    for(long long i = 1; i <= n; ++i) {
        cin >> v[i];

        s[i] = v[i] + s[i - 1];
    }

    cin >> q;

    for(long long i = 0; i < q; ++i) {
        cin >> l >> r;

        cout << s[r] - s[l - 1] <<  "\n";
    }

    return 0;
}