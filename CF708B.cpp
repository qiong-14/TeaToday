#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    double zero = (1 + sqrt(1 + 8 * double(a)))/2;
    double one = (1 + sqrt(1 + 8 * double(d)))/2;
    if((zero - int(zero)) > 1e-10 || (one - int(one)) > 1e-10 ) {
        cout << "Impossible" << endl;
        return 0;
    }
    int n0 = int(zero);
    int n1 = int(one);
    if(a == 0 && b == 0 && c == 0) {
        for(int i = 0; i < n1; i++) {
            printf("%c",'1');
        }
        return 0;
    }
    if(d == 0 && b == 0 && c == 0) {
        for(int i = 0; i < n0; i++) {
            printf("%c",'0');
        }
        return 0;
    }
    if (b+c != n0*n1) {
        cout << "Impossible" << endl;
        return 0;
    }
    int preOne = c/n0, lastOne = c%n0;
    for(int i = 0; i < preOne; i++) {
        printf("%c", '1');
    }
    for(int i = 0; i < n0 - lastOne; i++) {
        printf("%c", '0');
    }
    if(preOne < n1) {
        printf("%c", '1');
    }
    for(int i = 0; i < lastOne; i++) {
        printf("%c", '0');
    }
    for(int i = 0; i < (n1 - (preOne + 1)); i++) {
        printf("%c", '1');
    }
    return 0;
}