#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct vi{
    int v;
    int i;
};

struct node {
    int l;
    int r;
    int i;
};

int main() {
    int n;
    cin >> n;
    vector<vi> ps(2*n);
    for(int i = 0; i < 2*n; i++) {
        cin >> ps[i].v;
        ps[i].i = i;
    }
    sort(ps.begin(), ps.end(), [](const vi &a, const vi &b) {
        return a.v < b.v;
    });
    vector<int> kth(2*n);
    for(int i = 0; i < 2*n; i++) {
        kth[ps[i].i] = i + 1;
    }
    vector<node> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = node{kth[2*i], kth[2*i+1], i};
    }
    sort(a.begin(), a.end(), [](const node &x, const node &y) {
        return x.r < y.r;
    });
    vector<int> ans(n), tree(2*n+1);
    for(int i = 0; i < n; i++) {
        node p = a[i];
        int c = i;
        for(int i = p.l; i > 0; i &= i - 1) {
            c -= tree[i];
        }
        ans[p.i] = c;
        for (int i = p.l; i <= 2*n; i += i & -i) {
            tree[i]++;
        }
    }
    for (auto i : ans) cout << i << endl;
}