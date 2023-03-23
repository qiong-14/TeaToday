#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;        
        sort(s.begin(), s.end());
        string s1 = "",s2 = "";
        for(auto &c : s) {
            if(c&1) s1+=c;
            else s2+=c;
        }
        if(s1.size() == 0) {
            cout << s2 << endl;
        } else if (s2.size() == 0) {
            cout << s1 << endl;
        } else if (abs(s1[s1.size() - 1] - s2[0]) != 1) {
            cout << s1 << s2 << endl;
        } else if (abs(s2[s2.size() - 1] - s1[0]) != 1) {
            cout << s2 << s1 << endl;
        } else {
            cout << "No answer" << endl;
        }
    }
    return 0;
}