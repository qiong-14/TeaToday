#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int cnt = 0, n, mi;
vector<vector<int>> g;
unordered_set<long long> edges;
vector<int> ans;

void dfs(int u, int fa) {
    for (auto v : g[u]) {
        if(v!=fa) {
            if(!edges.count(1LL*u*n + v))cnt++;
            dfs(v, u);
        }
    }
}

void reboot(int u, int fa, int c) {
    mi = min(mi, c);
    for(auto v : g[u]) {
        if (v != fa) {
            int c1 = c - edges.count(1LL*v*n + u) + edges.count(1LL*u*n + v);
            ans[v] = min(ans[v], c1);
            reboot(v, u, c1);
        }
    }
}

int  main() {
    scanf("%d", &n);
    g = vector<vector<int>>(n);
    ans = vector<int>(n, n-1);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d",&u, &v);
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.insert(1LL*u*n + v);
    }
    cnt = 0;
    mi = n - 1;
    dfs(0, -1);
    ans[0] = cnt;
    reboot(0, -1, cnt);
    printf("%d\n", mi);
    for(int i = 0; i < n; i++) {
        if(mi == ans[i]) printf("%d ", i + 1);
    }
    printf("\n");
    return 0;
}