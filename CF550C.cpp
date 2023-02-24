#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<bool>> dp(n+1, vector<bool>(8));
    vector<vector<string>> ans(n+1, vector<string>(8));
    for(int i = 0; i <= n; i++) dp[0][i] = false;
    dp[0][0] = true;
    for(int i = 1; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            if (dp[i - 1][j]) {
                int x = s[i-1] - '0';
                dp[i][j] = true;
                dp[i][(j*10 + x) % 8] = true;
                ans[i][j] = ans[i-1][j];
                ans[i][(j*10 + x) % 8] = ans[i-1][j] + s[i - 1];
            }
        }
        if (dp[i][0] && ans[i][0].size() > 0) {
            cout << "Yes\n" << ans[i][0] << endl;
            return 0; 
        }
    } 
    cout << "No" << endl;
    return 0;
}