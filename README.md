# Tea Today
> MoYu的刷题记录，对于每一道题，重写一遍解答也会收获颇丰，本项目用以对每日算法题的记录，如果你也感兴趣，那就一起来刷题吧！

## CF708B [Recover The String](https://codeforces.com/problemset/problem/708/B)

输入四个数表示**只由0和1组成的字符串s**中**长为2的子序列**00，01，10，11的个数，如果能构造出这样的字符串请输出一个解，不能则输出Impossible。

```
Example 1
input
1 2 3 4
output
Impossible

Example 2
input
1 2 2 1
output
0110
```

* 解析

首先考虑$00$和$11$的子序列的个数。对于子序列$00$来说，字符串s中出现的0无论在哪都无法影响00子序列的个数，子序列$00$的个数只和$s$中$0$的个数有关。

$s$中$0$的个数为1时，$00$的子序列个数为$0$；s中$0$的个数为2时，$00$的子序列个数为$1$；s中$0$的个数为3时，$00$子序列的个数为$2 + 1 = 3$个；$s$中$0$的个数为$n$时，$00$子序列的个数为$n-1 + n - 2 +...+1 =\frac{n(n-1)}{2}$。因此$00$子序列的个数a来说需要满足$a=\frac{n(n-1)}{2}$的方程有正整数解，我们还需要考虑特殊情况，$00$或者$11$子序列个数为$0$但方程的解为1的情况，这时只有$01$子序列和$10$子序列全为$0$才能成立，我们对输出$11$或者$00$子序列对应的解$n$即可。

再来考虑$01$和$10$的个数之间的关系，当我们交换前面的一个$0$和后面的一个1的时候，$01$的数量减少，$10$的数量增加。我们可以不断的交换相邻的两个数来达到交换不同位置的$0$和$1$的目的，每次交换的相邻$01$的时候$01$子序列都会减少一个，同时$10$的子序列都会增加$1$个，可以得出$01$和$10$子序列的总和保持不变。对于输入的$01$和$10$的子序列的个数$b$和$c$的总和必须等于$0$的个数$n_{0}$和1的个数$n_{1}$的乘积（$0$全在$1$前面的情况）。

最后，我们构造出有多少个$0$在$1$的前面，我们可以假设所有的$1$全在后面，当有一个$0$在前面时，$01$子序列的个数就会增加$n_{1}$，因此我们计算$\frac {b}{n_{1}}$，放$\frac {b}{n_{1}}$个$0$在最前方，对于余数$b\%n_{1}$，我们可以单独在$n_{1}$个1的倒数第$b\%n_{1}$个位置放入$0$，这样就满足了题目的要求，最后若有剩余的$0$我们需要放在字符串的最后面。

* 代码

```c++
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
```



## CF1385E [Directing Edges](https://codeforces.com/contest/1385/problem/E)

给定一个有$n$个顶点的图的$m$条边，$m$条边存在无向边和有向边。请将所有的无向边变成有向，若存在一种方法让该图成为一个有向无环图，输出所有边，否则输出No。

```c
// input
4 //t
3 1 //m n
0 1 3 // 第一个数字0表示无向，1表示有向，后面两个数字为顶点，若为有向，则顶点1指向顶点2
5 5
0 2 1
1 1 5
1 5 4
0 5 2
1 3 5
4 5
1 1 2
0 4 3
1 3 1
0 2 3
1 2 4
4 5
1 4 1
1 1 3
0 1 2
1 2 4
1 3 2
```

* 解析

我们首先只考虑给定的所有有向边，若对所有顶点进行拓扑排序之后不存在环，我们则可以按照拓扑排序之后的顺序将所有无向边进行构造，若拓扑排序有环的话则不可以。

有关拓扑排序，我们可以按算法导论书中的思路，用三种颜色标记顶点， 当访问到的顶点之前正在访问时，说明存在环，若不是，则继续在该节点DFS，这样就会返还一个order数组，order中下标越靠前的顶点先访问到。

```c++
enum color{white, gray, black};
vector<int> order;
vector<color> color;
bool DFS(vector<vector<int>> &g,int  u)
{
    // 正在访问
    colors[u] = gray;
    // 访问u指向的顶点v
    for(auto v : g[u]) {
        if (colors[v] == gray) return false;
        if (colors[v] == white && !DFS(g, v)) return false;
    }
    // 访问结束
    colors[u] = black;
    // 放入order中
    order.push_back(u);
    return true;
}
```



* 代码

```c++
#include<iostream>
#include<vector>
using namespace std;


vector<int> ord;
vector<vector<int>> g;
vector<int> color;


    
// 单个顶点dfs
bool dfs(vector<vector<int>> &g, int u) {
    color[u] = 1;
    for(auto v : g[u]) {
        if (color[v] == 1) return false;
        if (color[v] == 0 && !dfs(g, v)) return false;
    }
    color[u] = 2;
    ord.push_back(u);
    return true;
}

// 所有顶点dfs
bool tpdfs(vector<vector<int>> &g, int n) {
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && !dfs(g, i)) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        g = vector<vector<int>>(n);
        vector<vector<int>> edges;
        for(int i = 0; i < m; i++) {
            int a,b,c;
            cin >> a >> b >>c;
            b--;c--;
            edges.push_back({b,c});
            if(a==1){
                g[b].push_back(c);
            }
        }
        ord.clear();
        color = vector<int> (n);
        if (!tpdfs(g, n)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            vector<int> pos(n);
            for(int i = 0; i < n; i++) {
                pos[ord[i]] = i;
            }
            for(int i = 0; i < m; i++) {
                if(pos[edges[i][0]] < pos[edges[i][1]]) {
                    cout << edges[i][1] + 1 << ' ' << edges[i][0] + 1 << endl;
                } else {
                    cout << edges[i][0] + 1 << ' ' << edges[i][1] + 1 << endl;
                }
            }
        }
    }
    return 0;
}
```

## CF735C [Mikasa](https://codeforces.com/problemset/problem/1554/C)

给定两个数$n$和$m$，计算出所有的$n \bigoplus i$形成序列，其中$0 <= i <= m$，找到不在该序列中的最小正整数，定义为$MEX$，例如$MEX(0, 1, 2, 4) = 3, MEX(1, 2021) = 0$。

* *Example*

```c
/*input
5
3 5
4 6
3 2
69 696
123456 654321*/
output
4
3
0
640
530866
```

* 解析

思考$n \bigoplus i = k$ 等同于 $n \bigoplus k = i$，我们只要找到最小的$k$使得$n \bigoplus k = m+1$即可？我们从高到低比较二进制表示下$n$的第$i$位$n_{i}$和$m+1$的第$i$位$m_{i}$，若$n_{i}=1，m_{i}=1 ; n_{i}=0，m_{i}=0$，则$k_{i} = 0$； 若$n_{i}=1，m_{i}=0$，则$k_{i} = 0$之后位全取$0$即可，即$n > m$时直接退出；若$n_{i}=0，m_{i}=1$则$k_{i} = 1$。

* 代码

```cpp
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

```



