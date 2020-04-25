/*************************************************************************
	> File Name: 326.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/23 20:41:19 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 50000 //要维护的最大结点数
int fa[MAX_N + 5], val[MAX_N + 5]; //fa[i]记录每个父结点的坐标 val[i]记录子结点到父结点的权值

void init(int n) {
    for (int i = 1; i <= n; i++) { //从一开始
        fa[i] = i;
        val[i] = 0;
    }
    return ;
}

/*找父结点并且路径压缩*/
int get(int x) {
    if (x == fa[x]) return x; //父结点就是本身
    int root = get(fa[x]);
    val[x] += val[fa[x]]; //路径压缩
    val[x] %= 3; //得到关系
    return fa[x] = root;
}

int merge(int x, int y, int t) {
    int a = get(x), b = get(y); //获得x,y最终的父结点
    if (a == b) { //此时x,y已经被挂在了同一个结点下
        return (val[x] - val[y] - t) % 3 == 0; //x,y之间的关系：val[x] - val[y]，用其和t作比较，来判断我们做的这条连接是否正确
    }
    fa[a] = b; //把结点a挂在结点b
    val[a] = (t + val[y] - val[x] + 3) % 3; //求a到b的权，+3是为了保证正值, 可画图理解，同向为+，反向为-
    return 1;
}

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    init(n);
    for (int i = 0; i < k; i++) {
        int x, y, t;
        cin >> t >> x >> y;
        t -= 1; //将1映射到0，2映射到1
        if (x <= n && y <= n && merge(x, y, t)) continue;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
