int mx = 1000, c[mx+1];

int lowbit(int x) {
    return x & (-x);
}

int query(int i) {
    int ans = 0;
    for( ; i; i -= lowbit(i)) {
        ans = ans + c[x];
    }
    return ans;
}

void updata(int i, int x) {
    for(; i <= mx; i += lowbit(i)) {
        c[i] += x;
    }
}
