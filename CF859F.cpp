#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

unordered_map<string, pair<int,int>> DIR(
    {{"DR",make_pair(1,1)},
    {"DL",make_pair(1,-1)},
    {"UR",make_pair(-1,1)},
    {"UL",make_pair(-1,-1)}});
int main() {
    int t;
    cin>>t;
    int n,m,i1,j1,i2,j2;
    vector<int> ans(t,-1);
    string d;
    for(int i = 0; i < t; i++) {            
        cin>>n>>m>>i1>>j1>>i2>>j2>>d;
        int s=i1,e=j1;
        int step = 1;
        vector<vector<int>> vis(n+1, vector<int>(m+1,0));
        while(step<=4*n*m) {
            if(!vis[i1][j1])
            vis[i1][j1] = step;
            int flag = 0;
            if(i1==1&&d[0]=='U') {
                flag=1;d[0]='D';
            }else if(i1==n&&d[0]=='D') {
                flag=1;d[0]='U';
            }
            if(j1==1&&d[1]=='L') {
                flag=1;d[1]='R';
            }else if(j1==m&&d[1]=='R') {
                flag=1;d[1]='L';
            }   
            if(flag) step++;     
            i1 = i1 + DIR[d].first;
            j1 = j1 + DIR[d].second;
        }
        if(vis[i2][j2]) ans[i] = vis[i2][j2]-1;
    }
    for(auto &x:ans) cout << x << endl;

    return 0;
}