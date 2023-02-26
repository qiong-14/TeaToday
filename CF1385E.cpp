
// vector<int> TpSort(vector<vector<int>> edges, int n) {
//     queue<int> S;
//     vector<int> L;
//     vector<int> in(n);
//     vector<vector<int>> g(n);
//     for(int i = 0; i < edges.size(); i++) {
//         in[edges[i][1]]++;
//         g[edges[i][0]].push_back(edges[i][1]);
//     }
//     for(int i = 0; i < n; i++) {
//         if (in[i] == 0) S.push(i);
//     }
//     while(!S.empty()) {
//         int u = S.front(); S.pop();
//         L.push_back(u);
//         for(auto v : g[u]) {
//             if(in[v]-- == 1) S.push(v);
//         }
//     }
//     return L;
// }
// int t;
// enum color {white, gray, black};

// struct point {
//     int start;
//     int end;
//     color color;
// };
// bool DFS_VISIT(vector< vector<int> > &g, int u, vector<point> &node) {
//     t = t + 1;
//     node[u].start = t;
//     node[u].color = gray;
//     for (auto v : g[u]) {
//         if (node[v].color == gray) return false;
//         if (node[v].color == white && !DFS_VISIT(g, v, node)) return false;
//     }
//     node[u].color = black;
//     t = t + 1;
//     node[u].end = t;
//     order.push_back(u);
//     return true;
// }
// bool DFS(vector<vector<int>> &g, int n) {
//     vector<point> node(n);
//     for(int i = 0; i < n; i++) {
//         node[i].start = 0;
//         node[i].end = 0;
//         node[i].color = white;
//     }
//     t = 0;
//     for(int i = 0; i < n; i++) {
//         if(node[i].color == white && !DFS_VISIT(g, i, node)) {
//             return false;
//         }
//     }
//     return true;
// }
#include<iostream>
#include<vector>
using namespace std;
vector<int> ord;
vector<vector<int>> g;
vector<int> color;

bool dfs(vector<vector<int>> &g, int u) {
    color[u] = 1;
    for(auto v : g[u]) {
        if (color[v] == 1) return false;
        if (color[v] == 0 && !dfs(g, v)) return false;
    }
    color[u] = 2;
    ord.push_back(u);
    return true;
}

bool tpdfs(vector<vector<int>> &g, int n) {
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && !dfs(g, i)) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        g = vector<vector<int>>(n);
        vector<vector<int>> edges;
        for(int i = 0; i < m; i++) {
            int a,b,c;
            cin >> a >> b >>c;
            b--;c--;
            edges.push_back({b,c});
            if(a==1){
                g[b].push_back(c);
            }
        }
        ord.clear();
        color = vector<int> (n);
        if (!tpdfs(g, n)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            vector<int> pos(n);
            for(int i = 0; i < n; i++) {
                pos[ord[i]] = i;
            }
            for(int i = 0; i < m; i++) {
                if(pos[edges[i][0]] < pos[edges[i][1]]) {
                    cout << edges[i][1] + 1 << ' ' << edges[i][0] + 1 << endl;
                } else {
                    cout << edges[i][0] + 1 << ' ' << edges[i][1] + 1 << endl;
                }
            }
        }
    }
    return 0;
}