#include<iostream>
#include<math.h>
using namespace std;

int main() {
    //  00 01 10 11
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // 0的个数
    double zero = (1 + sqrt(1 + 8 * double(a)))/2;
    // 1的个数
    double one = (1 + sqrt(1 + 8 * double(d)))/2;

    // 解不是正整数
    if((zero - int(zero)) > 1e-10 || (one - int(one)) > 1e-10 ) {
        cout << "Impossible" << endl;
        return 0;
    }
    int n0 = int(zero);
    int n1 = int(one);
    // 特殊情况
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
    // 01和10个数和不等于n0*n1
    if (b+c != n0*n1) {
        cout << "Impossible" << endl;
        return 0;
    }
    // 把0全放在后面，计算前面1的个数以及中间1的位置
    int preOne = c/n0, lastOne = c%n0;
    // 输出preOne个1
    for(int i = 0; i < preOne; i++) {
        printf("%c", '1');
    }
    // 输出n0-lastOne个0
    for(int i = 0; i < n0 - lastOne; i++) {
        printf("%c", '0');
    }
    // 如果有余数则放入1，并且已经使用的1的个数加1
    if(lastOne > 0) {
        preOne += 1;
        printf("%c", '1');
    }
    // 放入后面的0
    for(int i = 0; i < lastOne; i++) {
        printf("%c", '0');
    }
    // 放入剩余的1
    for(int i = 0; i < (n1 - preOne); i++) {
        printf("%c", '1');
    }
    return 0;
}