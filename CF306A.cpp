#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string s;
    cin >> s;


    vector<int> a, b;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A' && s[i+1] == 'B') a.push_back(i);
        if (s[i] == 'B' && s[i+1] == 'A') b.push_back(i);
    }
    for(int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if(abs(a[i] - b[j]) >= 2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
