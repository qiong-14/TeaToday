#include<iostream>
#include<string>
#include<vector>
using namespace std;
char find(char a, char b) {
    for(int i = 'a'; i <= 'z'; i++) {
        if (i!=a && i!=b) return i;
    }
    return ' ';
}
int main() {
    int n, t;
    cin >> n >> t;
    char c[n];
    string a,b;
    cin >> a >> b;
    int minT = 0, cnt[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            minT += 1;
            c[i] = (minT%2)?a[i]:b[i];
            cnt[minT%2]++;
        } else {
            c[i] = a[i];
        }
    }
    minT = (minT + 1)/2;
    if (minT > t ) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i] && cnt[0] < t && cnt[1] < t) {
            c[i] = (a[i] - 'a' + 1) % 26 + 'a';
            cnt[0]++; cnt[1]++;
        } 
    }
    for(int i = 0; i < n && (cnt[0] < t || cnt[1] < t); i++) {
        if(a[i] != b[i]) {
            c[i] == a[i] ? cnt[0]++ : cnt[1]++;
            c[i] = find(a[i], b[i]);
        } 
    }
    for(int i = 0; i < n; i++) cout << c[i];
    cout << endl;
    return 0;
}