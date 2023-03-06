#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t,n,m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        // m + 1
        m++;
        // k 开始所有位全为0
        int k = 0;
        for(int i = 30; i >= 0 && n < m; i--){
            // 情况1 ni = 1, mi = 1 或者 ni = 0 mi = 0 ki 可直接取0
            if ((n >> i & 1) == (m >> i & 1) ) continue;
            // 情况3 ni = 0 mi = 1 ki必须取1
            if (m >> i & 1) k |= 1 << i, n |= 1 << i;
            // 情况2 在循环判断条件里面
        }
        cout << k << endl;
    }
    return 0;
}
