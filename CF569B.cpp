#include<iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int x = 1, y = 1;
    for (int i = 1; i <= n/2; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d %d\n%d %d\n", i, j, n - i + 1, m - j + 1);
        }
    }
    if (n % 2) {
        int mid =  (n + 1) / 2;
        for (int j = 1; j <= m/2; j++) {
            printf("%d %d\n%d %d\n",mid, j, mid, m - j + 1);
        }
        if (m % 2) {
            printf("%d %d\n", mid, (m + 1)/2);
        }
    }
}