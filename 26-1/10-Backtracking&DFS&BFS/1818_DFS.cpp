#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[101];
bool visit[101];

void dfs(int cur) {
    visit[cur] = true;

    for(int next : adj[cur]) {
        if(!visit[next]) dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    int cnt = 0;

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(1);

    for(int i = 2; i <= n; i++) {
        if(visit[i]) ++cnt;
    }

    cout << cnt;

    return 0;
}