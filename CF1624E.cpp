#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        unordered_map<string, vector<int>> have;
        for(int i = 1; i <= n; i++) {
            string a;cin>>a;a=" " + a;
            for(int j = 1; j+1 <= m; j++) have[a.substr(j,2)] = {j,j+1,i};
            for(int j = 1; j+2 <= m; j++) have[a.substr(j,3)] = {j,j+2,i};
        }
        string s; cin>>s;s=" "+s;
        vector<int> dp(m+1);
        dp[0] = 1;
        for(int i = 2; i <= m; i++) {
            if(dp[i-2] && have.find(s.substr(i-1,2))!=have.end()) 
                dp[i] = 1;
            if(i >= 3 && dp[i-3]&&have.find(s.substr(i-2,3))!=have.end()) 
                dp[i] = 1;
        }
        if(dp[m]) {
            vector<vector<int>> ans;
            for(int i = m; i >= 1;) {
                if(dp[i-2] && have.find(s.substr(i-1,2))!=have.end()) {
                    ans.push_back(have[s.substr(i-1,2)]);
                    i-=2;
                } else {
                    ans.push_back(have[s.substr(i-2, 3)]);
                    i-=3;
                }
            }
            cout << ans.size() << endl;
            for(int i = ans.size()-1; i>=0; i--) {
                cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}