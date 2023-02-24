#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int dp[n];
    for(int i = 0; i < n; i++) dp[i] = 0;
    int ans = 0, cnt = 0;
    for(int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (dp[i - 1] == 0) {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i > 2) dp[i] += dp[i - 2];
                }
            } else {
                int j = i - 1 - dp[i - 1];
                if (j >= 0 && s[j] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (j - 1 >= 0) {
                        dp[i] += dp[j - 1];
                    }
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    for (int i = 0; i < n; i++) {
        if (dp[i] == ans) cnt++;
    }
    if (ans == 0) cnt = 1;
    cout << ans << ' ' << cnt << endl;

}