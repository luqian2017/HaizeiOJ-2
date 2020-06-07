#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 1000
#define MAX_M 1000000
#define ind(i, j) ((i) * (m) + (j) + 1) //完成数组二维到一维的映射
char g[MAX_N + 5][MAX_N + 5];

struct UnionSet {
    int fa[MAX_M + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i; //0是我们特殊虚拟的，1 ～ n 才是题目给出的
    }
    int get(int X) {
        return (fa[X] = (X - fa[X] ? get(fa[X]) : X));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u; //占内存很大，不能开在主函数里

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n * m);
    for (int i = 0;  i < n; i++) {
        cin >> g[i]; //输入地图，一次一行字符串
        for (int j = 0;j < m; j++) {
            if (g[i][j] == 'X') continue;
            //上下， 左右为对偶的，所以只用判断一边，就有了以下逻辑：
            if (i && g[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j)); //当前这个点上面有一个点存在，且这个点还为'O'，表示可以连通
            if (j && g[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1)); //当前这个点左有一个点存在，且这个点还为'O'，表示可以连通   
            //判断一个点是否处在边界，若是，将该点与虚拟特殊点连接
            if (i == 0 || i == n - 1) u.merge(ind(i, j), 0);
            if (j == 0 || j == m- 1) u.merge(ind(i, j), 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') continue;
            if (u.get(ind(i, j)) - u.get(0)) ans += 1; //该节点与0节点不连通，则是答案
        }
    }
    cout << ans << endl;
    return 0;
}
