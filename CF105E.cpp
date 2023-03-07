#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n,m,k,x,t=0;
    cin >> n >> m;
    vector<int> dp(m+1);
    while(n--) {
        cin >> k;
        vector<int> s(k+1); 
        // 前缀和
        for(int i = 1; i <= k; i++) {
            cin >> x;
            s[i] = s[i-1] + x;
        }
        vector<int> mx(k+1);
        // 计算从第i行数据中选i个数的最大和, i = 1~k
        // 遍历前面选j个数和后面选i-j个数的所有情况，取最大值
        // 前面 i 个 s[i], 后面 j - i 个 s[k] - s[k - i + j]
        for(int i = 1; i <= k; i++) {
            for (int j = 0; j <= i; j++) {   
                mx[i] = max(mx[i], s[j] + s[k] - s[k - (i - j)]);
            }
        }
        t = min(t+k, m);
        // 计算前 i 行选择 c 个数的最大和 
        // = 前 i-1 行 选 c - j 个数 的最大和 与 当前行选j个数的最大和
        // dp[i][c] = dp[i - 1][c - j] + mx[j]
        // 空间优化一下 从高到低遍历c dp[c] = dp[c-j] + mx[j]
        // 优化上界，从前面所有行的和与m的最小值开始
        for(int c = t; c >= 0; c--) {
            for(int j = 0; j <= k && j <= c; j++) {
                dp[c] = max(dp[c], dp[c - j] + mx[j]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}