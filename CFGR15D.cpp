#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> a(20);

int main() {
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_set<long long> st;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ok = false;
        for(int i = 0; i < (1 << n); i++) {
            long long sum = 0;
            for(int j = 0; j < n; j++) {
                if ((i>>j) & 1) {
                    sum += a[j];
                }
            }
            if(st.count(sum)) {
                cout << "Yes" << endl;
                ok = true;
                break;
            }
            st.insert(sum);
        }
        if(!ok) {
            cout << "No" << endl;
        }
    }
}
