#include<stdio.h>
#include<string.h>
#include<stdbool.h>
// 从c中选择两个不相交的子集，其中一个和为x，另一个和为k-x

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    int a[n+1];
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    int dp[k+1][k+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j1 = k; j1 >= 0; j1--) {
            for(int j2 = k; j2 >= 0; j2--) {
                if (j1 >= a[i])
                dp[j1][j2] |= dp[j1-a[i]][j2];
                if (j2 >= a[i])
                dp[j1][j2] |= dp[j1][j2-a[i]];
            }
        }
    }
    int ans[n];
    int size = 0;
    for(int x = 0; x <= k; x++) {
        if (dp[x][k-x]) ans[size++]=x;
    }
    printf("%d\n",size);
    for(int i = 0; i < size; i++) printf("%d ", ans[i]);
    return 0;
}