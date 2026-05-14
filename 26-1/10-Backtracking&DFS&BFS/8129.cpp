#include <iostream>
#include <vector>

using namespace std;

int n, k;
int count = 0;
int result = -1;
bool check;
vector<int> v;
vector<int> store(10);

void combine(int cnt, int start) {
    if(result != -1) return;
    
    if(cnt == k) {
        check = true;

        ++count;

        for(int i = 0; i < k; ++i) {
            if(v[i] != store[i]) {
                check = false;

                break;
            }
        }

        if(check) result = count;

        return;
    }

    for(int i = start; i <= n; ++i) {
        store[cnt] = i;

        combine(cnt + 1, i + 1);
    }
}

int main() {
    int num;

    cin >> n >> k;

    for(int i = 0; i < k; ++i) {
        cin >> num;

        v.push_back(num);
    }

    combine(0, 1);

    if(result == -1) cout << "None";
    else cout << result;

    return 0;
}