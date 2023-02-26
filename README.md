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

首先考虑00和11的子序列的个数。对于子序列00来说，字符串s中出现的0无论在哪都无法影响00子序列的个数，子序列00的个数只和s中0的个数有关。

s中0的个数为1时，00的子序列个数为0；s中0的个数为2时，00的子序列个数为1；s中0的个数为3时，00子序列的个数为2 + 1 = 3个；s中0的个数为n时，00子序列的个数为n-1 + n - 2 +...+1 = n(n-1)/2。因此00子序列的个数a来说需要满足a = n(n-1)/2的方程有正整数解，我们还需要考虑特殊情况，00或者11子序列个数为0但方程的解为1的情况，这时只有01子序列和10子序列全为0才能成立，我们对输出11或者00子序列对应的解n即可。

再来考虑01和10的个数之间的关系，当我们交换前面的一个0和后面的一个1的时候，01的数量减少，10的数量增加。我们可以不断的交换相邻的两个数来达到交换不同位置的0和1的目的，每次交换的相邻01的时候01子序列都会减少一个，同时10的子序列都会增加1个，可以得出01和10子序列的总和保持不变。对于输入的01和10的子序列的个数b和c的总和必须等于0的个数n0和1的个数n1的乘积（0全在1前面的情况）。

最后，我们构造出有多少个0在1的前面，我们可以假设所有的1全在后面，当有一个0在前面时，01子序列的个数就会增加n1，因此我们计算b/n1，放b/n1个0在最前方，对于余数b%n1，我们可以单独在n1个1的倒数第b%n1个位置放入0，这样就满足了题目的要求，最后若有剩余的0我们需要放在字符串的最后面。

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

给定一个有n个顶点的图的m条边，m条边存在无向边和有向边。请将所有的无向边变成有向，若存在一种方法让该图成为一个有向无环图，输出所有边，否则输出No。

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

